#include<stdio.h>
int stack[50],top=-1,value,n;
void push()
{
if(top==n-1)
{
printf("stack overflow");
return;
}
else{
    printf("enter elements:");
for(int i=0;i<n;i++)
{

scanf("%d",&value);


    top=top+1;

    stack[top]=value;
}}
}
int pop()
{

    if(stack<0)
    {
     printf("stack underflow");

    }
    else{printf("elements are:\n");
    for(int i=0;i<5;i++)
    {


        value=stack[top];
        top=top-1;
        printf("%d\n",value);

    }
}
}
void main()
{
printf("enter the size of stack");
scanf("%d",&n);
push();
pop();
}

