/* SLIP-3
Q.1)a random array of n integers (accept the value of n from user) in 
ascending order by using insertion sort algorithm. 

#include<stdio.h>
void insertion(int a[],int n)
{
   int pass,i,t,key;
   for(pass=1;pass<n;pass++)
   {
     key=a[pass];
     for(i=pass-1;i>=0 && a[i]>key;i--)
      {
        t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
      }
   }
   printf("Sorted Numbers By Insertion sort::");
   for(i=0;i<n;i++)
   {
     printf("%d\t",a[i]);
   }
}
int main()
{
  int i,a[100],n;
  printf("Enter Limit:");
  scanf("%d",&n);
  printf("Enter %d Numbers:",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  insertion(a,n);
}

Q.2)Write a C program to evaluate postfix expression.
*/
#include<stdio.h>
#define MAX 5
struct stack 
{
  int a[MAX];
  int top;
}s;
void init()
{
  s.top=-1;  
}
int isempty()
{
   if(s.top==-1)
     return 1;
   else
     return 0;  
}
int isfull()
{
   if(s.top==MAX-1)
     return 1;
   else
    return 0;  
}
void push(int num)
{
  if(isfull())
  {
    printf("Stack is Overflow...!");
  }
  else
  {
    s.top++;
    s.a[s.top]=num;
  }
}
int pop()
{
  int val;
  if(isempty())
  {
    printf("Stack is Underflow...!");
  }
  else
  {
    val=s.a[s.top];
    s.top--;
    return val;
  }
}
/*void disp()
{
  int i;
  for(i=s.top;i>=0;i--)
  {
    printf("%d\t",s.a[i]);
  }
}
*/
int main()
{
 char exp[20],*e;
 int n1,n2,n3,num,a,b,c,d;
 init();
 printf("Enter Expression in the form abcd::");
 scanf("%s",exp);
 printf("Enter the of abcd::");
 scanf("%d%d%d%d",&a,&b,&c,&d);
 e=exp;
 while(*e!='\0')
 {
   if(*e=='a')
   {
     push(a);
   }
   else if(*e=='b')
   {
     push(b);
   }
   else if(*e=='c')
   {
     push(c);
   }
   else if(*e=='d')
   {
     push(d);
   }
   else
   {
     n1=pop();
     n2=pop();
     switch(*e)
     {
      case '+' : n3=n1+n2; break;
      case '-' : n3=n2-n1; break;
      case '*' : n3=n1*n2; break;
      case '/' : n3=n2/n1; break;
     }
   push(n3);
   }
   e++;
 }
 printf("The Result of %s = %d",exp,pop());
}