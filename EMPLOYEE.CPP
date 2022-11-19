//teach by Surjeet sir in VITM(Vikrant group of institute and Management )!!
//code by Ayush Sharma 2nd year student 

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;

char number[20];

struct employee{
 char num[20],name[20],comp[10];
 float slry;
};

main(){
  system("cls");
  employee e;
  FILE* fp,*fp1;
  int i;
  char choice,yes_no;

  ram:

  cout<<"\n1. SHOW ALL RECORD\n";
  cout<<"2. INSERT A NEW RECORD\n";
  cout<<"3. DELETE EXISTING RECORD\n";
  cout<<"4. UPDATE EXISTING RECORD\n";
  cout<<"5. EXIT\n\n";
  cout<<"select option :"; cin>>choice;

  switch(choice){

   case '1':
	fp=fopen("Employ.txt","r");
	 cout<<"EMPLOY NAME	     "<<"EMPLOY NUM	     "<<"EMPLOY SALARY	     "<<"EMPLOY COMPY NAME"<<endl;

	 while( fread(&e,sizeof(e),1,fp)>0){

	  cout<<e.name<<"			"<<e.num<<"		      "<<e.slry<<"		      "<<e.comp<<endl;
	}

	 fclose(fp);
	cout<<"do u want to cont...(y/n) :"; cin>>yes_no;

	if(yes_no=='y'||yes_no=='Y'){
  	 system("cls");
	 goto ram;
	}
	else {
	break;
	}

   case '2':
	fp=fopen("employ.txt","a");

	 cout<<"ENTER NAME :"; cin>>e.name;
	 cout<<"ENTER COMPANY NAME :"; cin>>e.comp;
	 cout<<"ENTER NUMBER :"; cin>>e.num;
	 cout<<"ENTER SALARY :"; cin>>e.slry;
	 fwrite(&e,sizeof(e),1,fp);

	 fclose(fp);

       cout<<"do u want to cont...(y/n) :"; cin>>yes_no;
       if(yes_no=='y'||'Y'){
       system("cls");
       goto ram;
       }
       else{
	break;
       }

   case '3':  //delete a existing record

	cout<<"ENTER THE NUMBER OF EMPLOY TO DELETE :"; cin>>number;

	fp=fopen("employ.txt","r");
	fp1=fopen("temp.txt","w");

	while(fread(&e,sizeof(e),1,fp)>0){

	 if(strcmp(e.num,number)!=0){
	    fwrite(&e,sizeof(e),1,fp1);
	 }
	}

	fclose(fp); fclose(fp1);

       remove("employ.txt");
       rename("temp.txt","employ.txt");

       cout<<"do u want to cont...(y/n) :"; cin>>yes_no;
       if(yes_no=='y'||'Y'){
         system("cls");
       goto ram;
       }
       else{
	break;
       }

   case '4':  //Update a existing record

       cout<<"Enter the Number to Update :"; cin>>number;

       fp=fopen("employ.txt","r");
       fp1=fopen("temp.txt","w");

       while(fread(&e,sizeof(e),1,fp)>0){

	 if(strcmp(number,e.name)==0){

	 cout<<"ENTER NAME :";         cin>>e.name;
	 cout<<"ENTER COMPANY NAME :"; cin>>e.comp;
	 cout<<"ENTER NUMBER :";       cin>>e.num;
	 cout<<"ENTER SALARY :";       cin>>e.slry;
	// fwrite(&e,sizeof(e),1,fp1);

	 }
	 fwrite(&e,sizeof(e),1,fp1);
       }
       fclose(fp); fclose(fp1);
       remove("employ.txt");
       rename("temp.txt","employ.txt");

       cout<<"do u want to cont...(y/n) :"; cin>>yes_no;
       if(yes_no=='y'||'Y'){
         system("cls");
       goto ram;
       }
       else{
	break;
	}

     case '5': 		//Exit 

		cout<<"\n\t\tThanks to Surjeet Sir for teaching us how to make this program..!!\n";
		cout<<"\t\t"<<system("pause");
		break;
   
   default:

     cout<<"Enter a Valid Option\n";

     cout<<"do u want to cont...(y/n) :"; cin>>yes_no;
       if(yes_no=='y'||'Y'){
         system("cls");
       goto ram;
       }
       else{
	break;
       }

	}    //switch end
 getch();
}











