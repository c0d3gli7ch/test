#include <stdio.h>
#include <string.h>

#define MAX 100

int top=-1;
int item;

char stack_string[MAX];
void pushChar(char item);

char popChar(void);

int isEmpty(void);

int isFull(void);

void pushChar(char item)
{

    if(isFull())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    

    top=top+1;
    stack_string[top]=item;
}
 

 char popChar()
{

    if(isEmpty())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }


    item = stack_string[top];
    top=top-1;
    return item;
}
 

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}