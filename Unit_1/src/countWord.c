/*************************************************************************
	> File Name: countWord.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 26 Jun 2018 04:20:39 PM CST
 ************************************************************************/

#ifndef COUNTWORD_C
#define COUNTWORD_C

#include "./countWord.h"
Status InitList(SqList *L){
	SqList p;
	if(!((*L) = (SqList)malloc(sizeof(sqList)))) exit(OVERFLOW);
	p = *L;
	if(!(p -> elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE))) exit(OVERFLOW);
	p -> listsize = LIST_INIT_SIZE;
	p -> length = 0;
	return OK;
}

int LocateElem(SqList L,char *s){
	if(!L) exit(OVERFLOW);
	int curor,i;
	for(curor = 0;curor < L -> length;curor++){
		for(i = 0;(s[i] != '\0')&&(L -> elem[curor].word[i] != '\0')&&(i<21);i++){
			if(s[i] - L -> elem[curor].word[i] > 0) break;
			else if(s[i] - L -> elem[curor].word[i] < 0) return curor+1;	//返回插入位置
		}
		if((s[i] == '\0') && (L -> elem[curor].word[i] == '\0')){	//found
			++(L -> elem[curor].count);
			return 0;
		}
		if(s[i] == '\0') return curor+1;
	}
	return curor+1;
}

Status InsertList(SqList L,int i,char *s){
	ElemType *temp;
	if(!L) exit(OVERFLOW);
	int j;
	if(i < 1 || i > L -> length + 1) return ERROR;
	if(L -> listsize <= L -> length+1){
		temp = (ElemType *)realloc(L -> elem,sizeof(ElemType)*(L -> listsize+=LISTINCREMENT));
		L -> elem = temp;
	}
	for(j = L -> length;j>=i;j--)
		L -> elem[j] = L -> elem[j-1];
	for(j = 0;s[j]!='\0';j++) L -> elem[i-1].word[j]=s[j];
	L -> elem[i-1].word[j] = '\0';
	L -> elem[i-1].count = 1;
	L -> length++;

	return OK;
}

void check(char word[]){
	int i,j;
	i = j =0;
	while(word[i]!='\0'){ 
		if((word[i]>='a' && word[i]<='z')||(word[i] >= 'A' && word[i] <= 'Z'))
			word[j++]=word[i];
		i++;
	}
	word[j] = '\0';
	return;
}

void PrintList(SqList L){
	if(!L) exit(OVERFLOW);
	int i;
	printf("-------------------------------------\n");
	printf("length=%d,listsize=%d\n",L ->length,L -> listsize);
	for(i = 0;i<L -> length;i++){
		printf("word=%s, count=%d\n",L -> elem[i].word,L -> elem[i].count);
	}
	return;
}


Status run(SqList L,FILE *f){
	char word[21];
	int i;
	if(!L) exit(OVERFLOW);

	while(fscanf(f,"%s",&word) != EOF){
		//还缺一步，修饰word。
		check(word);
		if(word[0] == '\0') continue;
		i = LocateElem(L,word);
//		printf("i=%d\n",i);
		if(i != 0) InsertList(L,i,word);
	}

	PrintList(L);
	return OK;
}

#endif
