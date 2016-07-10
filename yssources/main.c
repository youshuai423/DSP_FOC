/******************************************************************************
| includes                          
|----------------------------------------------------------------------------*/
#include "main.h"
#include "math.h"

/******************************************************************************
| local variable definitions                          
|----------------------------------------------------------------------------*/
Uint16 Tinv[3] = {0, 0, 0};
Uint16 last[3];

double ADCSample[16];

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
  PieVectTable.EPWM1_INT = &epwm1_timer_isr;  // ePWM1中断函数入口
  EDIS;
  
  /* init application ports */
  InitPORT();
  InitPWM();
  //InitADC();
  //InitGpio();
 
  IER |= M_INT3;  // enable ePWM CPU_interrupt
  PieCtrlRegs.PIEIER3.bit.INTx1 = 1;  // enable ePWM1 pie_interrupt

  EINT;   // 总中断 INTM 使能
  ERTM;   // Enable Global realtime interrupt DBGM

  for(; ;)
  {
/*	  ParallelRD(ADCSample);
	  DACout(0, 5);
	  DACout(1, 4);
	  DACout(2, 3);
	  DACout(3, 2);*/
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
  EPwm1Regs.CMPA.half.CMPA = Tinv[0];
  EPwm2Regs.CMPA.half.CMPA = Tinv[1];
  EPwm3Regs.CMPA.half.CMPA = Tinv[2];

  // Clear INT flag for this timer
  EPwm1Regs.ETCLR.bit.INT = 1;

  // Acknowledge this interrupt to receive more interrupts from group 3
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
