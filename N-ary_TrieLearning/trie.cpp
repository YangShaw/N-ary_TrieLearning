#include "header1.h"
#include <fstream>
#include <sstream>
using namespace std;

/*
trie的实现类
对于每一份文件，new一个trie对象，初始化是把文件中的单词全部插入；插入；查询；删除；
*/

//ascii码转化为数组index
int trie::isNormal(char curChar) {
	//如果是大写字母，转化为对应的小写字母。
	int curInt = -1;
	if (curChar >= 65 && curChar <= 90) {
		curChar = curChar + 32;
	}
	if (curChar == 45) {
		curInt = 26;
		return curInt;
	}
	else if (curChar == 39) {
		curInt = 27;
		return curInt;
	}
	
	else {
		curInt = curChar - 97;

		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
		if (curInt < 0 || curInt >= 26) {
			return -1;
		}
		else {
			return curInt;
		}
	}
}

void trie::preSearch(trieNode *cur) {
	if (cur->wordList->getListSize()>0) {
		cur->wordList->listPrint();
	}
	for (int i = 0; i < 28; i++) {
		if (cur->next[i] != NULL) {
			preSearch(cur->next[i]);
		}
	}
}



void trie::beAWord(string *a) {
	//去除单词末尾的标点符号
	int i = a->length();
	while (i) {
		string s = a->substr(i - 1, 1);
		if (s == "?" || s == "." || s == "," || s == "!" || s == "/" || s == ":" || s == ";" ) {
			string b = a->substr(0, i - 1);
			*a = b;
			i--;
		}
		else
			break;
	}
}



trie::trie() {
	root = new trieNode();
}


//初始化，对每一行都读单词，分别插入
int trie::initialize(string path) {
	ifstream fin(path);
	int lineNum = 1;
	int count = 0;
	string theLine;
	while (getline(fin, theLine)) {
		stringstream ss(theLine);
		string word;
		while (ss >> word) {
			insert(word, lineNum);
			count++;
		}
		lineNum++;
	}
	return count;
}

//插入特定单词。必须有行号.修改完毕！
void trie::insert(string str, int lineNum) {
	beAWord(&str);
	int length = str.length();
	trieNode *cur = root;
	for (int i = 0; i < length; i++) {
		//按顺序从单词中一个一个取字母
		char curChar = str.at(i);

		//找出对应的数字
		int curInt = isNormal(curChar);

		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}

		else {
			if (cur->next[curInt] != NULL) {
				//cur = cur->next[curInt];
			}
			else {
				cur->next[curInt] = new trieNode();
				//cur = cur->next[curInt];
			}
			cur = cur->next[curInt];
		}
	}
	//插入完以后，cur应该是在最后一个字母处的
	//两个特殊的符号不会影响原本的str，所以存入链表的应该没啥问题。
	cur->wordList->wordInsert(lineNum, str);
}

//查找以这个单词为前缀的所有单词（包括本身）。修改完毕！
void trie::searchThePre(string str) {
	int length = str.length();
	trieNode *cur = root;
	//原理与插入大致相同
	for (int i = 0; i < length; i++) {
		//按顺序从单词中一个一个取字母
		char curChar = str.at(i);

		//找出对应的数字
		int curInt = isNormal(curChar);

		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//找到最后一位的时候，如果有对象，说明这里被经过过，也就是有这个单词。否则就是没找到。
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//没找到直接返回
			}
		}
	}
	//如果有截止到这里的单词，那么先输出一下
	//然后看看以这个为前缀的单词，前缀为str，cur为这个前缀的结尾。由于当前的已经被输出了，所以传入参数true，
	//防止被重复输出
	preSearch(cur);
}

