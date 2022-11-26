#include<iostream>
#include<time.h>
#include<thread>
#include<chrono>
using namespace std;

int main(){
	
	srand(time(0));
	
	string key="1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+{}:<>?/.,;'][-]";
	int key_size=91;
	string word="hello world";
	string hello_world="";
	int i=0;
	while(word!=hello_world){
		system("pause");
		while(true){
			char safe = key[rand()%key_size];
			if( word[i]==safe){
				hello_world+=safe;	
				cout<<hello_world<<endl;	 
				i++;
				std::this_thread::sleep_for(std::chrono::milliseconds(10));  //for delay in output
			}

			if( i==word.size()  ) {
				cout<<"\n\nYEAAAAAAAAAAAAAAAHHHH THIS WORKSSSSS XD \n";
				system("pause");
				break;	
			}
			
			if(word[i]!=safe  ){
				cout<<hello_world<<safe<<endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(10)); 
			}
			
		
		}
	}	
	
}


//	std::this_thread::sleep_for(std::chrono::milliseconds(10));  //for delay in output