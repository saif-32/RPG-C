#ifndef CHAMPIONS_H
#define CHAMPIONS_H


typedef enum ChampionRole
{ MAGE, FIGHTER, SUPPORT, TANK } ChampionRole;
typedef struct Champion
{
    ChampionRole role;
    int level;
    struct Champion* next;
} Champion;

/*
    Function: createChampion
    Dynamically allocates a Champion struct object and returns it.
    Returns: Dynamically allocated Champion struct object.
*/
Champion* createChampion();

/*
    Function: addChampion
    Adds a new champion struct object to linked list
        Champion* head: head of linked list
        Champion* c: New champion struct object being added
    Returns: head of linked list
*/
Champion* addChampion(Champion *head, Champion *c);

/*
    Function: buildChampionList
    Builds list of champions using linked list
        int n: determines how many champions are created.
    Returns: head of linked list
*/
Champion* buildChampionList(int n);

/*
    Function: printChampionList
    Prints out champion list
        Champion* head: head of linked list.
    Returns: Nothing
*/
void printChampionList(Champion *head); 

/*
    Function: removeChampion
    Removes and deallocates first node in linked list that head is poinitng at
        Champion* head: head of linked list.
    Returns: new head of linked list.
*/
Champion* removeChampion(Champion *head);

/*
    Function: destroyChampionList
    Destructor for a linked list that head is pointing at
        Champion* head: head of linked list.
    Returns: NULL
*/
Champion* destroyChampionList(Champion *head);

#endif