//如果是把这个完全定义在这个cpp里而不是在头文件里，那么就不能include头文件，否则会出现重定义错误。
#include "header1.h"
trieNode::trieNode() {
	//this->exist = 0;
	for (int i = 0; i < 28; i++) {
		this->next[i] = NULL;	//手动置为空，否则无法通过NULL来判断出来
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
//	sortedChain *lineList;	//用来存这个单词所有出现位置的行号	
//	//字母编码貌似必须用字母映射到编号上。从而才能在1时间内找到这个节点。
//	trieNode() {
//		this->exist = 0;
//		for (int i = 0; i < 26; i++) {
//			this->next[i] = NULL;	//手动置为空，否则无法通过NULL来判断出来
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
//	//	next = new trieNode[charSize];	//只是声明了数组大小，但是每一个trieNode都没有初始化，需要用到的时候初始化
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
	


