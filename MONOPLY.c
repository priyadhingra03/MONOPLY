#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#define colour(C1,C2)   printf("\033[%d;%dm",C2,C1)
#define SCREENSIZE_X    190
#define SCREENSIZE_Y    60
enum colours  {RESET,INCREASED_INTENSITY,BLACK=30,RED,GREEN,YELLOW,BLUE,PURPLE,CYAN,WHITE,\
               RED_BG=41,GREEN_BG,YELLOW_BG,BLUE_BG,PURPLE_BG,CYAN_BG,WHITE_BG,\
               LIGHTBLACK_BG=100,LIGHTRED_BG,LIGHTGREEN_BG,LIGHTYELLOW_BG,LIGHTBLUE_BG,LIGHTPURPLE_BG,LIGHTCYAN_BG,PUREWHITE_BG};
int i,k,x=100,y=15;
const int INITIAL_AMT =1200   ;             // Amount of money each player start with
const int BANKRUPT_VALUE =-500 ;                // Min value of cash in hand to be not bankrupt
int ClearRightScreen(int startLine)
{
    for (int i=startLine;i<SCREENSIZE_Y;i++)
    {
        goto_XY(95,i);
        for(int j=0;j<(SCREENSIZE_X-95);j++)
            printf(" ");
    }
    return EXIT_SUCCESS;
}
void gotoxy()
{
    printf("%c[%d;%df",0x1B,y++,x);
}
void goto_XY(X,Y)
{
    printf("%c[%d;%df",0x1B,Y,X);
}
int intro()
    {
    printf("\n\n");
    printf("\n\033[32m                                   888       888 8888888888 888      .d8888b.   .d88888b.  888b     d888 8888888888      88888888888 .d88888b.\033[0m       ");
    printf("\n\033[32m                                   888   o   888 888        888     d88P  Y88b d88P\" \"Y88b 8888b   d8888 888                 888    d88P\" \"Y88b\033[0m  ");
    printf("\n\033[32m                                   888  d8b  888 888        888     888    888 888     888 88888b.d88888 888                 888    888     888\033[0m      ");
    printf("\n\033[32m                                   888 d888b 888 8888888    888     888        888     888 888Y88888P888 8888888             888    888     888\033[0m      ");
    printf("\n\033[32m                                   888d88888b888 888        888     888        888     888 888 Y888P 888 888                 888    888     888\033[0m      ");
    printf("\n\033[32m                                   88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888                 888    888     888\033[0m      ");
    printf("\n\033[32m                                   8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888                 888    Y88b. .d88P\033[0m     ");
    printf("\n\033[32m                                   888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888          888     \"Y88888P\"\033[0m ");
    printf("\n\n\n\n");
    printf("\n\033[32m                                              888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P\033[0m           ");
    printf("\n\033[32m                                              8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P\033[0m      ");
    printf("\n\033[32m                                              88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P\033[0m             ");
    printf("\n\033[32m                                              888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P\033[0m              ");
    printf("\n\033[32m                                              888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888\033[0m              ");
    printf("\n\033[32m                                              888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888\033[0m               ");
    printf("\n\033[32m                                              888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888\033[0m              ");
    printf("\n\033[32m                                              888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888\033[0m         ");
    printf("Press any key to continue...\n");
    getch();
    return 0;
}

int Menu()
{
        int choice;
        printf("\n\x1B[31;33m                                              888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P\x1B[0m           ");
        printf("\n\x1B[31;33m                                              8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P\x1B[0m      ");
        printf("\n\x1B[31;33m                                              88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P\x1B[0m             ");
        printf("\n\x1B[31;33m                                              888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P\x1B[0m              ");
        printf("\n\x1B[31;33m                                              888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888\x1B[0m              ");
        printf("\n\x1B[31;33m                                              888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888\x1B[0m               ");
        printf("\n\x1B[31;33m                                              888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888\x1B[0m              ");
        printf("\n\x1B[31;33m                                              888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888\x1B[0m         ");
        printf("\n\n\n\n\n");
        printf("Select from the following options: \n");
        printf("\n\t  1-Play Monopoly");
        printf("\n\t  2-Read Rules");
        printf("\n\t  3-Exit\n\n");
        int flag=1;
        while(flag==1)
        {
            scanf("%d",&choice);
            if (choice == 1)
            {
                flag=0;
            }
            else if (choice == 2)
            {
                flag=0;
                clearScreen();
                ShowRules();
            }
            else if (choice == 3)
            {
                flag=0;
                printf("You chose to exit!");
                exit(0);
            }
            else
            {
                printf("Invalid input!\n");
                printf("Enter again!\n");
                flag=1;
            }
        }
        clearScreen();
        return 0;
}

