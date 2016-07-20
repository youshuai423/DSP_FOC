/******************************************************************************
| includes                          
|----------------------------------------------------------------------------*/
#include "ysPWM.h"

/******************************************************************************
| local variable definitions                          
|----------------------------------------------------------------------------*/

/******************************************************************************
| global variable definitions                          
|----------------------------------------------------------------------------*/

/******************************************************************************
@brief   Initialization of PWMs

@param   N/A

@return  N/A
******************************************************************************/
void InitPWM(void)
{   
  // ----------------EPwm4---------------------
  EPwm4Regs.TBPRD = period;
  EPwm4Regs.TBPHS.half.TBPHS = 0;  // 时基周期寄存器
  EPwm4Regs.TBCTR = 0;  // 时基计数寄存器置零
  EPwm4Regs.TBCTL.bit.PHSDIR = TB_UP;
  EPwm4Regs.TBCTL.bit.CLKDIV = 0;
  EPwm4Regs.TBCTL.bit.HSPCLKDIV = 0;
  EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
  EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;

  EPwm4Regs.CMPA.half.CMPA = period / 2; // duty_cycle = 0.5
  EPwm4Regs.CMPB = 0;
  EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
  EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
  EPwm4Regs.AQCTLA.bit.CAU = AQ_SET;
  EPwm4Regs.AQCTLA.bit.CAD = AQ_CLEAR;
  
  EPwm4Regs.DBCTL.bit.IN_MODE = DBA_ALL;
  EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;  // A不翻转，B翻转
  EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
  EPwm4Regs.DBRED = 800; // Deadzone
  EPwm4Regs.DBFED = 800;

  EPwm4Regs.ETSEL.bit.INTEN = 1;  // 使能ePWM中断
  EPwm4Regs.ETSEL.bit.INTSEL = ET_CTR_PRD;
  EPwm4Regs.ETPS.all = 0x01; // interrupt on first event
  EPwm4Regs.ETPS.bit.INTPRD = ET_1ST;

  // ----------------EPwm5---------------------
  EPwm5Regs.TBPRD = period;
  EPwm5Regs.TBPHS.half.TBPHS = 0;  // 时基周期寄存器
  EPwm5Regs.TBCTR = 0;  // 时基计数寄存器置零
  EPwm5Regs.TBCTL.bit.PHSDIR = TB_UP;
  EPwm5Regs.TBCTL.bit.CLKDIV = 0;
  EPwm5Regs.TBCTL.bit.HSPCLKDIV = 0;
  EPwm5Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
  EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;

  EPwm5Regs.CMPA.half.CMPA = period / 2; // duty_cycle = 0.5
  EPwm5Regs.CMPB = 0;
  EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
  EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;

  EPwm5Regs.AQCTLA.bit.CAU = AQ_SET;
  EPwm5Regs.AQCTLA.bit.CAD = AQ_CLEAR;

  EPwm5Regs.DBCTL.bit.IN_MODE = DBA_ALL;
  EPwm5Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;  // A不翻转，B翻转
  EPwm5Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
  EPwm5Regs.DBRED = 800; // Deadzone
  EPwm5Regs.DBFED = 800;

  // ----------------EPwm6---------------------
  EPwm6Regs.TBPRD = period;
  EPwm6Regs.TBPHS.half.TBPHS = 0;  // 时基周期寄存器
  EPwm6Regs.TBCTR = 0;  // 时基计数寄存器置零
  EPwm6Regs.TBCTL.bit.PHSDIR = TB_UP;
  EPwm6Regs.TBCTL.bit.CLKDIV = 0;
  EPwm6Regs.TBCTL.bit.HSPCLKDIV = 0;
  EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
  EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;

  EPwm6Regs.CMPA.half.CMPA = period / 2; // duty_cycle = 0.5
  EPwm6Regs.CMPB = 0;
  EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
  EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;

  EPwm6Regs.AQCTLA.bit.CAU = AQ_SET;
  EPwm6Regs.AQCTLA.bit.CAD = AQ_CLEAR;

  EPwm6Regs.DBCTL.bit.IN_MODE = DBA_ALL;
  EPwm6Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;  // A不翻转，B翻转
  EPwm6Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
  EPwm6Regs.DBRED = 800; // Deadzone
  EPwm6Regs.DBFED = 800;
}
