#include <io.h> // Ekran ciktilari icin 
#include <fcntl.h>  // Ekran ciktilari icin
#include <windows.h> // Ekran ciktilari ve Sleep icin

void printGameScreen(int tur, int dice,char highestName[128], double highestMoney, double *masa);
void printEndOfGameScreen(int tur, double* masa);