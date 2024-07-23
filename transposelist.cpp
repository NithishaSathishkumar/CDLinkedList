#include "transposelist.h"
//The transposelist: every time an element is accessed, it swapped with previouse node of the list 

// Check if the linked list contains a specific value and perform transpose
bool TransposeList::contains(int anEntry) {
    DListNode *current = header->next;

    // Traverse the linked list to find the value
    while (current != header) {

        traverseCount++;
        
        if (current->item == anEntry) {
            // value found, perform the transpose operation and Check if the current node is not the first node
            if (current != header->next) {
                // Swap the target node with the previous node
                current->prev->next = current->next;
                current->next->prev = current->prev;

                current->next = current->prev;
                current->prev = current->prev->prev;
                current->prev->next = current;
                current->next->prev = current;
            }

            return true;
        }
        current = current->next;
    }

    // value not found
    return false; 
}


// bool TransposeList::contains(int anEntry){
//     DListNode *temp = header->next;

//     while(temp != header){
//         if(temp->item == anEntry && temp->prev != header){
//             DListNode *before_temp = temp->prev;
//             DListNode *after_temp = temp->next;

//             temp->prev = before_temp->prev;
//             temp->next = before_temp;

//             before_temp->prev->next = temp;
//             before_temp->prev = temp;
                
//             after_temp->prev = before_temp;
//             before_temp->next = after_temp;

//             return true;       
//         }

//         temp = temp->next;
//         traverseCount++;
//     } 
//     return false;
// }

