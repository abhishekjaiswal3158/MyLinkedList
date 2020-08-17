#include <stdio.h>
#include <stdlib.h>
struct node{
	int data ;
	struct node *link;
};
struct node *head=NULL;
void insertionAtLastNode(){
	printf("enter the number that u want to add in the data structure \n");
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL){
		head=temp;
		
	}
	else{
		struct node * n;
		n=head;
		while(n->link!=NULL){
			n=n->link;
		}
		n->link=temp;
		
	}
}

void insertionAtFirstNode(){
	printf("enter the number that u want to add in the data structure \n");
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL){
		head=temp;
		
	}
	else{
		struct node * n;
		n=head;
		head=temp;
		temp->link=n;
		
	}
}

void displayAllData(){
	if(head==NULL){
		printf(" LIST IS Empty\n");

	}
	else{
		struct node * n;
		n=head;
		while(n!=NULL){
			printf("%d  ",n->data);
			n=n->link;
		}
	}
}

void deleteLastNode(){
	if(head== NULL){
		printf("LIST IS EMPTY AND NOTHING CAN BE DELETE");
	}
	else if(head->link==NULL){
	free(head);
	head=NULL;
	}
	else{
		struct node *n;
		n=head;
		while(n->link->link!=NULL){
		n=n->link;	
		}
		free(n->link);
		n->link=NULL;
	}	
}

void deleteFirstNode(){
	if(head== NULL){
		printf("LIST IS EMPTY AND NOTHING CAN BE DELETE");
	}
	else{
	struct node *temp=head->link;
	free(head);
	head=temp;
	}
	
}

void deleteSpecificNode(){
	printf("enter the number that u want to delete");
	int a;
	scanf("%d",&a);
struct node *temp;
temp=head;
int count=0;
while(temp!=NULL){
temp=temp->link;
count++;
}
struct node *tem;
struct node *past=head;
tem=head;
int c=0;
while(tem!=NULL){
	if(tem->data==a){
	struct node *swap;
	if(tem->link==NULL){
	deleteLastNode();
	break;
	}
	else if(head->data==a){
	deleteFirstNode();
	break;
	}
	else{
	past->link=tem->link;
	break;
	}
	}
	past=tem;
tem=tem->link;
c++;
}
if(count==c){
printf("\n NO SUCH ELEMENT \n");
}

}

void reverse(){
	struct node *newhead=head;
	struct node *temp=head->link;
	head->link=NULL;
	while(temp!=NULL){
		struct node *n=newhead;
		newhead=temp;
		temp=temp->link;
		newhead->link=n;
	}
	head=newhead;
}



int main(void) {
	printf("<<<<<<<<<<<------------WELCOME TO MY DATA STRUCTURE-------------->>>>>>>\n");
    while(1){
	printf("\n-----click----- \n \n 1->insertionAtLastNode \n 2->display \n 3->deleteLastNode \n 4->deleteFirstNode \n 5->deleteSpecificNode \n 6->insertionAtFirstNode \n 7->Reverseing 8->EXIT \n\n");
	int a;
	scanf("%d",&a);
	switch(a){
	case 1: insertionAtLastNode(); break;
	case 2:displayAllData(); break;
	case 3:deleteLastNode();break;
	case 4:deleteFirstNode();break;
	case 5:deleteSpecificNode();break;
	case 6:insertionAtFirstNode(); break;
	case 7:reverse();;break;
	case 8: exit(0);
	}
	}
	return EXIT_SUCCESS;
}
