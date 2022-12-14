/////////////////////////////////////////////////////
// 
//  Return middle element of link list
// 
////////////////////////////////////////////////////


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


int MiddleElement(PNODE Head)
{
    int icnt = 0;
    int i = 0;
    PNODE temp = Head;

    while (Head != NULL)
    {
        icnt++;
        Head = Head->next;
    }

    if (icnt % 2 != 0)
    {
        for (i = 1; i <= icnt / 2; i++)
        {
            temp = temp->next;
        }
    }
    else
    {
        for (i = 1; i < icnt / 2; i++)
        {
            temp = temp->next;
        }

    }

    return (temp->data);
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
    InsertFirst(&First,10);

    Display(First);

    iRet = MiddleElement(First);

    printf("Middle element is %d ", iRet);

    return 0;
}
