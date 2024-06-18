#include<reg51.h>
void delay(int time);

void main()
{	
    unsigned int i=0;   
	for(i=0;i<=5;i++)
	{
	P1 = 0xFF;
	delay(100);
	P1= 0x00;
	delay(100);
	}
	P2 = P1;
	delay(500);

}


void delay(int time)
{
	unsigned int i,j;
	for(i=0;i<=time;i++)
	{
	for(j=0;j<=1000;j++);
	}
}