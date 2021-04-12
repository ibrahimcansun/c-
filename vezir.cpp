#include <iostream>//cout cin
#include <ctime>//rand

using namespace std;

bool KonumuKontrolEt(char[8][8], int, int);
void SonKonumuBas(char[8][8]);
bool VezirKontrolEt(char[8][8], int, int);

int main(){
	char kaleKonumu[8][8];//satranc tahtam
	int sayac = 0;
	int rastgeleKonumX;
	int rastgeleKonumY;
	
	for(int a=0; a<8; a++){
		for(int b=0; b<8; b++){
			kaleKonumu[a][b] = '*';//bos eleman ataniyor
		}
	}
	srand(time(0));//rastgelelik sagla
	
	while(sayac != 8){
		rastgeleKonumX = rand() % (8);
		rastgeleKonumY = rand() % (8);
		if(KonumuKontrolEt(kaleKonumu, rastgeleKonumY, rastgeleKonumX)||VezirKontrolEt(kaleKonumu,rastgeleKonumX,rastgeleKonumY)){
			//yatayda veya dikeyde bir kale var
		}else{
			kaleKonumu[rastgeleKonumY][rastgeleKonumX] = 'K';
			sayac++;
			cout << endl <<endl << sayac << endl;
			SonKonumuBas(kaleKonumu);
		}
	}
	cin >> sayac;
	return 0;
}

void SonKonumuBas(char kaleKonum[8][8]){
	for(int a=0; a<8; a++){
		for(int b=0; b<8; b++){
			cout << kaleKonum[a][b] << " ";
		}
		cout << endl;
	}
}

bool KonumuKontrolEt(char kaleKonum[8][8], int say, int rastKonum){
	for(int i = 0; i < 8; i++){
		if(kaleKonum[say][i] == 'K'){
			return true;
		}else if(kaleKonum[i][rastKonum] == 'K'){
			return true;
		}
	}
	return false;
}

bool VezirKontrolEt(char vezirKonum[8][8], int konumx, int konumy){
	int x = konumx;
	int y = konumy;
	
	while(x < 8 && y < 8){
		if(vezirKonum[x][y] == 'K'){
			return true;
		}
		x++;
		y++;
	}
	x = konumx;
	y = konumy;
	
	while(x >= 0 && y >= 0){
		if(vezirKonum[x][y] == 'K'){
			return true;
		}
		x--;
		y--;
	}
	x = konumx;
	y = konumy;
	
	while(x >= 0 && y < 8){
		if(vezirKonum[x][y] == 'K'){
			return true;
		}
		x--;
		y++;
	}
	x = konumx;
	y = konumy;
	
	while(x < 8 && y >= 0){
		if(vezirKonum[x][y] == 'K'){
			return true;
		}
		x++;
		y--;
	}
	return false;
}