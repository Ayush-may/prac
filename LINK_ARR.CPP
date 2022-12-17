//Coded By Ayush Sharma
//17-12-2022
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node{
   int info;
   struct node* link;
};

struct node* start=NULL;
struct node* tail=NULL;

int main(){

   char op;
   int item;
   clrscr();


   again:
   cout<<"1.Show All Record\n";
   cout<<"2.Insert a Node at Head\n";
   cout<<"3.Insert a Node from Tail\n";
   cout<<"4.Delete a Node from Head\n";
   cout<<"5.Delete a Node from Tail\n";
   cout<<"6.Exit\n";

   cout<<"\nSelect Option :"; cin>>op;
   switch(op){
     case '1':  //Show all record
	clrscr();
	cout<<"All record :\n";
	{
	  struct node* ptr=start;

	  while(ptr!=NULL){
	      cout<<ptr->info<<" --> ";
	      ptr=ptr->link;
	  }
	  cout<<"NULL\n";
	}
	break;
     case '2':  //Insert at head
      {	struct node* newnode=new node;
	cout<<"\nEnter Item :"; cin>>item;
	newnode->info=item;
	if(start==NULL){
	    start=newnode;
	    tail=newnode;
	    newnode->link=NULL;
	}
	else{
	    newnode->link=start;
	    start=newnode;
	}
	}
	break;
     case '3':  //insert at tail
      { cout<<"Enter item :"; cin>>item;
	struct node* newnode=new node;
//	struct node* ptr=start;

	if(start==NULL){
	   start=newnode;
	   newnode->info=item;
	   newnode->link=NULL;
	   tail=newnode;
	}
	else{
	  tail->link=newnode;
	  newnode->info=item;
	  newnode->link=NULL;
	  tail=newnode;
	}
      }
	break;
     case '4': //Delete from head
      { if(start==NULL){
	   cout<<"UnderFlow\n";
	   getch();
	   clrscr();
	   goto again;
	}
	else{
	struct node* ptr=start;
	start=start->link;
	delete(ptr);
	cout<<"Node is Deleted from Head\n";
	getch();
	}
       }
	break;
     case '5':  //Delete from Tail
	struct node* ptr=start;
	while(ptr->link->link!=NULL){
	   ptr=ptr->link;
	}
	tail=ptr;
	ptr->link=NULL;
	cout<<"Node is Deleted from Tail\n";
	getch();
	break;
     case '6':  //Exit
	clrscr();
	cout<<"\n\n\n\n\t\tThanks for Using my Little program :)\n\t\t\t\t\t\t-Ayush Sharma";
	getch();
	return 0;
     default:
	cout<<"Select a Valid Option\n";
	clrscr();
	goto again;
   }

   cout<<"cont...(y/n) :"; cin>>op;
   if(op=='Y'||op=='y'){
	clrscr();
	goto again;
   }
   else{
	clrscr();
	cout<<"\n\n\n\n\t\tThanks for Using my Little program :)\n\t\t\t\t\t\t-Ayush Sharma";
   }
   getch();
   return 0;
}
