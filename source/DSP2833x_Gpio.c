//###########################################################################
//
// FILE:	DSP2833x_Gpio.c
//
// TITLE:	DSP2833x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.10 $
// $Release Date: February 15, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
   EALLOW;
   
   // Each GPIO pin can be: 
   // a) a GPIO input/output
   // b) peripheral function 1
   // c) peripheral function 2
   // d) peripheral function 3
   // By default, all are GPIO Inputs 
//epwm1-12
   GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;   // disable pullup on GPIO0
   GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;   // disable pullup on GPIO1
   GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;   // disable pullup on GPIO2
   GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;   // disable pullup on GPIO3
   GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;   // disable pullup on GPIO4
   GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;   // disable pullup on GPIO5
   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;   // disable pullup on GPIO6
   GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;   // disable pullup on GPIO7
   GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;   // disable pullup on GPIO8
   GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;   // disable pullup on GPIO9
   GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;   // disable pullup on GPIO10
   GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;   // disable pullup on GPIO11

  
    GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;  // 
   
    GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO5 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO5 = 1;  // 
   
    GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO8 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;  // 
   
    GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;  //  


// Enable Trip Zone inputs on GPIO12 - GPIO15
   GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;   // Enable pullup on GPIO12
   GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;   // Enable pullup on GPIO13
//   GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 3; // asynch input
//   GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3; // asynch input
   GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 1; // 3 sample time to SYSCLKOUT GPIO24 (TZ1) zl20090716cpc
   GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 1; // 3 sample time to SYSCLKOUT GPIO24 (TZ2) zl20090716cpc
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;  // GPIO12 = TZ1
   GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;  // GPIO13 = TZ2

//ad7606
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;    // Enable pull-up for GPIO14 (SCITXDB)
	GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // Enable pull-up for GPIO15 (SCIRXDB)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;  // Asynch input GPIO15 (SCIRXDB)
	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;   // Configure GPIO14 for SCITXDB operation
	GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;   // Configure GPIO15 for SCIRXDB operation 
    GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;  //
    GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;  // 
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 0;  // 
//scia
    GpioCtrlRegs.GPBPUD.bit.GPIO35 = 0;    // Enable pull-up for GPIO35 (SCITXDA)
	GpioCtrlRegs.GPBPUD.bit.GPIO36 = 0;    // Enable pull-up for GPIO36 (SCIRXDA)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO36 = 1;  // 3 sample time (SCIRXDA)//8.12
    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 0;   // Configure GPIO35 for SCITXDA operation
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 1;   // Configure GPIO36 for SCIRXDA operation
//	GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 0;   // Configure GPIO35 for SCITXDA operation
//	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 0;   // Configure GPIO36 for SCIRXDA operation
    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0;  // Enable pullup on GPIO34
    GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1; 
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;  // 485en
  //  GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;  // OUTPUT 485en
    GpioCtrlRegs.GPBDIR.bit.GPIO35 = 1;  // OUTPUT 485en
    GpioCtrlRegs.GPBDIR.bit.GPIO36 = 1;  // OUTPUT 485en
//spi-usb
    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;   // Enable pull-up on GPIO16 (SPISIMOA)
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;   // Enable pull-up on GPIO17 (SPISOMIA)
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;   // Enable pull-up on GPIO18 (SPICLKA)
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;   // Enable pull-up on GPIO19 (SPISTEA)
	GpioCtrlRegs.GPBPUD.bit.GPIO52 = 0;  // SPICS
    
    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3; // Asynch input GPIO16 (SPISIMOA)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3; // Asynch input GPIO17 (SPISOMIA)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3; // Asynch input GPIO18 (SPICLKA)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3; // Asynch input GPIO19 (SPISTEA)
	

	GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1; // Configure GPIO16 as SPISIMOA
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1; // Configure GPIO17 as SPISOMIA
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1; // Configure GPIO18 as SPICLKA
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0; // Configure GPIO19 as SPISTEA
	GpioCtrlRegs.GPADIR.bit.GPIO19 = 0;  //��ΪSPI_USB�ж�����
	GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;  // SPICS
    GpioDataRegs.GPBSET.bit.GPIO52 = 1;  //SPICS
    GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;  // SPICS
    
