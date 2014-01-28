#include "list1.h"
#include<stdio.h>
#include<stdlib.h>
/* A function to insert a node at the begining of a linked list*/
  void list_push(lnodeptr *head_ref,int new_data)
  {
	lnodeptr new_node=(lnodeptr)malloc(sizeof(lnode));

	/* put in the data */
	 new_node->elem = new_data;
 
	/* link the old list off the new node */
	new_node->nextptr = (*head_ref);
 
    	/* move the head to point to the new node */
    	(*head_ref) = new_node;
    
   }
 
 

/* A function that deletes the element from beginnig of the list*/
   void list_pop(lnodeptr *head_ref)
  {
	lnodeptr del_node;
	del_node=(*head_ref);
	printf("\nElement popped is %d ",del_node->elem);

	(*head_ref)=del_node->nextptr;
  }
/* A function that deletes entire list*/
   void list_delete(lnodeptr *head_ref)
  {
	(*head_ref)=NULL;

  }

/* A function that gives the length of the list*/ 
   int list_length(const lnodeptr h)
  {
	lnodeptr p;
	int count=0;
	p=h;
	while(p->nextptr!=NULL)
	{
		count++;
		p=p->nextptr;
	}

	return count+1;
   }
/* A function that concatenate two linked list*/
   void list_add(lnodeptr *head_ref, lnodeptr h)
   {
	lnodeptr p;
	p=h;
	while(p->nextptr!=NULL)
	{
		p=p->nextptr;
	}
	p->nextptr=(*head_ref);


    }
/* A function that cuts the linked list into two parts*/
    void list_sub(lnodeptr *head_ref, lnodeptr h)
    {
l	nodeptr p;
	int loc,count;
	count=1;
	p=h;
	printf("\nEnter the location after which you want to cut");
	scanf("%d",&loc);
	while(loc!=count)
	{
		count++;
		p=p->nextptr;
	}
	(*head_ref)=p->nextptr;

	p->nextptr=NULL;
     }

/* A program to test above function*/
     int main()
    {
    /* Start with the empty list */
    lnodeptr head1 = NULL;
    lnodeptr head2 = NULL;
    
 
    /*create a linked lists 4->3->2->1 */
    list_push(&head1, 1);
    list_push(&head1, 2);
    list_push(&head1, 3);
    list_push(&head1, 4);
 
    /*create a linked lists 7->6->5->4 */
    list_push(&head2, 4);
    list_push(&head2, 5);
    list_push(&head2, 6);
    list_push(&head2, 7);
    
    
   /*create a linked lists 4->3->2->1->7->6->5->4 */ 
    list_add(&head2,head1);

    list_pop(&head1);
    list_pop(&head1);
    list_pop(&head1);
    list_pop(&head1);
    list_pop(&head1);
    list_pop(&head1);

    

    list_push(&head2, 8);
    list_push(&head2, 9);
    list_push(&head2, 10);
    list_push(&head2, 11);
    

    

    list_sub(&head1,head2);
    
    

    list_pop(&head1);
    list_pop(&head1);
    list_pop(&head1);
    printf("\n%d",list_length(head2));
    printf("\n%d",list_length(head1));



    return 0;
   }
