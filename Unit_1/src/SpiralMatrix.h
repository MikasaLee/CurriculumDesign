/*************************************************************************
	> File Name: SpiralMatrix.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 25 Jun 2018 02:56:43 PM CST
 ************************************************************************/

/**
 * 1.	螺旋矩阵
 * 1.1【问题描述】
 * 输出下面的n（3≤n≤19）阶螺旋矩阵。输入n（=10），输出如下左图所示的螺旋矩阵。输入-n（=-10），输出如下右图所示的螺旋矩阵。
 * (左图)
 * 1   2   3   4   5   6   7   8   9  10
 * 36  37  38  39  40  41  42  43  44  11
 * 35  64  65  66  67  68  69  70  45  12
 * 34  63  84  85  86  87  88  71  46  13
 * 33  62  83  96  97  98  89  72  47  14
 * 32  61  82  95 100  99  90  73  48  15
 * 31  60  81  94  93  92  91  74  49  16
 * 30  59  80  79  78  77  76  75  50  17
 * 29  58  57  56  55  54  53  52  51  18
 * 28  27  26  25  24  23  22  21  20  19	
 *
 * (右图)
 *	1  36  35  34  33  32  31  30  29  28
 *	2  37  64  63  62  61  60  59  58  27
 *	3  38  65  84  83  82  81  80  57  26
 *	4  39  66  85  96  95  94  79  56  25
 *	5  40  67  86  97 100  93  78  55  24
 *	6  41  68  87  98  99  92  77  54  23
 *	7  42  69  88  89  90  91  76  53  22
 *	8  43  70  71  72  73  74  75  52  21
 *	9  44  45  46  47  48  49  50  51  20
 *	10  11  12  13  14   15  16  17  18  19
 *	
 *
 *	输入格式
 *	输入一个整数n或（-n），n表示要输出螺旋矩阵的阶数。
 *	输出格式
 *	输出右旋或左旋n阶螺旋矩阵。
 */

#ifndef SPIRALMATRIX_H
#define SPIRALMATRIX_H

#include "../../Tools/src/myDefine.c"

typedef struct{
	int data;		//存放值

	int row;		//行号
	int cols;		//列号
	int flag;		//该位置是否有值
}cell,*Cell;

typedef struct{
	cell **Matrix;

	int size;		//Matrix的阶数
}sMatrix,*SMatrix;

Status SpirMatrix(int n);			//n为输入的整数
Status InitMatrix(SMatrix *matrix,int n);
Status Clockwise(SMatrix matrix,int n);	//顺时针输出|n|阶
Status Eastern(SMatrix matrix,int n);		//逆时针输出|n|阶
int nextWise(SMatrix matrix,int *row,int *cols,int direct);		//根据当前direct来返回下一步的方向
int nextEast(SMatrix matrix,int *row,int *cols,int direct);		//根据当前direct来返回下一步的方向
void Print(SMatrix matrix,int n);

#endif
