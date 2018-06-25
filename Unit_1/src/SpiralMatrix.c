/*************************************************************************
	> File Name: SpiralMatrix.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 25 Jun 2018 03:07:58 PM CST
 ************************************************************************/

#ifndef SPIRALMATRIX_C
#define SPIRALMATRIX_C

#include "./SpiralMatrix.h"
#include "math.h"

Status SpirMatrix(int n){			//n为输入的整数
	SMatrix matrix;
	if(n == 0){
		printf("0阶的输出为空！\n");
		return OK;
	}
	if(!InitMatrix(&matrix,n)) exit(OVERFLOW);
	n > 0?Clockwise(matrix,n):Eastern(matrix,-n);
	
	Print(matrix,n);
	return OK;
}

Status InitMatrix(SMatrix *matrix,int n){
	SMatrix p;
	int i,j;
	if(n < 0) n = -n;
	if(*matrix) free(matrix);
	if(!((*matrix) = (SMatrix)malloc(sizeof(sMatrix)))) exit(OVERFLOW);
	p = *matrix;
	if(!(p -> Matrix = (cell **)malloc(sizeof(cell *)*n))) exit(OVERFLOW);
	for(i = 0;i<n;i++){
		if(!(p -> Matrix[i] = (cell *)malloc(sizeof(cell)*n))) exit(OVERFLOW);
		for(j = 0;j<n;j++){
			p -> Matrix[i][j].flag = 0;
			p -> Matrix[i][j].row = i;
			p -> Matrix[i][j].cols = j;
		}
	}
	p -> size = n;
	return OK;
}

int nextWise(SMatrix matrix,int *row,int *cols,int direct){		//根据当前direct来返回下一步的方向
	if(!matrix) return -1;
	int n = matrix -> size;
	switch(direct){
		case 0:		//Right
		if(((*cols)+1 != n) && (matrix -> Matrix[*row][(*cols)+1].flag == 0)) ++(*cols);
		else { direct = 1; ++(*row);}
		return direct;

		case 1:		//Down
		if(((*row)+1 != n) && (matrix -> Matrix[(*row)+1][*cols].flag == 0)) ++(*row);
		else{ direct = 2; --(*cols);}
		return direct;

		case 2:	//Left
		if(((*cols)-1 != -1) &&(matrix -> Matrix[*row][(*cols)-1].flag == 0)) --(*cols);
		else{ direct = 3; --(*row);}
		return direct;

		case 3: 	//Up;
		if(((*row)-1 != -1) && (matrix -> Matrix[(*row)-1][*cols].flag == 0)) --(*row);
		else{ direct = 0; ++(*cols);}
		return direct;

		default: printf("Direct ERROR!\n");return ERROR;
	}
}
int nextEast(SMatrix matrix,int *row,int *cols,int direct){		//根据当前direct来返回下一步的方向
	if(!matrix) return -1;
	int n = matrix -> size;
	switch(direct){
		case 1:		//Right
		if(((*cols)+1 != n) && (matrix -> Matrix[*row][(*cols)+1].flag == 0)) ++(*cols);
		else { direct = 2; --(*row);}
		return direct;

		case 0:		//Down
		if(((*row)+1 != n) && (matrix -> Matrix[(*row)+1][*cols].flag == 0)) ++(*row);
		else{ direct = 1; ++(*cols);}
		return direct;

		case 3:	//Left
		if(((*cols)-1 != -1) &&(matrix -> Matrix[*row][(*cols)-1].flag == 0)) --(*cols);
		else{ direct = 0; ++(*row);}
		return direct;

		case 2: 	//Up;
		if(((*row)-1 != -1) && (matrix -> Matrix[(*row)-1][*cols].flag == 0)) --(*row);
		else{ direct = 3; --(*cols);}
		return direct;

		default: printf("Direct ERROR!\n");return ERROR;
	}
}

Status Clockwise(SMatrix matrix,int n){
	if(!matrix) return ERROR;
	int i = 1,row,cols;
	row = cols = 0;
	int direct = 0;	
	const int size = n*n;
	while(i <= size){
		//设置好当前位置的值
		matrix -> Matrix[row][cols].data = i++;
		matrix -> Matrix[row][cols].flag = 1;

		//为下一个值做准备
		direct = nextWise(matrix,&row,&cols,direct);
	}
}

Status Eastern(SMatrix matrix,int n){
	if(!matrix) return ERROR;
	int i = 1,row,cols;
	row = cols = 0;
	int direct = 0;	
	const int size = n*n;
	while(i <= size){
		//设置好当前位置的值
		matrix -> Matrix[row][cols].data = i++;
		matrix -> Matrix[row][cols].flag = 1;

		//为下一个值做准备
		direct = nextEast(matrix,&row,&cols,direct);
	}
}
void Print(SMatrix matrix,int n){
	if(n < 0) n = -n;
	if(!matrix) return;
	int i,j;
	for(i = 0;i<n;i++){
		for(j = 0;j<n;j++)
			printf("%2d ",matrix -> Matrix[i][j].data);
		printf("\n");
	}
	return;
}


#endif