int ShowRules()
{
        printf("\n\033[96m          888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P      8888888b.  888     888 888      8888888888 .d8888b.\033[0m  ");
        printf("\n\033[96m          8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P       888   Y88b 888     888 888      888       d88P  Y88b\033[0m ");
        printf("\n\033[96m          88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P        888    888 888     888 888      888       Y88b.\033[0m      ");
        printf("\n\033[96m          888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P         888   d88P 888     888 888      8888888    \"Y888b.\033[0m   ");
        printf("\n\033[96m          888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888          8888888P\"  888     888 888      888           \"Y88b.\033[0m ");
        printf("\n\033[96m          888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888          888 T88b   888     888 888      888             \"888\033[0m ");
        printf("\n\033[96m          888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888          888  T88b  Y88b. .d88P 888      888       Y88b  d88P\033[0m ");
        printf("\n\033[96m          888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888          888   T88b  \"Y88888P\"  88888888 8888888888 \"Y8888P\"\033[0m  ");
        printf("\n");

            printf("\n\t\x1B[1;31mOBJECTIVE OF THE GAME\x1B[0m");
            printf("\n\tBecome the wealthiest player through buying, renting and selling of property and force other players into bankruptcy.");
            printf("\n\n\t\x1B[1;31mGAMEPLAY\x1B[0m");
            printf("\n\tAt the start, each player throws the dice. The player with the highest total starts the play.");
            printf("\n\tAll players start at \"START\" and are given the opportunity roll the two dice.");
            printf("\n\tBased on the total of the two, the player moves to a location and can buy the property, or pay rent/tax, draw a Chance/Community Chest card, Go To Jail, or etc...");
            printf("\n\tIf the player throws doubles, they move their token and are subject to any privileges or penalties pertaining to the space on which they land.");
            printf("\n\tThen they can throw again and move their token as before. However, if the player ever throws doubles three times in succession, they are immediately sent to jail.");

            printf("\n\n\t\x1B[1;31mSTART\x1B[0m");
            printf("\n\tEach time a player passes over START the player is paid a $200 salary.");
            printf("\n\n\t\x1B[1;31mBUYING PROPERTY\x1B[0m");
            printf("\n\tWhen a player lands on an unowned property they can buy that property at its printed price.");
            printf("\n\n\t\x1B[1;31mPAYING RENT\x1B[0m");
            printf("\n\tWhen a player lands on a property owned by another player, the owner collects rent in accordance with factors like no. of houses, hotels, etc.");
            printf("\n\n\t\x1B[1;31mCHANCE AND COMMUNITY CHEST\x1B[0m");
            printf("\n\tWhen a player lands here, they can recieve a certain amount, have to pay a certain amount, or teleport to a random location.");
            printf("\n\n\t\x1B[1;31mJAIL\x1B[0m");
            printf("\n\tA player can be sent to jail when they land on \"GO TO JAIL\" or roll a certain number of doubles.");
            printf("\n\tThe player is given the option to pay a certain amount to get out or can stay for a certain number of turns.");
            printf("\n\tIf the player stays, at each turn, the number of turns to wait is displayed. The player cannot sell properties or buy houses/hotels when in jail.");
            printf("\n\n\t\x1B[1;31mFREE PARKING\x1B[0m");
            printf("\n\tJust a free location with no reward or pentaly.");
            printf("\n\n\t\x1B[1;31mHOUSES AND HOTELS\x1B[0m");
            printf("\n\tIf the player has completed a set, they are now allowed to buy a max of 4 Houses or a hotel if they have a sufficient balance.");
            printf("\n\tThe player can build houses in only property type locations whose sets are completed.");
            printf("\n\tThe player can only build a hotel if 4 houses have been built.");
            printf("\n\n\t\x1B[1;31mBANKRUPTCY\x1B[0m");
            printf("\n\tWhen the player has an amount lesser than -500 in hand, they are bankrupt and out. Players can sell properties to avoid so.\n\n");
            printf("Press any key to continue...");
            getch();
            return 0;
}

void ReadPlayers(int inp,char Names[][30])
{
        clearScreen();
        printf("\n\x1B[36m              8888888b.  888             d8888 Y88b   d88P 8888888888 8888888b.       8888888b.  8888888888 88888888888     d8888 8888888 888      .d8888b.\x1B[0m  ");
        printf("\n\x1B[36m              888   Y88b 888            d88888  Y88b d88P  888        888   Y88b      888  \"Y88b 888            888        d88888   888   888     d88P  Y88b\x1B[0m ");
        printf("\n\x1B[36m              888    888 888           d88P888   Y88o88P   888        888    888      888    888 888            888       d88P888   888   888     Y88b.\x1B[0m      ");
        printf("\n\x1B[36m              888   d88P 888          d88P 888    Y888P    8888888    888   d88P      888    888 8888888        888      d88P 888   888   888      \"Y888b.\x1B[0m   ");
        printf("\n\x1B[36m              8888888P\"  888         d88P  888     888     888        8888888P\"       888    888 888            888     d88P  888   888   888         \"Y88b.\x1B[0m ");
        printf("\n\x1B[36m              888        888        d88P   888     888     888        888 T88b        888    888 888            888    d88P   888   888   888           \"888\x1B[0m ");
        printf("\n\x1B[36m              888        888       d8888888888     888     888        888  T88b       888  .d88P 888            888   d8888888888   888   888     Y88b  d88P\x1B[0m ");
        printf("\n\x1B[36m              888        88888888 d88P     888     888     8888888888 888   T88b      8888888P\"  8888888888     888  d88P     888 8888888 88888888 \"Y8888P\"\x1B[0m  ");
        printf("\n\n\n\n");
        if (inp >= 2 && inp<= 8)
        {
            for(i=0;i<inp;i++){
                printf("\n\tPlayer %d enter name: ",i+1);
                fflush(stdin);
                scanf("%s",&Names[i]);
            }
        }
        else{
        printf("\n\n\tInvalid Input (Enter a number from 2-8) \n\tEntered: %d\n",inp);
    }
}

