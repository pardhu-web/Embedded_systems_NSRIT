#include<reg51.h>
void delay(int time);
void main()
{
	unsigned char a=0;
	for(a=0;a<=255;a++)
	{
	P1 = a;
	delay(100);
	}
}


void delay(int time)
{
	unsigned int i,j;
	for(i=0;i<=time;i++)
	{
	for(j=0;j<=1000;j++);
	}
}