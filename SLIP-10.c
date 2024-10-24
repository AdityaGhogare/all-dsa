/*SLIP -10
Q.1)Implement a list library (singlylist.h) for a singly linked list.Create a linked list,reverse
it and display reversed linked list. 

#include<stdio.h>
typedef struct node 
{
 int data;
 struct node *next;
}NODE;
NODE *create(NODE *head)
{
  int i,n;
  NODE *temp,*new;
  printf("Enter Limit:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    new=(NODE *)malloc(sizeof(NODE));
    printf("Enter Value:");
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
NODE *reverse(NODE *head)
{
  NODE *prev=head,*cur=head->next,*next;
  while(cur!=NULL)
  {
    next=cur->next;
  cur->next=prev;
  prev=cur;
  cur=next;
  }
  head->next=NULL;
  head=prev;
 return head; 
}
void *disp(NODE *head)
{
  NODE *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
     printf("%d\t",temp->data);
}
int main()
{
  NODE *head=NULL;
  head=create(head);
  printf("Original Linked List::");
  disp(head);
  printf("\nReverse Linked List:");
  head=reverse(head);
  disp(head);
}
*/
/*
Q.2)Write a program that copies the content of one stack into another.Use stack library to 
perform basic stack operations. The order of two stacks must be identical.(Hint:Use a
temporary stack to preserve the order).
*/

#include<stdio.h>
#define MAX 5
struct stack
{
  int a[MAX];
  int top;
}*s;
int init(struct stack *s)
{
   //s=(struct stack *)malloc(sizeof(struct stack));
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
void push(struct stack *s,int num)
{
  if(isfull(&s))
  {
   printf("Stack is Full..!");
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
  if(isempty(&s))
  {
    printf("Stack is Empty..!");
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
  for(i=0;i<=s->top;i++)
  {
    printf("%d\t",s->a[i]);
  }
}
int main()
{
  struct stack s1,s2,t;
  init(&s1);
  init(&s2);
  init(&t);  
  int i,num;
  printf("Enter 5 Numbers:");
  for(i=0;i<5;i++)
  {
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
  disp(&s2);
}