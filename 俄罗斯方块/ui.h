/*
�������
�ṩһ��UI��screen��������ӻ�����
����ͨ����ȡ������ͼa�����
�ɵ��õĽӿ��У�
bool:
set_pause():��ͣ
set_playing()������
set_gameover():��Ϸ����
Score():���·���
Maxscore():������߷�
Now():���µ�ǰ״̬
Next():������һ������
update():ˢ����Ļ
clear():����maxscore���
�ɹ�ִ�з���1
*/
#ifndef _ui_
#define _ui_
#include"diag.h"
#include"watch.h"

class UI:public WATCH{
	void paint(const int a[][aM], int n, int Endl){
		//������ڼ���,������,�Ƿ���(1��)
		For(j, 1, M){
			if (a[n][j] == 0) printf("��");
			if (a[n][j] == 1) printf("��");
		}
		if (Endl) printf("\n");
	}
	void paint(int next, int n){
		//��ӡ��һ��
		printf("   ");
		For(j, 0, pieceM - 1){
			if (piece[next][n][j] == 0) printf("��");
			if (piece[next][n][j] == 1) printf("��");
		}
		printf("\n");
	}
public:
	UI(const int tmp[][aM]):WATCH(0),
		score(0),maxscore(0), now(0), hard(0), next(7),a(tmp)
	{
		system("mode con cols=45 lines=23");
		system("title ����˹����v2.0");
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
		//��ͼa����ʷ��߷�(maxscore)����ǰ����(score)����Ϸ�Ѷ�(hard)����һ������(next)����Ϸ״̬(0pause 1 playing)
		while(!is_end(50)){}
		Start();
		system("cls");
		printf("����˹����V2.0 2020.2.4\n���ߣ�ˮ��\n\nEsc:��ͣ �������� ���������� ������ spaceֱ��\n\n");
		paint(a, 1, 1);
		paint(a, 2, 0);
		printf("   ��ǰ������\n");
		paint(a, 3, 0);
		if (score == -1)
			printf("   Game over!\n");
		else printf("   %10d\n", score);
		paint(a, 4, 1);

		paint(a, 5, 0);
		printf("   ��߷�����\n");
		paint(a, 6, 0);
		printf("   %10d\n", maxscore);
		paint(a, 7, 1);

		paint(a, 8, 0);
		printf("   ����\n");
		paint(a, 9, 0);
		printf("   %10d\n", hard);
		paint(a, 10, 1);

		paint(a, 11, 0);
		printf("   ��һ����\n");
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
		//��ͼa����ʷ��߷�(maxscore)����ǰ����(score)����Ϸ�Ѷ�(hard)����һ������(next)����Ϸ״̬(0pause 1 playing)
};


UI screen(a);
#endif