/////////////////////////////////////////////////////////////////////////////////////////
// 
// Accept link list from user and display nodes of perfect element  in linked list
// 
// 
/////////////////////////////////////////////////////////////////////////////////////////

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

void DisplaysumFactors(PNODE Head)
{
    int iNo = 0;
    int iSum = 0;
    int i = 0;

    while (Head != NULL)
    {
        iSum = 0;

        for (i = 1; i <= (Head->data) / 2; i++)
        {
            if ((Head->data) % i == 0)
            {
                iSum = iSum + i;
            }
        }

        if (iSum == Head->data)
        {
            printf("%d is perfect number in node\n ", Head->data);
        }
        Head = Head->next;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;
    int iNo = 0;

    InsertFirst(&First, 28);
    InsertFirst(&First, 6);
    InsertFirst(&First, 496);
    InsertFirst(&First, 24);
    InsertFirst(&First, 22);

    Display(First);

    DisplaysumFactors(First);

    return 0;
}
