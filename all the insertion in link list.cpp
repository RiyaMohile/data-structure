#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void listTraversal(struct node*  ptr)
{
    while(ptr!=NULL)
   { printf("%d->",ptr->data);
    ptr=ptr->next;
   }
     printf("NULL\n");
      
}

struct node* insertlistAtfirst(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
struct node* insertlistAtindex(struct node* head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node* insertlistAtend(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p=head;
    
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* insertAfterNode(struct node* head,struct node* prevNode,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    
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
  third->next=NULL;
  
  listTraversal(head);
  //head=insertlistAtfirst(head,56);
  //head=insertlistAtindex(head,56,2);
  //head=insertlistAtend(head,90);
  head=insertAfterNode(head,third,32);
  listTraversal(head);
  
    return 0;
}
