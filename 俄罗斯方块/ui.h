/*
程序界面
提供一个UI类screen，负责可视化部分
该类通过读取公共地图a来输出
可调用的接口有：
bool:
set_pause():暂停
set_playing()：运行
set_gameover():游戏结束
Score():更新分数
Maxscore():更新最高分
Now():更新当前状态
Next():更新下一个方块
update():刷新屏幕
clear():除了maxscore清空
成功执行返回1
*/
#ifndef _ui_
#define _ui_
#include"diag.h"
#include"watch.h"

class UI:public WATCH{
	void paint(const int a[][aM], int n, int Endl){
		//输出面板第几行,不换行,是否换行(1换)
		For(j, 1, M){
			if (a[n][j] == 0) printf("□");
			if (a[n][j] == 1) printf("■");
		}
		if (Endl) printf("\n");
	}
	void paint(int next, int n){
		//打印下一个
		printf("   ");
		For(j, 0, pieceM - 1){
			if (piece[next][n][j] == 0) printf("□");
			if (piece[next][n][j] == 1) printf("■");
		}
		printf("\n");
	}
public:
	UI(const int tmp[][aM]):WATCH(0),
		score(0),maxscore(0), now(0), hard(0), next(7),a(tmp)
	{
		system("mode con cols=45 lines=23");
		system("title 俄罗斯方块v2.0");
		Start();
	}
	bool clear(){
		score = 0;
		now = 0;
		hard = 0;
		next = 7;
		return 1;
	}
	bool set_pause(){ Now(0); update(); return 1; }
	
	bool set_playing(){ Now(1); update(); return 1;
	}
	
	bool set_gameover(){
		score = -1; return 1; update();
	}

	bool update(){
		//地图a，历史最高分(maxscore)，当前分数(score)，游戏难度(hard)，下一个方块(next)，游戏状态(0pause 1 playing)
		while(!is_end(50)){}
		Start();
		system("cls");
		printf("俄罗斯方块V2.0 2020.2.4\n作者：水兵\n\nEsc:暂停 ↑换方向 ←→左右移 ↓加速 space直降\n\n");
		paint(a, 1, 1);
		paint(a, 2, 0);
		printf("   当前分数：\n");
		paint(a, 3, 0);
		if (score == -1)
			printf("   Game over!\n");
		else printf("   %10d\n", score);
		paint(a, 4, 1);

		paint(a, 5, 0);
		printf("   最高分数：\n");
		paint(a, 6, 0);
		printf("   %10d\n", maxscore);
		paint(a, 7, 1);

		paint(a, 8, 0);
		printf("   级别：\n");
		paint(a, 9, 0);
		printf("   %10d\n", hard);
		paint(a, 10, 1);

		paint(a, 11, 0);
		printf("   下一个：\n");
		paint(a, 12, 0);
		paint(next, 0);
		paint(a, 13, 0);
		paint(next, 1);
		For(i, 14, N) paint(a, i, 1);
		if (!now) printf("pause...\n");
		else printf("playing...\n");
		return 1;
	}

	bool Score(int tmp){
		score = tmp;
		update();
		return 1;
	}

	bool Maxscore(){
		maxscore = max(maxscore,score);
		update();
		return 1;
	}

	bool Hard(int tmp){
		hard = tmp;
		update();
		return 1;
	}

	bool Next(int tmp){
		next = tmp;
		update();
		return 1;
	}

	bool Now(int tmp){
		now = tmp;
		update();
		return 1;
	}

	private:
		int score, maxscore, hard, next, now;
		const int (*const a)[aM];
		//地图a，历史最高分(maxscore)，当前分数(score)，游戏难度(hard)，下一个方块(next)，游戏状态(0pause 1 playing)
};


UI screen(a);
#endif