/*SLIP-9
Q.1) Implement a stack library (ststack.h) of integers using a static implementation of the 
stack and implementing the operations like init(S),S=push(S) and S=pop(S). Write a driver 
program that includes stack library and calls different stack operations. [10]

#include<stdio.h>
#define MAX 5
struct stack 
{
  int a[MAX];
  int top;
}s;
int init()
{
  return s.top=-1; 
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
    printf("Stack is Full..!");
  }
  else
  {
    s.top++;
    s.a[s.top]=num;
    printf("Pushed Successfully..!");
  }
}
int pop()
{
  int val;
  if(isempty())
  {
    printf("Stack is Empty..!");
  }
  else
  {
    val=s.a[s.top];
    s.top--;
    printf("Poped Value=%d",val);
  }
}
void disp()
{
  int i;
  for(i=s.top;i>=0;i--)
  {
    printf("%d\t",s.a[i]);
  }
}
int main()
{
  int ch,num;
   init();
  do
  {
   printf("\nMENU\n1.Push\n2.Pop\n3.disp\n4Exit\n");
   printf("Enter Your Choice:");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1 : printf("Enter number:");
              scanf("%d",&num);
              push(num);
              break;
     case 2 : pop(); break;
     case 3 : disp(); break;         
   }
  }while(ch<4);
}
*/
/*
Q.2) Write a program that sorts the elements of linked list using bubble sort technique.
*/
#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *next;
};
struct node *create(struct node *head)
{
  int i,n;
  struct node *new,*temp;
  printf("Enter Limit:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter Value::");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL)
    {
      temp=head=new;
    }
    else
    {
      temp->next=new;
      temp=new;
    } 
  }
  return head;
}
struct node *sort(struct node *head)
{
  struct node *i,*j,*t;
  for(i=head;i!=NULL;i=i->next)
  {
    for(j=head;j!=NULL;j=j->next)
    {
      if(i->data<j->data)
      {
        t=i->data;
        i->data=j->data;
        j->data=t;
      }
    }
  }
  return head;
}
void disp(struct node *head)
{
  struct node *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}
int main()
{
  int ch;
  struct  node *head=NULL;
 do{
    printf("\nMENU\n1.Create\n2.Disp\n3.Sort\n");
    printf("Enter Your Choice:"); 
    scanf("%d",&ch);
    switch(ch)
    {
     case 1 : head=create(head); break;
     case 2 : disp(head); break;
     case 3 : sort(head);
              printf("\nSorted List using Bubble Sort\n");
              disp(head); 
              break;
    }
 }while(ch<4);
}