/*SLIP - 12
Q.1) Sort a random array of n integers (accept the value of n from user) in ascending order
by using selection sort algorithm. 

#include<stdio.h>
void selection(int a[],int n)
{
  int max,index,pass,i,t;
  for(pass=0;pass<n;pass++)
  {
    max=a[pass];
    index=pass;
    for(i=pass+1;i<n;i++)
    {
      if(a[i]<max)
      {
        max=a[i];
        index=i;
      }
    }
      t=a[pass];
      a[pass]=a[index];
      a[index]=t;
  }
  printf("\nSorted Numbers Using Selection Sort::");
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
  selection(a,n);
}
*/
/*
Q.2)There are lists where insertion should ensure the ordering of data elements.Since the 
elements are in ascending order the search can terminate once equal or greater element is 
found. Implement a doubly linked list of ordered integers(ascending/descending) with 
insert,search and display operations.
*/
#include<stdio.h>
typedef struct node
{
  int data;
  struct node *next,*prev;
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
void disp(NODE *head)
{
  NODE *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}
void search(NODE *head,int num)
{
  NODE *temp;
  int f=0;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
     if(temp->data==num)
     {
       f=1;
       break;     
     }    
  }
  if(f==1)
  {
    printf("Element is Found..!");
  }
  else
  {
    printf("Element Not Found..!");
  }
}
int main()
{
   int ch,num;
   NODE *head=NULL;
   do
   {
     printf("\nMENU\n1.;Create\n2.Disp\n3.Search\n4.Exit\n");
     printf("Enter Your Choice::");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1 : head=create(head); break;
       case 2 : disp(head); break;
       case 3 : printf("Enter Number To Search:");
                scanf("%d",&num);
                search(head,num);
                break;
       default : printf("Invalid Choice...1");         
     }
   }while(ch<4);
}