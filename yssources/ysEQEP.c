/******************************************************************************
| includes
|-------------------------------------------------------------------------------------------*/
#include "ysEQEP.h"

/******************************************************************************
| variables
|--------------------------------------------------------------------------------------------*/

/******************************************************************************
| functions
|-------------------------------------------------------------------------------------------*/
void InitEQEP1(void)
{
	EQep1Regs.QUPRD = 1500000;			// Unit Timer for 100Hz at 150 MHz SYSCLKOUT
	//EQep1Regs.QUPRD = 1000000;			// Unit Timer for 100Hz at 100 MHz SYSCLKOUT

	EQep1Regs.QDECCTL.bit.QSRC = 0;		// QEP quadrature count mode

	EQep1Regs.QEPCTL.bit.FREE_SOFT = 2;
	EQep1Regs.QEPCTL.bit.PCRM = 0;		// PCRM=00 mode - QPOSCNT reset on index event
	EQep1Regs.QEPCTL.bit.UTE = 1; 		// Unit Timeout Enable
	EQep1Regs.QEPCTL.bit.QCLM=1; 		// Latch on unit time out
	EQep1Regs.QPOSMAX=0xffffffff;
	EQep1Regs.QEPCTL.bit.QPEN=1; 		// QEP enable

	EQep1Regs.QCAPCTL.bit.UPPS=5;   	// 1/32 for unit position
	EQep1Regs.QCAPCTL.bit.CCPS=7;		// 1/128 for CAP clock
	EQep1Regs.QCAPCTL.bit.CEN=1; 		// QEP Capture Enable
}
