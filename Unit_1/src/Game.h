/*************************************************************************
	> File Name: Game.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 25 Jun 2018 06:02:41 PM CST
 ************************************************************************/

/**
 * 2.	消除类游戏
 * 2.1【问题描述】
 * 消除类游戏是深受大众欢迎的一种游戏，游戏在一个包含有n行m列的游戏棋盘上进行，棋盘的每一行每一列的方格上放着一个有颜色的棋子，当一行或一列上有连续三个或更多的相同颜色的棋子时，这些棋子都被消除。当有多处可以被消除时，这些地方的棋子将同时被消除。
 * 2.2【基本要求】
 * 现在给你一个n行m列的棋盘(1≤n,m≤30)，棋盘中的每一个方格上有一个棋子，请给出经过一次消除后的棋盘。
 * 请注意：一个棋子可能在某一行和某一列同时被消除。
 * 输入数据格式：
 * 输入的第一行包含两个整数n, m，用空格分隔，分别表示棋盘的行数和列数。接下来n行，每行m个整数，用空格分隔，分别表示每一个方格中的棋子的颜色。颜色使用1至9编号。
 * 输出数据格式：
 * 输出n行，每行m个整数，相邻的整数之间使用一个空格分隔，表示经过一次消除后的棋盘。如果一个方格中的棋子被消除，则对应的方格输出0，否则输出棋子的颜色编号。
 *
 */

#ifndef GAME_H
#define GAME_H

#include "../../Tools/src/myDefine.c"


typedef struct{
	int data;
	int flag;	//是否消除,0表示不消除，1表示消除
}cell;			//简单点，就不用指针了

typedef struct{
	int row;		//行数
	int cols;		//列数
	
	cell **arr;
}GAME,*Game;

Status initGame(Game *game,FILE *f);	//从文件f中来初始化Game
Status runGame(Game game);				//开始消除一次
void isDelete(Game game,int row,int cols);	//判断[row,cols]位置是否需要删除
void printGame(Game game);				//打印游戏

#endif
