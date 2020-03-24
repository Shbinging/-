/*
1.�ṩ���ַ���Ķ���ά��
����ΪZERO ONE TWO THREE FOUR FIVE
�ֱ��Ӧ������״�ķ���
����̳��ڻ���base
base����ά�����������ƽ��,�Լ��ڵ�ͼ�ϵĻ���,��Ļ��ˢ��
���ฺ��ά�������������״����ת
���õĽӿ��У�
bool��
down()����
left()����
right()����
turn()��ת
�ɹ�ִ�з���1

*/
#ifndef _piece_
#define _piece_

#include"diag.h"
#include"ui.h"



class base{
protected:
	inline bool can_turn(){
		//��ⷽ���ڵ�ǰλ���ܷ���ת���ܷ���1�����ܷ���0
		int h1 = h, l1 = l;
		if (a[h1][l1] != 0) return 0;
		For(i, 0, 7){
			int th = h1, tl = l1;
			For(j, 1, image[i]){
				th += goH[i];
				tl += goL[i];
				if (a[th][tl] != 0) return 0;
			}
		}
		return 1;
	}

	inline bool draw(){
		//����������ڵ�ͼ�ϣ�����Ӧ����1
		a[h][l] = 1;
		For(i, 0, 7){
			int th = h, tl = l;
			For(j, 1, image[i]){
				th += goH[i];
				tl += goL[i];
				a[th][tl] = 1;
			}
		}
		return 1;
	}
	inline bool erase(){
		//������ӵ�ͼ�ϲ�ȥ������Ӧ����1
		a[h][l] = 0;
		For(i, 0, 7){
			int th = h, tl = l;
			For(j, 1, image[i]){
				th += goH[i];
				tl += goL[i];
				a[th][tl] = 0;
			}
		}
		return 1;
	}
public:
	inline bool inner_down(int tmp){
		//���ݷ�������һ�������·���1���������·���0(���ܵ�������������Լ�������������)
		erase();
		int h1 = h + 1, l1 = l;
		bool f = 1;
		if (a[h1][l1] != 0) f = 0;
		For(i, 0, 7){
			int th = h1, tl = l1;
			For(j, 1, image[i]){
				th += goH[i];
				tl += goL[i];
				if (a[th][tl] != 0) f = 0;
			}
		}
		if (f) h++;
		draw();
		if (f&&tmp) screen.update();
		return f;
	}
	inline bool down(){
		bool f = inner_down(1);
		if (!f) return 0;
		f = inner_down(1);
		screen.update();
		return f;
	}
	inline bool fall(){
		return(inner_down(1));
	}
	inline bool space(){
		while (!pump()){ inner_down(0); }
		screen.update();
		erase();
		screen.update();
		draw();
		screen.update();
		return 1;
	}
	inline bool left(){
		//���ݷ�������һ�������󷵻�1���������󷵻�0(���ܵ�����������߽��Լ�������������)
		erase();
		bool f = 1;
		int h1 = h, l1 = l - 1;
		if (a[h1][l1] != 0) f = 0;
		For(i, 0, 7){
			int th = h1, tl = l1;
			For(j, 1, image[i]){
				th += goH[i];
				tl += goL[i];
				if (a[th][tl] != 0) f = 0;
			}
		}
		if (f) l--;
		draw();
		if (f) screen.update();
		return f;
	}
	inline bool right(){
		//���ݷ�������һ�������ҷ���1���������ҷ���0(���ܵ�����������߽��Լ�������������)
		erase();
		bool f = 1;
		int h1 = h, l1 = l + 1;
		if (a[h1][l1] != 0) f = 0;
		For(i, 0, 7){
			int th = h1, tl = l1;
			For(j, 1, image[i]){
				th += goH[i];
				tl += goL[i];
				if (a[th][tl] != 0) f = 0;
			}
		}
		if (f) l++;
		draw();
		if (f) screen.update();
		return f;
	}
	inline bool pump(){
		//�ж��Ƿ����´����������飬��������1��û�д�������0
		erase();
		bool flag = 0;
		if (a[h + 1][l] == 1) flag = 1;
		For(i, 0, 7){
			int th = h, tl = l;
			For(j, 1, image[i]){
				th += goH[i];
				tl += goL[i];
				if (a[th+1][tl] == 1) flag = 1;
			}
		}
		draw();
		return flag;
	}

protected:
	int image[8];//�±귽��ֵΪ�����ϼ���
	int h, l;//�к���
	int (*a)[aM];
};

