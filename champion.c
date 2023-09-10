/*
    Function: createChampion
    Dynamically allocates a Champion struct object and returns it.
    Returns: Dynamically allocated Champion struct object.
*/

/*
    Function: addChampion
    Adds a new champion struct object to linked list
        Champion* head: head of linked list
        Champion* c: New champion struct object being added
    Returns: head of linked list
*/

/*
    Function: buildChampionList
    Builds list of champions using linked list
        int n: determines how many champions are created.
    Returns: head of linked list
*/

/*
    Function: printChampionList
    Prints out champion list
        Champion* head: head of linked list.
    Returns: Nothing
*/

/*
    Function: removeChampion
    Removes and deallocates first node in linked list that head is poinitng at
        Champion* head: head of linked list.
    Returns: new head of linked list.
*/

/*
    Function: destroyChampionList
    Destructor for a linked list that head is pointing at
        Champion* head: head of linked list.
    Returns: NULL
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "champion.h"

Champion* createChampion()
{
    Champion* new = (Champion*)malloc(sizeof(Champion));; // Dynamically allocates champion
    int randnum = 0;
    int randlevel = 0;
    randnum = (rand() % 4) + 1; // 25% chance of each role
    if (randnum == 1)
    {
        randlevel = (rand()%(8-5 + 1) + 5); // Assigns level
        new->role = MAGE;
        new->level = randlevel;
        new->next = NULL;
        return new;
    }
    else if (randnum == 2)
    {
        randlevel = (rand()%(4-1 + 1) + 1);
        new->role = FIGHTER;
        new->level = randlevel;
        new->next = NULL;
        return new;
    }
    else if (randnum == 3)
    {
        randlevel = (rand()%(6-3 + 1) + 3);
        new->role = SUPPORT;
        new->level = randlevel;
        new->next = NULL;
        return new;
    }
    else
    {
        randlevel = (rand()%(8-1 + 1) + 1);
        new->role = TANK;
        new->level = randlevel;
        new->next = NULL;
        return new;
    }
    return new;
}

Champion* addChampion(Champion *head, Champion *c)
{
    Champion* temp = head;
    Champion* previous = NULL;
    if (head == NULL) // If there is nothing in the list
    {
        return c;
    }
    while(temp != NULL) // Loop through list
    {

        if (temp->level < c->level) // Move it in front
        {
            if (previous == NULL) // If there is nothing before
            {
                head = c;
                c->next = temp;
                return head;
            }
            else // If there is a node before
            {
                previous->next = c;
                c->next = temp;
            }
            return head;
        }

        if (temp->next == NULL) // If it is the end of the list
        {
            temp->next = c;
            return head;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;
}


Champion* buildChampionList(int n)
{
    Champion* newNode = NULL;
    Champion* head = NULL;
    for (int z = 0; z < n; z++) // Create champions and add based on n
    {
        newNode = createChampion();
        head = addChampion(head, newNode);
    }
    return head;
}

void printChampionList(Champion *head)
{
    Champion* temp = head;
    while (temp != NULL)
    {
        if (temp->role == MAGE)
        {
            printf("M%d ", temp->level);
        }
        else if (temp->role == FIGHTER)
        {
            printf("F%d ", temp->level);
        }
        else if (temp->role == SUPPORT)
        {
            printf("S%d ", temp->level);
        }
        else if (temp->role == TANK)
        {
            printf("T%d ", temp->level);
        }
        temp = temp->next;
    }
    printf("\n");
}

Champion* removeChampion(Champion *head)
{
        if (head == NULL) // If there is nothing in the list
        {
            return NULL;
        }
        Champion* temp = head;
        head = head->next;
        free(temp);
        return head;
}

Champion* destroyChampionList(Champion *head)
{
    while (head!= NULL) // Loops through list destroying each node
    {
        Champion* temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}