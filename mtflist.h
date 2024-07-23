#ifndef MTF_LIST_H
#define MTF_LIST_H
#include "CDLinkedList.h"

// Move-to-Front List class, derived from CDLinkedList
class MtfList:public CDLinkedList{
    
    public:
        // Override the contains method to perform move-to-front operation
        bool contains(int anEntry) override;
};

#endif

