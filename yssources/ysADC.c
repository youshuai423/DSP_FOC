/******************************************************************************
| includes
|-------------------------------------------------------------------------------------------*/
#include "ysADC.h"

/******************************************************************************
| variables
|--------------------------------------------------------------------------------------------*/
int conv_flg = 0;

/******************************************************************************
| functions
|-------------------------------------------------------------------------------------------*/
void InitADC(void)
{
	AD7606_RST_HIGH;
	DELAY_US(0.5L);
	AD7606_RST_LOW;
	DELAY_US(0.5L);
	AD7606_RST_HIGH;
}

void SerialRD(double * buf)
{
	unsigned char j, k;
	unsigned short int TempA, TempB;

   /* ת����ʼ */
	AD7606_CNVST_LOW;
	DELAY_US(1);  // *
	AD7606_CNVST_HIGH;
	DELAY_US(1);

	while(AD7606_BUSY_READ==1)
	{
	}

	 /* Ƭѡ�ź���Ч */
	//AD7606_SCS_LOW;

	for(j=0; j<Nospl / 2; j++)
	{
		TempA=0;
		TempB=0;

		for(k=0; k<16; k++)
		{
			AD7606_SCK_LOW;

			TempA=(TempA<<1) + AD7606_DOUTA_READ;
			TempB=(TempB<<1) + AD7606_DOUTB_READ;

			AD7606_SCK_HIGH;
		}

		buf[2 * j]=(int)TempA * (sRange * 2 / 65536.0);
		buf[2 * j + 1]=(int)TempB * (sRange * 2 / 65536.0); //������ת��Ϊģ����,���뷶Χ������10V,����Ϊ16λ
		                                //�൱�ڽ�20V�ֳ���65536��,��ʽΪA=(20.0/65536.0)*D;AΪģ����ֵ��DΪ������ֵ;
		                                //������뷶Χ������5V��ʽΪA=(10.0/65536.0)*D
	}
	AD7606_SCS_HIGH;
	conv_flg=1;
}

void ParallelRD(double * buf)
{
	int16 addat[16];
	int16 i = 0;

	AD7606_CNVST_HIGH;//xhold--ADCONV,����ADת��
	DELAY_US(0.5L);
	AD7606_CNVST_LOW;
	DELAY_US(0.5L);
	AD7606_CNVST_HIGH;
	//DELAY_US(5L);

	//����AD������100us֮ǰ�Ľ��?????
	if(AD7606_BUSY_READ == 0)//AD_BUSY
	{
		addat[0] = *AD_ASTART;	      // UACA1�������ѹUab
		addat[1] = *(AD_ASTART);     // UACA2�������ѹUbc
		addat[2] = *(AD_ASTART);     // INV_Uab
		addat[3] = *(AD_ASTART);     // INV_Ubc
		addat[4] = *(AD_ASTART);     // VDC+
		addat[5] = *(AD_ASTART);     // VDC-
		addat[6] = *(AD_ASTART);     // Ia
		addat[7] = *(AD_ASTART);     // Ib
		DELAY_US(1L);
		addat[8] = *AD_BSTART;	      // Ic
		addat[9] = *AD_BSTART;        // Idc1
		addat[10] = *AD_BSTART;      // Idc2
		addat[11] = *AD_BSTART;      // Amux
		addat[12] = *AD_BSTART;      //
		addat[13] = *AD_BSTART;      //
		addat[14] =  *AD_BSTART;     //
		addat[15] =  *AD_BSTART;     //
	}

    for(i=0; i<Nospl ;i++)
	{
       buf[i]=addat[i]*sRange/32768.0;
	}
}
