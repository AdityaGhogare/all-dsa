/*SLIP-8
Q.1) Sort a random array of n integers (accept the value of n from user) in ascending
 order by using count sort algorithm. 
 
#include<stdio.h>
void countsort(int a[],int n,int k)
{
   int b[100],c[100],i;
   for(i=0;i<n;i++)
   {
     c[a[i]]++;
   }
   for(i=1;i<=k;i++)
   {
     c[i]=c[i]+c[i-1];
   }
   for(i=n-1;i>=0;i--)
   {
      b[c[a[i]]-1]=a[i];
      c[a[i]]--;
   }
   printf("Sorted N Numbers By Count Sort:");
   for(i=0;i<n;i++)
   {
     printf("%d\t",b[i]);
   }
}
int main()
{
  int i,n,a[100],k;
  printf("Enter Limit:");
  scanf("%d",&n);
  printf("Enter Key:");
  scanf("%d",&k);
  printf("Enter %d Numbers:",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  countsort(a,n,k);
}
*/
/*
Q.2) Implement linear queue library (st_queue.h) of integers using a static implementation 
of the queue and implementing the init(Q),add(Q) and peek(Q) operations. Write a 
program that includes queue library and calls different queue operations.
*/
#include<stdio.h>
#define MAX 5
struct queue
{
  int a[MAX];
  int front,rear;
}q;
int init()
{
  return q.front=q.rear=-1;
}
int isempty()
{
  if(q.front==-1 || q.front>q.rear)
    return 1;
  else
    return 0;  
}
int isfull()
{
  if(q.rear==MAX-1)
     return 1;
  else
    return 0;   
}
void add(int num)
{
  if(isfull())
  {
    printf("Queue is Full.");
  }
  else
  {
    if(q.front==-1)
    q.front=0;
    q.rear++;
    q.a[q.rear]=num;
   printf("Inseert Successfully...!");
  }
}
int removeq()
{
  int val;
  if(isempty())
  {
     printf("\nQueue is Empty.");
  }
  else
  {
   val=q.a[q.front];
   q.front++;
   printf("Deleted Value=%d",val);
  }
}
int peek()
{
  return q.a[q.front];
}
void disp()
{
  int i;
  for(i=q.front;i<=q.rear;i++)
  {
    printf("%d\t",q.a[i]); 
  }
}
int main()
{
  int n,num,ch;
  init();
  do
  {
    printf("\nMENU\n1.Add\n2.Remove\n3.Peek\n4.Disp\n5.Exit\n");
    printf("Enter Your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1 : printf("Enter Number:");
              scanf("%d",&num);
              add(num);
              break;
     case 2 : removeq(); break;
     case 3 : n=peek();
              printf("\nTop Most Element=%d",n);  
              break;         
     case 4 : disp(); break;
    }
  }while(ch<5);
}