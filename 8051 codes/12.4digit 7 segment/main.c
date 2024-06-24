#include<reg51.h> 

#define led P2
sbit sw1=P3^0;
sbit sw2=P3^1;
sbit sw3=P3^2;
sbit sw4=P3^3;

unsigned char ch[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void display (unsigned long int);
void sdelay (char);



void sdelay (char d)
{
	for(;d>0;d--);
}

void delay(int val)
{
int a,b=0;
for(a=0;a<=val;a++)
{
	for(b=0;b<=1000;b++);
}
}

void display (unsigned long int n)
{
	led=ch[n/1000];
	sw1=1;
	sdelay(30);
	sw1=0;
	
	led=ch[(n/100)%10];
	sw2=1;
	sdelay(30);
	sw2=0;
	
	led=ch[(n/10)%10];
	sw3=1;
	sdelay(30);
	sw3=0;
	
	led=ch[n%10];
	sw4=1;
	sdelay(30);
	sw4=0;
}

void main()
{
	unsigned long int i=0;
	
	while(1)
	{
		i++;
		display(i); 
		if(i==9999)
			i=0;
	}
}