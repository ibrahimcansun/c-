#include <iostream>
/*
 *			SAKARYA UNIVERSITESI
 *		BILGISAYAR VE BILISIM BILIMLERI
 *				FAKULTESI
 *		   BILGISAYAR MUHENDISLIGI
 *		ALGORITMA ANALIZI VE TASARIMI DERSI
 *			LCS ALGORITMASI KODU
 *
 *	author:	ibrahim cansun
 *	date:	22.04.2021
*/
using namespace std;

const short tabloBoyutu = 20;//size of matrix, you can change it to your need

void MatriseDikeyAta(short [tabloBoyutu][tabloBoyutu], string, short);
void MatriseYatayAta(short [tabloBoyutu][tabloBoyutu], string, short);
void MatrisiBas(short [tabloBoyutu][tabloBoyutu], short, short);
void LCS(short [tabloBoyutu][tabloBoyutu], short, short);

int main(){
	string katar1, katar2;//i will compare both of them
	
	short tablo[tabloBoyutu][tabloBoyutu] = {0};
	
	cout << "Merhaba, katarlari sirasi ile giriniz!\t(katar uzunlugu 20yi gecemez)\nkatar1: ";
	cin >> katar1;
	cout << "katar2: ";
	cin >> katar2;
	MatriseYatayAta(tablo, katar1, 0);
	MatriseDikeyAta(tablo, katar2, 0);
	
	MatrisiBas(tablo, katar1.length()+1, katar2.length()+1);
	LCS(tablo, katar1.length(), katar2.length());
	cout << endl << endl;
	MatrisiBas(tablo, katar1.length()+1, katar2.length()+1);
	return 0;
}

//declaring column
void MatriseDikeyAta(short matris[tabloBoyutu][tabloBoyutu], string katar, short dikey){
	for(int j = 0; j < katar.length(); j++){
		matris[j+2][dikey] = katar[j];
	}
}

//declaring line
void MatriseYatayAta(short matris[tabloBoyutu][tabloBoyutu], string katar, short yatay){
	for(int i = 0; i < katar.length(); i++){
		matris[yatay][i+2] = katar[i];
	}
}

//printing matrix
void MatrisiBas(short matris[tabloBoyutu][tabloBoyutu], short dikey, short yatay){
	for(int i = 0; i <= yatay; i++){
		for(int j = 0; j <= dikey; j++){
			if(j == 0 || i == 0){
				cout << (char) matris[i][j] << "\t";
			}else{
				cout << matris[i][j] << "\t";
			}
		}
		cout << endl;
	}
}

void LCS (short matris[tabloBoyutu][tabloBoyutu], short yatay, short dikey){
	for(int j = 2; j < 2+dikey; j++){
		for(int i = 2; i < 2+yatay; i++){
			if(matris[0][i] == matris[j][0]){//equal characters. example: d=d
				matris[j][i] = matris[j-1][i-1] + 1;
			}else{
				if(matris[j-1][i] > matris[j][i-1]){//which one is bigger than other
					matris[j][i] = matris[j-1][i];
				}else{
					matris[j][i] = matris[j][i-1];
				}
			}
		}
	}
}