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
      
};

//Case 1:Deleting the first node
struct node* deleteFirst(struct node* head){
    struct node* ptr=head;
    head=head->next;
    free(ptr);
    return(head);
    
}
//Case 2:Deleting the index at a given index
struct node* deleteindex(struct node* head,int index){
    struct node* p=head;
    struct node* q=head->next;
    for(int i=0;i<index-1;i++) 
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return(head);
    
}
//Case 3:Deleting the last node
struct node* deleteLast(struct node* head){
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=NULL) 
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return(head);
    
}
//Case 4:Deleting the element with a given value 
struct node* deletevalue(struct node* head,int value){
    struct node *p=head;
    struct node *q=head->next;
     while(q->data!=value && q->next!=NULL) 
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
    p->next=q->next;
    free(q);
    }
    return(head);
    
} 
int main()
{
  struct node* head;
  struct node* second;
  struct node* third;
  
  //Allocate memory fir nodes in the linked list in heap
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
  //head=deleteFirst(head);
 // head=deleteindex(head,2);
 //head=deleteLast(head);
 head=deletevalue(head,0);
  
  listTraversal(head);
  
    return 0;
}
