/*SLIP-13
Q.1) Implement a stack library (ststack.h) of integers using a static implementation of the 
stack and implementing the operations Like init(S),S=push(S), isFull(S). Write a driver 
program that includes stack library and calls different stack operations. 

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
    printf("Stack is Overflow..!");
  }
  else
  {
    s.top++;
    s.a[s.top]=num;
    printf("\nPushed Sucessfully..!");
  }
}
int pop()
{
  int val;
  if(isempty())
  {
    printf("Stack is Underflow..!");
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
    printf("\nMENU\n1.Push\n2.POP\n3.Display\n");
    printf("Enter Your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : printf("Enter Number:");
               scanf("%d",&num);
               push(num);
               break;
      case 2 : pop(); break;
      case 3 : disp(); break;
      default : printf("Invalid choice..!");         
    }
  }while(ch<4);
}
*/
/*
Q.2) There are lists where new elements are always appended at the end of the list. The list 
can be implemented as a circular list with the external pointer pointing to the last element
of the list. Implement singly linked circular list of integers with append and display 
operations. The operation append(L, n),appends to the end of the list,n integers either
accepted from user or randomly generated
*/
#include<stdio.h>
struct node 
{
  int data;
  struct node *next;
};
struct node *create(struct node *head)
{
   struct node *temp=head,*new;
   int i,n;
   printf("Enter Limit:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     new=(struct node *)malloc(sizeof(struct node));
     printf("Enter Value:");
     scanf("%d",&new->data);
     new->next=head;
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
void disp(struct node *head)
{
  struct node *temp=head;
  do
  {
     printf("%d\t",temp->data);
     temp=temp->next;
  }while(temp!=head);
}   
struct node *append(struct node *head,int num)
{
   int i;
   struct node *temp,*new;
   new=(struct node *)malloc(sizeof(struct node));
   new->data=num;
   new->next=head;
   for(temp=head;temp->next!=head;temp=temp->next);
   temp->next=new;
  return head;
} 
int main()
{
  int ch,num;
  struct node *head=NULL;
  do
  {
    printf("\nMENU\n1.Create\n2.Display\n3.append\n4.Exit\n");
    printf("Enter Your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : head=create(head); break;
      case 2 : disp(head); break;
      case 3 : printf("Enter Number:");
               scanf("%d",&num);
               head=append(head,num); break;
      default : printf("Invalid Choice..!");
    }
  }while(ch<4);
}