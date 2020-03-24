/*
随机生成方块类SEED，和随机函数srand()
*/
#ifndef _rand_
#define _rand_
#include"diag.h"

clock_t start;

int random(){
	start = clock();
	srand((int)start);
	rand();
	return rand();
}

int random(int x){
	start = clock();
	srand((int)start);
	rand();
	return rand() % (x);
}
int random(int x, int seed){
	srand(seed);
	rand();
	return rand() % (x);
}
class SEED{
public:
	SEED():s(0){}
	//Bag7
	int Bag7(){
		if (s % pieceNUM == 0){
			For(i, 0, pieceNUM - 1) a[i] = i;
			For(i, 1, 3000000){
				int r = random(pieceNUM);
				int l = random(pieceNUM);
				swap(a[l], a[r]);
			}
			/*
			memset(f, 0, sizeof(f));
			int k = 0;
			while (k < pieceNUM){
				int tmp = random(pieceNUM);
				while (f[tmp]) tmp = random(pieceNUM);
				f[tmp] = 1;
				a[k++] = tmp;
			}*/
			s++;
			return a[0];
		}
		else return a[(s++) % pieceNUM];
	}
	//普通随机
	int Normal(){
		return random(pieceNUM);
	}
	private:
		int s;
		int a[pieceNUM*2];
		bool f[pieceNUM*2];
};
#endif