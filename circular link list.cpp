#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void listTraversal(struct node  *head)
{
    struct node *ptr=head;
    do{
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("NULL\n");  
}

struct node* insertlistAtfirst(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    
    struct node*p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    //at this point p points to the last node of r=this circular linked list 
   p->next=ptr;
   ptr->next=head;
   head=ptr;
    return head;
}

int main()
{
  struct node* head;
  struct node* second;
  struct node* third;
  
  //Allocate memosy fir nodes in the linked list in heap
  head=(struct node*)malloc(sizeof(struct node)); 
  second=(struct node*)malloc(sizeof(struct node)); 
  third=(struct node*)malloc(sizeof(struct node)); 
  
  head->data=3;
  head->next=second;
  
  second->data=5;
  second->next=third;
  
  third->data=9;
  third->next=head;
  
  listTraversal(head);
  head=insertlistAtfirst(head,56);
  //head=insertlistAtindex(head,56,2);
  //head=insertlistAtend(head,90);
 // head=insertAfterNode(head,third,32);
  listTraversal(head);
  
    return 0;
}
