#include<reg51.h>
sbit led =  P1^0;
int i=0;
void delay()  //1ms delay
{
TH1 = 0xFC;
TL1 = 0x67;
TR1=1;
while(TF1 == 0);
TR1 = 0;
TF1 = 0;
}

void my_delay(int val)
{
	   for(i=0;i<=val;i++)
	   {
	   delay();
	   }
}

void main()
{
    TMOD = 0x10;
	while(1)
	{
	   led = 1;
	   my_delay(1000);

	   led = 0;
	   my_delay(1000);
	}
}