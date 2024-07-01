#include<reg51.h> //header file
#include<stdio.h> // sprint

#define lcd P2   //lcd data pins
sbit en = P3^1;	 //Enable
sbit rs = P3^0;	 //Register select

sbit up = P1^0;
sbit down = P1^1;
sbit ok = P1^2;
sbit change_st = P1^3;

char *product[5] = {"Oil","Sugra","Rice","Salt","Drink"};
float cost[5] = {120.0,30.0,50.0,10.0,60.0};

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

int a=0;
float total_cost = 0;
int status=0;
void main()  //main programs
{
	lcd_cmd(0x38); //select 8bit 2lines
	lcd_cmd(0x01); //clear display
	lcd_cmd(0x0E); //display on coursor blink
	lcd_cmd(0x06); //Increment from leftg to right
    lcd_cmd(0x84);
	lcd_print("WELCOME"); delay(100);
	lcd_cmd(0x01);
	while(1)
	{
	lcd_cmd(0x01);
	lcd_cmd(0x8f); 
	int_lcd(status);
	lcd_cmd(0x80); 
	lcd_print("P_name:");
	lcd_print(product[a]);
	lcd_cmd(0xc0);
	lcd_print("T_cost:");
	float_lcd(total_cost);
	delay(50);
		if(up == 0)
		{
		while(up == 0);
		a++;
			if(a>=4)
			{
			a=4;
			}
		}
		if(down == 0)
		{
		while(down == 0);
		a--;
		     if(a<=0)
			{
			a=0;
			}
		}

		if(ok == 0)
		{
		while(ok == 0);
		if(status == 0)
		{
		total_cost = total_cost+cost[a];
  		}
		if(status == 1)
		{
		total_cost = total_cost-cost[a];
		}
		}

		if(change_st == 0)
		{
		while(change_st == 0);
		 status = !status;
		}
	}		
} 