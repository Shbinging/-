/*
时间模块，用于计时和判断是不是要扔下下一个方块
接口如下
Start() 开始计时
is_end()判断是否到时间
Hard()设定难度计算时间
*/
#ifndef _watch_
#define _watch_

#include"diag.h"

class WATCH{
public:
	WATCH(int hard){
		if (hard >= maxLEVEL) return;
		inter = maxLEVEL * 100 - hard * 100;
	}
	int interval(){
		return inter;
	}
	inline bool is_end(){
		end = clock();
		double endtime = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		if (endtime < inter) return 0;
		else return 1;
	}

	inline bool is_end(int t){
		end = clock();
		double endtime = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		if (endtime < t) return 0;
		else return 1;
	}

	inline bool Start(){
		start = clock();
		return 1;
	}

	inline bool Hard(int hard){
		if (hard >= maxLEVEL) return 0;
		inter = maxLEVEL * 100 - hard * 100;
		return 1;
	}
private:
	int inter;
	clock_t start, end;
};
#endif