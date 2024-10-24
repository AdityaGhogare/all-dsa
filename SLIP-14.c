/*SLIP-14
Q.1) Accept number from user and search inarray using linear serach algorithm. 

 #include<stdio.h>
 int main()
 {
   int i,a[100],n,key,f=0;
   printf("Enter Limit:");
   scanf("%d",&n);
   printf("Enter  Key to search:");
   scanf("%d",&key);
   printf("Enter %d Numbers:",n);
   for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);  
   }
   for(i=0;i<n;i++)
   {
     if(a[i]==key)
     {
       f=1;
       break;
     }
   }
   if(f==1)
    {
      printf("%d Is Found At %d.",key,i+1);
    }
   else
   {
     printf("%d Not Found.",key);
   } 
 }
*/
/*

Q.2) Implement a linear queue library (st_queue.h) of integers using a static 
implementation of the queue and implementing the operations like init (Q),AddQueue(Q,x) 
and X=Delete Queue(Q).Write a program that includes queue library and calls different 
queue operations.
*/
#include<stdio.h>
#define MAX 5
struct queue
{
  int a[MAX];
  int front,rear;
}q;
void init()
{
  q.front=q.rear=-1;
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
void enqueue(int num)
{
  if(isfull())
  {
    printf("Queue is Overflow..!");
  }
  else
  {
    if(q.front==-1)
     q.front=0;
     q.rear++;
     q.a[q.rear]=num;
    printf("\n Inserted Successfully..!");
  }
}
int dequeue()
{
  int val;
  if(isempty())
  {
    printf("Queue is Underflow..!");
  }
  else
  {
    val=q.a[q.front];
    q.front++;
    printf("deleted Value=%d",val);
  }
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
  int ch,num;
  init();
  do
  {
    printf("\nMENU\n1.Insert\n2.Delete\n3.display\n4.Exit\n");
    printf("Enter Your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : printf("Enter Number:");
               scanf("%d",&num);
               enqueue(num);
               break;
      case 2 : dequeue(); break;
      case 3 : disp(); break;
      default : printf("Invalid choice...!");         
    }
  }while(ch<4);
}