/* SLIP -20
Q.1) Sort a random array of n integers (accept the value of n from user) in ascending order 
by using bubble sort algorithm. 

   #include<stdio.h>
   int main()
   {
     int n,i,a[100],t,pass;
     printf("Enter Limit:");
     scanf("%d",&n);
     printf("Enter %d Numbers:",n);
     for(i=0;i<n;i++)
     {
       scanf("%d",&a[i]);
     }
     for(pass=1;pass<n;pass++)
     {
       for(i=0;i<n-pass;i++)
       {
         if(a[i]>a[i+1])
         {
           t=a[i];
           a[i]=a[i+1];
           a[i+1]=t;
         }
       }
     }
     printf("Sorted Number Using Bubble Sort:\n");
     for(i=0;i<n;i++)
     {
       printf("%d\t",a[i]);
     }
   }

Q.2) There are lists where new elements are always appended at the end of the list. The list 
can be implemented as a circular list with the external pointer pointing to the last element 
of the list. Implement singly linked circular list of integers with append and display 
operations. The operation append(L, n),appends to the end of the list, n integers accepted 
from user.
*/
#include<stdio.h>
struct node 
{
  int data;
  struct node *next;
};
struct node *create(struct node *head)
{
  int i,n;
  struct node *new,*temp=head;
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
  struct node *head=NULL;
  int ch,num;
  do
  {
    printf("\nMENU\n1.Create\n2.Display\n3.append\n");
    printf("Enter your Choice:");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1 : head=create(head); break;
     case 2 : disp(head); break;
     case 3 : printf("Enter Number:");
              scanf("%d",&num); 
              append(head,num); break;
     default : printf("Invalid choice..!");
   } 
  }while(ch<4);
}
    