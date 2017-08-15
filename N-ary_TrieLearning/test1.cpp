#include "header1.h"
#include <fstream>
#include <sstream>
#include "time.h"
using namespace std;

int main() {
	//string str=NULL!!!��������д����˭�ܸ�����Ϊʲô��
	
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

	//		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
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
	//	myTrie->insert(strArray[j], j+1);	//��Ϊ�кŲ��Ǵ�0��ʼ�ǵ�ѽ

	//	for (int k = 0; k < strArray[j].length(); k++) {
	//		char curChar = strArray[j].at(k);
	//		if (curChar >= 65 && curChar <= 90) {
	//			curChar = curChar + 32;
	//		}
	//		int curInt = curChar - 97;

	//		//����ⲻ�Ǹ���ĸ�Ļ����ǲ��ܱ�����ģ���ʱ��Ӧ��ֱ�ӷ���
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
	cout << "��������Ҫ������ֵ䣺" << endl;
	cin >> fileName;

	cout << myTrie->initialize(fileName) << " words have been inserted" << endl;
	
	
	int n = 1;
	while (n) {
		cout << "1:���뵥��\t2:���ҵ���\t3:ɾ������\t\n4:����ǰ׺\t5:��ȷɾ��\t6:��ȷ����\t\n7:����ֵ�\t0:����" << endl;
		cin >> n;
		switch (n)
		{
		case 1: {
			cout << "�����뵥�ʣ�";
			string theStr;
			cin >> theStr;
			cout << "�������кţ�";
			int lineNum;
			cin >> lineNum;
			myTrie->insert(theStr, lineNum);
			cout << theStr << "(" << lineNum << ")" << " insert success!" << endl;
			break;
		}
		case 2: {
			cout << "�����뵥�ʣ�";
			string theStr;
			cin >> theStr;
			myTrie->search(theStr);
			break;
		}
		case 3: {
			cout << "�����뵥�ʣ�";
			string theStr;
			cin >> theStr;
			myTrie->erase(theStr);
			break;
		}
		case 4: {
			cout << "�������ַ�����";
			string theStr;
			cin >> theStr;
			myTrie->searchThePre(theStr);
			break;
		}
		case 5: {
			cout << "�����뵥�ʣ�";
			string theStr;
			cin >> theStr;
			cout << "�Ƿ��к�ɾ����y or n��";
			char requ;
			cin >> requ;
			switch (requ) {
			case 'y':
			case 'Y':
				cout << "�������кţ�";
				int theLineNum;
				cin >> theLineNum;
				myTrie->eraseWithLine(theStr, theLineNum);
				break;
			case 'n':
			case 'N':
				myTrie->eraseAccurately(theStr);
				break;
			default:
				cout << "�Ƿ����룡" << endl;
				break;
			}
			break;
		}
		case 6: {
			cout << "�����뵥�ʣ�";
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
	


	std::cout << "��ѯ������" << endl;
	std::cin.ignore();
	std::cin.ignore();
}