void SetPlayerOrder(int numberOfPlayers, char Names[][30])
{
    clearScreen();
    printf("\n\x1B[33m                      8888888b.  888             d8888 Y88b   d88P 8888888888 8888888b.        .d88888b.  8888888b.  8888888b.  8888888888 8888888b.\x1B[0m  ");
    printf("\n\x1B[33m                      888   Y88b 888            d88888  Y88b d88P  888        888   Y88b      d88P\" \"Y88b 888   Y88b 888  \"Y88b 888        888   Y88b\x1B[0m ");
    printf("\n\x1B[33m                      888    888 888           d88P888   Y88o88P   888        888    888      888     888 888    888 888    888 888        888    888\x1B[0m ");
    printf("\n\x1B[33m                      888   d88P 888          d88P 888    Y888P    8888888    888   d88P      888     888 888   d88P 888    888 8888888    888   d88P\x1B[0m ");
    printf("\n\x1B[33m                      8888888P\"  888         d88P  888     888     888        8888888P\"       888     888 8888888P\"  888    888 888        8888888P\"\x1B[0m ");
    printf("\n\x1B[33m                      888        888        d88P   888     888     888        888 T88b        888     888 888 T88b   888    888 888        888 T88b\x1B[0m   ");
    printf("\n\x1B[33m                      888        888       d8888888888     888     888        888  T88b       Y88b. .d88P 888  T88b  888  .d88P 888        888  T88b\x1B[0m  ");
    printf("\n\x1B[33m                      888        88888888 d88P     888     888     8888888888 888   T88b       \"Y88888P\"  888   T88b 8888888P\"  8888888888 888   T88b\x1B[0m ");
    printf("\n\n\n\n");
    int die1, die2, order[10], len=strlen(Names[0]);
    for (int i=0;i<numberOfPlayers;i++){
        if (len<strlen(Names[i]))
            len=strlen(Names[i]);
    }
    for(int i=0;i<numberOfPlayers;i++){
        die1=PlayerRolls();
        die2=PlayerRolls();
        order[i]=die1+die2;
        printf("\n\t %s : Rolled a %d and a %d thus has a total of %d.",Names[i],die1,die2,order[i]);
    }

    int Temp;char TempName[30];
    for(int i=0;i<numberOfPlayers;i++){
        for(int j=0;j<numberOfPlayers-1;j++){
            if(order[j]<order[j+1])
            {
                int Temp = order[j+1];
                order[j+1] = order[j];
                order[j] = Temp;

                strcpy(TempName  , Names[j+1]);
                strcpy(Names[j+1], Names[j]);
                strcpy(Names[j]  , TempName);
            }
        }
    }

    printf("\n\n\tPlaying order based on highest roll of the dice:");
    for(int i=0;i<numberOfPlayers;i++)
        {
            printf("\n\t%s",Names[i]);
         }
    printf("\n");
    printf("        Press any key to continue...\n");
    getch();
}

int PlayerRolls()
{
    return (rand()%6)+1;
}

void clearScreen()
{
    system("cls");
}

extern struct location
{
    unsigned int ID  :6;                    // Uniquely identify location (1-40)
    unsigned int type:3;                    // Type of location: FREE/CHEST/CHANCE/JAIL/TAX/UTILITY/RAIL/PROPERTY
    int setColour:8;                        // Colour associated with set
    unsigned int isOwnable:1;               // If the location be owned currently by a player
    char name[30];                          // Name of the location
    int rent;                               // Current rent of the property
};

 struct player
{
    unsigned int ID:4;                      // Uniquely identify player
    char name[30];                          // Name of player
    unsigned int colour1:7,colour2:7;       // Colour of player on screen
    int currentLocation ;                   // The current location of the player (structure)
    short int netWorth;                     // The net worth of the player
    short int cashInHand;                   // Amount of cash player currently has
    unsigned int isOut:1;                   // If the player is out of the game
    unsigned int isBankrupt:1;              // If the player is bankrupt
    unsigned int isInJail:1;                // If the player is in jail
    unsigned int jailTurn:2;                // Number of turns player left to leave jail
    unsigned short int propertyOwnedCount:6;// Amount of properties the player owns
    char propertyOwned[20][20];               // Lists of properties the player owns
    unsigned int position:4;                // Position of the player post-game
    int pos[20];                            // to store the positions
    int c;                                  // to count the no of properties
} Player;
int GraphicalMove(struct player Player[],int OldLocationID,int i)
{
    int map[40][2]={{ 10,42},{ 10,39},{ 10,36},{ 10,33},{ 10,30},{ 10,27},{ 10,22},{ 10,23},{ 10,18},{ 10, 15},\
                    { 17, 15},{24, 15},{33, 15},{40, 15},{47, 15},{52, 15},{63, 15},{72, 15},{79, 15},{80, 18},\
                    {79, 21},{79, 24},{79,25},{79,30},{79,33},{79,34},{79,37},{79,42},{79,45},{79,48},\
                    {79,40},{72,40},{65,40},{58,40},{51,40},{44,40},{37,40},{30,40},{23,40},{16,40}};

    int playerID = Player[i].ID;
    int NewLocationID = Player[i].currentLocation;
    goto_XY(map[OldLocationID-1][0]+(playerID-1)%4,(map[OldLocationID-1][1]+(playerID-1)/4));
    printf(" ");
    colour(Player[i].colour1,Player[i].colour2);
    goto_XY(map[NewLocationID-1][0]+(playerID-1)%4,(map[NewLocationID-1][1]+(playerID-1)/4));
    printf("o");
    colour(RESET,RESET);
    return EXIT_SUCCESS;
}
int GraphicalPropertyInfo(struct player Player[],int playerCount,int i,int d)
{
    int map[40][2]={{ 10,42},{ 10,39},{ 10,36},{ 10,33},{ 10,30},{ 10,27},{ 10,24},{ 10,23},{ 10,18},{ 10, 15},\
                    { 17, 15},{24, 15},{33, 15},{40, 15},{47, 15},{52, 15},{63, 15},{72, 15},{79, 15},{80, 18},\
                    {79, 21},{79, 24},{79,25},{79,30},{79,33},{79,34},{79,37},{79,42},{79,45},{79,48},\
                    {79,40},{72,40},{65,40},{58,40},{51,40},{44,40},{37,40},{30,40},{23,40},{16,40}};

    int playerID = Player[i].ID;
    int NewLocationID = Player[i].currentLocation;
    int OldLocationID=d;
    goto_XY(map[OldLocationID-1][0]+(playerID-1)%4,(map[OldLocationID-1][1]+(playerID-1)/4));
    printf(" ");
    colour(Player[i].colour1,Player[i].colour2);
    goto_XY((map[NewLocationID-1][0]+(playerID-1)%4),(map[NewLocationID-1][1]+(playerID-1)/4)+1);
    printf("%c",120);
    colour(RESET,RESET);
    return EXIT_SUCCESS;
}

