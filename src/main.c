#include "Header.h"
#include "Kisi.h"
#include "Oyun.h"
#include "Dosya.h"

int main(int argc, char const *argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    //Ekran ciktisini icin Unicode ciktilari alimi icin
    //Konsol ceviri modu Unicode olarak ayarlanir
    //Ancak bu dongu sonucunda dar yazdirma islevi olan printf()
    //Calismaz hale geliyor. Bunun yuzden wprintf() kullanilir.

    //Daha fazla bilgi icin:
    //https://docs.microsoft.com/tr-tr/cpp/c-runtime-library/reference/setmode?view=msvc-170
    
    double masa = 0;
    
    // Eger -d argumani varsa debugify true olur.
    // Oyunu debug modda baslatir.
    // Gereksiz fonksiyonlar cagrilmaz.
    boolean debugify = 0;

    if (argc > 1){
        if (strcmp(argv[1], "-d") == 0){debugify = 1;}
        else{debugify = 0;}
    }

    // Kisiler ve Sayilarin eklenecegi arrayler baslatilir.
    PlayerArray playerArray = PlayerInitilize();
    DiceArray diceArray = DiceInitilize();

    //Okunan dosyadan kisiler ve sayilar eklenir.
    rfReadPlayers(playerArray, "Kisiler.txt");
    rfReadDice(diceArray, "Sayilar.txt");

    //Oyun baslatilir.
    PlayTheGame(playerArray, diceArray, &masa , debugify);

    //Oyun sonunda bellek temizlenir.
    free(playerArray);
    free(diceArray);

    return 0;
}
