struct DICE_ARRAY{
    int diceNumber;
    struct DICE_ARRAY *next;

    void (*DiceInsert)(struct DICE_ARRAY *, int diceNumber);
    void (*DicePrintAll)(struct DICE_ARRAY *);
};

typedef struct DICE_ARRAY* DiceArray;
DiceArray DiceInitilize();
void DiceInsert(DiceArray, int diceNumber);
void DicePrintAll(DiceArray);

void PlayTheGame(PlayerArray player, DiceArray dice, double *masa, boolean debugify);