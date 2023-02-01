// นายประพันธ์ แข็งขัน  65543206022-7 sec 2
// https://youtu.be/_WejweZLczM
#include <stdio.h>

struct Konggaret
{
    int Num;
    struct Konggaret *next;
};

struct Konggaret *AddNode(struct Konggaret **walk, int newwe);
void ShowAll(struct Konggaret *walk);
void UpdateNode(struct Konggaret **walk, int choose, int newwe);
void ShowBack( struct Konggaret **walk);
void SwapNode (struct Konggaret **walk,int Num1,int Num2);

int main()
{
    struct Konggaret *start;
    start = NULL;
    AddNode(&start, 50);
    AddNode(&start, 60);
    AddNode(&start, 70);
    AddNode(&start, 80);
    ShowAll(start);
    UpdateNode(&start, 60, 69);
    ShowAll(start);
    ShowBack(&start);
    ShowAll(start);
    SwapNode(&start, 69, 80);
    ShowAll(start);
    return 0;
}


struct Konggaret *AddNode(struct Konggaret **walk, int newwe)
{
    while (*walk != NULL)
    {
        walk = &(*walk)->next;
    }
    *walk = new struct Konggaret;
    (*walk)->Num = newwe;
    (*walk)->next = NULL;
    return *walk;
}


void ShowAll(struct Konggaret *walk)
{
    while (walk != NULL)
    {
        printf("%d ", walk->Num);
        walk = walk->next;
    }
    printf("\n");
}

void UpdateNode(struct Konggaret **walk, int choose, int newwe)
{
    while ((*walk)->Num != choose)
    {
        walk = &(*walk)->next;
    }
    (*walk)->Num = newwe;
}

void ShowBack(struct Konggaret **walk)
{
    struct Konggaret* PKron = NULL;
    struct Konggaret* current = *walk;
    struct Konggaret* next = NULL;
    while (current != NULL) {   
        next = current->next;
        current->next = PKron;
        PKron = current;
        current = next;
    }
    *walk = PKron;
}

void SwapNode(struct Konggaret**walk, int x, int y)
{
    
    
    struct Konggaret *prevX = NULL, *currX = *walk;
    while (currX && currX->Num != x) {
        prevX = currX;
        currX = currX->next;
    }
    struct Konggaret *prevY = NULL, *currY = *walk;
    while (currY && currY->Num != y) {
        prevY = currY;
        currY = currY->next;
    }
    if (prevX != NULL)
        prevX->next = currY;
    else 
        *walk = currY;
    if (prevY != NULL)
        prevY->next = currX;
    else 
        *walk = currX; 
    struct Konggaret* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
