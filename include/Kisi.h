struct PLAYER_ARRAY{
    char name[128];
    double health;
    double changeRate;
    int diceNumber;
    struct PLAYER_ARRAY *next;
    struct PLAYER_ARRAY *prev;

    void (*PlayerInsert)(struct PLAYER_ARRAY *, char name[128], double health, double changeRate, int diceNumber);
    void (*PlayerDelete)(struct PLAYER_ARRAY *, char name[128]);
    void (*PlayerPrintAll)(struct PLAYER_ARRAY *);
};

typedef struct PLAYER_ARRAY* PlayerArray;
PlayerArray PlayerInitilize();
PlayerArray PlayerHighest(PlayerArray);
void PlayerInsert(PlayerArray, char name[128], double health, double changeRate, int diceNumber);
void PlayerDelete(PlayerArray, char name[128]);
void PlayerPrintAll(PlayerArray);