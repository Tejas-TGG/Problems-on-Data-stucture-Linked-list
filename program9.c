////////////////////////////////////////////////////////////
// 
// Accept link list from user and also number from user and 
//  return position at last occurance
// 
///////////////////////////////////////////////////////////



#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*Head != NULL)
    {
        newn->next = *Head;
    }
    *Head = newn;
}

void Display(PNODE Head)
{
    printf("Elements of linked list are : \n");
    while(Head != NULL)
    {
        printf("|%d|-> ",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}



int LastOccurance(PNODE  Head , int no)
{
    int icnt = 1;
    int ipos = 0;
    
    while(Head != NULL)
    {
       if(Head->data==no)
       {
          ipos = icnt ;
       }

       icnt++;

       Head=Head->next;
    }
    
   
    return ipos ;
    
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;
    int iNo=0;

    InsertFirst(&First,10);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);

    printf("Enter number :\n");
    scanf("%d",&iNo);

    iRet = LastOccurance(First, iNo );
    
  
    printf("Last occurance is at %d ",iRet );
    
    
    return 0;
}