//GPIO20-23 as GPIO
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pull-up on GPIO18 (SPICLKA)
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;   // Enable pull-up on GPIO19 (SPISTEA)
    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;   // Enable pull-up on GPIO18 (SPICLKA)
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;   // Enable pull-up on GPIO19 (SPISTEA)
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0; // Configure GPIO18 as SPICLKA
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0; //Configure GPIO19 as SPISTEA
	GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0; // Configure GPIO18 as SPICLKA
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 0; // Configure GPIO19 as SPISTEA
	GpioDataRegs.GPACLEAR.bit.GPIO20 = 1;  //
    GpioDataRegs.GPACLEAR.bit.GPIO21 = 1;  //
	GpioDataRegs.GPACLEAR.bit.GPIO22 = 1;  //
    GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;  //
	GpioCtrlRegs.GPADIR.bit.GPIO20 = 1;   // ouTPUT
    GpioCtrlRegs.GPADIR.bit.GPIO21 = 1;   //ouTPUT
	GpioCtrlRegs.GPADIR.bit.GPIO22 = 1;   // IGBT-RESET
    GpioCtrlRegs.GPADIR.bit.GPIO23 = 1;   // INTPUT
//CAP1-6
	GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;     // enable pull-up on GPIO24 (CAP1)
	GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;    // enable pull-up on GPIO25 (CAP2)
	GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;     // enable pull-up on GPIO26 (CAP3)
	GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0;   // enable pull-up on GPIO27 (CAP4)
    GpioCtrlRegs.GPBPUD.bit.GPIO48 = 0;  //enable pull-up on GPIO48
    GpioCtrlRegs.GPBPUD.bit.GPIO49 = 0;  // enable pull-up on GPIO49  
	GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 1;   // 3 sample time to SYSCLKOUT GPIO24 (CAP1) 09.6.30 t=2.13us
	GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 1;   // 3 sample time to SYSCLKOUT GPIO25 (CAP2) 09.6.30
	GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 1;   // 3 sample time to SYSCLKOUT GPIO26 (CAP3) 09.6.30
	GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 1; 	// 3 sample time to SYSCLKOUT GPIO27 (CAP4) 09.6.15 t=0.853us
	GpioCtrlRegs.GPBQSEL2.bit.GPIO48 = 0;  //  Synch to SYSCLKOUT GPIO27 (CAP5) 
    GpioCtrlRegs.GPBQSEL2.bit.GPIO49 = 0;  //  Synch to SYSCLKOUT GPIO27 (CAP6) 
	GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 1;    // Configure GPIO24 as CAP1
	GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 1;   // Configure GPIO25 as CAP2
	GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 1;    // Configure GPIO26 as CAP3
	GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 1;  // Configure GPIO27 as CAP4  
    GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 1;  // apwm1 or CAP5 Configure GPIO27 as CAP5
	GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 1;  // apwm2  or CAP6   Configure GPIO27 as CAP6

//EEPROM
    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;   // Enable pullup on GPIO32
	GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 1;  // 3 sample time GPIO32 (SDAA)  //8.12 
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;  // GPIO32 
   
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;   // Enable pullup on GPIO33
    GpioDataRegs.GPBSET.bit.GPIO33 = 1;  // GPIO33 = SCLK
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0;  // GPIO33 = SCLK
    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;  // GPIO33 OUTPUT

//prd1//8.12
    GpioCtrlRegs.GPBCTRL.bit.QUALPRD0 = 100;  // sample frequency for 3 or 6 sample window 
    GpioCtrlRegs.GPACTRL.bit.QUALPRD3 = 32;   // sample frequency for 3 or 6 sample window FOR eCAP4
    GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 32;   // sample frequency for 3 or 6 sample window FOR TZ1 and TZ2 0.853us cpc
//apwm1,apwm2
    //GpioCtrlRegs.GPBPUD.bit.GPIO48 = 1;  //disable pull-up on apwm1
	//GpioCtrlRegs.GPBPUD.bit.GPIO49 = 1;  // disable pull-up on apwm2 
	//GpioDataRegs.GPBCLEAR.bit.GPIO48 = 1;  //=0
	//GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;  // =0 
    //GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 0;  // apwm1
	//GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 0;  // apwm2 
	//GpioCtrlRegs.GPBDIR.bit.GPIO48 = 0;  // apwm1
	//GpioCtrlRegs.GPBDIR.bit.GPIO49 = 0;  // apwm2 

