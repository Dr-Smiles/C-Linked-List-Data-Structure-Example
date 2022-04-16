#include "Header.h"

DiceArray DiceInitilize()
{
    DiceArray this;

    this = (DiceArray)malloc(sizeof(struct DICE_ARRAY));

    this->next = NULL;

    this->DiceInsert = &DiceInsert;
    this->DicePrintAll = &DicePrintAll;
    return this;
}

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

void DicePrintAll(DiceArray self){
    DiceArray temp = self->next;
    while(temp != NULL){
        printf("%d\n", temp->diceNumber);
        temp = temp->next;
    }
}

void PlayTheGame(PlayerArray player, DiceArray dice, double *masa, boolean debugify){
    PlayerArray Player;
    DiceArray Dice = dice->next;
    PlayerArray HighestPlayer;
    int counter = 0;

    while (Dice != NULL){
        Player = player->next;
        counter++;
        while(Player != NULL){
            if (Player->health > 1000.00){
                if(Player->diceNumber != Dice->diceNumber){
                    *masa += (Player->changeRate * Player->health);
                    Player->health -= (Player->changeRate * Player->health); 
                }
                else if(Player->diceNumber == Dice->diceNumber){
                    *masa -= (Player->changeRate * Player->health *10);
                    Player->health += ((Player->changeRate * Player->health) * 9); 
                }
            }
            Player = Player->next;
        }
        HighestPlayer = PlayerHighest(player);

        if(debugify == 0){
            printGameScreen(counter, Dice->diceNumber, HighestPlayer->name, HighestPlayer->health, masa);
            Sleep(350);    
        }
        else if (debugify == 1){
            wprintf(L"TUR %d | Şanslı Numara: %d |\t", counter, Dice->diceNumber);
            wprintf(L"%s, %.2f Para miktari ile en zengin oyuncu. \t\t", HighestPlayer->name, HighestPlayer->health);
            wprintf(L" Masa: %.2f\n", *masa);
        }
        Dice = Dice->next;
    }

    if(debugify == 1){
        wprintf(L"Tur Sayısı: %d ve Masa: %.2f\n", counter, *masa);
    }
    else if (debugify == 0){
        printEndOfGameScreen(counter, masa);
    }

}