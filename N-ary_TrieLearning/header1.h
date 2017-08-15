#pragma once
/*
	c++头文件：
	可以include现有的库，这样所有include这个头文件的类都会引用相应的库；
	可以定义一个名字(TEST_1),仅用来作为其内代码的标识，ifndef防止重复引用；如在头文件中定义了这个类，这个类的方法
可以没有实现，在另一个文件(Compute)中实现，但是实现的时候一定要加上Compute::myAdd的标识；

*/
#include "c++lib.h"
//#ifndef LISTNODE
//#define LISTNODE
//class listNode {
//public:
//	listNode *link;
//	int lineNum;	//行号
//
//	/*
//		本来没有word这个变量的，但是考虑到同一单词的不同大小写可能会同时存在（比如apple和Apple），为了区分他们，
//		所以加入word使每个链表节点都能存储单词的“初始形态”和行号。
//	*/
//	std::string word;	//单词
//	listNode();
//	listNode(int theLineNum);
//	listNode(int theLineNum, listNode *theLink);
//};
//#endif // !LISTNODE
class sortedChain;
#ifndef LISTNODE
#define LISTNODE
class listNode {
public:
	listNode *link;
	int lineNum;	//行号
	listNode();
	listNode(int theLineNum);
	listNode(int theLineNum, listNode *theLink);
};
#endif // !LISTNODE

#ifndef WORDNODE
#define WORDNODE
class wordNode {
public:
	wordNode *wordLink;
	sortedChain *lineList;	//存储行号的链表
	std::string word;
	wordNode();
	wordNode(std::string theWord);
};
#endif // !WORDNODE


#ifndef SORTEDCHAIN
#define SORTEDCHAIN
//注释掉的部分是之前没有给链表节点加word变量的时候的方法。
class sortedChain{
private:
	int listSize;	//单词总个数
	int wordNum;	//不同种类的单词数
	//std::string word;	//保存的单词

public:
	listNode *head;		//lineList中用这个头节点
	wordNode *wordHead;	//wordList中用这个头节点
	sortedChain();
	//sortedChain(std::string theWord);
	int getListSize();		
	void setListSize(int theSize);		
	//std::string getWord();
	void wordInsert(int theLineNum,std::string theWord);
	int listInsert(int theLineNum);	//插入单词
	int listSearch(std::string theWord);					//精确查找单词（区分大小写）,返回查到的单词数
	int listEraseWithLine(std::string theWord,int theLineNum);							//按照行号删除单词，返回删除数
	int listErase(std::string theWord);						//精确删除单词
	int listEraseAll();										//全删，返回删除数
	void listPrint();										//输出全部单词
	
	//void setWord(std::string theWord);
};
#endif // !TRIENODE

#ifndef TRIENODE
#define TRIENODE
class trieNode {
public:
	trieNode *next[28];		//子节点数组，26个（小写）字母和"-","'"两个可能存在于单词中的连接符
	//char letter;			//当前节点对应的单词
	//sortedChain *lineList;	//用来存这个单词所有出现位置的行号	
	sortedChain *wordList;
	trieNode();
	//trieNode(char theLetter);
};
#endif // !TRIENODE

#ifndef TRIE
#define TRIE
class trie {
private:
	//int size;		//树中存了多少个单词
	int isNormal(char curChar);		//检验字母是否合法，大写字母会映射到小写字母上
	//void preSearch(trieNode *cur, bool theFlag);		//前缀查找
	void beAWord(std::string *a);			//删除单词末尾标点
	void preSearch(trieNode *cur);

public:
	trieNode *root;					//根节点

	trie();
	/*int getSize();
	void setSize(int theSize);*/
	int initialize(std::string path);			//初始化，返回加入的单词个数
	void insert(std::string str, int lineNum);	//向trie中手动插入单词
	void search(std::string str);				//查找单词（大小写不敏感）
	void searchAccurately(std::string str);		//查找单词（大小写敏感）
	void searchThePre(std::string str);			//按前缀查找
	void erase(std::string str);					//删除单词（大小写不敏感）
	void eraseWithLine(std::string str, int lineNum);	//删除单词（按行号）
	void eraseAccurately(std::string str);	//删除单词（大小写敏感）
	void triePrint();	//表示整个字典

};
#endif // !TRIE



