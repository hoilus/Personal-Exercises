#ifndef _REMVDUPLSORTLISTII_H_ 
#define _REMVDUPLSORTLISTII_H_

#include <iostream>

using namespace std;

// a struct defines a single node
struct node {
  int data;
  node *next;
};

class list {
private:
  node *head, *tail;
public:
  // constructor
  list() {
    head = NULL;
    tail = NULL;
  }

  // get access to head
  node* getHead() {
    return head;
  }

  // head reposition
  void reposHead(node *tmp) {
    head = tmp;
  }

  // create a node
  void createnode(int value) {
    node *tmp = new node;
    tmp->data = value;
    tmp->next = NULL;

    if (head == NULL) {
      head = tmp;
      tail = tmp;
      tmp = NULL;
    }
    else {
      tail->next = tmp;
      tail = tmp;
    }
  }

  // print the list
  void display() {
    node *tmp = new node;
    tmp = head;
    while (tmp!=NULL) {
      cout << tmp->data << '\t';
      tmp = tmp->next;
    }
    cout << '\n';
  }

}; // end of list

#endif
