/*************************************************************************
	> File Name: test_Game.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 26 Jun 2018 03:25:32 PM CST
 ************************************************************************/

#include "../src/countWord.c"

int main(int argc,char **argv){

	FILE *f;
	SqList L;
	if((f = fopen("../src/countWord_data","r")) == NULL){
		printf("File Not Found!\n");
		return ERROR;
	}
	if(InitList(&L)){
		run(L,f);
	}else{
		printf("InitList ERROR!\n");
	}
	fclose(f);
	return 0;
}
