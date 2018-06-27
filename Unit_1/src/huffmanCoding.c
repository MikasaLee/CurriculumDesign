/*************************************************************************
	> File Name: huffmanCoding.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 27 Jun 2018 03:24:43 PM CST
 ************************************************************************/

#ifndef HUFFMANCODING_C
#define HUFFMANCODING_C

#include "./huffmanCoding.h"

Status CreatHuffmanCode(HCode code[],int nodenum){/*求赫夫曼编码函数*/
	int i,temp,k;
	const int size = 2*nodenum-1;
	Node node[size];
	int s1,s2;			//权值最小的两棵树
	char *tempCode;
	/** ---------------------初始化二叉树--------------------------------**/
	//将HCODE数据复制到Node中
	for(i = 0;i<nodenum;i++){
		node[i].w = code[i].weight;
		node[i].parent = node[i].left = node[i].right = -1;
	}
	//将剩下的槽位都设置成无穷大
	for(i=nodenum;i<2*nodenum-1;i++){
		node[i].w = MAX_WEIGHT;
		node[i].parent = node[i].left = node[i].right = -1;
	}

	/** ---------------------建立二叉树--------------------------------**/
	for(i = 0;i<nodenum-1;i++){			//这里偷个懒，因为n个数需要构建成哈夫曼树一定是n-1次
		GetTwoNode(node,size,&s1,&s2);
		//第i次，其存放的节点是nodenum+i;
		temp = nodenum+i;
		//设置新节点
		node[temp].w = node[s1].w + node[s2].w;
		node[temp].left = s1;
		node[temp].right = s2;
		//废除旧节点;
		node[s1].w = node[s2].w = MAX_WEIGHT;
		node[s1].parent = node[s2].parent = temp;
	}
	PrintTree(node,size);
	
	/** ---------------------获得编码--------------------------------**/
	k = nodenum;
	i = 0;
	while(k != 0){
		k/=2;
		++i;
	}
	k = i + 1;		//n个字符其哈夫曼编码长度最多为k,+1是为了'\0'
	for(i = 0;i<nodenum;i++){
		//第i次，其存放的节点是nodenum+i;
		if(!(tempCode = (char *)malloc(sizeof(char)*k))) exit(OVERFLOW);			
		if(!setBuffManCode(tempCode,node,i,size,nodenum,0,size-1)) return ERROR;	//从根开始遍历
		code[i].buffmancode = tempCode;
	}
	return OK;
}


Status setBuffManCode(char *code,Node node[],int i,const int size,const nodenum,int level,int now){		/* 设置第i个值的哈夫曼编码 */
	if(now != i && (now < nodenum - 1)) return ERROR;
	if(now != i){
		if(node[now].left != -1){
			code[level] = '0';
			if(setBuffManCode(code,node,i,size,nodenum,level+1,node[now].left)) return OK;
		}
		if(node[now].right != -1){
			code[level] = '1';
			if(setBuffManCode(code,node,i,size,nodenum,level+1,node[now].right)) return OK;
		}
	}
	if(now == i){
		code[level] = '\0';
		return OK;
	}
//	printf("\nsetBuffManCode ERROR!\n\t ERROR：No.%d not found!,now=%d\n",i,now);
	return ERROR;
}



void GetTwoNode(Node huffmantree[],int n,int *s1,int *s2){/*找权值最小的两棵子树函数，并且是s1的权值小于s2*/
	int i,min1,min2;
	min1 = 0;
	min2 = 1;
	for(i = 1;i<n;i++){
		if(huffmantree[i].w == MAX_WEIGHT || huffmantree[i].w > huffmantree[min2].w) continue;
		else{
			if(huffmantree[i].w < huffmantree[min1].w){
				min2 = min1;
				min1 = i;
			}else if(huffmantree[i].w < huffmantree[min2].w){
				min2 = i;
			}
		}
	}
	(*s1) = min1;
	(*s2) = min2;
	return;
}

void PrintTree(Node node[],int size){
	int i;
	for(i = 0;i<size;i++){
		printf("No.%d:\n\tw = %d,parent = %d,left = %d,right = %d\n",i,node[i].w,node[i].parent,node[i].left,node[i].right);
	}
}

#endif
