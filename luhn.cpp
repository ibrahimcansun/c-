#include <iostream>//cout cin
/*
EN
author: ibrahim cansun
date: 15.09.2021
purpose: i will check credit cards with this program.
TR
yazan: ibrahim cansun
tarih: 15.09.2021
amac: program kredi kartlarini kontrol edecek.
*/
using namespace std;//standard

const int cc = 16;//cc has 16 numbers

void NumbersToNums(int, string, int[]);

int main(){
	string ccnumbers;
	int ccnums[cc];
	int i = 0;
	int result = 0;
	
	do{
		cout << "Please write your cc numbers: ";
		cin >> ccnumbers;
	}while(ccnumbers.length() != cc);
	
	NumbersToNums(cc, ccnumbers, ccnums);//changing
	
	while(i < 16){
		if(i%2 == 0){
			ccnums[i] = ccnums[i] * 2;
			if(ccnums[i] > 9){
				ccnums[i] -= 9;
			}
		}
		result += ccnums[i];
		i++;
	}
	
	if(result % 10 == 0){
		cout << "Your credit card is acceptable.";
	}else{
		cout << "Something wrong!";
	}
	
	return 0;
}

void NumbersToNums(int cc, string ccnumbers, int ccnums[]){
	//credit card cc=16, convert numbers to int
	for(int a = 0; a < cc; a++){
		ccnums[a] = ((int)ccnumbers[a])-48;
	}
}
