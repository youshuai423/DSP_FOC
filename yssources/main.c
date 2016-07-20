/******************************************************************************
| includes                          
|----------------------------------------------------------------------------*/
#include "main.h"
#include "math.h"

/******************************************************************************
| local variable definitions                          
|----------------------------------------------------------------------------*/
Uint16 Tinv[3] = {0, 0, 0};
Uint16 last[3] = {0, 0, 0};

double ADCSample[16];

/* TEST */
/*PHASE_ABC Uabc = {0, 0, 0};
PHASE_ALBE Ualbe = {0, 0};
PHASE_DQ Udq = {0, 0};*/
double tpass = 0;
double idsum = 0;
double lasterr = 0;

/******************************************************************************
| global variable definitions                          
|----------------------------------------------------------------------------*/

/******************************************************************************
@brief  Main 
******************************************************************************/
void main(void)
{
  InitSysCtrl();

  DINT;

  InitPieCtrl();

  IER = 0x0000;
  IFR = 0x0000;

  InitPieVectTable();

  EALLOW;
  PieVectTable.EPWM4_INT = &epwm1_timer_isr;  // ePWM1中断函数入口
  //PieVectTable.TINT0 = &ISRTimer0;
  EDIS;
  
  /* init application ports */
  InitPORT();
  InitPWM();
  //InitCpuTimers();
  //ConfigCpuTimer(&CpuTimer0, 150, 100);
  //StartCpuTimer0();
  //InitADC();
  //InitGpio();
 
  IER |= M_INT3;  // enable ePWM CPU_interrupt
  //IER |= M_INT1;  // enable ePWM CPU_interrupt

  PieCtrlRegs.PIEIER3.bit.INTx4 = 1;  // enable ePWM1 pie_interrupt
  //PieCtrlRegs.PIEIER1.bit.INTx7 = 1;  // Enable TINT0 in the PIE: Group 1 interrupt 7

  EINT;   // 总中断 INTM 使能
  ERTM;   // Enable Global realtime interrupt DBGM

  for(; ;)
  {
  }
}

/******************************************************************************
@brief   FOC 
******************************************************************************/
interrupt void epwm1_timer_isr(void)
{
  Ud = 60;
  ualbe_cmd.al = 40 * cos(2*pi*10 * (period_count/10000.0));
  ualbe_cmd.be = 40 * cos(2*pi*10 * (period_count/10000.0) - 0.5*pi);
  
  period_count++;
  if (period_count > 10000) 
  {
    period_count = 0;
  }

  /* current sampling and voltage calculation *

  * speed calculation *
  wrCal(&lamdaralbe, &anglek, ualbe, ialbe, Ts);
  
  * 3s/2r coordinate transform *
  S3toR2(&iabc, &idq, theta);

  * rotor flux calculation *
  lamdar = lamdarCal(lamdar, idq.d);

  * theta calculation *
  theta = positonCal(wr, lamdar, idq.q, theta);

  * ud* calculation *
  udq_cmd.d = PImodule(ud_Kp, ud_Ki, idset - idq.d, &ud_Isum, ud_Uplimit, ud_Downlimit);

  * uq* calculation *
  if (n < 370)
    iqset = PImodule(iqset_Kp1, iqset_Ki1, nset - n, &iqset_Isum, iqset_Uplimit, iqset_Downlimit);
  else
    iqset = PImodule(iqset_Kp2, iqset_Ki2, nset - n, &iqset_Isum, iqset_Uplimit, iqset_Downlimit);
  
  udq_cmd.q = PImodule(uq_Kp, uq_Ki, iqset - idq.q, &uq_Isum, uq_Uplimit, uq_Downlimit);

  * 2r/2s coordinate transform *
  R2toS2(&udq_cmd, &ualbe_cmd, theta); */

  /* SVM modulation */
  ualbeSVM(ualbe_cmd.al, ualbe_cmd.be, Ud, Tinv);

  /* register setting */
  EPwm4Regs.CMPA.half.CMPA = Tinv[0];
  EPwm5Regs.CMPA.half.CMPA = Tinv[1];
  EPwm6Regs.CMPA.half.CMPA = Tinv[2];

  // Clear INT flag for this timer
  EPwm4Regs.ETCLR.bit.INT = 1;

  // Acknowledge this interrupt to receive more interrupts from group 3
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

/******************************************************************************
@brief   FOC
******************************************************************************/
interrupt void ISRTimer0(void)     // Timer 0
{
	theta = tpass * 2 * pi * 50 + 0.5*pi;

	iabc.a = sin(2 * pi * 50 * tpass);
	iabc.b = sin(2 * pi * 50 * tpass - 2.0/3.0*pi);
	iabc.c = sin(2 * pi * 50 * tpass + 2.0/3.0*pi);

/*	S3toS2(&Uabc, &Ualbe);
	S2toR2(&Ualbe, &Udq, angle);*/
	S3toR2(&iabc, &idq, theta);

	lamdar = lamdarCal(lamdar, idq.d);

	idsum = PImodule(10, 20, idsum, 0.1 * sin(100*pi*tpass), &lasterr, 5, -5);

	DACout(0, idsum);
	DACout(1, iabc.a);

	tpass += 0.0001;
	if (tpass > 1)
		tpass -= 1;

	// Acknowledge this interrupt to receive more interrupts from group 1
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
	CpuTimer0Regs.TCR.bit.TIF=1;
	CpuTimer0Regs.TCR.bit.TRB=1;
}