//mode0-5
	GpioCtrlRegs.GPBPUD.bit.GPIO50 = 0;  //XHOLD
	GpioCtrlRegs.GPBPUD.bit.GPIO51 = 0;  // ADRES
	
	GpioCtrlRegs.GPBPUD.bit.GPIO53 = 0;  // AD1BUSY
	GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0;  //AD2BUSY
	GpioCtrlRegs.GPBPUD.bit.GPIO55 = 0;  // mode5

   // GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 3;  //  asynchronous 
   // GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 3;  //  asynchronous 
   // GpioCtrlRegs.GPBQSEL2.bit.GPIO52 = 3;  //  asynchronous 
    GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 3;  //  asynchronous 
    GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 3;  //  asynchronous 
    GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 3;  //  asynchronous   
   
	GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 0;  // mode0
	GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 0;  // mode1

	GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 0;  // mode3
	GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0;  // mode4
	GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 0;  // mode5
    
  	GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1;  //
    GpioCtrlRegs.GPBDIR.bit.GPIO50 = 1;  // 
    GpioDataRegs.GPBCLEAR.bit.GPIO51 = 1;  //
    GpioCtrlRegs.GPBDIR.bit.GPIO51 = 1;  // 
	GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1;  //
    GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;  // 
    GpioCtrlRegs.GPBDIR.bit.GPIO53 = 0;  // 
    GpioCtrlRegs.GPBDIR.bit.GPIO54 = 0;  //
    GpioCtrlRegs.GPBDIR.bit.GPIO55 = 0;  // 
//display0-7
	GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;  // display0
	GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0;  // display1
	GpioCtrlRegs.GPBPUD.bit.GPIO58 = 0;  // display2
	GpioCtrlRegs.GPBPUD.bit.GPIO59 = 0;  // display3
	GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0;  // display4
	GpioCtrlRegs.GPBPUD.bit.GPIO61 = 0;  // display5
	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0;  // display6
	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 0;  // display7 

	GpioDataRegs.GPBSET.bit.GPIO56 = 1;  // display0
	GpioDataRegs.GPBSET.bit.GPIO57 = 1;  // display1
	GpioDataRegs.GPBSET.bit.GPIO58 = 1;  // display2
	GpioDataRegs.GPBSET.bit.GPIO59 = 1;  // display3
	GpioDataRegs.GPBSET.bit.GPIO60 = 1;  // display4
	GpioDataRegs.GPBSET.bit.GPIO61 = 1;  // display5
	GpioDataRegs.GPBSET.bit.GPIO62 = 1;  // display6
	GpioDataRegs.GPBSET.bit.GPIO63 = 1;  // display7 

	GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;  // display0
	GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;  // display1
	GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0;  // display2
	GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 0;  // display3
	GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;  // display4
	GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 0;  // display5
	GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 0;  // display6
	GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 0;  // display7

    GpioCtrlRegs.GPBDIR.bit.GPIO56 = 1;  //  OUTPUT
    GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1;  //   
    GpioCtrlRegs.GPBDIR.bit.GPIO58 = 1;  //  
    GpioCtrlRegs.GPBDIR.bit.GPIO59 = 1;  //  
    GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;  //   
    GpioCtrlRegs.GPBDIR.bit.GPIO61 = 1;  //  
    GpioCtrlRegs.GPBDIR.bit.GPIO62 = 1;  // 
    GpioCtrlRegs.GPBDIR.bit.GPIO63 = 1;  //  

//xd15-0 	
 	GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 3;  // XD15
    GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 3;  // XD14
    GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 3;  // XD13
    GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 3;  // XD12
    GpioCtrlRegs.GPCMUX1.bit.GPIO68 = 3;  // XD11
    GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 3;  // XD10
    GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 3;  // XD19
    GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 3;  // XD8
    GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 3;  // XD7
    GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 3;  // XD6
    GpioCtrlRegs.GPCMUX1.bit.GPIO74 = 3;  // XD5
    GpioCtrlRegs.GPCMUX1.bit.GPIO75 = 3;  // XD4
    GpioCtrlRegs.GPCMUX1.bit.GPIO76 = 3;  // XD3
    GpioCtrlRegs.GPCMUX1.bit.GPIO77 = 3;  // XD2
    GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 3;  // XD1
    GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 3;  // XD0

