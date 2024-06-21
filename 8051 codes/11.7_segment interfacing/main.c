#include<reg51.h>

#define segment P2

void delay(int time)
{
 unsigned int i,j;
 for(i=0;i<=time;i++)
 {
 	for(j=0;j<=1000;j++);
 }
}
char digit[] = {0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};
int k=0;
void main()
{
while(1)
{
	segment = digit[k];
	delay(100);
	k++;

	if(k>9)
	{
		k=0;
	}
}
}