int DisplayMap()
{
    //clearScreen();
    //printf("\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\tTHE MAP OF THE GAME. THE PLAYERS SHALL MOVE CLOCKWISE ON THE BOARD\n");
    //printf("\n");
    printf("\n                ST.CH  ELCT  STATES VRGNIA PNSLVA  ST.JA   COM    TEN    NY    FREE         ");
    printf("\n                 AVE   COMP    AVE    AVE   RAIL    AVE   CHEST   AVE   AVE    PARK         ");
    printf("\n        ____________________________________________________________________________        ");
    printf("\n VISIT |      |      |      |      |      |      |      |      |      |      |      |       ");
    printf("\n  JAIL |      |      |      |      |      |      |      |      |      |      |      |       ");
    printf("\n       |______|______|______|______|______|______|______|______|______|______|______|       ");
    printf("\n CNNCT |      |                                                              |      | KNTCY ");
    printf("\n  AVE  |      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n VERMNT|      |                                                              |      |       ");
    printf("\n  AVE  |      |                                                              |      |CHANCE ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n       |      |                                                              |      |  IND  ");
    printf("\n CHANCE|      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n ORNTL |      |                                                              |      |  ILL  ");
    printf("\n  AVE  |      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n  READ |      |                                                              |      | B&O.  ");
    printf("\n  RAIL |      |                                                              |      | RAIL  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n       |      |                                                              |      |ATLNTC ");
    printf("\n  TAX  |      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n BALTIC|      |                                                              |      | VNTNR ");
    printf("\n  AVE  |      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n  COM  |      |                                                              |      | WATER ");
    printf("\n CHEST |      |                                                              |      | WORKS ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n MEDTRN|      |                                                              |      | MRVN  ");
    printf("\n  AVE  |      |                                                              |      | GRDNS ");
    printf("\n       |______|______________________________________________________________|______|       ");
    printf("\n       |      |      |      |      |      |      |      |      |      |      |      | GO TO ");
    printf("\n START |      |      |      |      |      |      |      |      |      |      |      |  JAIL ");
    printf("\n       |______|______|______|______|______|______|______|______|______|______|______|       ");
    printf("\n                BRDWK LUXURY  PARK  CHANCE  SHORT PNSLVA   COM    NC    PCFC                ");
    printf("\n                       TAX    PLACE         LINE    AVE   CHEST   AVE   AVE                 ");
    getch();
    return 0;
}

void InitialisePlayers(struct player Player[],struct location Location[],int PlayerCount, char (*Names)[30])
{
    for(int i=0;i<PlayerCount;i++)
    {
        Player[i].c=0;
        strcpy(Player[i].name,Names[i]);
        Player[i].ID = i+1;
        Player[i].netWorth = 0;
        Player[i].cashInHand = 1200;
        Player[i].jailTurn = Player[i].position = Player[i].propertyOwnedCount =  0;
        Player[i].isOut = Player[i].isBankrupt = Player[i].isInJail = 0;
        Player[i].currentLocation = 0;
        for(int j=0;j<20;j++)
        {
            for(int k=0;k<20;k++)
            {
                Player[i].propertyOwned[j][k]= " ";
            }
        }
        switch(Player[i].ID)
        {
            case 1 :
                Player[i].colour1=RED;
                Player[i].colour2=0;
                break;
            case 2 :
                Player[i].colour1=GREEN;
                Player[i].colour2=0;
                break;
            case 3 :
                Player[i].colour1=BLUE;
                Player[i].colour2=0;
                break;
            case 4 :
                Player[i].colour1=PURPLE;
                Player[i].colour2=0;
                break;
            case 5 :
                Player[i].colour1=CYAN;
                Player[i].colour2=0;
                break;
            case 6 :
                Player[i].colour1=YELLOW;
                Player[i].colour2=0;
                break;
            case 7 :
                Player[i].colour1=PURPLE;
                Player[i].colour2=INCREASED_INTENSITY;
                break;
            case 8 :
                Player[i].colour1=CYAN;
                Player[i].colour2=INCREASED_INTENSITY;
                break;
        }
      }
}

