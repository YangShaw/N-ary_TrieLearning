//����ǰ������ȫ���������cpp���������ͷ�ļ����ô�Ͳ���includeͷ�ļ������������ض������
#include "header1.h"
trieNode::trieNode() {
	//this->exist = 0;
	for (int i = 0; i < 28; i++) {
		this->next[i] = NULL;	//�ֶ���Ϊ�գ������޷�ͨ��NULL���жϳ���
	}
	//letter = '?';
	//lineList = new sortedChain();
	wordList = new sortedChain();
	wordList->wordHead = new wordNode();
}

//trieNode::trieNode(char theLetter) {
//	//this->exist = 0;
//	for (int i = 0; i < 26; i++) {
//		this->next[i] = NULL;
//	}
//	letter = theLetter;
//	lineList = new sortedChain();
//}

//class trieNode {
//public:
//	trieNode *next[26];
//	char letter;
//	sortedChain *lineList;	//����������������г���λ�õ��к�	
//	//��ĸ����ò�Ʊ�������ĸӳ�䵽����ϡ��Ӷ�������1ʱ�����ҵ�����ڵ㡣
//	trieNode() {
//		this->exist = 0;
//		for (int i = 0; i < 26; i++) {
//			this->next[i] = NULL;	//�ֶ���Ϊ�գ������޷�ͨ��NULL���жϳ���
//		}
//		letter = '?';
//		lineList = NULL;
//	}
//
//	trieNode(char theLetter) {
//		this->exist = 0;
//		for (int i = 0; i < 26; i++) {
//			this->next[i] = NULL;
//		}
//		letter = theLetter;
//		lineList = NULL;
//	}
//	
//
//	//trieNode(int charSize) {
//	//	this->exist = 0;
//	//	next = new trieNode[charSize];	//ֻ�������������С������ÿһ��trieNode��û�г�ʼ������Ҫ�õ���ʱ���ʼ��
//	//}
//
//	int getExist() {
//		return exist;
//	}
//	void setExist(int exist) {
//		this->exist = exist;
//	}
//
//private:
//	int exist;
//};
	


