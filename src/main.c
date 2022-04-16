#include "Header.h"

int main(int argc, char const *argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    double masa = 0;
    boolean debugify = 0;

    if (argc > 1){
        if (strcmp(argv[1], "-d") == 0){debugify = 1;}
        else{debugify = 0;}
    }

    PlayerArray playerArray = PlayerInitilize();
    DiceArray diceArray = DiceInitilize();

    rfReadPlayers(playerArray, "Kisiler.txt");
    rfReadDice(diceArray, "Sayilar.txt");

    PlayTheGame(playerArray, diceArray, &masa , debugify);

    free(playerArray);
    free(diceArray);

    return 0;
}
