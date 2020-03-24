/*
提供游戏转场动画，音效等
1.消行闪烁
*/
#ifndef _picture_
#define _picture_
#include"diag.h"
#include"ui.h"

class SOUND{
public:
	void lr(){
		PlaySound(TEXT("lr.wav"), 0, SND_ASYNC | SND_NOWAIT| SND_PURGE| SND_RING);
	}
	void down(){
		PlaySound(TEXT("down.wav"), 0, SND_ASYNC | SND_NOWAIT| SND_PURGE| SND_RING);
	}
	void up(){
		PlaySound(TEXT("up.wav"), 0, SND_ASYNC | SND_NOWAIT| SND_PURGE| SND_RING);
	}
	void newer(){
		PlaySound(TEXT("new.wav"), 0, SND_ASYNC | SND_NOWAIT| SND_PURGE| SND_RING);
	}
	void clean(){
		PlaySound(TEXT("clean.wav"), 0, SND_ASYNC | SND_NOWAIT| SND_PURGE| SND_RING);
	}
};
SOUND sound;
class PIC_TWINKLE{
private:
	bool ff[N * 2];
	int check(){//检查是否满行
		int s = 0;
		Down(i, N, 1){
			bool f = 1;
			For(j, 1, M){
				if (!a[i][j]) f = 0;
			}
			if (f){
				s++;
				ff[i] = 1;
			}
		}
		return s;
	}

	bool draw(){//配合twinkle
		For(i, 1, N){
			if (ff[i]){
				For(j, 1, M) a[i][j] = !a[i][j];
			}
		}
		return 1;
	}
public:
	PIC_TWINKLE(){//满行闪烁
		memset(ff, 0, sizeof(ff));
		int s = check();
		if (!s) return;
		sound.clean();
		For(i, 1, twinkleN * 2){
			draw();
			screen.update();
		}
	}
};
class PIC_NEW{
	public:
		bool paint(int n ,int tmp){
			For(j, 1, M) a[n][j] = tmp;
			return 1;
		}
		PIC_NEW(){
			sound.newer();
			For(i, 1, N) paint(i, 0);
			screen.update();
			Sleep(300);
			Down(i, N, 1){
				paint(i, 1);
				screen.update();
				Sleep(70);
			}
			Sleep(300);
			For(i, 1, N) paint(i, 0);
			screen.update();
			Sleep(500);
		}
};
#endif
