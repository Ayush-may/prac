//Doubly Linked List by Ayush Sharma
//23-12-22

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* pre;
	struct node* next;
		//Constructor of structure
		//parameterized constructor
		node(int value){
			this->data=value;
			this->pre=NULL;
			this->next=NULL;
		}
};


struct node* start;
struct node* tail;


void init(){
  start=tail=NULL;
}

int forwardTraverse(){

	if(start==NULL){
		cout<<"UnderFlow\n";
		return 0;
	}

	struct node* ptr=start;
	cout<<"\nForward Traversal : ";

	cout<<"Start --> ";
	while(ptr!=NULL){
		cout<<ptr->data<<" --> ";
		ptr=ptr->next;
	}
	cout<<"Tail\n";
	return 0;
}

int backwardTraverse(){
	if(tail==NULL){
		cout<<"UnderFlow\n";
		return 0;
	}
	else{
		struct node* ptr=tail;
		cout<<"\nBackward Traversal : ";

		cout<<"Tail <-- ";
		while(ptr!=NULL){
			cout<<ptr->data<<" <-- ";
			ptr=ptr->pre;
		}
		cout<<"Start\n";
	}
	return 0;
}

void allTraverse(){
	forwardTraverse();
	backwardTraverse();
}

void insertAtHead(int item){
	struct node* newnode=new node(item);
	if(start==NULL){
	       //newnode->pre=NULL;
		tail=newnode;
		start=newnode;
	}
	else{
		start->pre=newnode;
		newnode->next=start;
		start=newnode;
	}
}

void insertAtTail(int value){
	//struct node* newnode=new node(value);
	if(tail==NULL){
		insertAtHead(value);
	}
	else{
		struct node* newnode=new node(value);
		newnode->pre=tail;
		tail->next=newnode;
		tail=newnode;
	}
}

int deleteFromHead(){
	struct node* temp;
	if(start==NULL){
		cout<<"UnderFlow\n";
		getch();
		return 0;
	}
	else if(start==tail){
		temp=start;
		start=tail=NULL;
		delete(temp);
	}
	else{
		temp=start;
		start=start->next;
		start->pre=NULL;
		delete(temp);
	}
	return 0;
}

int deleteFromTail(){
	if(tail==NULL || start==tail)
		deleteFromHead();
	else{
		struct node* temp=tail;
		tail=tail->pre;
		tail->next=NULL;
		delete(temp);
	}
	return 0;
}

int main(){
	char op;
	int item;
	init();
	again:
	clrscr();
	cout<<"***********************************\n";
	cout<<"1.Forward Traverse\n";
	cout<<"2.Backward Traverse\n";
	cout<<"3.All Traverse\n";
	cout<<"4.Insert At Head\n";
	cout<<"5.Insert At Tail\n";
	cout<<"6.Delete From Head\n";
	cout<<"7.Delete From Tail\n";
	cout<<"8.Exit\n";
	cout<<"***********************************\n";

	cout<<"Chose any option :";  cin>>op;

	switch(op){
		case '1': //forward traversing
			forwardTraverse();
			getch();
			clrscr();
			goto again;

		case '2': //backward traversing
			backwardTraverse();
			getch();
			clrscr();
			goto again;

		case'3':  //forward and backward traversal
			if(start==NULL && tail==NULL)
				cout<<"UnderFlow\n";
			else
				allTraverse();

			getch();
			clrscr();
			goto again;

		case '4':  //Insert at Head
			cout<<"Enter item :"; cin>>item;
			insertAtHead(item);
			clrscr();
			goto again;

		case '5':  //Insert at Tail
			cout<<"Enter Item : "; cin>>item;
			insertAtTail(item);
			clrscr();
			goto again;

		case '6': //Delete from head
			 deleteFromHead();
			 clrscr();
			 goto again;

		case '7': //Delete from Tail
			deleteFromTail();
			clrscr();
			goto again;
		case'8':   //Exit from program
			clrscr();
			cout<<"\n\n\n\t\tThanks For Using my little program\n";
			getch();
			break;



	}
	return 0;
}