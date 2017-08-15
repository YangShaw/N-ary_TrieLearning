#pragma once
/*
	c++ͷ�ļ���
	����include���еĿ⣬��������include���ͷ�ļ����඼��������Ӧ�Ŀ⣻
	���Զ���һ������(TEST_1),��������Ϊ���ڴ���ı�ʶ��ifndef��ֹ�ظ����ã�����ͷ�ļ��ж���������࣬�����ķ���
����û��ʵ�֣�����һ���ļ�(Compute)��ʵ�֣�����ʵ�ֵ�ʱ��һ��Ҫ����Compute::myAdd�ı�ʶ��

*/
#include "c++lib.h"
//#ifndef LISTNODE
//#define LISTNODE
//class listNode {
//public:
//	listNode *link;
//	int lineNum;	//�к�
//
//	/*
//		����û��word��������ģ����ǿ��ǵ�ͬһ���ʵĲ�ͬ��Сд���ܻ�ͬʱ���ڣ�����apple��Apple����Ϊ���������ǣ�
//		���Լ���wordʹÿ������ڵ㶼�ܴ洢���ʵġ���ʼ��̬�����кš�
//	*/
//	std::string word;	//����
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
	int lineNum;	//�к�
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
	sortedChain *lineList;	//�洢�кŵ�����
	std::string word;
	wordNode();
	wordNode(std::string theWord);
};
#endif // !WORDNODE


#ifndef SORTEDCHAIN
#define SORTEDCHAIN
//ע�͵��Ĳ�����֮ǰû�и�����ڵ��word������ʱ��ķ�����
class sortedChain{
private:
	int listSize;	//�����ܸ���
	int wordNum;	//��ͬ����ĵ�����
	//std::string word;	//����ĵ���

public:
	listNode *head;		//lineList�������ͷ�ڵ�
	wordNode *wordHead;	//wordList�������ͷ�ڵ�
	sortedChain();
	//sortedChain(std::string theWord);
	int getListSize();		
	void setListSize(int theSize);		
	//std::string getWord();
	void wordInsert(int theLineNum,std::string theWord);
	int listInsert(int theLineNum);	//���뵥��
	int listSearch(std::string theWord);					//��ȷ���ҵ��ʣ����ִ�Сд��,���ز鵽�ĵ�����
	int listEraseWithLine(std::string theWord,int theLineNum);							//�����к�ɾ�����ʣ�����ɾ����
	int listErase(std::string theWord);						//��ȷɾ������
	int listEraseAll();										//ȫɾ������ɾ����
	void listPrint();										//���ȫ������
	
	//void setWord(std::string theWord);
};
#endif // !TRIENODE

#ifndef TRIENODE
#define TRIENODE
class trieNode {
public:
	trieNode *next[28];		//�ӽڵ����飬26����Сд����ĸ��"-","'"�������ܴ����ڵ����е����ӷ�
	//char letter;			//��ǰ�ڵ��Ӧ�ĵ���
	//sortedChain *lineList;	//����������������г���λ�õ��к�	
	sortedChain *wordList;
	trieNode();
	//trieNode(char theLetter);
};
#endif // !TRIENODE

#ifndef TRIE
#define TRIE
class trie {
private:
	//int size;		//���д��˶��ٸ�����
	int isNormal(char curChar);		//������ĸ�Ƿ�Ϸ�����д��ĸ��ӳ�䵽Сд��ĸ��
	//void preSearch(trieNode *cur, bool theFlag);		//ǰ׺����
	void beAWord(std::string *a);			//ɾ������ĩβ���
	void preSearch(trieNode *cur);

public:
	trieNode *root;					//���ڵ�

	trie();
	/*int getSize();
	void setSize(int theSize);*/
	int initialize(std::string path);			//��ʼ�������ؼ���ĵ��ʸ���
	void insert(std::string str, int lineNum);	//��trie���ֶ����뵥��
	void search(std::string str);				//���ҵ��ʣ���Сд�����У�
	void searchAccurately(std::string str);		//���ҵ��ʣ���Сд���У�
	void searchThePre(std::string str);			//��ǰ׺����
	void erase(std::string str);					//ɾ�����ʣ���Сд�����У�
	void eraseWithLine(std::string str, int lineNum);	//ɾ�����ʣ����кţ�
	void eraseAccurately(std::string str);	//ɾ�����ʣ���Сд���У�
	void triePrint();	//��ʾ�����ֵ�

};
#endif // !TRIE