void PlayerMainMenu(struct player Player[], char (*Names)[30],int i,
                    char locations[][30],int cost[],int ava[],int rent[],int inp)
{
        //clearScreen();
        /*printf("\n\x1B[31;96m                                              888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P\x1B[0m           ");
        printf("\n\x1B[31;96m                                              8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P\x1B[0m      ");
        printf("\n\x1B[31;96m                                              88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P\x1B[0m             ");
        printf("\n\x1B[31;96m                                              888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P\x1B[0m              ");
        printf("\n\x1B[31;96m                                              888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888\x1B[0m              ");
        printf("\n\x1B[31;96m                                              888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888\x1B[0m               ");
        printf("\n\x1B[31;96m                                              888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888\x1B[0m              ");
        printf("\n\x1B[31;96m                                              888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888\x1B[0m         ");
        printf("\n\n\n\n\n");
        DisplayMap();*/
        ClearRightScreen(15);
        gotoxy();
        int Choice;
        colour(Player[i].colour1,Player[i].colour2);
        printf("PLAYER: %s\n",Names[i]);
        colour(RESET,RESET);
        gotoxy();
        printf("CASH IN HAND: $%d \n\n",Player[i].cashInHand);
        gotoxy();
        printf("Properties currently owning:\n");

         for(int a=0;a<Player[i].propertyOwnedCount;a++)
            {
                gotoxy();
                printf("%s\n", locations[Player[i].pos[a]]);
            }
            printf("\n");
            gotoxy();
        printf("MENU FOR:  ");
        colour(Player[i].colour1,Player[i].colour2);
        printf("%s\n\n",Names[i]);
        colour(RESET,RESET);
        gotoxy();
        printf("The system rolls the dice\n");
        int r= PlayerRolls();
        gotoxy();
            printf("The number coming up is: %d\n",r);
            int d= Player[i].currentLocation;
            Player[i].currentLocation= d+r;
            if(!(Player[i].isInJail==1))
            {
                GraphicalMove(Player,d,i);
            }
            gotoxy();
            printf("New Location: %d\n",Player[i].currentLocation);
            gotoxy();
         printf("Choose an option:\n");
         gotoxy();
         printf("  0-GIVE UP\n");
         gotoxy();
         printf("  1-BUY HOUSES AND HOTELS\n");
         gotoxy();
         scanf("%d", &Choice);
        if(Choice == 1)
        {
            gotoxy();
            printf("YOU CHOSE TO BUY HOUSES AND HOTELS\n\n");
            BuyHousesMenu(Player,Player[i].currentLocation-1,i,locations,cost,ava,rent,inp,d);
        }
        else if(Choice ==0)
        {
            gotoxy();
            printf("YOU CHOSE TO GIVE UP\n\n");
           // ThankYou();
        }
        getch();
}

