#include "header1.h"

//listNode���ʵ��

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

//�ҵ�wordList�з��ϵĵ��ʣ����û�о��½���Ȼ���ڶ�Ӧ���ʴ���lineList�в����кţ��½���ɡ�
void sortedChain::wordInsert(int theLineNum,std::string theWord) {
	wordNode *cur = wordHead;
	while (cur->wordLink != NULL&&cur->wordLink->word!=theWord) {
		cur = cur->wordLink;
	}
	if (cur->wordLink == NULL) {
		cur->wordLink = new wordNode();
		cur=cur->wordLink;
		wordNum++;

		cur->word = theWord;	//�洢��¼��Сд�ĵ��ʣ�ÿ������ֻ��Ҫ������洢һ�ξ͹��ˣ������ֻ��Ҫ���к�
		cur->lineList = new sortedChain();	//��������ʸ���һ��linelist���������кţ�
		cur->lineList->head = new listNode();
		cur->lineList->listInsert(theLineNum);
		//listSize = listSize + cur->lineList->listInsert(theLineNum);	//��ÿһ��wordNode��Ӧ��lineList��listSize���������õ����wordList��listSize
	}
	else {
		cur = cur->wordLink;
		cur->lineList->listInsert(theLineNum);
	}
	listSize++;
}

/*
������룬�����кŴ�С�����������ֻ��Ҫ�����кžͿ����ˡ��޸���ɡ�
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


//������ȫƥ����ַ��������ִ�Сд��.�޸���ɣ�
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

//�޸���ɣ�
int sortedChain::listEraseAll() {
	int eraseNum = listSize;
	wordHead = new wordNode();
	setListSize(0);
	return eraseNum;
}

//��ȷɾ�����޸���ɣ�
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

//ɾ����һ�е�ÿ������
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
			if (curWord->word == theWord) {	//�ҵ�le�������
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

//�����ӡҲ��Ҫ�޸ģ����յ���������д�ӡ���޸���ɡ�
void sortedChain::listPrint() {
	wordNode *curWord = wordHead;	//	��������Ǳ�wordList���õġ���ʵ��һ��ѭ���Ϳ����ˣ�
	if (curWord->wordLink == NULL) {
		std::cout << "not exists!" << std::endl;
	}
	else {
		curWord = curWord->wordLink;
		while (curWord != NULL) {	//	һ��һ�ֵش�ӡ��
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
