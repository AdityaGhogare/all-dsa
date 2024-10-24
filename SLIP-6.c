/* SLIP-6
Q.1) Sort a random array of n integers (accept the value of n from user) in ascending
 order by using quick sort algorithm. 
 
 #include<stdio.h>
 #include<stdlib.h>
 int partition(int a[],int start,int end)
 {
   int i,j,pivot,t;
   pivot=a[start];
   i=start;
   j=end;
  do
  {
   while(a[i]<=pivot && i<=end-1)
   {
     i++;
   }
   while(a[j]>=pivot && j>=start+1)
   {
     j--;
   }
   if(i<j)
   {
     t=a[i];
     a[i]=a[j];
     a[j]=t;
   }
  }while(i<j);
  t=a[start];
  a[start]=a[j];
  a[j]=t;
 return j;
 }
void quicksort(int a[],int start,int end)
{
  int j;
  if(start<end)
  {
    j=partition(a,start,end);
    quicksort(a,start,j-1);
    quicksort(a,j+1,end);
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
  quicksort(a,0,n-1);
  printf("Sorted Numbers By Quick Sort::");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}
 */
 /*
Q.2) Write a program that checks whether a string of characters is palindrome or not. 
 The function should use a stack library (cststack.h) of stack of characters using
 a static implementation of the stack.
 */
#include<stdio.h>
#define MAX 20
struct stack
{
  char a[MAX];
  int top;
}s;
init()
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
void push(char ch)
{
  if(isfull())
  {
    printf("Stack is Overflow..!..!");
  }
  else
  {
    s.top++;
    s.a[s.top]=ch;
  }
}
char pop()
{
  char val;
  if(isempty())
  {
    printf("Stack is Underflow..!");
  }
  else
  {
    val=s.a[s.top];
    s.top--;
    return val;
  }
}
int main()
{
  int i;
  char ch,s1[20];
  printf("Enter String:");
  gets(s1);
  init();
  for(i=0;s1[i]!='\0';i++)
  {
    push(s1[i]);
  }
  for(i=0;s1[i]!='\0';i++)
  {
    if(s1[i]!=pop())
    {
       break;
    } 
  }
  if(isempty())
    printf("String is Palindrome..!");
  else
    printf("String is not palindrome..!");   
} 
