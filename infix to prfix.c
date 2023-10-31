#include<stdio.h>
#include<string.h>
char infix[100];
char postfix[100];
char stack[100];
int top=-1;
char symbol ,next;
void intopost(char*s)
{

    int i,j=0;
    for(i=0;i<strlen(s);i++)
    {
        symbol=infix[i];

        switch(symbol)
        {
    case '(':
        push(symbol);
    case')':
        while(next=pop()!='(')
        postfix[j++]=next;
      break;
    case'+':
    case'-':
    case'*':
    case'/':
    case'^':
        default:
        while(!isempty()&&precendence(stack[top])>=precendence(symbol))
{

           postfix[j++]=pop();
        push(symbol);
        break;
        postfix[j++]=symbol;

        }
    }
}
}

while(!isempty())
{

    postfix[j++]=pop();
    postfix[j]='\0';

}
int  precendence(char symbol)
{
    switch(symbol)
    {
 case'^':
 return 2;
 case'/':
 case'*':
    return 1;
 case'+':
 case'-':
    return 0;


    }
}
void print()
{
int i=0;
printf("The equivalent postfix");
while(postfix[i])
{

    printf("%c",postfix[i++]);
}

}
void push(char c)
{
if(top==100)
{
 printf("overflow");

}
    else{
        top++;
        stack[top]=c;
    }
}
void pop()
{

    if(top==-1)
    {
        printf("underflow");

    }
    else{
        char c=stack[top];
        top--;
        return c;

    }
}
int isempty()
{

    if(top==-1)
        return 1;
    else
        return 0;

}
reversestring(infix)

intopost(char s)

reversestring(postfix)
{
printf("the equivalent prefix is %s\n,"postfix);
return 0;
}
void reversestring(char*str)
{

    int length=strlen(str)
    int i,j;
    for(i=0;i<strlen;i<j;i++)
    {
       char temp=str[i];
       str[i]=str[j];
       str[j]=temp;

    }

}
int main
{
    {
 printf("enter the infix");
 gets(infix);
}

 intopost(char s);
 print();
 return 0;


}

