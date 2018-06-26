/*************************************************************************
	> File Name: Game.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 26 Jun 2018 02:53:39 PM CST
 ************************************************************************/

#ifndef GAME_C
#define GAME_C

#include "Game.h"

Status initGame(Game *game,FILE *f){	//文件已经打开
	int row,cols,i,j;
	Game p;
	if(!f) return ERROR;
	if(!((*game) = (Game)malloc(sizeof(GAME)))) exit(OVERFLOW);
	p = (*game);
	fscanf(f,"%d",&row);
	fscanf(f,"%d",&cols);
//	printf("row = %d,cols = %d\n",row,cols);	
	if(!(p -> arr = (cell **)malloc(sizeof(cell *)*row))) exit(OVERFLOW);
	for(i = 0;i<row;i++){
		if(!(p -> arr[i] = (cell *)malloc(sizeof(cell)*cols))) exit(OVERFLOW);
		for(j = 0;j<cols;j++){
			fscanf(f,"%d",&(p -> arr[i][j].data));
//			printf("i = %d,j = %d,data = %d\n",i,j,p -> arr[i][j].data);	
			p -> arr[i][j].flag = 0;
		}
	}
	p -> row = row;
	p -> cols = cols;
	return OK;
}

Status runGame(Game game){
	int row,cols,i,j;
	if(!game) exit(OVERFLOW);
	row = game -> row;
	cols = game -> cols;

	printf("---------before runGame---------------\n");
	printGame(game);
	for(i = 0;i<row;i++){
		for(j = 0;j<cols;j++){
			isDelete(game,i,j);
		}
	}
	printf("---------after runGame---------------\n");
	printGame(game);
}

void isDelete(Game game,int row,int cols){	//上下左右
	int data;
	int i,j;
	if(!game) exit(OVERFLOW);
	data = game -> arr[row][cols].data;
	//行判断
	//printf("row = %d,cols =%d\n",row,cols);
	if((cols - 1 >= 0) &&(game -> arr[row][cols-1].data == data)){
		if(((cols -2 >= 0) &&(game -> arr[row][cols-2].data == data)) 
			||((cols+1 < game -> cols)&&(game -> arr[row][cols+1].data == data))){
			game -> arr[row][cols].flag = 1;
			return;
		}
	}else if((cols + 1 < game -> cols)&&(game -> arr[row][cols+1].data == data)){
		if((cols + 2 < game -> cols)&&(game -> arr[row][cols+2].data == data)){
			game -> arr[row][cols].flag = 1;
			return;
		}
	}
	//列判断
	if((row - 1 >= 0) &&(game -> arr[row-1][cols].data == data)){
		if(((row -2 >= 0) &&(game -> arr[row-2][cols].data == data)) 
			||((row+1 < game -> row)&&(game -> arr[row+1][cols].data == data))){
			game -> arr[row][cols].flag = 1;
			return;
		}
	}else if((row + 1 < game -> row)&&(game -> arr[row+1][cols].data == data)){
		if((row + 2 < game -> row)&&(game -> arr[row+2][cols].data == data)){
			game -> arr[row][cols].flag = 1;
			return;
		}
	}
	return;
}

void printGame(Game game){				//打印游戏
	if(!game) exit(OVERFLOW);
	int row = game -> row;
	int cols = game -> cols;
	int i,j;
	for(i = 0;i<row;i++){
		for(j = 0;j<cols;j++){
			if(game -> arr[i][j].flag == 1) printf("0 ");
			else printf("%d ",game -> arr[i][j].data);
		}
		printf("\n");
	}
}
#endif
