/*SLIP -18
1) Write a c program that search a number in integers array using binary search 
algorithm. 
 
#include<stdio.h>
int main()
{
    int a[100],f=0,i,n,top,bottom,num,mid;
    printf("Enter Limit:");
    scanf("%d",&n);
    printf("Enter n Elements:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter Number to search:");
    scanf("%d",&num);
    top=0;
    bottom=n-1;
    while(top<=bottom)
    {
        mid=(top+bottom)/2;
        if(a[mid]==num)
        {
            f=1; break;
        }
        if(num>a[i])
        {
            top=mid+1;
        }
        else
        {
            bottom=mid-1;
        }
    }
    if(f==1)
        printf("Number is Found");
    else
        printf("Number not found");
}
*/ 
 /*
Q.2) Write a program that merges two ordered linked lists into third new list. When two 
lists are merged the data in the resulting list are also ordered. The two original lists should 
be left unchanged. That is merged list should be new one.Use linked implementation
*/
#include<stdio.h>
#define memory (struct node *)malloc(sizeof(struct node))
struct node 
{
  int data;
  struct node *next;
};
struct node *create(struct node *head)
{
  struct node *new,*temp;
  int i,n;
  printf("Enter Limit:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    new=memory;
    printf("Enter Value=");
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
void disp(struct node *head)
{
  struct node *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}
struct node *merge(struct node *head1,struct node *head2,struct node *head3)
{
  struct node *temp1,*temp2,*temp3,*new;
  temp1=head1;
  temp2=head2;
  while(temp1!=NULL && temp2!=NULL)
  {
    new=memory;
    new->next=NULL;
    if(temp1->data<temp2->data)
    {
      new->data=temp1->data;
      temp1=temp1->next;
    }
    else
    {
      new->data=temp2->data;
      temp2=temp2->next;
    }
    if(head3==NULL)
    {
      temp3=head3=new;
    }
    temp3->next=new;
    temp3=new;
  }
  while(temp1!=NULL)
  {
    new=memory;
    new->next=NULL;
    new->data=temp1->data;
    temp1=temp1->next;
    temp3->next=new;
    temp3=new;
  }
  while(temp2!=NULL)
  {
    new=memory;
    new->next=NULL;
    new->data=temp2->data;
    temp2=temp2->next;
    temp3->next=new;
    temp3=new;
  }
  printf("\nMerged Linked List::");
  disp(head3);
}
int main()
{
  struct node *head1=NULL,*head2=NULL,*head3=NULL;
  printf("\nLinked List 1::");
  head1=create(head1);
  printf("\nLinked List 2::");
  head2=create(head2);
  printf("\nLinked List 1::");
  disp(head1);
   printf("\nLinked List 2::");
  disp(head2);
  merge(head1,head2,head3);
}