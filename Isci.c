#include <stdio.h>

int calisanSayisi;

void GetString(char*);

int main(){
	FILE *fp;
	char* bilgi;
	char buff[255];
	
	printf("\nCalisan sayisi: ");
	scanf("%d", &calisanSayisi);
	
	fp = fopen("calisanListesi.txt", "w+");
	
	for(int i = 1; i <= calisanSayisi; i++){
		printf("%d. calisanin bilgilerini giriniz", i);
		
		printf("\nad: ");
		GetString(buff);
		fputs(buff,fp);
		
		fputs("\t",fp);
		
		printf("soyad: ");
		GetString(buff);
		fputs(buff,fp);

		fputs(" ",fp);
		
		printf("dogum yili: ");
		GetString(buff);
		fputs(buff,fp);

		fputs(" ",fp);
		
		printf("tel no: ");
		GetString(buff);
		fputs(buff,fp);
		
		fputs("\n",fp);
	}
	fclose(fp);
	
	return 0;
}

void GetString(char* str){
	do{
		gets(str);
	}while(str[0] == '\0');
}