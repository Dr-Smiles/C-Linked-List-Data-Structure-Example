#include "Header.h"

//DiceArray elamaninin baslatilmasi.
//diceArray icin alt methodlari gosterir.
DiceArray DiceInitilize()
{
    DiceArray this;

    this = (DiceArray)malloc(sizeof(struct DICE_ARRAY));

    this->next = NULL;

    this->DiceInsert = &DiceInsert;
    this->DicePrintAll = &DicePrintAll;
    return this;
}

//DiceArray icin bir eleman ekleme islemi.
void DiceInsert(DiceArray self, int diceNumber){
    DiceArray newDice = (DiceArray)malloc(sizeof(struct DICE_ARRAY));
    newDice->diceNumber = diceNumber;
    newDice->next = NULL;
    if(self->next == NULL){
        self->next = newDice;
    }
    else{
        DiceArray temp = self->next;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newDice;
    }
}

//DiceArray icin tum elemanlari yazdiran method.
void DicePrintAll(DiceArray self){
    DiceArray temp = self->next;
    while(temp != NULL){
        printf("%d\n", temp->diceNumber);
        temp = temp->next;
    }
}

// Verilen kurallara, Kisi sayisina ve verilen Sayilara gore
// Oyunun baslatilmasi.
void PlayTheGame(PlayerArray player, DiceArray dice, double *masa, boolean debugify){
    
    PlayerArray Player; // player->next olmamasinin sebebi while icinde olmasi.
    DiceArray Dice = dice->next;
    PlayerArray HighestPlayer; // En yuksek oyuncu.
    int counter = 0;    // Turn sayac.

    while (Dice != NULL){

        Player = player->next;
        counter++;

        while(Player != NULL){ // Oyuncu varmi kontrolu.
            if (Player->health > 1000.00){ // 1000.00 degerinden kucuk olanlarin oynamasini engeller.
                // Oyuncu kaybetme islemi.
                if(Player->diceNumber != Dice->diceNumber){
                    *masa += (Player->changeRate * Player->health);
                    Player->health -= (Player->changeRate * Player->health); 
                }
                // Oyuncu kazanma islemi.
                else if(Player->diceNumber == Dice->diceNumber){
                    *masa -= (Player->changeRate * Player->health *9);
                    Player->health += ((Player->changeRate * Player->health) * 9); 
                    // (x - x*DegismeOrani) + x*DegismeOrani*10 == x + x*degismeOrani*9
                }
            }
            Player = Player->next; // Sonraki oyuncuyu al.
        }
        HighestPlayer = PlayerHighest(player); // Round sonundaki en yuksek oyuncuyu al.

        // Debug moduna gore round sonucunu yazdirama.
        if(debugify == 0){
            printGameScreen(counter, Dice->diceNumber, HighestPlayer->name, HighestPlayer->health, masa);
            Sleep(350); // 0.35 saniye bekle. >>>> HIZ AYARI BURADA <<<<.
        }
        else if (debugify == 1){
            wprintf(L"TUR %d | Şanslı Numara: %d |\t", counter, Dice->diceNumber);
            wprintf(L"%s, %.2f Para miktari ile en zengin oyuncu. \t\t", HighestPlayer->name, HighestPlayer->health);
            wprintf(L" Masa: %.2f\n", *masa);
        }
        Dice = Dice->next; // Sonraki sayiyi al.
    }

    // Oyun sonunda en yuksek oyuncu ve masa bilgilerini yazdir.
    // Debug moduna gore degistirilmeli.
    if(debugify == 1){
        wprintf(L"Tur Sayısı: %d ve Masa: %.2f\n", counter, *masa);
    }
    else if (debugify == 0){
        printEndOfGameScreen(counter, masa);
    }

}