class ZERO :public base{
public:
	ZERO(int tmp[][aM], int tl):base(){
		a = tmp;
		image[0] = 1;
		image[1] = 0;
		image[2] = 1;
		image[3] = 0;
		image[4] = 0;
		image[5] = 0;
		image[6] = 1;
		image[7] = 0;
		h = 2;
		l = tl;
		if (tl == 1) l++;
		if (tl == M) l--;
		draw();
		screen.update();
	}
	inline void turnr(){
		For(k, 1, 2){
			int tmp = image[7];
			Down(i, 7, 1) image[i] = image[i - 1];
			image[0] = tmp;
		}
	}
	inline void turnl(){
		For(k, 1, 2){
			int tmp = image[0];
			For(i, 0, 6) image[i] = image[i + 1];
			image[7] = tmp;
		}
	}
	inline bool turn(){
		erase();
		turnr();
		if (!can_turn()){
			turnl();
			draw();
			return 0;
		}
		turnl();
		erase();
		turnr();
		draw();
		screen.update();
	}
};

class ONE :public base{
public:
	ONE(int tmp[][aM], int tl) :base(){
		a = tmp;
		image[0] = 0;
		image[1] = 0;
		image[2] = 1;
		image[3] = 1;
		image[4] = 1;
		image[5] = 0;
		image[6] = 0;
		image[7] = 0;
		h = 1;
		l = tl;
		if (tl == M) l--;
		draw();
		screen.update();
	}

	inline bool turn(){
		return 0;
	}
};

class TWO :public base{
public:
	TWO(int tmp[][aM], int tl) {
		a = tmp;
		image[0] = 0;
		image[1] = 0;
		image[2] = 1;
		image[3] = 0;
		image[4] = 0;
		image[5] = 0;
		image[6] = 1;
		image[7] = 1;
		h = 2;
		l = tl;
		if (tl == 1) l++;
		if (tl == M) l--;
		draw();
		screen.update();
	}
	inline void turnr(){
		For(k, 1, 2){
			int tmp = image[7];
			Down(i, 7, 1) image[i] = image[i - 1];
			image[0] = tmp;
		}
	}
	inline void turnl(){
		For(k, 1, 2){
			int tmp = image[0];
			For(i, 0, 6) image[i] = image[i + 1];
			image[7] = tmp;
		}
	}
	inline bool turn(){
		erase();
		turnr();
		if (!can_turn()){
			turnl();
			draw();
			return 0;
		}
		turnl();
		erase();
		turnr();
		draw();
		screen.update();
	}
};

class THREE :public base{
public:
	THREE(int tmp[][aM], int tl) :fx(0)
	{
		a = tmp;
		image[0] = 1;
		image[1] = 0;
		image[2] = 1;
		image[3] = 0;
		image[4] = 0;
		image[5] = 0;
		image[6] = 0;
		image[7] = 1;
		h = 2;
		l = tl;
		if (tl == 1) l++;
		if (tl == M) l--;
		draw();
		screen.update();
	}
	inline void turnr(){
		For(k, 1, 2){
			int tmp = image[7];
			Down(i, 7, 1) image[i] = image[i - 1];
			image[0] = tmp;
		}
	}
	inline void turnl(){
		For(k, 1, 2){
			int tmp = image[0];
			For(i, 0, 6) image[i] = image[i + 1];
			image[7] = tmp;
		}
	}
	inline bool turn(){
		erase();
		if (!fx){
			turnl();
			if (!can_turn()){
				turnr();
				draw();
				return 0;
			}
			fx = !fx;
			turnr();
			erase();
			turnl();
			draw();
			screen.update();
		}
		else{
			turnr();
			if (!can_turn()){
				turnl();
				draw();
				return 0;
			}
			fx = !fx;
			turnl();
			erase();
			turnr();
			draw();
			screen.update();
		}
	}
private:
	bool fx;
};

