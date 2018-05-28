/*
*
Author: Mehmet Şerefoğlu
Github: https://github.com/mhmtsrfglu/Binary-Search-Tree-Document-indexing
*
*/
#ifndef _LIST_
#define _LIST_

#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

template <class T>

class List
{
  private:
    Node<T> *head;
    int sz;

  public:
    List() : sz(0), head(NULL)
    {
    }

    int getSize() const
    {
        cout << sz << endl;
        return sz;
    }

    bool isEmpty() const
    {
        return sz == 0;
    }

    bool isFull() const
    {
        return false;
    }

    void traverse() const
    {
        Node<T> *walk = head;
        if (walk != NULL)
        {
            while (walk != NULL)
            {
                cout << walk->data << "->";
                walk = walk->next;
            }
            cout << "NULL\n";
        }
        else
            cout << "Empty" << endl;
    }

    bool issetFunc(const int fnum)
    {
        Node<T> *walk = head;

        bool flag = false;

        if (walk != NULL)
        {
            while (walk != NULL)
            {
                if (walk->data == fnum)
                {
                    flag = true;
                    break;
                }
                walk = walk->next;
            }
        }

        return flag;
    }

    void insertEnd(const T &data)
    {
        if (issetFunc(data) == false)
        {
            Node<T> *newNode = new Node<T>(data);
            Node<T> *walk = head;
            if (walk == NULL)
            {
                head = newNode;
                return;
            }
            while (walk->next != NULL)
            {
                walk = walk->next;
            }
            walk->next = newNode;
        }
    }

    bool operator==(const List &l2) const
    {
        if (&l2 == this)
            return true;
        else if (sz != l2.sz)
            return false;
        Node<T> *walkOfl2 = l2.head;
        Node<T> *walk = head;
        for (int i = 0; i < sz; i++)
        {
            if (walk->data != walkOfl2->data)
                return false;
            walk = walk->next;
            walkOfl2 = walkOfl2->next;
        }
        return true;
    }

    ~List()
    {
        Node<T> *walk;
        while (head != NULL)
        {
            walk = head;
            head = head->next;
            delete walk;
            sz--;
        }
    }
};

#endif