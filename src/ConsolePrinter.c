#include "Header.h"

// Konsol imlecinin konumunu ayarlar.
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Ciktilar icin kenarlari cizdirir.
void printBorders(int satir, int sutun){
    int x,y;
    wchar_t star = 0x2605;
    for(y = 0; y<sutun; y++){
        for(x = 0; x<satir; x++){
            if ((y==0 | y==sutun-1) | (x==0 | x == satir-1)){
                gotoxy(x,y);
                wprintf(L"\u2588");
            }
        }
    }
}

// Ciktilar icin kenarlari cizdirir.
// Icinde bir alt cizgi bulunduran versiyon.
void printBordersWith2(int satir, int sutun, int secondY){
    int x,y;
    for(y = 0; y<sutun; y++){
        for(x = 0; x<satir; x++){
            if ((y==0 | y==sutun-1 | y==secondY) | (x==0 | x == satir-1)){
                gotoxy(x,y);
                wprintf(L"\u2588");
            }
        }
    }
}

// Oyun ciktilarini ekrana yazdirir.
void printGameScreen(int tur, int dice,char highestName[128], double highestMoney, double *masa){
    system ("cls"); 
    printBordersWith2(45, 15, 5);
    gotoxy(5,2);
    wprintf(L"Tur Sayısı: %d", tur);
    gotoxy(5,3);
    wprintf(L"Şanslı Numara: %d", dice);
    gotoxy(5,8);
    wprintf(L"Masa: %.2f", *masa);
    gotoxy(5,10);
    wprintf(L"En zengin oyuncu: %s", highestName);
    gotoxy(5,11);
    wprintf(L"Oyuncu bakiyesi: %.2f", highestMoney);
    gotoxy(5,16);
}

// Oyun sonu ekrani.
void printEndOfGameScreen(int tur, double* masa){
    system ("cls");
    printBordersWith2(45, 10, 4);
    gotoxy(18,2);
    wprintf(L"OYUN BİTTİ");
    gotoxy(5,6);
    wprintf(L"Toplam Tur Sayisi: %d", tur);
    gotoxy(5,7);
    wprintf(L"Toplam Masa: %.2f", *masa);
    gotoxy(5,12);
}