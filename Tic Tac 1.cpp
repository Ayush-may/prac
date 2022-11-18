
//TIC TAC GAME , PRACTICE JHEHHEHEHEHE

#include<iostream>
#include<stdlib.h>
using namespace std;

//bool running=true;
//choice for the matrix 
char c[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;
char turn = 'X';
bool draw=false;

void border(){
	
	system("cls"); //works like clrscr() in turbo
	
	cout<<"\t      WELCOME TO TIC TAC GAME\n";
	cout<<"\n\t\tPlayer 1- [X]\n\t\tPlayer 2- [O]\n\n";
	
	
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<c[0][0]<<"  |  "<<c[0][1]<<"  |   "<<c[0][2]<<"     "<<endl;
	cout<<"\t\t_____|_____|_____"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<c[1][0]<<"  |  "<<c[1][1]<<"  |   "<<c[1][2]<<"     "<<endl;
	cout<<"\t\t_____|_____|_____"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<c[2][0]<<"  |  "<<c[2][1]<<"  |   "<<c[2][2]<<"     "<<endl;
	cout<<"\t\t     |     |     "<<endl;	
	
	
}

bool gameOver(){

	//if someone wins
	for(int i=0;i<3;i++){
		if( c[i][0] == c[i][1] && c[i][0] == c[i][2] || c[0][i] == c[1][i] && c[0][i] == c[2][i] ){
			return false;
		}
	}
	
	//This checks Diagonally 
	if( c[0][0] == c[1][1] && c[0][0] == c[2][2] || c[0][2] == c[1][1] && c[0][2] == c[2][0] )
		return false;
	
	//if there is still some steps to go
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(c[i][j] !='X' && c[i][j] !='O' )	{
			//cout<<"this will execute"<<endl;
			return true;	
			
			}
		}
	}
	
	//if no one wins
	draw=true;
	return false;
	
}

/* //cheching stuffs
void check(){
	
	//this is check who win the game 
	//left to right     ---------->
	if( c[0][0] == 'X' && c[0][1] == 'X' && c[0][2] == 'X' ){
		win();
		return;	
	}
	else if( c[1][0] == 'X' && c[1][1] == 'X' && c[1][2] == 'X' ){
		win();
		return;
	}
	else if( c[2][0] == 'X' && c[2][1] == 'X' && c[2][2] == 'X' ){
		win();
		return;
	}
		
	//up to down
	if( c[0][0] == 'X' && c[1][0] == 'X' && c[2][0] == 'X' ){
		win();
		return;	
	}
	else if( c[0][1] == 'X' && c[1][1] == 'X' && c[2][1] == 'X' ){
		win();
		return;
	}
	else if( c[0][2] == 'X' && c[1][2] == 'X' && c[2][2] == 'X' ){
		win();
		return;
	}
	
	//Diagonally
	if( c[0][0] == 'X' && c[1][1] == 'X' && c[2][2] == 'X' ){
		win();
		return;	
	}
	else if( c[0][2] == 'X' && c[1][1] == 'X' && c[2][0] == 'X' ){
		win();
		return;
	}	

}
*/

void player(){
	
	char choice;
	
	if(turn=='X'){
	 	cout<<"\n\tPLAYER [X] turn :";  
		cin>>choice;
	}	
	else{
		cout<<"\n\tPLAYER [O] turn :";  
		cin>>choice;
	}
	
	switch(choice){
		case '1' : row=0 ; col=0 ; break;
		case '2' : row=0 ; col=1 ; break;
		case '3' : row=0 ; col=2 ; break;
		case '4' : row=1 ; col=0 ; break;
		case '5' : row=1 ; col=1 ; break;
		case '6' : row=1 ; col=2 ; break;
		case '7' : row=2 ; col=0 ; break;
		case '8' : row=2 ; col=1 ; break;
		case '9' : row=2 ; col=2 ; break;
		
			default:
				cout<<"\tENTER A VALID OPTION\n";			
				return;
	}
	
	if(turn=='X' && c[row][col]!='X' && c[row][col]!='O' ){
		c[row][col]='X';
		turn='O';
	}
	else if( turn=='O' && c[row][col]!='X' && c[row][col]!='O'  ){
		c[row][col]='O';
		turn='X';
	}
	else{
		cout<<"\n    BOX IS ALREADY FILLED!\n    Choose Another Option\n\n";
		system("pause");
	}
	
		border();
}



int main(){
	
	while(gameOver()){
		border();
		player();
		gameOver();
  }
  if( turn=='X' && draw==false ){
  	cout<<"\n\n\tPlayer2 [O]...Wins the Game!!\n\tCongratulation..!!!\n\n";
 	cout<<"\t"<<system("pause"); 
  }
  else if( turn=='O' && draw==false ){
  	cout<<"\n\n\tPlayer1 [X]...Wins the Game!!\n\tCongratulation..!!!\n\n";
 	cout<<"\t"<<system("pause");
  }
  else{
  	cout<<"\n\n\tMatch is Draw\n\tPlay Again...?\n\n";
  	cout<<"\t"<<system("pause");
  }
  
}