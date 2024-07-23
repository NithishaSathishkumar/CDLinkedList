#ifndef TRANSPOSE_LIST_H
#define TRANSPOSE_LIST_H
#include "CDLinkedList.h"
#include<iostream>

using namespace std;

// TransposeList class, derived from CDLinkedList
class TransposeList:public CDLinkedList{

    public:
        // Override the contains method for transposition
        bool contains(int anEntry) override;
};

#endif