void BuyHousesMenu(struct player Player[],int j,int p,
                   char locations[][30],int cost[],int ava[],int rent[],int inp,int d)
{

        int ChoiceInt;
        gotoxy();
        colour(Player[p].colour1,Player[p].colour2);
        printf("PLAYER: %s\n",Player[p].name);
        colour(RESET,RESET);

        if(strcmp("INCOME TAX",locations[j])==0)
        {
            gotoxy();
            printf("This place is Income Tax\n");
            gotoxy();
            printf("As the name says, you have to pay Income tax!!");
            Player[p].cashInHand= Player[p].cashInHand - rent[j];
            gotoxy();
            printf("Cash in hand now: %d", Player[p].cashInHand);
        }
        else if(Player[p].isInJail==1)
        {
            gotoxy();
            printf("%s is currently in Jail. You miss a turn\n");
            Player[p].isInJail= 0;
        }
        else if(strcmp("FREE PARK",locations[j])==0)
        {
            gotoxy();
            printf("This place is Free Park. This is a place with no property to buy and no rent to pay!\n");
        }
        else if(strcmp("FREE PARKING",locations[j])==0)
        {
            gotoxy();
            printf("This place is Free Park. This is a place with no property to buy and no rent to pay!\n");
        }
        else if(strcmp("LUXURY TAX",locations[j])==0)
        {
            gotoxy();
            printf("This place is Luxury Tax\n");
            gotoxy();
            printf("As the name says, you have to pay Luxury tax!!");
            Player[p].cashInHand= Player[p].cashInHand - rent[j];
            gotoxy();
            printf("Cash in hand now: %d", Player[p].cashInHand);
        }
         else if(strcmp("GO TO JAIL",locations[j])==0)
        {
            gotoxy();
            printf("This place is JAIL\n");
            gotoxy();
            printf("On arriving at Jail, the person misses this and the next turn!!");
            Player[p].isInJail=1;

        }
        else if(strcmp("COMMUNITY CHEST",locations[j])==0)
        {
            gotoxy();
            printf("This place is community chest\n");
            gotoxy();
            printf("On arriving here, you get $200 !!");
            Player[p].cashInHand= Player[p].cashInHand + 200;
            gotoxy();
            printf("Cash in hand now: %d", Player[p].cashInHand);
        }

        else if(strcmp("CHANCE",locations[j])==0)
        {
            gotoxy();
            printf("The place you have reached is Chance...\n");
            gotoxy();
            printf("On arriving at Chance, you get the next property for free!\n");
            if(ava[j+1]==1)
            {
                gotoxy();
                printf("This place has already been bought. You have to pay rent\n");
                gotoxy();
                printf("The rent of the place is %d\n", rent[j+1]);
                Player[p].cashInHand= Player[p].cashInHand- rent[j+1];
                gotoxy();
                printf("Cash in hand now: %d\n", Player[p].cashInHand);
                for(int i=0;i<8;i++)
                {
                    for(int ji=0;ji<8;ji++)
                    {
                        if(Player[i].pos[ji]==j)
                        {
                           Player[i].cashInHand= rent[j+1]+Player[i].cashInHand;
                           gotoxy();
                           printf("The cash of %s has become %d\n", Player[i].name, Player[i].cashInHand);
                        }

                    }
                }
            }
            else
            {

            if(j==inp)
                j=0;
            else
                j++;
                gotoxy();
        printf("The property at this location is %s at $%d\n", locations[j],cost[j]);
                Player[p].pos[Player[p].c] = j;
                Player[p].c = Player[p].c + 1;
                Player[p].propertyOwnedCount=Player[p].propertyOwnedCount+1;
                ava[j]=1;
            }
        }
        else
        {
        gotoxy();
        printf("The property at this location is %s at $%d\n", locations[j],cost[j]);
        gotoxy();
        printf("Do you wish to buy this property?\n");
        gotoxy();
        printf("1. Yes\n");
        gotoxy();
        printf("2. No\n");
        gotoxy();
        printf("Enter your choice 1 or 2\n");
        int c;
        gotoxy();
        scanf("%d", &c);
        if(c==1 && ava[j]==0)
        {
            GraphicalPropertyInfo(Player,inp,p,d);
        }
        if(c==1)
        {
            char person[15];
            if(ava[j]==1)
            {
                gotoxy();
                printf("This place has already been bought. You have to pay rent\n");
                gotoxy();
                printf("The rent of the place is %d\n", rent[j]);
                Player[p].cashInHand= Player[p].cashInHand- rent[j];
                gotoxy();
                printf("Cash in hand now: %d\n", Player[p].cashInHand);
                for(int i=0;i<8;i++)
                {
                    for(int ji=0;ji<8;ji++)
                    {
                        if(Player[i].pos[ji]==j)
                        {
                           Player[i].cashInHand= rent[j]+Player[i].cashInHand;
                           gotoxy();
                           printf("The cash of %s has become %d\n", Player[i].name, Player[i].cashInHand);
                        }

                    }
                }

            }
            else
            {
                 if (Player[p].cashInHand>=cost[j])
            {
                Player[p].pos[Player[p].c] = j;
                Player[p].c = Player[p].c + 1;
                Player[p].propertyOwnedCount=Player[p].propertyOwnedCount+1;
                Player[p].cashInHand= Player[p].cashInHand- cost[j];
                ava[j]=1;

            }
            else
            {
                gotoxy();
                printf("You do not have enough cash to buy the property :( \n");
            }
            gotoxy();
            printf("Cash in hand Now: %d\n",Player[p].cashInHand);
            gotoxy();
            printf("Property Now you own! : %s\n",locations[j]);
            }
            }

            if(c==2)
            {
                gotoxy();
                printf("No transaction done :(");
            }
        }
        gotoxy();
        printf("Press any key to continue...");

   }

int type;
void PlayerResults(struct player Player[],int playerCount,int t,char locations[][30],int cost[])
{
    clearScreen();
    printf("\n");
    printf("\n\x1B[33m                                                 8888888b.  8888888888 .d8888b.  888     888 888    88888888888 .d8888b.\x1B[0m  ");
    printf("\n\x1B[33m                                                 888   Y88b 888       d88P  Y88b 888     888 888        888    d88P  Y88b\x1B[0m ");
    printf("\n\x1B[33m                                                 888    888 888       Y88b.      888     888 888        888    Y88b.\x1B[0m      ");
    printf("\n\x1B[33m                                                 888   d88P 8888888    \"Y888b.   888     888 888        888     \"Y888b.\x1B[0m   ");
    printf("\n\x1B[33m                                                 8888888P\"  888           \"Y88b. 888     888 888        888        \"Y88b.\x1B[0m ");
    printf("\n\x1B[33m                                                 888 T88b   888             \"888 888     888 888        888          \"888\x1B[0m ");
    printf("\n\x1B[33m                                                 888  T88b  888       Y88b  d88P Y88b. .d88P 888        888    Y88b  d88P\x1B[0m ");
    printf("\n\x1B[33m                                                 888   T88b 8888888888 \"Y8888P\"   \"Y88888P\"  88888888   888     \"Y8888P\"\x1B[0m  ");
    printf("\n\n\n\n\n");
    if(type==2)
    {
        printf("The winner shall be decided by the maximum number of property holders:\n");
        int result[10];
    char TempName[30];
    for(int i=0;i<playerCount;i++)
    {
        result[i]=Player[i].c;
    }
    for(int i=0;i<playerCount;i++)
    {
        for(int j=0;j<playerCount-1;j++)
        {
            if(result[j]<result[j+1])
            {
                int temp=result[j];
                result[j]=result[j+1];
                result[j+1]=temp;

                strcpy(TempName  , Player[j+1].name);
                strcpy(Player[j+1].name, Player[j].name);
                strcpy(Player[j].name  , TempName);

            }
        }
    }
    }
    else if(type==1)
    {
        printf("The winner shall be decided by who has the maximum worth of property:\n");
        int result[10];
        char TempName[30];
        for(int i=0;i<playerCount;i++)
        {
            for(int j=0;j<Player[i].c;j++)
            {
                Player[i].netWorth= Player[i].netWorth+ cost[Player[i].pos[j]];
            }
        }
        for(int i=0;i<playerCount;i++)
        {
            printf("%d\n",Player[i].netWorth);
        }
        for(int i=0;i<playerCount;i++)
       {
        for(int j=0;j<playerCount-1;j++)
        {
            if(Player[j].netWorth<Player[j+1].netWorth)
            {
                strcpy(TempName  , Player[j+1].name);
                strcpy(Player[j+1].name, Player[j].name);
                strcpy(Player[j].name  , TempName);

            }
        }
    }
    }
    printf("Winning Positions: \n\n\n");

    for(int i=0;i<playerCount;i++)
    {
        printf("%d. %s\n", i+1, Player[i].name);
    }
    int v,w;
    /*for(v=0;v<t;v++)
    {
        for(w=0;w<playerCount;w++)
        {
            printf("%s\t\t", locations[Player[w].pos[v]]);
        }
        printf("\n");
    }*/
    printf("                       Congratulations to all!!!\n                   ");
    printf("Press any key to continue...\n");
    getch();

}

