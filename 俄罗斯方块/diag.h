//copyright ˮ�� 2020.2.4
#ifndef _diag_
#define _diag_
#include <stdlib.h>
#include <windows.h>
#include<thread>
/*
ͷ�ļ������ֳ����͹����ռ�
*/
#include <conio.h>
#include<stdio.h>
#include<string>
#include <cstdlib>
#include <ctime>
#include<ctime>
#include<cstdlib>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >=l; i--)
const int N = 15;//��ͼ��
const int M = 10;//��ͼ��
/*const char B = '��';
const char H = '��';*/
const int aN = 30;//������
const int aM = 20;//������
const int piece[8][2][4] = { {{0,1,0,0},{1,1,1,0}},{{1,1,0,0},{1,1,0,0}},{{1,0,0,0},{1,1,1,0}},{{1,1,0,0},{0,1,1,0}},{{0,1,1,0},{1,1,0,0}},{{1,1,1,1},{0,0,0,0}},{{0,0,1,0},{1,1,1,0}},{{0,0,0,0},{0,0,0,0}} };//����������״
const int pieceN = 2;//������
const int pieceM = 4;//������
const int goH[8] = { -1,-1,0,1,1,1,0,-1 };//������״����
const int goL[8] = { 0,1,1,1,0,-1,-1,-1 };//������״����
const int pieceNUM = 7;//������
const int maxLEVEL = 15;//���ȼ�
int score = 0, hard = 0;
int a[aN][aM];
const int twinkleN = 3;
#endif