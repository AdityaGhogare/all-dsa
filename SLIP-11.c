/* SLIP 11
Q.1)Sort an random array of n integers (accept the value of n from user)in ascending
order by using Counting sort algorithm.

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
  struct node *temp,*new;
  printf("Enter Limit:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    new=memory;
    printf("Enter Coef & Pow::");
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
    printf("%d X^ %d",temp->coef,temp->pow);
  }
}
void add(struct node *h1,struct node *h2,struct nosde *h3)
{
  struct node *new,*t1=h1,*t2=h2,*t3;
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
      h3=t3=new;
    }
    else
    {
     t3->next=new;
     t3=new;
    }
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
  printf("\nPOlynomial 1::\n");
  h1=create(h1);
  printf("\nPOlynomial 2::\n");
  h2=create(h2);
  printf("\nPOlynomial 1::");
  disp(h1);
  printf("\nPOlynomial 2::");
  disp(h2);
  add(h1,h2,h3);
}