void Thankyou()
{
    clearScreen();
    printf("\n\n");
    printf("\n\x1B[31;96m                              88888888888 888    888        d8888 888b    888 888    d8P   .d8888b.       8888888888 .d88888b.  8888888b.\x1B[0m  ");
    printf("\n\x1B[31;96m                                  888     888    888       d88888 8888b   888 888   d8P   d88P  Y88b      888       d88P\" \"Y88b 888   Y88b\x1B[0m ");
    printf("\n\x1B[31;96m                                  888     888    888      d88P888 88888b  888 888  d8P    Y88b.           888       888     888 888    888\x1B[0m ");
    printf("\n\x1B[31;96m                                  888     8888888888     d88P 888 888Y88b 888 888d88K      \"Y888b.        8888888   888     888 888   d88P\x1B[0m ");
    printf("\n\x1B[31;96m                                  888     888    888    d88P  888 888 Y88b888 8888888b        \"Y88b.      888       888     888 8888888P\"\x1B[0m  ");
    printf("\n\x1B[31;96m                                  888     888    888   d88P   888 888  Y88888 888  Y88b         \"888      888       888     888 888 T88b\x1B[0m   ");
    printf("\n\x1B[31;96m                                  888     888    888  d8888888888 888   Y8888 888   Y88b  Y88b  d88P      888       Y88b. .d88P 888  T88b\x1B[0m  ");
    printf("\n\x1B[31;96m                                  888     888    888 d88P     888 888    Y888 888    Y88b  \"Y8888P\"       888        \"Y88888P\"  888   T88b\x1B[0m ");
    printf("\n\n\n\n");
    printf("\n\x1B[31;96m                                              8888888b.  888             d8888 Y88b   d88P 8888888 888b    888  .d8888b.  888\x1B[0m              ");
    printf("\n\x1B[31;96m                                              888   Y88b 888            d88888  Y88b d88P    888   8888b   888 d88P  Y88b 888\x1B[0m              ");
    printf("\n\x1B[31;96m                                              888    888 888           d88P888   Y88o88P     888   88888b  888 888    888 888\x1B[0m              ");
    printf("\n\x1B[31;96m                                              888   d88P 888          d88P 888    Y888P      888   888Y88b 888 888        888\x1B[0m              ");
    printf("\n\x1B[31;96m                                              8888888P\"  888         d88P  888     888       888   888 Y88b888 888  88888 888\x1B[0m              ");
    printf("\n\x1B[31;96m                                              888        888        d88P   888     888       888   888  Y88888 888    888 Y8P\x1B[0m              ");
    printf("\n\x1B[31;96m                                              888        888       d8888888888     888       888   888   Y8888 Y88b  d88P  \"\x1B[0m               ");
    printf("\n\x1B[31;96m                                              888        88888888 d88P     888     888     8888888 888    Y888  \"Y8888P88 888\x1B[0m              ");
    printf("\n\n\n\n");
    printf("Press any key to continue...");
    getch();
}

int SelectGamemode()
{
        int choice;
        clearScreen();
        printf("\n\x1B[35m     .d8888b.  8888888888 888      8888888888 .d8888b. 88888888888       .d8888b.         d8888 888b     d888 8888888888 888b     d888  .d88888b.  8888888b.  8888888888\x1B[0m ");
        printf("\n\x1B[35m    d88P  Y88b 888        888      888       d88P  Y88b    888          d88P  Y88b       d88888 8888b   d8888 888        8888b   d8888 d88P\" \"Y88b 888  \"Y88b 888\x1B[0m        ");
        printf("\n\x1B[35m    Y88b.      888        888      888       888    888    888          888    888      d88P888 88888b.d88888 888        88888b.d88888 888     888 888    888 888\x1B[0m        ");
        printf("\n\x1B[35m     \"Y888b.   8888888    888      8888888   888           888          888            d88P 888 888Y88888P888 8888888    888Y88888P888 888     888 888    888 8888888\x1B[0m    ");
        printf("\n\x1B[35m        \"Y88b. 888        888      888       888           888          888  88888    d88P  888 888 Y888P 888 888        888 Y888P 888 888     888 888    888 888\x1B[0m        ");
        printf("\n\x1B[35m          \"888 888        888      888       888    888    888          888    888   d88P   888 888  Y8P  888 888        888  Y8P  888 888     888 888    888 888\x1B[0m        ");
        printf("\n\x1B[35m    Y88b  d88P 888        888      888       Y88b  d88P    888          Y88b  d88P  d8888888888 888   \"   888 888        888   \"   888 Y88b. .d88P 888  .d88P 888\x1B[0m        ");
        printf("\n\x1B[35m     \"Y8888P\"  8888888888 88888888 8888888888 \"Y8888P\"     888           \"Y8888P88 d88P     888 888       888 8888888888 888       888  \"Y88888P\"  8888888P\"  8888888888\x1B[0m ");
        printf("\n\n\n\n\n");
        printf("\n\tChoose a game mode:");
        printf("\n\t  1-Net Worth : Game ends after certain number of turns and the person with properties of max worth wins");
        printf("\n\t  2-Turns     : Game ends after certain number of turns/rounds are over and the person with maximum ");
        printf("properties wins");
        printf("\n\t  3-Exit\n\n");
        scanf("%d", &choice);
        if (choice == 1)
            {
                type=1;
            }
        else if (choice == 2)
            {
                type=2;
            }
        else if (choice == 3)
            {
                printf("Game exit");
                exit(0);
            }
        else
        {
            printf("\n\n\tYou entered an invalid choice \"%c\". Enter any key to try again.",choice);
            getch();
        }
}

