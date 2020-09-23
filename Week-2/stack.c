<<<<<<< HEAD
#include<stdio.h>
void push();
void pop();
void display();
int stack[100],choice,n,top,x,i;

int main()
{
    top=-1;
    printf("\nEnter the size of stack(max=100):");
    scanf("%d",&n);
    printf("\n1.push\n2.pop\n3.display\n4.exit");
    do
    {
        printf("\n Enter ID of the operation to be performed:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\nexit");
                break;
            }
            default:
            {
                printf ("\nEnter a Valid Choice");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\nStack Overflow");
        
    }
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\nStack underflow");
    }
    else
    {
        printf("\n\t The popped element is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in the stack: \n");
        for(i=top; i>=0; i--)
            printf("\n> %d",stack[i]);
    }
    else
    {
        printf("\nStack is empty");
    }
   
=======
#include<stdio.h>
void push();
void pop();
void display();
int stack[100],choice,n,top,x,i;

int main()
{
    top=-1;
    printf("\nEnter the size of stack(max=100):");
    scanf("%d",&n);
    printf("\n1.push\n2.pop\n3.display\n4.exit");
    do
    {
        printf("\n Enter ID of the operation to be performed:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\nexit");
                break;
            }
            default:
            {
                printf ("\nEnter a Valid Choice");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\nStack Overflow");
        
    }
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\nStack underflow");
    }
    else
    {
        printf("\n\t The popped element is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in the stack: \n");
        for(i=top; i>=0; i--)
            printf("\n> %d",stack[i]);
    }
    else
    {
        printf("\nStack is empty");
    }
   
>>>>>>> a575d514bd5725ce7152decb93459989149d9afb
}