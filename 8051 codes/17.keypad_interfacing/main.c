#include<reg51.h> //header file
#include<stdio.h> // sprint

#define lcd P2   //lcd data pins
sbit en = P3^1;	 //Enable
sbit rs = P3^0;	 //Register select


sbit r1 = P1^0;
sbit r2 = P1^1;
sbit r3 = P1^2;
sbit r4 = P1^3;

sbit c1 = P1^4;
sbit c2 = P1^5;
sbit c3 = P1^6;


void delay(unsigned int time)	  //delay function
{
	unsigned int i,j;
	for(i=0;i<=time;i++)
	{
		for(j=0;j<=1000;j++);
	}

}

void lcd_cmd(unsigned char ch)	 //command function
{
  lcd = ch;
  rs=0;
  en=1;
  delay(2);
  en=0;
}

void lcd_data(unsigned char ch)	 //data function
{
  lcd = ch;
  rs=1;
  en=1;
  delay(2);
  en=0;
}

void lcd_print(char str[])
{
	unsigned int k=0;
	for(k=0;str[k]!='\0';k++)
	{
	  lcd_data(str[k]);
	}	
}

void int_lcd(int num)
{
   char buffer[16];
   sprintf(buffer,"%d",num);  
   lcd_print(buffer);
}

void float_lcd(float num)
{
   char buffer[16];
   sprintf(buffer,"%.2f",num);  
   lcd_print(buffer);
}

char read_keypad()
{
r1=0;r2=1;r3=1;r4=1;
if(c1 == 0){while(c1==0); return '1';}
if(c2 == 0){while(c2==0); return '2';}
if(c3 == 0){while(c3==0); return '3';}

r1=1;r2=0;r3=1;r4=1;
if(c1 == 0){while(c1==0); return '4';}
if(c2 == 0){while(c2==0); return '5';}
if(c3 == 0){while(c3==0); return '6';}

r1=1;r2=1;r3=0;r4=1;
if(c1 == 0){while(c1==0); return '7';}
if(c2 == 0){while(c2==0); return '8';}
if(c3 == 0){while(c3==0); return '9';}

r1=1;r2=1;r3=1;r4=0;
if(c1 == 0){while(c1==0); return '*';}
if(c2 == 0){while(c2==0); return '0';}
if(c3 == 0){while(c3==0); return '#';}

return 'n';

}

char get_key()
{
 char key = 'n';
 while(key == 'n')
 {
 key = read_keypad();
 }
 return key;
}

void main()  //main programs
{
	lcd_cmd(0x38); //select 8bit 2lines
	lcd_cmd(0x01); //clear display
	lcd_cmd(0x0E); //display on coursor blink
	lcd_cmd(0x06); //Increment from leftg to right
	lcd_cmd(0x80);
	while(1)
	{
	   char new_key = get_key();
	   lcd_data(new_key);
	}		
} 