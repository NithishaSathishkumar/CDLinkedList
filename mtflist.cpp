//MTF list: every time an element is accessed, it moved to the front of the list.
#include "mtflist.h"

// Override the contains method to perform move-to-front operation
bool MtfList::contains(int anEntry){
    DListNode *temp = header->next;

    // Traverse the linked list to find the value
    while(temp != header){

        // value found
        if(temp->item == anEntry){

            // Move the target node to the front of the list
            // delete the target node from its current position
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;

            // Connect the target node to the front of the list
            temp->prev = header;
            temp->next = header->next;

            header->next->prev = temp;
            header->next = temp;

            return true;
        }

        temp = temp->next;
        traverseCount++;
    }

    // value not found
    return false;
}