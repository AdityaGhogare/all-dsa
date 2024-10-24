/* SLIP-2
Q.1) Implement a list library (singlylist.h) for a singly linked list of integer 
with the operations create, display. Write a menu driven program to call 
these operations.

#include<stdio.h>
struct node 
{
  int data;
  struct node *next;
};
struct node *create(struct node *head)
{
   struct node *temp,*new;
   int i,n;
   printf("Enter Limit:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     new=(struct node *)malloc(sizeof(struct node));
     printf("Enter value:");
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
struct node *disp(struct node *head)
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
  struct node *head=NULL;
  do
  {
    printf("\n1.Create\n2.Disp\n");
    printf("Enter Your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1 : head=create(head); break;
       case 2 : disp(head); break;
       default : printf("Invalid Choice...!");
    }
  }while(ch<3);
}

*/

/*
Q.2) Write a program that copies the contents of one stack into another. Use 
stack library to perform basic stack operations. The order of two stacks 
must be identical.(Hint:Use a temporary stack to preserve the order).
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