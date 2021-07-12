#include <stdio.h>
#include <stdlib.h>

const int sinir = 512;// EN maximum number

void NumbPrintToScreen(int, int[]);
void SortLargeToSmallDirect(int, int[]);

int main(){
	int sayiAdet;
	int sayilar[sinir];
	
	printf("Kac sayi gireceksiniz: ");
	scanf("%d", &sayiAdet);
	printf("%d adet sayi giriniz", sayiAdet);
	
	if(sayiAdet > sinir){
		printf("\nGirdiginiz deger sinirdan buyuk.\nSinir: %d", sinir);
		exit(0);
	}
	
	for(int i = 0; i < sayiAdet; i++){
		printf("\n%d. sayiyi giriniz: ", i+1);
		scanf("%d", &sayilar[i]);
	}
	
	SortLargeToSmallDirect(sayiAdet, sayilar);
	NumbPrintToScreen(sayiAdet, sayilar);
	return 0;
}

void NumbPrintToScreen(int counting, int numbs[]){
	for(int x = 0; x < counting; x++){
		printf("\n%d. eleman: %d", x+1, numbs[x]);
	}
}

void SortLargeToSmallDirect(int counting, int numbs[]){
	int hafiza;
	
	for(int j = 0; j < counting; j++){
		for(int k = j+1; k < counting; k++){
			if(numbs[j] < numbs[k]){
				hafiza = numbs[k];
				numbs[k] = numbs[j];
				numbs[j] = hafiza;
			}
		}
	}
}