#include"diag.h"
#include"ui.h"
#include"watch.h"
#include"piece.h"
#include"rand.h"
#include"picture.h"
using namespace std;




bool clear(){//清行
	PIC_TWINKLE pic;
	int s = 0;
	Down(i, N, 1){
		bool f = 1;
		For(j, 1, M){
			if (!a[i][j]) f = 0;
		}
		if (f){
			s++;
			if (i == 1) For(j, 1, M) a[1][j] = 0;
			else{
				Down(k, i, 2)
					For(j, 1, M)
					a[k][j] = a[k - 1][j];
				i++;
			}
		}
	}
	int tmp = (s > 0) ? 1 : 0;
	For(i, 1, s - 1) tmp *= 2;
	score += tmp * 10;
	if (s > 0) return 1;
	else return 0;
}

bool finish(){//检查游戏是否结束
	For(j, 1, M) if (a[1][j] == 1) return 1;
	return 0;
}

int Hard(int score){//升级计算
	return min((score / 10) / 4,maxLEVEL - 1);
}
template<typename T>
void fall(T& pie){
	bool f1(0);
	bool first = 1;
	while (1){
		if (!first){
			pie.fall();
		}
		else first = 0;
		WATCH t(hard);
		t.Start();
		char ch;
		while(!t.is_end()){
			if (_kbhit())
			{
				ch = _getch();
			}
			if (ch == 72){//上键
				sound.up();
				pie.turn();
				//Sleep(300);
			}
			if (ch == 75){//左键
				sound.lr();
				pie.left();
				//Sleep(300);
			}
			if (ch == 77){//右键
				sound.lr();
				pie.right();
				//Sleep(300);
			}
			if (ch == 80){//下键
				sound.lr();
				pie.down();
				Sleep(300);
				if (pie.pump()) break;
			}
			if (ch == 27){//Esc
				sound.lr();
				screen.set_pause();
				while (_kbhit()){ ch = _getch(); }
				printf("任意键继续");
				while (!_kbhit()){}
				while (_kbhit()){ ch = _getch(); }
				sound.lr();
				screen.set_playing();
			}
			if (ch == 32){//空格
				sound.down();
				pie.space();
				f1 = 1;
				break;
			}
			ch = 0;
		}
		if (pie.pump()){
			score += 5;
			if (!f1) sound.down();
			else f1 = 0;
			if (finish()) return;
			if (clear()) Sleep(600);
			screen.Score(score);
			hard = Hard(score);
			screen.Hard(hard);
			break;
		}
	}
}

void fall(int id_now, int tl){
	if (id_now == 0){
		ZERO A(a, tl);
		fall<ZERO>(A);
	}
	if (id_now == 1){
		ONE B(a, tl);
		fall<ONE>(B);
	}
	if (id_now == 2){
		TWO C(a, tl);
		fall<TWO>(C);
	}
	if (id_now == 3){
		THREE D(a, tl);
		fall<THREE>(D);
	}
	if (id_now == 4){
		FOUR E(a, tl);
		fall<FOUR>(E);
	}
	if (id_now == 5){
		FIVE F(a, tl);
		fall<FIVE>(F);
	}
	if (id_now == 6){
		SIX F(a, tl);
		fall<SIX>(F);
	}
}

bool running(){
	screen.set_playing();
	SEED ran;
	int id_now = ran.Bag7();
	Sleep(1000);
	while (1){
		int id_next = ran.Bag7();
		int tl = M/2;
		screen.Next(id_next);
		fall(id_now, tl);
		id_now = id_next;
		if (finish()){
			screen.Maxscore();
			screen.set_gameover();
			break;
		}
	}
	return 1;
}

void ini(){//初始化控制台，面板周围打上-1
	memset(a, 0, sizeof(a));
	For(i, 0, N + 1){
		a[i][0] = -1;
		a[i][M + 1] = -1;
	}
	For(j, 0, M + 1){
		a[0][j] = -1;
		a[N + 1][j] = 1;
	}
	screen.clear();
}

int main(){
	while (1){
		ini();
		char ch;
		screen.set_pause();
		while (_kbhit()){ ch = _getch(); }
		printf("任意键开始:\n");
		while (!_kbhit()){}
		ch = _getch();
		PIC_NEW pic;
		running(); 
		screen.set_pause();
		while (_kbhit()){ ch = _getch(); }
		printf("任意键返回");
		while (!_kbhit()){}
		ch = _getch();
	}
}
