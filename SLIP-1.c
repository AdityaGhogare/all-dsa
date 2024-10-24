/*SLIP - 1
Q1) Q.1) Implement a list library (doublylist.h) for a doubly linked list of integers 
with the create, display operations. Write a menu driven program to call these 
operations.  
 
#include<stdio.h>
struct node 
{
  int data;
  struct node *next,*prev;
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
     printf("Enter Limit:");
     scanf("%d",&new->data);
     new->next=NULL;
     new->prev=NULL;
     if(head==NULL)
     {
       temp=head=new;
     }
     else
     {
      temp->next=new;
      new->prev=temp;
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
  struct node *head=NULL;
  int ch,num;
  do
  {  
     printf("\n1.Create\n2.Disp\n");
     printf("Enter Your Choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1 : head=create(head); break;
        case 2 : disp(head); break;
        default :printf("Invlaid Choice:"); 
     }
  }while(ch<3);
}

Q 2)  Write a program that sorts the elements of linked list using any of sorting 
technique. 

*/
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
struct node *disp(struct node *head)
{
   struct node *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
      {
       printf("%d\t",temp->data);
      }
}
struct node *sort(struct node *head)
{
  struct node *i,*j,*t;
  for(i=head;i!=NULL;i=i->next)
  {
    for(j=head;j!=NULL;j=j->next)
    {
      if(i->data < j->data)
      {
        t=i->data;
        i->data=j->data;
        j->data=t;
      }
    }
  }
  return head;
}
int main()
{
  struct node *head=NULL;
  int ch,num;
  do
  {  
     printf("\n1.Create\n2.Sort\n");
     printf("Enter Your Choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1 : head=create(head);
                 printf("\nLinked List:");
                 disp(head); break;
        case 2 : head=sort(head); 
                 printf("\nAfter Sorting::");
                 disp(head); break;
        default :printf("Invlaid Choice:"); 
     }
  }while(ch<3);
}