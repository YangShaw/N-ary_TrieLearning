#include "header1.h"
#include <fstream>
#include <sstream>
using namespace std;

/*
trie��ʵ����
����ÿһ���ļ���newһ��trie���󣬳�ʼ���ǰ��ļ��еĵ���ȫ�����룻���룻��ѯ��ɾ����
*/

//ascii��ת��Ϊ����index
int trie::isNormal(char curChar) {
	//����Ǵ�д��ĸ��ת��Ϊ��Ӧ��Сд��ĸ��
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

		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
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
	//ȥ������ĩβ�ı�����
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


//��ʼ������ÿһ�ж������ʣ��ֱ����
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

//�����ض����ʡ��������к�.�޸���ϣ�
void trie::insert(string str, int lineNum) {
	beAWord(&str);
	int length = str.length();
	trieNode *cur = root;
	for (int i = 0; i < length; i++) {
		//��˳��ӵ�����һ��һ��ȡ��ĸ
		char curChar = str.at(i);

		//�ҳ���Ӧ������
		int curInt = isNormal(curChar);

		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
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
	//�������Ժ�curӦ���������һ����ĸ����
	//��������ķ��Ų���Ӱ��ԭ����str�����Դ��������Ӧ��ûɶ���⡣
	cur->wordList->wordInsert(lineNum, str);
}

//�������������Ϊǰ׺�����е��ʣ������������޸���ϣ�
void trie::searchThePre(string str) {
	int length = str.length();
	trieNode *cur = root;
	//ԭ������������ͬ
	for (int i = 0; i < length; i++) {
		//��˳��ӵ�����һ��һ��ȡ��ĸ
		char curChar = str.at(i);

		//�ҳ���Ӧ������
		int curInt = isNormal(curChar);

		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//�ҵ����һλ��ʱ������ж���˵�����ﱻ��������Ҳ������������ʡ��������û�ҵ���
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//û�ҵ�ֱ�ӷ���
			}
		}
	}
	//����н�ֹ������ĵ��ʣ���ô�����һ��
	//Ȼ�󿴿������Ϊǰ׺�ĵ��ʣ�ǰ׺Ϊstr��curΪ���ǰ׺�Ľ�β�����ڵ�ǰ���Ѿ�������ˣ����Դ������true��
	//��ֹ���ظ����
	preSearch(cur);
}

//������������ʱ���,��Сд�����֡��޸����
void trie::search(string str) {
	int length = str.length();
	trieNode *cur = root;
	//ԭ������������ͬ
	for (int i = 0; i < length; i++) {
		//��˳��ӵ�����һ��һ��ȡ��ĸ
		char curChar = str.at(i);

		//�ҳ���Ӧ������
		int curInt = isNormal(curChar);

		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//�ҵ����һλ��ʱ������ж���˵�����ﱻ��������Ҳ������������ʡ��������û�ҵ���
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//û�ҵ�ֱ�ӷ���
			}
		}
	}
	//����н�ֹ������ĵ��ʣ���ô�����һ��
	if (cur->wordList->getListSize() != 0) {
		cur->wordList->listPrint();
	}
	else {
		cout << str << " cannot be found!" << endl;
	}
}

//���ִ�Сд��׼ȷ���ҡ��޸����
void trie::searchAccurately(string str) {
	int length = str.length();
	trieNode *cur = root;
	//ԭ������������ͬ
	for (int i = 0; i < length; i++) {
		//��˳��ӵ�����һ��һ��ȡ��ĸ
		char curChar = str.at(i);

		//�ҳ���Ӧ������
		int curInt = isNormal(curChar);

		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//�ҵ����һλ��ʱ������ж���˵�����ﱻ��������Ҳ������������ʡ��������û�ҵ���
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//û�ҵ�ֱ�ӷ���
			}
		}
	}
	//��ʼ�����׼ȷ�ĵ��ʡ�
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

//ɾ�����иõ��ʡ��޸���ɣ�
void trie::erase(string str) {
	int length = str.length();
	trieNode *cur = root;
	//ԭ������������ͬ
	for (int i = 0; i < length; i++) {
		//��˳��ӵ�����һ��һ��ȡ��ĸ
		char curChar = str.at(i);

		//�ҳ���Ӧ������
		int curInt = isNormal(curChar);

		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//�ҵ����һλ��ʱ������ж���˵�����ﱻ��������Ҳ������������ʡ��������û�ҵ���
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//û�ҵ�ֱ�ӷ���
			}
		}
	}
	//����н�ֹ������ĵ��ʣ���ô�����һ��
	if (cur->wordList->getListSize() != 0) {
		cur->wordList->listPrint();
		int eraseNum=cur->wordList->listEraseAll();
		cout << "has been deleted. The number of these words is "<< eraseNum << endl;
	}
	else {
		cout << str << " cannot be found!" << endl;
	}

}

//ɾ�����ʣ���Сд���У�������Ҳ������ʾͱ���
void trie::eraseWithLine(string str, int lineNum) {
	int length = str.length();
	trieNode *cur = root;
	//ԭ������������ͬ
	for (int i = 0; i < length; i++) {
		//��˳��ӵ�����һ��һ��ȡ��ĸ
		char curChar = str.at(i);

		//�ҳ���Ӧ������
		int curInt = isNormal(curChar);

		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//�ҵ����һλ��ʱ������ж���˵�����ﱻ��������Ҳ������������ʡ��������û�ҵ���
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//û�ҵ�ֱ�ӷ���
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

//ɾ�����ʣ���Сд���У�������Ҳ������ʾͱ���
void trie::eraseAccurately(string str) {
	int length = str.length();
	trieNode *cur = root;
	//ԭ������������ͬ
	for (int i = 0; i < length; i++) {
		//��˳��ӵ�����һ��һ��ȡ��ĸ
		char curChar = str.at(i);

		//�ҳ���Ӧ������
		int curInt = isNormal(curChar);

		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
		if (curInt < 0) {
			cout << str << " is an invalid word!" << endl;
			return;
		}
		//�ҵ����һλ��ʱ������ж���˵�����ﱻ��������Ҳ������������ʡ��������û�ҵ���
		else {
			if (cur->next[curInt] != NULL) {
				cur = cur->next[curInt];
			}
			else {
				cout << str << " cannot be found!" << endl;
				return;	//û�ҵ�ֱ�ӷ���
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