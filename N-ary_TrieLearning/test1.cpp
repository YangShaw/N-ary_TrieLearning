#include "header1.h"
#include <fstream>
#include <sstream>
#include "time.h"
using namespace std;

int main() {
	//string str=NULL!!!不能这样写！！谁能告诉我为什么！
	
	/*ifstream fin("D://data.txt");
	string str;
	int count = 1;
	while (getline(fin, str)) {
		stringstream ss(str);
		string word;
		while (ss >> word) {
			cout << word << " & " << count;
		}
		cout << endl;
		count++;
	}*/

	/*trieNode *myTrieNode = new trieNode();
	myTrieNode->next[1] = new trieNode();
	myTrieNode->next[3] = new trieNode();
	for (int i = 0; i < 26; i++) {

		if (myTrieNode->next[i] != NULL) {
			cout << i << endl;
		}
	}*/

	//string *strArray = new string[26];
	//int i = 0;
	//
	//trie *myTrie = new trie();
	//while (fin >> str) {
	//	cout << "the " << i + 1 << "line: ";
	//	myTrie->insert(str, i + 1);
	//	//strArray[i] = str;
	//	for (int k = 0; k < str.length(); k++) {
	//		char curChar = str.at(k);
	//		if (curChar >= 65 && curChar <= 90) {
	//			curChar = curChar + 32;
	//		}
	//		int curInt = curChar - 97;

	//		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
	//		if (curInt < 0 || curInt >= 26) {
	//			cout << str << " is an invalid word! ";
	//			break;
	//		}
	//		else {
	//			cout << curChar << curInt << " ";
	//		}
	//	}
	//	cout << str << endl;
	//	i++;
	//}
	//int j = 0;
	//while (strArray[j] != "") {
	//	cout << "the " << j + 1 << "line: ";
	//	myTrie->insert(strArray[j], j+1);	//因为行号不是从0开始记的呀

	//	for (int k = 0; k < strArray[j].length(); k++) {
	//		char curChar = strArray[j].at(k);
	//		if (curChar >= 65 && curChar <= 90) {
	//			curChar = curChar + 32;
	//		}
	//		int curInt = curChar - 97;

	//		//如果这不是个字母的话，是不能被插入的，这时候应该直接返回
	//		if (curInt < 0 || curInt >= 26) {
	//			cout << strArray[j] << " is an invalid word! ";
	//			break;
	//		}
	//		else {
	//			cout << curChar << curInt << " ";

	//		}
	//	}
	//	cout << strArray[j] << endl;
	//	j++;
	//}

	//	int a;
	//	
	//	cin >> a;
	//	cout << a;
	//	system("pause");

	//
	//return 0;

	string str1 = "aaa";
	string str2 = "aaa";
	int flag = 0;
	if (str1 == str2) {
		flag = 1;
	}
	else
		flag = -1;
	//cout << flag << endl;

	trie *myTrie = new trie();
	string fileName;
	cout << "请输入需要导入的字典：" << endl;
	cin >> fileName;

	cout << myTrie->initialize(fileName) << " words have been inserted" << endl;
	
	
	int n = 1;
	while (n) {
		cout << "1:插入单词\t2:查找单词\t3:删除单词\t\n4:查找前缀\t5:精确删除\t6:精确查找\t\n7:输出字典\t0:结束" << endl;
		cin >> n;
		switch (n)
		{
		case 1: {
			cout << "请输入单词：";
			string theStr;
			cin >> theStr;
			cout << "请输入行号：";
			int lineNum;
			cin >> lineNum;
			myTrie->insert(theStr, lineNum);
			cout << theStr << "(" << lineNum << ")" << " insert success!" << endl;
			break;
		}
		case 2: {
			cout << "请输入单词：";
			string theStr;
			cin >> theStr;
			myTrie->search(theStr);
			break;
		}
		case 3: {
			cout << "请输入单词：";
			string theStr;
			cin >> theStr;
			myTrie->erase(theStr);
			break;
		}
		case 4: {
			cout << "请输入字符串：";
			string theStr;
			cin >> theStr;
			myTrie->searchThePre(theStr);
			break;
		}
		case 5: {
			cout << "请输入单词：";
			string theStr;
			cin >> theStr;
			cout << "是否按行号删除（y or n）";
			char requ;
			cin >> requ;
			switch (requ) {
			case 'y':
			case 'Y':
				cout << "请输入行号：";
				int theLineNum;
				cin >> theLineNum;
				myTrie->eraseWithLine(theStr, theLineNum);
				break;
			case 'n':
			case 'N':
				myTrie->eraseAccurately(theStr);
				break;
			default:
				cout << "非法输入！" << endl;
				break;
			}
			break;
		}
		case 6: {
			cout << "请输入单词：";
			string theStr;
			cin >> theStr;
			myTrie->searchAccurately(theStr);
			break;
		}
		case 7: {
			myTrie->triePrint();
			break;
		}
		case 0:
		default:
			return 0;
		}
	}
	


	std::cout << "查询结束！" << endl;
	std::cin.ignore();
	std::cin.ignore();
}