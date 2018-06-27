/*************************************************************************
	> File Name: huffmanCoding.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 27 Jun 2018 03:02:16 PM CST
 ************************************************************************/

/**
 * 把m个字符的出现频率：P1，P2，…，Pm 作为m个权值，构造m个权值的哈夫曼树，按哈夫曼树给出这m个字符的哈夫曼编码。
 * m个权值的赫夫曼树有2m-1个结点，采用数组存储哈夫曼树中的结点，树中的每个结点结构为：
 * w	parent	left	right
 * 其中：w为结点的权值，parent是结点的双亲在数组中的下标，left和right分别是结点的左右孩子在结点数组中的下标。
 * 另外，与每个叶子结点对应字符的编码存放在一个字符数组中，因为编码是不等长的，即每个编码所占用的空间不等，应此存储编码串的空间需动态分配。
 * ****************************************************************************
 * 输入数据格式：
 * 输入的第一行包含一个整数 m，表示字符的个数。接下来m行，每行两个数据，字符和权值，用空格分隔，表示字符和字符的权值。
 * 
 * 输出数据格式：
 * 输出m行，每行两个数据，字符和字符的哈夫曼编码，用空格分隔。
 */

#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H

#include "../../Tools/src/myDefine.c"
/* 额外的定义 */
#define SUCCESS 1
#define FAILED -1
#define CODE_NUM 20			//最多字符数
#define MAX_WEIGHT 32767	//最大权值，代表无穷大

typedef struct{
	int w;
	int parent,left,right;
}Node;
typedef struct{
	char ch;			//字符
	int weight;			//权值
	char *buffmancode;	//指向哈夫曼编码的指针
}HCode;

Status CreatHuffmanCode(HCode code[],int nodenum);	/* 求赫夫曼编码函数 */
void GetTwoNode(Node huffmantree[],int n,int *s1,int *s2); /* 找权值最小的两棵子树函数 */
Status setBuffManCode(char *code,Node node[],int i,const int size,const int nodenum,const int level,int now);		/* 设置第i个值的哈夫曼编码 */
void PrintTree(Node node[],int size);
#endif
