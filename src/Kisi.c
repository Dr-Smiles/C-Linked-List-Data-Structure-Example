#include "Header.h"

PlayerArray PlayerInitilize()
{
    PlayerArray this;

    this = (PlayerArray)malloc(sizeof(struct PLAYER_ARRAY));

    this->next = NULL;
    this->prev = NULL;

    this->PlayerInsert = &PlayerInsert;
    this->PlayerDelete = &PlayerDelete;
    this->PlayerPrintAll = &PlayerPrintAll;
    return this;
}

void PlayerInsert(PlayerArray self, char name[128], double health, double changeRate, int diceNumber){
    PlayerArray newPlayer = (PlayerArray)malloc(sizeof(struct PLAYER_ARRAY));
    strcpy(newPlayer->name, name);
    newPlayer->health = health;
    newPlayer->changeRate = changeRate;
    newPlayer->diceNumber = diceNumber;
    newPlayer->next = NULL;
    newPlayer->prev = NULL;
    
    if(self->next == NULL){
        self->next = newPlayer;
        newPlayer->prev = self;
    }
    else{
        PlayerArray temp = self->next;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newPlayer;
        newPlayer->prev = temp;
    }
}

void PlayerPrintAll(PlayerArray self){
    PlayerArray temp = self->next;
    while(temp != NULL){
        printf("%s | %f | %f | %d\n", temp->name, temp->health, temp->changeRate, temp->diceNumber);
        temp = temp->next;
    }
}

void PlayerDelete(PlayerArray self, char name[128]){
    PlayerArray temp = self->next;
    while(temp != NULL){
        if(strcmp(temp->name, name) == 0){
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            free(temp);
            break;
        }
        temp = temp->next;
    }
}

PlayerArray PlayerHighest(PlayerArray self){
    PlayerArray temp = self->next;
    PlayerArray highest = self->next;
    while(temp != NULL){
        if(temp->health > highest->health){
            highest = temp;
        }
        temp = temp->next;
    }
    //printf("%s, %.2f Para miktari ile en zengin oyuncu. \t\t", highest->name, highest->health);
    return highest;
}