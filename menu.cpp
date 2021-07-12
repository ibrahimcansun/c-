/*
*	owner: ibrahim cansun
*	date: 21.09.2020
*	purpose: i will make a basic menu
*/

#include <iostream>//cout cin library

using namespace std;//standard namespace

void CallMenu(string[], int);//declaration

const int maxMsg = 3;//how many message will show to user
string msgs[maxMsg] = {"Call ibrahim", "Call Cansu", "Call Cansun"};//what will program show

int main(){
	CallMenu(msgs, maxMsg);//calling function
	
	return 0;
}

void CallMenu(string msg[], int msgNum){
	for(int i = 0; i < msgNum; i++){
		cout << i+1 << "-" << msg[i] << endl;//program will write messages.
		//1-bla bla
		//2-flip flop
		//.....
	}
}