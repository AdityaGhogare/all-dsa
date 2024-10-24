/*SLIP -5

Q.1) Sort a random array of n integers (accept the value of n from user) in ascending
 order by using selection sort algorithm. 

#include<stdio.h>
void selection(int a[],int  n)
{
  int pass,index,max,i,t;
  for(pass=0;pass<n;pass++)
  {
    max=a[pass];
    index=pass;
    for(i=pass+1;i<n;i++)
    {
      if(a[i]<max)
      {
        max=a[i];
        index=i;
      }
      t=a[index];
      a[index]=a[pass];
      a[pass]=t;
    }
  }
  printf("Sorted Numbers By Selection Sort::");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}
int main()
{
  int i,n,a[100];
  printf("Enter Limit:");
  scanf("%d",&n);
  printf("Enter %d numbers:",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  selection(a,n); 
}
*/
/*
Q.2) Implement a queue library (dyqueue.h) of integers using a dynamic (linked list) 
implementation of the queue and implement init, enqueue,dequeue,isempty,peek 
operations.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  int *next;
}*front,*rear,*new;
void init()
{
   front=rear=NULL;
}
int isempty()
{
  if(front==NULL)
    return 1;
   else
    return 0; 
}
int peek()
{
   front=rear=NULL; 
}
void enqueue(int num)
{
  new=(struct node *)malloc(sizeof(struct node));
  new->data=num;
  new->next=NULL;
  if(front==NULL)
  {
    front=rear=new;
  }  
  else
  {
     rear->next=new;
     rear=new;
  }
}
void dequeue()
{
  int val;
  struct node *p;
  if(isempty())
  {
    printf("Queue is Underflow...!");
  }
  else
  {
   p=front;
   val=front->data;
   front=front->next;
   free(p);
   printf("\nDeleted Value=%d",val);
  }
}
void disp()
{
  struct node *temp;
  for(temp=front;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}
int main()
{
   int ch,num;
   init();
   do
   {
     printf("\n1.enqueue\n2.dequeue\n3disp\n");
     printf("Enter your Choice:"); 
     scanf("%d",&ch);
     switch(ch)
     {
       case 1 : printf("Enter Value:");
                scanf("%d",&num);
                enqueue(num);
                break;
       case 2 : dequeue(); break;
       case 3 : disp(); break;         
     } 
   }while(ch<4);
}