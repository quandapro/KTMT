/*
 * Bai2.c
 *
 * Created: 10/2/2020 10:01:14 AM
 * Author: Dell
 // Viet chuong trinh led sang - toi theo chu ky 1s (Blinking LED)     
 // Viet chuong trinh sang 1s - toi 1s - sang 2s - toi 2s - toi mai  
 // Viet chuong trinh bam nut CT_1 den sang, tha nut CT_1 den tat
 CT1 = PD3 => INPUT => DDR = 0
 // Viet chuong trinh bam CT_1 den sang, bam CT_2 den nhap nhay
 */

#include <io.h>
#include <delay.h> // Thu vien de su dung ham lam tre (delay)


void main(void)
{
DDRE = 0x20;
DDRD = 0x00; // PORT D => PD3, PD5 la input
PORTD = 0x28; // 0b0010 1000

while (1)
    {
        if (PIND.3 == 0) // Day la phep so sanh
        {
            PORTE = 0x00;
        }
        if (PIND.5 == 0)
        {
            PORTE = 0x00;
            delay_ms(100);
            PORTE = 0x20;
            delay_ms(100); 
        }
        else
        {
            PORTE = 0x20;
        }
    }
}
