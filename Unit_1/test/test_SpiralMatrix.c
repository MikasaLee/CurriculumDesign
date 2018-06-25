/*************************************************************************
	> File Name: test_SpiralMatrix.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 25 Jun 2018 04:31:23 PM CST
 ************************************************************************/

#ifndef TEST_SPIRALMATRIX_C
#define TEST_SPIRALMATRIX_C

#include "../src/SpiralMatrix.c"

int main(int argc,char **agrv){

	int n;
	printf("please input Number:");
	scanf("%d",&n);
	SpirMatrix(n);
	return 0;
}

#endif