class FOUR :public base{
public:
	FOUR(int tmp[][aM], int tl) :fx(1)
	{
		a = tmp;
		image[0] = 1;
		image[1] = 1;
		image[2] = 0;
		image[3] = 0;
		image[4] = 0;
		image[5] = 0;
		image[6] = 1;
		image[7] = 0;
		h = 2;
		l = tl;
		if (tl == 1) l++;
		if (tl == M) l--;
		draw();
		screen.update();
	}
	inline void turnr(){
		For(k, 1, 2){
			int tmp = image[7];
			Down(i, 7, 1) image[i] = image[i - 1];
			image[0] = tmp;
		}
	}
	inline void turnl(){
		For(k, 1, 2){
			int tmp = image[0];
			For(i, 0, 6) image[i] = image[i + 1];
			image[7] = tmp;
		}
	}
	inline bool turn(){
		erase();
		if (!fx){
			turnl();
			if (!can_turn()){
				turnr();
				draw();
				return 0;
			}
			fx = !fx;
			turnr();
			erase();
			turnl();
			draw();
			screen.update();
		}
		else{
			turnr();
			if (!can_turn()){
				turnl();
				draw();
				return 0;
			}
			fx = !fx;
			turnl();
			erase();
			turnr();
			draw();
			screen.update();
		}
	}
private:
	bool fx;
};

class FIVE :public base{
public:
	FIVE(int tmp[][aM], int tl) :fx(1)//1��2��
	{
		a = tmp;
		image[0] = 0;
		image[1] = 0;
		image[2] = 2;
		image[3] = 0;
		image[4] = 0;
		image[5] = 0;
		image[6] = 1;
		image[7] = 0;
		h = 1;
		l = tl;
		if (tl == 1) l++;
		if (tl >= M - 1) l = M - 2;
		draw();
		screen.update();
	}
	inline void turnr(){
		For(k, 1, 2){
			int tmp = image[7];
			Down(i, 7, 1) image[i] = image[i - 1];
			image[0] = tmp;
		}
	}
	inline void turnl(){
		For(k, 1, 2){
			int tmp = image[0];
			For(i, 0, 6) image[i] = image[i + 1];
			image[7] = tmp;
		}
	}
	inline bool turn(){
		erase();
		if (!fx){
			turnl();
			if (!can_turn()){
				turnr();
				draw();
				return 0;
			}
			fx = !fx;
			turnr();
			erase();
			turnl();
			draw();
			screen.update();
		}
		else{
			turnr();
			if (!can_turn()){
				turnl();
				draw();
				return 0;
			}
			fx = !fx;
			turnl();
			erase();
			turnr();
			draw();
			screen.update();
		}
	}
private:
	bool fx;
};
class SIX :public base{
public:
	SIX(int tmp[][aM], int tl) {
		a = tmp;
		image[0] = 0;
		image[1] = 1;
		image[2] = 1;
		image[3] = 0;
		image[4] = 0;
		image[5] = 0;
		image[6] = 1;
		image[7] = 0;
		h = 2;
		l = tl;
		if (tl == 1) l++;
		if (tl == M) l--;
		draw();
		screen.update();
	}
	inline void turnr(){
		For(k, 1, 2){
			int tmp = image[7];
			Down(i, 7, 1) image[i] = image[i - 1];
			image[0] = tmp;
		}
	}
	inline void turnl(){
		For(k, 1, 2){
			int tmp = image[0];
			For(i, 0, 6) image[i] = image[i + 1];
			image[7] = tmp;
		}
	}
	inline bool turn(){
		erase();
		turnr();
		if (!can_turn()){
			turnl();
			draw();
			return 0;
		}
		turnl();
		erase();
		turnr();
		draw();
		screen.update();
	}
};
#endif