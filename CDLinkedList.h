#ifndef CD_LINKED_LINK_H
#define CD_LINKED_LINK_H

#include<iostream>
using namespace std;

// Node structure for the doubly linked list
struct DListNode { 

  // Data stored in the node, Pointer to the previous node and Pointer to the next node
  int item;
  DListNode *prev;
  DListNode *next;
};

// Doubly Linked List class
class CDLinkedList {
public:

  // Constructor
  CDLinkedList(); 

  // Copy constructor
  CDLinkedList(const CDLinkedList &rhs);

  // Destructor
  ~CDLinkedList(); 

  // Get the current size of the linked list
  int getCurrentSize() const; 

  // Get the count of traversals performed during operations
  int getTraverseCount() const;

  // Reset the traversal count to zero
  void resetTraverseCount() { traverseCount = 0; }

  // Check if the linked list is empty
  bool isEmpty() const; 

  // Clear the entire linked list
  void clear(); 

  // Create a new node with the given value
  DListNode *CreateNewNode(int value);

  // Display the elements of the linked list
  void display();
  
  // Add a new value to the linked list
  bool add(int newEntry); 

  // Remove an value from the linked list
  bool remove(int anEntry);  

  // Check if the linked list contains a specific value
  virtual bool contains(int anEntry); 

  // Retrieve the value at a specified index in the linked list     
  int retrieve(const int index); 

protected:
  //dummy header
  DListNode *header; 

  // Count of traversals performed during operations
  int traverseCount = 0; 

};

#endif