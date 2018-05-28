/*
*
Author: Mehmet Şerefoğlu
Github: https://github.com/mhmtsrfglu/Binary-Search-Tree-Document-indexing
*
*/
#include <iostream>
#include <string>
#include <cstring>

#include "BTreeNode.h"

using namespace std;

template <class T>
class BinarySearchTreeIndex
{
  private:
    BTreeNode<T> *root;

  public:
    BinarySearchTreeIndex() : root(NULL) {}

    void insertWord(const string &w, int fileName)
    {
        if (root == NULL)
        {
            root = new BTreeNode<T>(w);
            root->listOfFiles.insertEnd(fileName);
            root->frequency++;
        }
        else
        {
            BTreeNode<T> *walk = root;

            while (walk != NULL)
            {
                if (w < walk->word)
                {
                    if (walk->lchild == NULL)
                    {
                        walk->lchild = new BTreeNode<T>(w);
                        walk->frequency++;
                        walk->listOfFiles.insertEnd(fileName);
                        break;
                    }
                    walk = walk->lchild;
                }
                else if (w > walk->word)
                {
                    if (walk->rchild == NULL)
                    {
                        walk->rchild = new BTreeNode<T>(w);
                        walk->frequency++;
                        walk->listOfFiles.insertEnd(fileName);
                        break;
                    }
                    walk = walk->rchild;
                }
                else if (walk->word == w)
                {
                    walk->frequency++;
                    walk->listOfFiles.insertEnd(fileName);
                    break;
                }
            }
        }
    }
    void printListOfFiles(const string &w)
    {
        BTreeNode<T> *walk = root;
        int flag = false;

        while (walk != NULL)
        {
            if (w == walk->word)
            {
                cout << "List of files : ";
                walk->listOfFiles.traverse();
                cout << endl;
                cout<<"Frequency : "<<walk->frequency<<endl;
                flag = true;
                break;
            }
            else if (w < walk->word)
            {
                walk = walk->lchild;
            }
            else
            {
                walk = walk->rchild;
            }
        }

        if (flag == false)
        {
            cout << "Not Found!" << endl;
        }
    }
};
