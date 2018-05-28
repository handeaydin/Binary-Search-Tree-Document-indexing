/*
*
Author: Mehmet Şerefoğlu
Github: https://github.com/mhmtsrfglu/Binary-Search-Tree-Document-indexing
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "BTreeindexing.h"

const int files = 9598;
const int nonstopwordsize = 200;

string nonestop[nonstopwordsize];

int addedstring = 0;

string stringToLower(string words)
{
    char str[100];
    string ret;
    strcpy(str, words.c_str());
    int differ = 'A' - 'a';
    char ch;
    int ii = strlen(str);
    for (int i = 0; i < ii; i++)
    {
        strncpy(&ch, str + i, 1);
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - differ;
            memcpy(str + i, &ch, 1);
        }
    }
    ret = str;

    return ret;
}

void initializeNonStopStrings()
{
    ifstream inFile;
    int i = 1;
    string txt;

    inFile.open("stopwords.txt");

    if (!inFile)
    {
        cerr << "Unable to open file stopwords.txt";
        exit(1);
    }
    while (inFile >> txt)
    {
        nonestop[addedstring] = stringToLower(txt);
        addedstring++;
    }
}

bool checknonstop(const string w)
{
    bool finded = false;
    string tolow = stringToLower(w);
    int i = 0;
    while (i < addedstring)
    {
        if (tolow == nonestop[i])
        {
            finded = true;
            break;
        }
        i++;
    }
    return finded;
}

int main()
{
    BinarySearchTreeIndex<string> bst;

    initializeNonStopStrings();

    int i = 1;
    while (i < files)
    {
        string dirname = "AllDocs/";
        string filename = dirname.append(to_string(i)).append(".txt");
        string txt;

        ifstream inFileWords;

        inFileWords.open(filename);

        if (!inFileWords)
        {
            cerr << "Unable to open file " << filename;
            exit(1);
        }

        while (inFileWords >> txt)
        {
            if (checknonstop(txt) == false)
            {
                bst.insertWord(stringToLower(txt), i);
            }
        }

        i++;
    }

    while (1)
    {
        cout << "\n\n **** Hint: Please write exit for terminate! **** \n\n" << endl;

        string w;
        cout << "Please enter text for search : " << endl;
        cin >> w;
        if (stringToLower(w) == "exit")
        {
            break;
        }
        else
        {
            bst.printListOfFiles(stringToLower(w));
        }
    }

    return 0;
}