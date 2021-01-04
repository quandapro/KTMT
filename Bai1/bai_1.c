/*
 * bai_1.c
 *
 * Created: 9/25/2020 9:43:30 AM
 * Author: Dell
 */
// viet chuong trinh dieu khien den led tren board mach

/*
Den LED duoc ket noi vao PE5 (Port E bit 5)
De dieu khien duoc den LED thi du lieu phai di tu MCU ra LED (OUTPUT)
Tuy thuoc vao ket noi LED voi MCU la loai nao ma logic xuat ra de dieu khien tuong ung la 0 hoac 1 de bat den
    Neu noi loai K thi LED sang khi logic xuat ra = 0
    Neu noi loai A thi LED sang khi logic xuat ra = 1
    Trong mach dien duoc ket noi theo dang K
*/

/*
Trong AVR co 3 thanh ghi tac dong vao tung port
    DDR = Data DiRection = thanh ghi chi huong du lieu
        DDR = 1 Du lieu duoc dieu khien theo huong di tu MCU - DV/ (Output)
        DDR = 0 Du lieu duoc dieu khien nhan tu device vao MCU (Input)
    PORT Thanh ghi du lieu 
        PORT = 1 + Output = Ghi logic 1 o loi ra (nghia la noi ra voi VCC = 5V, 3.3V...)
        PORT = 1 + Input thi loi vao duoc PULL UP (treo len VCC)
        PORT = 0 thi ghi logic 0 o loi ra (nghia la noi loi ra voi GND = 0V)
    PIN Thanh ghi doc du lieu
*/

/* De PE5 la loi ra chung ta phai tac dong vao DDR
    DDRE.5 = 1;
    Vi led noi theo kieu K nen muon LED sang, chung ta phai xuat logic 0V = GND
    PORTE.5 = 0;
*/
#include <io.h>

/* bien toan cuc */ // Chu y khai bao thong minh, tiet kiem RAM

void main(void)
{
//DDRE.5 = 1; // Day la cach viet tac dong truc tiep vao bit
//DDRE = 0b0010 0000 ; // Cach viet nhi phan
DDRE = 0x20; // Cach viet hex
PORTE = 0x20;
while (1)
    {
        // PORTE.5 = 0;
    }
}

