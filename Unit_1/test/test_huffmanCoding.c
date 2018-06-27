/*************************************************************************
	> File Name: test_huffmanCoding.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 27 Jun 2018 03:26:36 PM CST
 ************************************************************************/

/**
 * 测试代码和数据均由题目给出
 * 测试数据：
 *	输入：
 *	8
 *	a 12
 *	b 23
 *	c 9
 *	d 2
 *	e 27
 *	f 6
 *	g 15
 *	h 5	
 *	输出：
 *	a 001
 *	b 01
 *	c 000
 *	d 11010
 *	e 10
 *	f 1100
 *	g 111
 *	h 11011
 *
 */

#include "../src/huffmanCoding.c"

int main(int argc,char *argv){
	int i,nodenum;
	HCode node[CODE_NUM];			/*定义数组，存储字符、权值和哈夫曼编码*/
	printf("please input nodenum:");
	scanf("%d",&nodenum);			/*输入字符个数*/
	printf("please input char & weight:");
	for(i=0;i<nodenum;i++)			/*输入字符和权值*/
		scanf("%*c%c%*c%d",&node[i].ch,&node[i].weight);
	CreatHuffmanCode(node,nodenum);	/*求哈夫曼编码*/
	for(i=0;i<nodenum;i++)			/*输出字符及其哈夫曼编码*/
		printf("%c  %s\n",node[i].ch,node[i].buffmancode);

	return 0;
}

