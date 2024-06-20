#include<reg51.h>

sbit led = P1^0;
sbit button = P2^0;

void main()
{
	led = 0;
	while(1)
	{
	 if(button == 0)
	 {
	  led = 1;
	 }
	 if(button == 1)
	 {
	 led = 0;
	 }
	}
}