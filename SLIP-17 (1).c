/*SLIP-15
Q.1)Implement a stack library (ststack.h)of integers using a static implementation of the 
stack and implementing the operations like init(S),S=Push(S,x )and isEmpty(S).Write a
driver program that includes stack library and calls different stack operations.

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
Q.2)There are lists where insertion should ensure the ordering of data elements.Since the 
elements are in ascending order the search can terminate once equal or greater element is 
found .Implement a singly linked list of ordered integers (ascending/descending) with 
insert, search,and display operations.
*/
#include<stdio.h>
struct node 
{
  int data;
  struct node *next;
};
struct node *insert(struct node *head)
{
  int i,n;
  struct node *new,*temp;
  printf("Enter Limit:");
  scanf("%d",&n);
  printf("Enter Elements In Ascending Order\n");
  for(i=0;i<n;i++)
  {
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter Element:");
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
void *disp(struct node *head)
{
  struct node *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
     printf("%d\t",temp->data);
  }
}
void *search(struct node *head,int num)
{
  int f=0;
  struct node *temp;
  for(temp=head;temp->next!=NULL;temp=temp->next)
  {
    if(temp->data==num)
     {
       f=1;
       break;
     }
  }
  if(f==1)
    printf("%d is Found..!");
  else
    printf("%d Not Found..!");
}

int main()
{
  int ch,num;
  struct node *head=NULL;
  do
  {
    printf("\nMENU\n1:Insert\n2.search\n3.Display\n");
    printf("Enter Your Choice::");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : head=insert(head); break;
      case 2 : printf("Enter number to search:"); 
               scanf("%d",&num);
               search(head,num);
               break;
      case 3 : disp(head); break;         
      default : printf("Invlaid Choice..!");
    }
  }while(ch<4);
}