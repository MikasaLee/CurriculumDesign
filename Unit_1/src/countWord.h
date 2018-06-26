/*************************************************************************
	> File Name: countWord.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 26 Jun 2018 04:10:47 PM CST
 ************************************************************************/

#ifndef COUNTWORD_H
#define COUNTWORD_H

/**
 * 3.2【设计需求及分析】
要统计英文文本文件中出现了哪些单词，就要从文件中读取字符，读取出来的连续英文字符认为是一个单词，遇空格或标点符号单词结束。
使用线性表记录单词以及每个单词出现的次数。线性表中的单词按字典顺序存储。
线性表的顺序存储结构如下：（必须使用如下定义的存储结构，否则无效）
#define LIST_INIT_SIZE 100    //线性表存储空间的初始分配量
#define LISTINCREMENT 10      //线性表存储空间的分配增量
typedef struct{
    char word[21]             //存储单词，不超过20个字符
    int count;                //单词出现的次数
} ElemType;                   //顺序表元素类型
typedef struct{
    ElemType *elem;           //存储空间基址
    int length;               //当前长度
int listsize;             //当前分配的存储容量
    } Seqlist;                    //顺序表类型
3.3【功能设计】
3.3.1 实现顺序表的基本操作（必须使用下面给定的函数名和参数表，否则无效）
⑴顺序表的初始化：InitList(SqList &L)
⑵顺序表上查找指定的单词：LocateElem(SqList &L,char *s)
  若找到，单词的出现次数增1，返回0，否则返回该单词的插入位置。
⑶在顺序表上插入新的单词：InsertList(SqList &L,int i，char *s) 
要求按字典顺序有序。新单词的出现次数为1。
⑷输出顺序表上存储的单词统计信息：PrintList(SqList &L)
  输出文件中每个单词出现的次数以及文件中总的单词数(可输出到文件中)。
3.3.2 统计单词数
统计过程如下：
（1）输入要统计单词的文本文件名，打开相应的文件；
（2）初始化顺序表；
（3）从文本文件中读取字符，直到文件结束。具体描述如下：
while (读文件没有结束结束)
{
       过滤单词前的非字母字符；
       读取一个单词，以字符串形式存储在一个字符数组中；
       在线性表中查找该单词，若找到，单词的出现次数加1，否则返回其插入位置；
       上一步中，若没找到，则进行插入操作；
       处理下一个单词。
}
（4）关闭文件，输出统计结果。
 */
#include "../../Tools/src/myDefine.c"

#define LIST_INIT_SIZE 10   //线性表存储空间的初始分配量
#define LISTINCREMENT 10      //线性表存储空间的分配增量

#ifndef ELEMTYPE
#define ELEMTYPE
typedef struct{
    char word[21];             //存储单词，不超过20个字符
    int count;                //单词出现的次数
}ElemType;          //顺序表元素类型
#endif

typedef struct{
    ElemType* elem;           //存储空间基址
    int length;              //当前长度
	int listsize;            //当前分配的存储容量
}sqList,*SqList;            //顺序表类型


Status InitList(SqList *L);	 //顺序表的初始化
int LocateElem(SqList L,char *s);	//顺序表上查找指定的单词,若找到，单词的出现次数增1，返回0，否则返回该单词的插入位置
Status InsertList(SqList L,int i,char *s);	//在顺序表上插入新的单词,要求按字典顺序有序。新单词的出现次数为1
void check(char word[]);			//对word进行修饰
void PrintList(SqList L);			//输出顺序表上存储的单词统计信息,输出文件中每个单词出现的次数以及文件中总的单词数(可输出到文件中)。

Status run(SqList L,FILE *f);

#endif