int j=0;
int main()
{
    int choice,inp;
    char Names[8][30];
    intro();
    clearScreen();
    Menu();
printf("\n\x1B[31;33m                                              888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P\x1B[0m           ");
        printf("\n\x1B[31;33m                                              8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P\x1B[0m      ");
        printf("\n\x1B[31;33m                                              88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P\x1B[0m             ");
        printf("\n\x1B[31;33m                                              888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P\x1B[0m              ");
        printf("\n\x1B[31;33m                                              888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888\x1B[0m              ");
        printf("\n\x1B[31;33m                                              888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888\x1B[0m               ");
        printf("\n\x1B[31;33m                                              888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888\x1B[0m              ");
        printf("\n\x1B[31;33m                                              888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888\x1B[0m         ");
        printf("\n\n\n\n\n");
        int flag=1;
        while(flag==1)
        {
            printf("\n\tEnter the number of players: ");
            scanf("%d",&inp);
            if(inp<2||inp>8)
            {
                printf("The number of players cannot be less than 2 and greater than 8\n");
                printf("Enter again\n");
                flag=1;
            }
            else
            {
                flag=0;
            }
        }
ReadPlayers(inp,Names);
SetPlayerOrder(inp,Names);
SelectGamemode();
int PlayerCount;
struct location Location[30];
struct player Player[9];
struct player *CurrentPlayer;
InitialisePlayers(Player,Location,inp, Names);
char locations[][30]= {"MEDITTERRANEAN AVENUE","COMMUNITY CHEST","BALTIC AVENUE","INCOME TAX","READING RAILROAD",
                       "ORIENTAL AVENUE","CHANCE","VERMONT AVENUE","CONNECTICUT AVENUE",
                       "GO TO JAIL","ST. CHARLES PLACE","ELECTRIC COMPANY","STATES AVENUE",
                       "VIRGNIA AVENUE","PENNSYLVANIA RAILROAD","ST. JAMES PLACE",
                       "TENNESSEE AVENUE","NEW YORK AVENUE","FREE PARKING","KENTUCKY AVENUE",
                       "CHANCE","INDIANA AVENUE","ILLINOIS AVENUE","B. & O. RAILROAD",
                       "ATLANTIC AVENUE","VENTNOR AVENUE","WATER WORKS","MARVIN GARDENS","GO TO JAIL",
                       "PACIFIC AVENUE","NORTH CAROLINA AVENUE","COMMUNITY CHEST", "PENNSYLVANIA AVENUE","SHORT LINE",
                       "CHANCE","PARK PLACE","LUXURY TAX","	BOARDWALK"
                       };
    int cost[40]={60,0,60,0,200,100,0,100,120,0,140,150,140,
                  150,140,160,200,180,0,180,200,0,220,0,
                  220,240,200,260,260,150,280,0,300,300,
                  0,320,200,0,350,0,400};
    int ava[40]={0,0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,0,
                 };
    int rent[40]={20,0,40,200,25,60,0,60,80,0,
                  50,25,10,12,25,14,0,14,16,0,
                  18,0,18,20,25,22,22,25,24,0,
                  26,26,0,28,25,0,35,100,35};
int t;
clearScreen();
printf("\n\x1B[31;96m                                              888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P\x1B[0m           ");
        printf("\n\x1B[31;96m                                              8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P\x1B[0m      ");
        printf("\n\x1B[31;96m                                              88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P\x1B[0m             ");
        printf("\n\x1B[31;96m                                              888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P\x1B[0m              ");
        printf("\n\x1B[31;96m                                              888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888\x1B[0m              ");
        printf("\n\x1B[31;96m                                              888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888\x1B[0m               ");
        printf("\n\x1B[31;96m                                              888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888\x1B[0m              ");
        printf("\n\x1B[31;96m                                              888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888\x1B[0m         ");
        printf("\n\n");
DisplayMap();
printf("%c[%d;%df Enter the number of turns you wish to play: ",0x1B,15,100);
scanf("%d",&t);
//clearScreen();
for(i=1;i<=t;i++)
{
     j=0;
    for(k=1;k<=inp;k++)
    {
        PlayerMainMenu(Player,Names,j,locations,cost,ava,rent,inp);
        j++;
        //clearScreen();
        y=15;

    }
}
PlayerResults(Player,inp,t,locations,cost);
Thankyou();
return 0;
}