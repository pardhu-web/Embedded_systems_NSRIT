#include<reg51.h>   //header file for 8051

sbit E_red = P1^0;
sbit E_green = P1^1;
sbit E_yellow = P1^2;

sbit W_red = P1^3;
sbit W_green = P1^4;
sbit W_yellow = P1^5;

sbit S_red = P1^6;
sbit S_green = P1^7;
sbit S_yellow = P2^0;


sbit N_red = P2^1;
sbit N_green = P2^2;
sbit N_yellow = P2^3;


void E_allow(int time);
void W_allow(int time);
void S_allow(int time);
void N_allow(int time);
void delay(int val);
void E_ready(int num);
void W_ready(int num);
void S_ready(int num);
void N_ready(int num);



void main()
{

   E_red=E_green=E_yellow=0;
   W_red=W_green=W_yellow=0;
   S_red=S_green=S_yellow=0;
   N_red=N_green=N_yellow=0;
   delay(500);
	while(1)
	{
	 E_allow(500); W_ready(5);
	 W_allow(500); S_ready(5);
	 S_allow(500); N_ready(5);
	 N_allow(500); E_ready(5);
	}
}

void E_allow(int time)
{
  E_green = 1;  E_red=E_yellow=0;
  W_red = 1;  W_green=W_yellow=0;
  S_red = 1;  S_green=S_yellow=0;
  N_red = 1;  N_green=N_yellow=0;
  delay(time);
}

void W_allow(int time)
{
  W_green = 1;  W_red=W_yellow=0;
  E_red = 1;  E_green=E_yellow=0;
  S_red = 1;  S_green=S_yellow=0;
  N_red = 1;  N_green=N_yellow=0;
  delay(time);
}

void S_allow(int time)
{
   S_green = 1;  S_red=S_yellow=0;
  W_red = 1;  W_green=W_yellow=0;
  E_red = 1;  E_green=E_yellow=0;
  N_red = 1;  N_green=N_yellow=0;
  delay(time);
  }


void N_allow(int time)
{
   N_green = 1;  N_red=N_yellow=0;
  W_red = 1;  W_green=W_yellow=0;
  S_red = 1;  S_green=S_yellow=0;
  E_red = 1;  E_green=E_yellow=0;
  delay(time);
}

 void delay(int val)
  {
	  unsigned int i,j=0;
	  for(i=0;i<=val;i++)
	  {
	  	for(j=0;j<=1000;j++);
	  }
  }


  void E_ready(int num)
  {
  int i=0;
  for(i=0;i<=num;i++)
  {
   E_yellow = ~E_yellow;
   delay(10);
  }
  }

  void W_ready(int num)
  {
  int i=0;
  for(i=0;i<=num;i++)
  {
   W_yellow = ~W_yellow;
   delay(10);
  }
  }

  void S_ready(int num)
  {
  int i=0;
  for(i=0;i<=num;i++)
  {
   S_yellow = ~S_yellow;
   delay(10);
  }
  }

  void N_ready(int num)
  {
  int i=0;
  for(i=0;i<=num;i++)
  {
   N_yellow = ~N_yellow;
   delay(10);
  }
  }

