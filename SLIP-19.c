/* SLIP -19
Q.1) Implement a stack library (ststack.h) of integers using a static implementation of the 
stack and implementing the operations like init(S),S=push(S), and X=peek(S). Write a 
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
 int isfull()
 {
   if(s.top==MAX-1)
     return 1;
   else
    return 0;  
 }
 int isempty()
 {
   if(s.top==-1)
     return 1;
   else
     return 0;  
 }
 int peek()
 {
   return s.a[s.top];
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
     printf("Pushed succesfully..!");
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
     printf("\nPoped value =%d",val);
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
   int n,ch,num;
   init();
   do
   {
     printf("\nMENU\n1.Push\n2.Pop\n3.peek\n4.disp\n");
     printf("Enter Your Choice:"); 
     scanf("%d",&ch);
     switch(ch)
     {
       case 1 : printf("Enter number:");
                scanf("%d",&num);
                push(num);
                break;
       case 2 : pop(); break;
       case 3 : n=peek(); 
               printf("\nTop Most Value:%d",n); break;
       case 4 : disp(); break;
       default : printf("Invalid Choice..!");          
     }
   }while(ch<5);
 }
 */
 /*
Q.2)Write a program that add two single variable polynomials.Each polynomial should be 
represented as a list with linked list implementation.
*/
#include<stdio.h>
#define memory (struct node *)malloc(sizeof(struct node))
struct node 
{
  int coef,pow;
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
     new=memory;
     printf("Enter coef And pow:");
     scanf("%d%d",&new->coef,&new->pow);
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
void disp(struct node *head)
{
  struct node *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    printf("%d X ^ %d ",temp->coef,temp->pow);
  } 
}
void add(struct node *h1,struct node *h2,struct node *h3)
{
  struct node *new,*t1,*t2,*t3=NULL;
  t1=t2=NULL;
  while(t1!=NULL && t2!=NULL)
  {
    new=memory;
    new->next=NULL;
    if(t1->pow>t2->pow)
    {
      new->coef=t1->coef;
      new->pow=t1->pow;
     t1=t1->next;   
    }
    else if(t1->pow<t2->pow)
    {
      new->coef=t2->coef;
      new->pow=t2->pow;
      t2=t2->next; 
    }
    else
    {
     new->coef=t1->coef+t2->coef;
     new->pow=t2->pow;
     t1=t1->next;
     t2=t2->next; 
    }
    if(h3==NULL)
    {
      t3=h3=new;
    }
    t3->next=new;
    t3=new;
  }
  while(t1!=NULL)
  {
    new=memory;
    new->next=NULL;
    new->coef=t1->coef;
    new->pow=t1->pow;
    t1=t1->next;
    t3->next=new;
    t3=new;
  }
  while(t2!=NULL)
  {
    new=memory;
    new->next=NULL;
    new->coef=t2->coef;
    new->pow=t2->pow;
    t2=t2->next;
    t3->next=new;
    t3=new;
  }
 disp(h3);
}

int main()
{
 struct node *h1,*h2,*h3=NULL;
 h1=h2=NULL;
 printf("\nPolynomial1:\n");
  h1=create(h1); 
 printf("\nPolynomial2:\n");
  h2=create(h2); 
 printf("\nPolynomial1:\n");
  disp(h1); 
 printf("\nPolynomial2:\n");
  disp(h2);
  add(h1,h2,h3);  
}