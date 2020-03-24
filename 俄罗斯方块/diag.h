//copyright 水兵 2020.2.4
#ifndef _diag_
#define _diag_
#include <stdlib.h>
#include <windows.h>
#include<thread>
/*
头文件，各种常量和公共空间
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
const int N = 15;//地图行
const int M = 10;//地图列
/*const char B = '□';
const char H = '■';*/
const int aN = 30;//数组行
const int aM = 20;//数组列
const int piece[8][2][4] = { {{0,1,0,0},{1,1,1,0}},{{1,1,0,0},{1,1,0,0}},{{1,0,0,0},{1,1,1,0}},{{1,1,0,0},{0,1,1,0}},{{0,1,1,0},{1,1,0,0}},{{1,1,1,1},{0,0,0,0}},{{0,0,1,0},{1,1,1,0}},{{0,0,0,0},{0,0,0,0}} };//各个方块形状
const int pieceN = 2;//方块行
const int pieceM = 4;//方块列
const int goH[8] = { -1,-1,0,1,1,1,0,-1 };//用于形状计算
const int goL[8] = { 0,1,1,1,0,-1,-1,-1 };//用于形状计算
const int pieceNUM = 7;//方块数
const int maxLEVEL = 15;//最大等级
int score = 0, hard = 0;
int a[aN][aM];
const int twinkleN = 3;
#endif