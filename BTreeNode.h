/*
*
Author: Mehmet Şerefoğlu
Github: https://github.com/mhmtsrfglu/Binary-Search-Tree-Document-indexing
*
*/
#include <iostream>
#include "List.h"
using namespace std;

template<class T>

class BTreeNode{
	public:
		BTreeNode *lchild;
		BTreeNode *rchild;
		T word;
		int frequency;
		List<int> listOfFiles;
	
	public:
		BTreeNode ():lchild(NULL), rchild(NULL),frequency(0){}
		BTreeNode (const T &w):lchild(NULL), rchild(NULL),word(w) ,frequency(1){}
};