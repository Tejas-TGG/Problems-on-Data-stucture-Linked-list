///////////////////////////////////////////////////////////////
// 
// Accept number from user and return frequency of that number
// calculate how many times number is occured in linked list
// 
///////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (*Head != NULL)
    {
        newn->next = *Head;
    }
    *Head = newn;
}

void Display(PNODE Head)
{
    printf("Elements of linked list are : \n");
    while (Head != NULL)
    {
        printf("|%d|-> ", Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}

int Frequency(PNODE Head, int no)
{
    int icnt = 0;
    while (Head != NULL)
    {
        if ((Head->data) == no)
        {
            icnt++;
        }
        Head = Head->next;
    }

    return icnt;
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;
    int iNo = 0;

    InsertFirst(&First, 10);
    InsertFirst(&First, 40);
    InsertFirst(&First, 30);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    Display(First);

    printf("Enter number :\n");
    scanf("%d", &iNo);

    iRet = Frequency(First, iNo);
    printf("Frequency is : %d\n", iRet);
    return 0;
}
