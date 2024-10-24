/*SLIP-7
Q.1) Implement a list library (singlylist.h) for a singly linked list of integer With the 
operations create, delete specific element and display. Write a menu driven program to
call these operations.

#include<stdio.h>
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
    printf("Enter Value:");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL)
    {
      temp=head=new;
      continue;
    }
    temp->next=new;
    temp=new;
  }
  return head;
}
struct node *disp(struct node *head)
{
  struct node *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}
struct node *delbyval(struct node *head)
{
  int num;
  struct node *temp,*temp1;
  printf("Enter Value:");
  scanf("%d",&num);
  for(temp=head;temp->next!=NULL;temp=temp->next)
  {
    if(temp->next->data==num)
    {
       temp1=temp->next;
       temp->next=temp1->next;
       free(temp1); 
    }
  }
}
int main()
{
  struct node *head=NULL;
  int ch;
  do
  {
  printf("\nMENU\n1.Create\n2.Disp\n3.Delete By Value\n");
  printf("Enter Your choice:");
  scanf("%d",&ch);
    switch(ch)
    {
      case 1 : head=create(head); break; 
      case 2 : disp(head); break;
      case 3 : delbyval(head); break;
      default : printf("Invliad choice..!");
    }
  }while(ch<4);
}
*/
/*
Q.2) Write a C program to check whether the contents of two stacks are identical. Use 
stack library to perform basic stack operations. Neither stack should be changed.
*/
#include<stdlib.h>
#include<stdio.h>
#define MAX 5
struct stack
{
  int a[MAX];
  int top;
};
void init(struct stack *s)
{
 // s=(struct stack *)malloc(sizeof(struct stack));
  s->top=-1;
}
int isempty(struct stack *s)
{
  if(s->top==-1)
    return 1;
  else
    return 0;  
}
int isfull(struct stack *s)
{
   if(s->top==MAX-1)
      return 1;
   else
      return 0; 
}
int peek(struct stack *s)
{
  return s->a[s->top];
}
int push(struct stack *s,int num)
{
   if(isfull(s))
   {
     printf("Stack is Overflow..!");
   }
   else
   {
     s->top++;
     s->a[s->top]=num;
   }
}
int pop(struct stack *s)
{
  int val;
  if(isempty(s))
  {
    printf("Stack is Underflow...!");
    return -1;
  }
  else
  {
   val=s->a[s->top]; 
   s->top--;
   return val;
  }
}
void disp(struct stack *s)
{
   int i;
   for(i=s->top;i>=0;i--)
   {
     printf("%d\t",s->a[i]);
   } 
}
int main()
{
  struct stack s1,s2,t;
  int i,num;
  init(&s1);
  init(&s2);
  init(&t);
  for(i=0;i<MAX;i++) 
  {
    printf("Enter number:");
    scanf("%d",&num);
    push(&s1,num);
  }
  while(!isempty(&s1))
  {
    num=pop(&s1);
    push(&t,num);
  }
  while(!isempty(&t))
  {
     num=pop(&t);
     push(&s2,num);
  }
  printf("\nDisplay Stack 2::");
  disp(&s2);
}