#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "champion.h"

int main(int argc, char *argv[])
{
    srand(time(0)); // Random function for creating champions
    // Variables
    int numberPlays;
    int roundNumber = 0;

    if (argc != 2) // Checks if their are enough values
    {
        printf("ERROR: Missing value.\n");
        return 1;
    }
    numberPlays = atoi(argv[1]); // Convertsstring to int
    if (numberPlays <= 0) // Checks to see if the user inputed a non-positive number
    {
        printf("ERROR: Value is 0 or less.\n");
        return 1;
    }

    // Builds champions list
    Champion* Player1 = buildChampionList(numberPlays);
    Champion* Player2 = buildChampionList(numberPlays);
    printf("\n============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");


    while( (Player1 != NULL) && (Player2 != NULL) ) // Infinite loop until one player has no cards remaining
    {
        Champion* newChamp = NULL;
        roundNumber++;
        printf("\n----- Round %d -----\n", roundNumber);
        printf("Player 1: ");
        printChampionList(Player1);
        printf("Player 2: ");
        printChampionList(Player2);

        // Prints out which role each player has
        if (Player1->role == MAGE)
        {
            printf("Player 1 is a MAGE and ");
        }
        else if (Player1->role == FIGHTER)
        {
            printf("Player 1 is a FIGHTER and ");
        }
        else if (Player1->role == SUPPORT)
        {
            printf("Player 1 is a SUPPORT and ");
        }
        else if (Player1->role == TANK)
        {
            printf("Player 1 is a TANK and ");
        }

        if (Player2->role == MAGE)
        {
            printf("Player 2 is a MAGE\n");
        }
        else if (Player2->role == FIGHTER)
        {
            printf("Player 2 is a FIGHTER\n");
        }
        else if (Player2->role == SUPPORT)
        {
            printf("Player 2 is a SUPPORT\n");
        }
        else if (Player2->role == TANK)
        {
            printf("Player 2 is a TANK\n");
        }

        // All outcomes in a duel
        if (Player1->role == MAGE)
        {
            if (Player2->role == MAGE)
            {
                if (Player1->level > Player2->level)
                {
                    printf("Player 1 (MAGE) wins and gains another champion.\n");
                    printf("Player 2 (MAGE) loses one champion.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player1 = addChampion(Player1, newChamp);
                }
                else if (Player2->level > Player1->level)
                {
                    printf("Player 1 (MAGE) loses one champion.\n");
                    printf("Player 2 (MAGE) wins and gains another champion.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player2 = addChampion(Player2, newChamp);
                }
                else
                {
                    printf("Nothing happens - no penalty or reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                }
            }
            else if (Player2->role == FIGHTER)
            {
                if (Player1->level > Player2->level) // Mage wins
                {
                    printf("Player 1 (MAGE) wins and gains another champion.\n");
                    printf("Player 2 (FIGHTER) loses with no penalty.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player1 = addChampion(Player1, newChamp);
                }
                else if (Player2->level > Player1->level) // Fighter wins
                {
                    printf("Player 1 (MAGE) loses one champion.\n");
                    printf("Player 2 (FIGHTER) wins with no reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    Player1 = removeChampion(Player1);
                }
                else
                {
                    printf("Nothing happens - no penalty or reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                }

            }
            else if (Player2->role == SUPPORT)
            {
                if (Player1->level > Player2->level) // Mage wins
                {
                    printf("Player 1 (MAGE) wins and gains another champion.\n");
                    printf("Player 2 (SUPPORT) loses 2 champions.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player1 = addChampion(Player1, newChamp);
                    Player2 = removeChampion(Player2);
                    Player2 = removeChampion(Player2);
                }
                else if (Player2->level > Player1->level) // Support wins
                {
                    printf("Player 1 (MAGE) loses one champion.\n");
                    printf("Player 2 (SUPPORT) wins and gains two champions.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player2 = addChampion(Player2, newChamp);
                    newChamp = createChampion();
                    Player2 = addChampion(Player2, newChamp);
                    Player1 = removeChampion(Player1);
                }
                else
                {
                    printf("Nothing happens - no penalty or reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                }
            }
            else if (Player2->role == TANK)
            {
                printf("Player 1 (MAGE) wins and gains one champion.\n");
                printf("Player 1 (TANK) loses one champion.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
                Player2 = removeChampion(Player2);
                newChamp = createChampion();
                Player2 = addChampion(Player2, newChamp);
            }
        
        }


        else if (Player1->role == FIGHTER)
        {
            if (Player2->role == MAGE)
            {
                if (Player2->level > Player1->level) // Mage wins
                {
                printf("Player 1 (FIGHTER) loses with no penalty.\n");
                printf("Player 2 (MAGE) wins and gains one champion.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player2 = addChampion(Player2, newChamp);
                }
                else if (Player1->level > Player2->level) // Fighter wins
                {
                    printf("Player 1 (FIGHTER) wins with no reward.\n");
                    printf("Player 2 (MAGE) loses one champion.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    Player2 = removeChampion(Player2);
                }
                else
                {
                    printf("Nothing happens - no penalty or reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                }

            }
            else if (Player2->role == FIGHTER)
            {
                printf("Both players gain a champion.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
                newChamp = createChampion();
                Player1 = addChampion(Player1, newChamp);
                newChamp = createChampion();
                Player2 = addChampion(Player2, newChamp);
            }
            else if (Player2->role == SUPPORT)
            {
                if (Player1->level > Player2 ->level) // Fighter wins
                {
                    printf("Player 1 (FIGHTER) wins with no reward.\n");
                    printf("Player 2 (SUPPORT) loses one champion.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    Player2 = removeChampion(Player2);
                }
                else if (Player2->level > Player1->level)
                {
                    printf("Player 1 (FIGHTER) loses with no penalty.\n");
                    printf("Player 2 (SUPPORT) wins and gains one champion.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player2 = addChampion(Player2, newChamp);
                }
                else
                {
                    printf("Nothing happens - no penalty or reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                }
            }
            else if (Player2->role == TANK)
            {
                printf("Player 1 (FIGHTER) wins and gains one champion.\n");
                printf("Player 2 (TANK) loses with no penalty.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
                newChamp = createChampion();
                Player1 = addChampion(Player1, newChamp);
            }
        }


        else if (Player1->role == SUPPORT)
        {
            if (Player2->role == MAGE)
            {
                if (Player1->level > Player2->level) // Support wins (Player1)
                {
                    printf("Player 1 (SUPPORT) wins and gains two champions.\n");
                    printf("Player 2 (MAGE) loses one champion.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player1 = addChampion(Player1, newChamp);
                    newChamp = createChampion();
                    Player1 = addChampion(Player1, newChamp);
                    Player2 = removeChampion(Player2);
                }
                else if (Player2->level > Player1->level) // Mage wins (Player2)
                {
                    printf("Player 1 (SUPPORT) loses two champions.\n");
                    printf("Player 2 (MAGE) wins and gains one champion.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player2 = addChampion(Player2, newChamp);
                    Player1 = removeChampion(Player1);
                    Player1 = removeChampion(Player1);
                }
                else
                {
                    printf("Nothing happens - no penalty or reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                }
            }
            else if (Player2->role == FIGHTER)
            {
                if (Player1->level > Player2->level) // Support wins (Player1)
                {
                    printf("Player 1 (SUPPORT) wins and gains one champion.\n");
                    printf("Player 2 (FIGHTER) loses but with no penalty\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    newChamp = createChampion();
                    Player1 = addChampion(Player1, newChamp);
                }
                else if (Player2->level > Player1->level)
                {
                    printf("Player 1 (SUPPORT) loses one champion.\n");
                    printf("Player 2 (FIGHTER) wins with no reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                    Player1 = removeChampion(Player1);
                }
                else
                {
                    printf("Nothing happens - no penalty or reward.\n");
                    Player1 = removeChampion(Player1);
                    Player2 = removeChampion(Player2);
                }
            }
            else if (Player2->role == SUPPORT)
            {
                printf("Both players lose one champion.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
            }
            else if (Player2->role == TANK)
            {
                printf("Player 1 (SUPPORT) loses but with no penalty.\n");
                printf("Player 2 (TANK) wins and gains one champion.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
                newChamp = createChampion();
                Player2 = addChampion(Player2, newChamp);
            }
        }


        else if (Player1->role == TANK)
        {
            if (Player2->role == MAGE)
            {
                printf("Player 1 (TANK) loses one champion.\n");
                printf("Player 2 (MAGE) wins and gains one champion.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
                Player1 = removeChampion(Player1);
                newChamp = createChampion();
                Player2 = addChampion(Player2, newChamp);
            }
            else if (Player2->role == FIGHTER)
            {
                printf("Player 1 (TANK) loses with no penalty.\n");
                printf("Player 2 (FIGHTER) wins and gains one champion.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
                newChamp = createChampion();
                Player2 = addChampion(Player2, newChamp);
            }
            else if (Player2->role == SUPPORT)
            {
                printf("Player 1 (TANK) wins and gains one champion.\n");
                printf("Player 2 (SUPPORT) loses with no penalty.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
                newChamp = createChampion();
                Player1 = addChampion(Player1, newChamp);
            }
            else if (Player2->role == TANK)
            {
                printf("Nothing happens - no penalty or reward.\n");
                Player1 = removeChampion(Player1);
                Player2 = removeChampion(Player2);
            }
        }

    }
    // Game over results
    printf("\n============ GAME OVER  =============\n\n");
    printf("Player 1 ending champion list: ");
    printChampionList(Player1);
    printf("Player 2 ending champion list: ");
    printChampionList(Player2);

    if (Player1 == NULL && Player2 == NULL)
    {
        printf("\nTIE -- both players ran out of champions.\n");
    }
    else if (Player1 == NULL)
    {
        printf("\nPlayer 1 has ran out of champions. Player 2 wins.\n");
    }
    else if (Player2 == NULL)
    {
       printf("\nPlayer 2 has ran out of champions. Player 1 wins.\n");
    }

    destroyChampionList(Player1);
    destroyChampionList(Player2);
    return 0;

    }