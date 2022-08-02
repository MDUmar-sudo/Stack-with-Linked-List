#include <stdio.h>
#include <stdlib.h>

typedef struct Node stack;

struct Node
{
    int data;
    struct Node *next;
};

//head position is taken as top of the stack so that pop() & push () operations can be done in constant time O(1)
stack *top=NULL;

int main()
{

    int choice;
    printf("------------------------------\n");
    printf("STACKING USING LINKED LIST\n");   //here we are using heap memory
    printf("------------------------------\n");

    do{
    printf("____________________________");
    printf("\nCHOOSE A STACK OPERATION\n\n(1)PUSH\n(2)POP\n(3)DISPLAY\n(4)PEEK\n(5)EXIT\n");
    printf("____________________________");

    printf("\nENTER YOUR CHOICE :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:  push();
             break;

    case 2: pop();
            break;

    case 3: display();
             break;

    case 4: peek();
             break;

    case 5: printf("\nEXIT\n");
            break;

    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");

    }
  }while(choice!=5);

  getch();
  return 0;

}

//return stack status: Empty or Not

int isEmpty(){
    if(top==NULL) return 1;

    return 0;
}

//return stack status: Full or Not

int isFull(){
    stack *n = (stack *)malloc(sizeof(stack));
    if(n==NULL) return 1;

    return 0;
}

//append an element at the top of the stack

void push()
{
    if(isFull()){
        printf("\nSTACK OVERFLOW\n");
    }
    else{
      int x;
      printf("\nENTER AN ELEMENT TO PUSH IN STACK: ");
      scanf("%d",&x);
      stack *temp;
      temp = (stack *)malloc(sizeof(stack));
      temp->data =x;
      temp->next = top;
      top = temp;

      printf("\nPUSHED ELEMENT IS THE STACK :%d\n", top->data);
    }




}

//deletes top element from the stack

void pop()
{
    stack *temp;
    temp = top;

    if(isEmpty())
    {
        printf("\nSTACK UNDERFLOW\n");
    }
    else
    {
       printf("\nPOPPED ELEMENT FROM THE STACK  :%d\n",top->data);
       top = top->next;
       free(temp);
    }
}

//display all the element in the stack

void display()
{
    stack *temp;
    temp = top;

    if(isEmpty())
   {
     printf("\nSTACK UNDERFLOW\n");

   }


    else
    {
        printf("\nELEMENTS IN THE STACK :\n");
        while(temp!=NULL)
        {
            printf("%d \n",temp->data);
            temp = temp->next;
        }
    }

}

//peek() and top() function are same both returns top most element of the stack

void peek()
{
    if(isEmpty())
    {
        printf("\nSTACK UNDERFLOW\n");
    }

    else
    {
        printf("TOP ELEMENT OF THE STACK :%d\n",top->data);
    }
}

