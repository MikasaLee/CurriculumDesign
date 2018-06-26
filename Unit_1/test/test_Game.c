/*************************************************************************
	> File Name: test_Game.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 26 Jun 2018 03:25:32 PM CST
 ************************************************************************/

#include "../src/Game.c"

int main(int argc,char **argv){

	FILE *f;
	Game game;
	if((f = fopen("../src/Game_data2","r")) == NULL){	//测试文件1为Game_data1
		printf("File Not Found!\n");
	}
	if(initGame(&game,f)){
		runGame(game);	
	}else{
		printf("InitGame ERROR!\n");
	}
	fclose(f);
	return 0;
}
