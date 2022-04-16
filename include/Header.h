#ifndef HEADED_H
#define HEADED_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // stccmp kullanmak icin
//#include <math.h> // Dosya okuma icindi >> Artik bu kullanilmiyor.
//#include <conio.h> // Ekran ciktilari icin >> Artik bu kullanilmiyor. mingw icinde yok.
#include <io.h> // Ekran ciktilari icin 
#include <fcntl.h>  // Ekran ciktilari icin
#include <windows.h> // Ekran ciktilari ve Sleep icin

#endif // HEADED_H

// Birden fazla define ve include eklenmesini engellemek icin
#ifndef KİSİ_H
#define KİSİ_H
#include "Kisi.h"
#endif // KİSİ_H

#ifndef OYUN_H
#define OYUN_H
#include "Oyun.h"
#endif // OYUN_H

#ifndef DOSYA_H
#define DOSYA_H
#include "Dosya.h"
#endif // DOSYA_H

#ifndef CONSOLEPRINTER_H
#define CONSOLEPRINTER_H
#include "ConsolePrinter.h"
#endif // CONSOLEPRINTER_H