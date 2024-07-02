#include<reg51.h>
#include"display.h"

void main()
{
 lcd_cmd(0x38);
 lcd_cmd(0x01);
 lcd_cmd(0x0E);
 lcd_cmd(0x06);

 lcd_print("WELCOME");
}