//仅查找这个单词本身,大小写不区分。修改完成
void trie::search(string str) {
	int length = str.length();
	trieNode *cur = root;
	//原理与插入大致相同
	for (int i = 0; i < length; i++) {
		//按顺序从单词中一个一个取字母
		char curChar = str.at(i);

		//找出对应的数字
		int curInt = isNormal(curChar);

		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//找到最后一位的时候，如果有对象，说明这里被经过过，也就是有这个单词。否则就是没找到。
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//没找到直接返回
			}
		}
	}
	//如果有截止到这里的单词，那么先输出一下
	if (cur->wordList->getListSize() != 0) {
		cur->wordList->listPrint();
	}
	else {
		cout << str << " cannot be found!" << endl;
	}
}

//区分大小写的准确查找。修改完成
void trie::searchAccurately(string str) {
	int length = str.length();
	trieNode *cur = root;
	//原理与插入大致相同
	for (int i = 0; i < length; i++) {
		//按顺序从单词中一个一个取字母
		char curChar = str.at(i);

		//找出对应的数字
		int curInt = isNormal(curChar);

		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//找到最后一位的时候，如果有对象，说明这里被经过过，也就是有这个单词。否则就是没找到。
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//没找到直接返回
			}
		}
	}
	//开始找这个准确的单词。
	if (cur->wordList->getListSize() != 0) {
		int count=cur->wordList->listSearch(str);
		if (count==0) {
			cout << str << " cannot be found!" << endl;
		}
	}
	else {
		cout << str << " cannot be found!" << endl;
	}
}

//删除所有该单词。修改完成！
void trie::erase(string str) {
	int length = str.length();
	trieNode *cur = root;
	//原理与插入大致相同
	for (int i = 0; i < length; i++) {
		//按顺序从单词中一个一个取字母
		char curChar = str.at(i);

		//找出对应的数字
		int curInt = isNormal(curChar);

		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//找到最后一位的时候，如果有对象，说明这里被经过过，也就是有这个单词。否则就是没找到。
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//没找到直接返回
			}
		}
	}
	//如果有截止到这里的单词，那么先输出一下
	if (cur->wordList->getListSize() != 0) {
		cur->wordList->listPrint();
		int eraseNum=cur->wordList->listEraseAll();
		cout << "has been deleted. The number of these words is "<< eraseNum << endl;
	}
	else {
		cout << str << " cannot be found!" << endl;
	}

}

//删除单词（大小写敏感），如果找不到单词就报错
void trie::eraseWithLine(string str, int lineNum) {
	int length = str.length();
	trieNode *cur = root;
	//原理与插入大致相同
	for (int i = 0; i < length; i++) {
		//按顺序从单词中一个一个取字母
		char curChar = str.at(i);

		//找出对应的数字
		int curInt = isNormal(curChar);

		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//找到最后一位的时候，如果有对象，说明这里被经过过，也就是有这个单词。否则就是没找到。
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//没找到直接返回
			}
		}
	}
	if (cur->wordList->getListSize() != 0) {
		cur->wordList->listEraseWithLine(str, lineNum);
	}
	else {
		cout << str << " cannot be found!" << endl;
	}
}

//删除单词（大小写敏感），如果找不到单词就报错
void trie::eraseAccurately(string str) {
	int length = str.length();
	trieNode *cur = root;
	//原理与插入大致相同
	for (int i = 0; i < length; i++) {
		//按顺序从单词中一个一个取字母
		char curChar = str.at(i);

		//找出对应的数字
		int curInt = isNormal(curChar);

		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//找到最后一位的时候，如果有对象，说明这里被经过过，也就是有这个单词。否则就是没找到。
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//没找到直接返回
			}
		}
	}
	if (cur->wordList->getListSize() != 0) {
		cur->wordList->listErase(str);
	}
	else {
		cout << str << " cannot be found!" << endl;
	}
}

void trie::triePrint() {
	trieNode *cur = root;
	for (int i = 0; i < 28; i++) {
		if (cur->next[i] != NULL) {
			preSearch(cur->next[i]);
		}
	}
}