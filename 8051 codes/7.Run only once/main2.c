#include<reg51.h>

sbit led =  P1^0;

void delay(int time)
{
unsigned int i,j;
for(i=0;i<=time;i++)
{
for(j=0;j<1000;j++);
}
}

void main()
{
	int i=0;
	for(i=0;i<10;i++)
	{
	led = ~led;
	delay(100);
	}
	while(1)
	{
	
	}
}