//xa0-19
    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 3;  // XA0/XWE1n
    GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 3;  // XA1
    GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 3;  // XA2
    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 3;  // XA3
    GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 3;  // XA4
    GpioCtrlRegs.GPBMUX1.bit.GPIO45 = 3;  // XA5
    GpioCtrlRegs.GPBMUX1.bit.GPIO46 = 3;  // XA6
    GpioCtrlRegs.GPBMUX1.bit.GPIO47 = 3;  // XA7

    GpioCtrlRegs.GPCMUX2.bit.GPIO80 = 3;  // XA8
    GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 3;  // XA9
    GpioCtrlRegs.GPCMUX2.bit.GPIO82 = 3;  // XA10
    GpioCtrlRegs.GPCMUX2.bit.GPIO83 = 3;  // XA11
    GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 3;  // XA12
    GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 3;  // XA13
    GpioCtrlRegs.GPCMUX2.bit.GPIO86 = 3;  // XA14
    GpioCtrlRegs.GPCMUX2.bit.GPIO87 = 3;  // XA15
    GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 3;  // XA16
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 3;  // XA17
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 3;  // XA18
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3;  // XA19

    GpioCtrlRegs.GPBMUX1.bit.GPIO38 = 3;  // XWE0

    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 3;  // XZCS7
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // XZCS6 
/*// Pull-ups can be enabled or disabled. 
    GpioCtrlRegs.GPAPUD.all = 0x0FC00FFF;    // disable pull-up on pwm1-12,xint1,xint2,cap1-4,enable pull-up on pdpinta,pdpintb,scitxdb,scirxdb
	GpioCtrlRegs.GPBPUD.all = 0x0000;      // 
	GpioCtrlRegs.GPCPUD.all = 0x0000;      //
    
    GpioCtrlRegs.GPAMUX1.all = 0xA5555555;   // Configure GPIO0-15 as pwm1-12,TZ1,TZ2,scitxdb,scirxdb
	GpioCtrlRegs.GPAMUX2.all = 0xFF550F55;   // Configure GPIO16-31 as spisimoa,spisomi,spiclka,spistea,cantxb,canrxb,gpi022,23,CAP1-4,XZCS6,a19,a18,a17
	GpioCtrlRegs.GPBMUX1.all = 0xFFFFFB40;   // Configure GPIO32-47 as gpio32(sdaa),gpio33(scla),485en,scitxda,scirxda,xzcs7,xwe,a16,a0-7
	GpioCtrlRegs.GPBMUX2.all = 0x0000;   // Configure GPIO48-63 as apwm1,apwm2,mode0-5,display0-7
	GpioCtrlRegs.GPCMUX1.all = 0xFFFFFFFF;     // Configure  GPIO64-GPIO79 AS D15-0
	GpioCtrlRegs.GPCMUX2.all = 0x0000FFFF;     // Configure  GPIO80-GPIO87 AS A8-15,RESERVED

//0-INPUT, 1-OUTPUT
	GpioCtrlRegs.GPADIR.all = 0x00C00000;      // 22,23 are outputs
	GpioCtrlRegs.GPBDIR.all = 0xFF030006;      // 33,34,48,49,56-63 are outputs,50-55 as inputs

   // Each input can have different qualification
   // a) input synchronized to SYSCLKOUT
   // b) input qualified by a sampling window
   // c) input sent asynchronously (valid for peripheral inputs only)
	GpioCtrlRegs.GPAQSEL1.all = 0x0F000000;    // asy for tz1,tz2
	GpioCtrlRegs.GPAQSEL2.all = 0x0000;    // GPIO16-GPIO31 Synch to SYSCLKOUT
	GpioCtrlRegs.GPBQSEL1.all = 0x0000;    // GPIO32-GPIO39 Synch to SYSCLKOUT 
	GpioCtrlRegs.GPBQSEL2.all = 0x0000;    // GPIO48-GPIO63 Synch to SYSCLKOUT */

	EDIS;

}	
	
//===========================================================================
// End of file.
//===========================================================================
