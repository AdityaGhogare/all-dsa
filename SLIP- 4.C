/*SLIP-4
Q.1)Read the ‘n’ numbers from user and sort using bubble sort. 

#include<stdio.h>
void bubble(int a[],int n)
{
  int i,pass,t;
  for(pass=1;pass<n;pass++)
  {
    for(i=0;i<n-pass;i++)
    {
      if(a[i]>a[i+1])
      {
        t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
      }
    }
  }
  printf("Sorted Numbers by Bubble Sort::");
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
  printf("Enter %d Numbers:",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  bubble(a,n);
}
*/

/*
Q.2) Write a program to reverse the elements of a queue using queue library.
 Implement basic queue operations init,enqueue,dequeue,isempty,peek.
 */
 #include<stdio.h>
 #include<stdlib.h>
 #define MAX 5
 struct queue
 {
   int a[MAX];
   int front,rear;
 }*q;
 void init()
 {
  q=(struct queue *)malloc(sizeof(struct queue));
  q->front=q->rear=-1;
 }
int isempty()
 {
  if(q->front==-1 || q->front>q->rear)
    return 1;
  else
    return 0;  
 }
int isfull()
{
  if(q->rear==MAX-1)
    return 1;
  else
    return 0;  
} 
void enqueue(int num)
{
  if(isfull())
  {
    printf("Queue is Overflow...!");
  }
  else
  {
    if(q->front==-1)
      q->front=0;
      q->rear++;
      q->a[q->rear]=num;
      printf("Insert Successfully..!");
  }
}
void dequeue()
{
  int val;
  if(isempty())
  {
    printf("Stack is Underflow..!");
  }
  else
  {
    val=q->a[q->front];
    q->front++;
    printf("Deleted Value=%d",val);
  }
}
int peek()
{
  return q->a[q->front];
}
void disp()
{
   int i;
   for(i=q->rear;i>=q->front;i--)
   {
     printf("%d\t",q->a[i]);
   }
}
int main()
{
 int ch,num;
 init();
 do
 {
   printf("\n1,Insert(enqueue)\n2.Delete(dequeue)\n3.Disp\n");
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
     default : printf("Invalid Choice...!");         
   }
 }while(ch<4);
}
    