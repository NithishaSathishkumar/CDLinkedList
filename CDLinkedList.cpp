#include "CDLinkedList.h"

// Constructor for CDLinkedList
CDLinkedList::CDLinkedList(){    

    // Creating a new header node for the doubly linked list
    header = new DListNode;

    // Initializing the next and previous pointers of the header to point to itself
    header->next = header;
    header->prev = header;
}

// Destructor for CDLinkedList
CDLinkedList::~CDLinkedList(){

    // Clearing the entire double linked list to release allocated memory
    clear();

    // Deleting the header node to avoid memory leaks
    delete header;
}

// Copy constructor for CDLinkedList
CDLinkedList::CDLinkedList(const CDLinkedList &rhs){

    // Creating a new header node for the new doubly linked list
    header = new DListNode;

    // Initializing the next and previous pointers of the header to point to itself
    header->next = header;
    header->prev = header;

    // Copying elements from the rhs linked list to the new linked list
    DListNode *temp = rhs.header->next;
    while (temp != rhs.header) {

        // Creating a new node with the same item value as the corresponding node in rhs
        DListNode *new_node = CreateNewNode(temp->item);

        // Connecting the new node to the new linked list
        new_node->prev = header->prev;
        new_node->next = header;

        header->prev->next = new_node;
        header->prev = new_node;
        temp = temp->next;
    }
}

// Get the current size of the linked list
int CDLinkedList::getCurrentSize() const{
    int size = 0;
    DListNode *temp = header->next;

    // Counting the number of nodes in the linked list
    while(temp != header){
        size++;
        temp = temp->next;
    }

    return size;
}

// Get the traverse count of the linked list
int CDLinkedList::getTraverseCount() const{
    return traverseCount;
}

// Check if the linked list is empty
bool CDLinkedList::isEmpty() const{

    // Checking if the next pointer of the header points to itself
    if(header->next != header){

        // The linked list is not empty
        return false;
    }else{

        // The linked list is empty
        return true;
    }
}

// Clear the entire linked list
void CDLinkedList::clear(){
    DListNode *move_front = header->next;

    // Traverse the linked list and delete each node
    while(move_front != header){
        DListNode *temp = move_front;
        move_front = move_front->next;
        delete temp;
    }

    // Reset the header pointers to make the linked list empty
    header->prev = header;
    header->next = header;
}

// Display method to print the elements of the linked list
void CDLinkedList::display(){

    // Starting from the first node after the header and traversing the linked list
    DListNode *temp = header->next;
    while(temp != header){

        // Printing the item value of the current node
        cout << temp->item << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Create a new node with the given value
DListNode *CDLinkedList::CreateNewNode(int value){

    // Creating a new node and initializing its value, next, and prev
    struct DListNode *newNode = new(struct DListNode);
    newNode->item = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Add a new value to the linked list
bool CDLinkedList::add(int newEntry){

    // Check if the value already exists in the linked list
    bool node_exist = contains(newEntry);

    // If the value does not exist, add it to the linked list
    if(!node_exist){
        DListNode *new_node = CreateNewNode(newEntry);
        new_node->prev = header;
        new_node->next = header->next;

        header->next->prev = new_node;
        header->next = new_node;

        return true;
    }

    // value already exists, not added
    return false;
}

// Remove an value from the linked list
bool CDLinkedList::remove(int anEntry){
    DListNode *temp = header->next;

    // Traverse the linked list to find the value
    while(temp != header){
        if(temp->item == anEntry){

            // Remove the value from the linked list
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // Delete the node and increment traverseCount
            delete temp;
            traverseCount++;
            return true;
        }

        temp = temp->next;
        traverseCount++;
    }

    // value not found, not removed
    return false;
}

// Check if the linked list contains a specific value
bool CDLinkedList::contains(int anEntry){
    DListNode *temp = header->next;

    // Traverse the linked list to find the value
    while(temp != header){
        if(temp->item == anEntry){

            // value found, increment traverseCount and return true
            traverseCount++;
            return true;
        }

        // value not found
        temp = temp->next;
        traverseCount++;
    }
    return false;
}

// Retrieve the value at a specified index in the linked list
int CDLinkedList::retrieve(const int index){ 
    DListNode *temp = header->next;
    int index_value = 0;

    // Traverse the linked list to reach the specified index
    while(temp != header && index_value < index){
        temp = temp->next;
        index_value++;
        traverseCount++;
    }

    // Check if the specified index is valid
    if(index_value != index || temp == header){

        // Index is invalid or reached the end of the list, return -1
        return -1;
    }

    // Return the item value at the specified index
    return temp->item;
}
