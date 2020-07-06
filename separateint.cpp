#include <iostream>//cout cin
/*
EN
author: ibrahim cansun
date: 06.07.2020
purpose: i will take a number from user then number digits will separate with this program.

TR
yazan: ibrahim cansun
tarih: 06.07.2020
amac: kullanicinin girdigi sayiyi basamaklarina ayiran programi yazmak
*/
using namespace std;//standard

void separateDigits(int);
int isNegative(int);

int main()
{
	int numb;//EN the numb is integer, not float. TR sayi tam sayi olacak
	cout << "Hi, please enter integer :";
	cin >> numb;//EN user can enter float (e.g. 5.25) but it will be int. TR kullanici tam sayi girebilir ama sayi tam sayi olarak kullanilacak
	numb = isNegative(numb);
	separateDigits(numb);
	isZero(numb);
	return 0;
}

int isNegative(int num)//EN number will be positive. TR sayi pozitif olacak
{
	if(num<0){num = -num;}
	return num;
}

void isZero(int num)//EN if number is zero. TR sayi sifirsa
{
	if(num==0){cout << "0" << endl;}//EN separateDigits function does not calculate 0. TR separateDigits fonksiyonu 0 sayisini hesaplayamiyor
}
void separateDigits(int num)//EN numb digits will separate with this function. TR sayinin basamaklari fonksiyon sayesinde ayrilicak
{
	int lengh = 1;//EN local variable. TR yerel degisken
	for(lengh; lengh <= num; lengh*=10)//EN when number's length is end, other for loop will separate. TR sayinin uzunlugunu buluyor, diger for dongusude sayiyi ayiriyor
	{
		if(lengh * 10 > num)//EN if(not else if) loop will be over, program will separate. TR eger dongu bitecek olursa, sayiyi ayirmaya haziriz demektir
		{
			for(int a = lengh; a >= 1; a/=10)//EN separating. TR ayriliyor
			{
				cout << (num / a) % 10 << endl;
			}
		}
	}
}

