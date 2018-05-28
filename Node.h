/*
*
Author: Mehmet Şerefoğlu
Github: https://github.com/mhmtsrfglu/Binary-Search-Tree-Document-indexing
*
*/
#ifndef _NODE_
#define _NODE_
#include <iostream>
using namespace std;
template <class T>
class Node{
public:
	T data;
	Node *next;
	Node *fileNum;
	Node():next(NULL){}
	Node (const T &d):data(d),next(NULL){}
};

#endif