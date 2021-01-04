/*
 * Bai4.c
 *
 * Created: 10/16/2020 9:20:46 AM
 * Author: Dell
 * Viet chuong trinh bam CT1 tung ky tu 1 trong Hello World chay tu trai sang phai va ket thuc o cuoi man hinh    
 * bam CT2 nguoc lai
 * ban CT3 hien HelloWorld o dong 2 man hinh
 */

#include <io.h>
#include <alcd.h>
#include <delay.h>

#define CT1 PIND.3
#define CT2 PIND.5
#define CT3 PIND.2

unsigned char mode = 0;
unsigned char x = 0, y = 0, len = 11, i, j;
char* message = "Hello World";

void main(void)
{
DDRD = 0x00;
PORTD = 0xFF;

lcd_init(16); //8
lcd_clear();
while (1)
    {
    if (CT1 == 0 || mode == 1)
        {           
            delay_ms(250);
            for (i = 0; i <= 15; i++)
                {   
                    lcd_gotoxy(i, y);
                    lcd_putchar(' ');
                    for (j = 0; j < len; j++)
                    {                             
                        // Pos of message[j] = x - j
                        if (x - j == i)
                        {
                            lcd_gotoxy(i, y);
                            lcd_putchar(message[len - j - 1]);
                        }
                    }     
                }
            x++;
            if (x == 16 + len - 1)
                x = 0;
            mode = 1;
        }       
    if (CT2 == 0 || mode == 2)
        {    
            delay_ms(250);  
            for (i = 0; i <= x; i++)
                {
                    
                }
            if (x == 0)
                x = 15;
            else
                x--;
            mode = 2;
            //_lcd_write_data(0x18);
        }
    if (CT3 == 0)
        {   
            y = ~y;            
        }   
    }
}
