#include "header1.h"

//listNode类的实现

listNode::listNode() {
	link = NULL;
	lineNum = -1;
}

listNode::listNode(int theLineNum) {
	link = NULL;
	lineNum = theLineNum;
}

listNode::listNode(int theLineNum, listNode *theLink) {
	link = theLink;
	lineNum = theLineNum;
}

wordNode::wordNode() {
	wordLink = NULL;
	lineList = NULL;
	//wordList = new sortedChain();
}

wordNode::wordNode(std::string theWord) {
	word = theWord;
	wordLink = NULL;
	lineList = NULL;
	//wordList = new sortedChain();
}


//sortedChain::sortedChain() {
//	head = new listNode();
//	//word = "unknown";
//	listSize = 0;
//	
//}
sortedChain::sortedChain() {
	wordHead = new wordNode();
	//word = "unknown";
	listSize = 0;
	wordNum = 0;

}


int sortedChain::getListSize() {
	return listSize;
}

void sortedChain::setListSize(int theSize) {
	this->listSize = theSize;
}

//找到wordList中符合的单词，如果没有就新建；然后在对应单词处的lineList中插入行号；新建完成。
void sortedChain::wordInsert(int theLineNum,std::string theWord) {
	wordNode *cur = wordHead;
	while (cur->wordLink != NULL&&cur->wordLink->word!=theWord) {
		cur = cur->wordLink;
	}
	if (cur->wordLink == NULL) {
		cur->wordLink = new wordNode();
		cur=cur->wordLink;
		wordNum++;

		cur->word = theWord;	//存储记录大小写的单词，每个单词只需要在这里存储一次就够了，多余的只需要存行号
		cur->lineList = new sortedChain();	//给这个单词赋予一个linelist，用来存行号；
		cur->lineList->head = new listNode();
		cur->lineList->listInsert(theLineNum);
		//listSize = listSize + cur->lineList->listInsert(theLineNum);	//把每一个wordNode对应的lineList的listSize加起来，得到这个wordList的listSize
	}
	else {
		cur = cur->wordLink;
		cur->lineList->listInsert(theLineNum);
	}
	listSize++;
}

/*
有序插入，按照行号从小到大进行排序。只需要保存行号就可以了。修改完成。
*/
int sortedChain::listInsert(int theLineNum) {
	listNode *cur = head;
	while (cur->link != NULL&&cur->link->lineNum < theLineNum) {
		cur = cur->link;
	}
	if (cur->link == NULL) {
		cur->link = new listNode(theLineNum);
	}
	else {
		listNode *temp = new listNode(theLineNum, cur->link);
		cur->link = temp;

	}
	listSize++;
	return listSize;

}


//查找完全匹配的字符串（区分大小写）.修改完成！
int sortedChain::listSearch(std::string theWord) {
	wordNode *curWord = wordHead;
	int num = 0;
	if (curWord->wordLink == NULL) {

	}
	else {
		curWord = curWord->wordLink;
		while (curWord != NULL) {
			if (curWord->word == theWord) {
				std::cout << curWord->word << ":";
				listNode *cur = curWord->lineList->head->link;
				while (cur != NULL) {
					std::cout << "(" << cur->lineNum << ")";
					cur = cur->link;
					num++;
				}
				std::cout << ";" << std::endl;
				break;
			}
			else {
				curWord = curWord->wordLink;
			}
		}
	}

	return num;

}

//修改完成！
int sortedChain::listEraseAll() {
	int eraseNum = listSize;
	wordHead = new wordNode();
	setListSize(0);
	return eraseNum;
}

//精确删除，修改完成！
int sortedChain::listErase(std::string theWord) {
	wordNode *curWord = wordHead;
	int num = 0;
	if (curWord == NULL) {
		std::cout << "not exists!" << std::endl;
		return num;
	}

	else {
		curWord = curWord->wordLink;
		while (curWord != NULL) {
			if (curWord->word == theWord) {
				num = curWord->lineList->listSize;
				listSize = listSize - num;
				curWord->lineList->setListSize(0);
				std::cout << curWord->word << ":";

				listNode *cur = curWord->lineList->head->link;
				while (cur != NULL) {
					std::cout << "(" << cur->lineNum << ")";
					cur = cur->link;
				}
				curWord->lineList->head = new listNode();
				break;
			}
			else {
				curWord = curWord->wordLink;
			}
		}
		if (num > 0) {
			std::cout << "has been deleted. The number of these words is " << num << std::endl;
		}
		else {
			std::cout << theWord<<" not exist!" << std::endl;
		}
		return num;
	}

}

//删除这一行的每个单词
int sortedChain::listEraseWithLine(std::string theWord,int theLineNum) {
	wordNode *curWord = wordHead;
	std::cout << theWord << ":";
	int num = 0;
	if (curWord == NULL) {
		std::cout << "not exists!" << std::endl;
		return num;
	}

	else {
		curWord = curWord->wordLink;
		while (curWord != NULL) {
			if (curWord->word == theWord) {	//找到le这个单词
				if (curWord->lineList->listSize == 0) {
					std::cout << "not exists!" << std::endl;
				}
				else {
					listNode *cur = curWord->lineList->head;
					listNode *preCur = NULL;

					while (cur->link != NULL&&cur->link->lineNum < theLineNum) {
						preCur = cur;
						cur = cur->link;
					}
					if (cur->link == NULL) {
						std::cout << "not exists at this line! " << std::endl;
					}
					else {
						preCur = cur;
						cur = cur->link;
						while (cur!=NULL&&cur->lineNum == theLineNum) {
							std::cout << "(" << cur->lineNum << ")";
							cur = cur->link;
							preCur->link = cur;
							num++;
						}
						if(num>0)
							std::cout << "has been deleted. The number of these words is " << num << std::endl;
						else {
							std::cout << "not exists at this line! " << std::endl;
						}
					}
				}
				break;
			}
			else {
				curWord = curWord->wordLink;
			}
		}
		curWord->lineList->listSize =curWord->lineList->listSize-num;
		listSize =listSize-num;
		
		return num;
	}
}

//这个打印也需要修改，按照单词种类进行打印。修改完成。
void sortedChain::listPrint() {
	wordNode *curWord = wordHead;	//	这个方法是被wordList调用的。其实加一个循环就可以了；
	if (curWord->wordLink == NULL) {
		std::cout << "not exists!" << std::endl;
	}
	else {
		curWord = curWord->wordLink;
		while (curWord != NULL) {	//	一种一种地打印；
			if (curWord->lineList->listSize > 0) {
				std::cout << curWord->word << ":";
					if (curWord->lineList->head->link != NULL) {
					listNode *cur = curWord->lineList->head->link;
					while (cur != NULL) {
						std::cout << "(" << cur->lineNum << ")";
						cur = cur->link;
					}
					std::cout << ";" << std::endl;
				}
			}
			curWord = curWord->wordLink;
		}
		//std::cout << std::endl;
	}

	/*listNode *cur = head;
	if (cur->link == NULL) {
		std::cout << "not exists!" << std::endl;
	}
	else {
		cur = cur->link;
		while (cur != NULL) {
			std::cout << cur->word << "(" << cur->lineNum << ")" << ";" ;
			cur = cur->link;
		}
		std::cout << std::endl;
	}*/

}

//void sortedChain::setWord(std::string theWord) {
//	word = theWord;
//}
