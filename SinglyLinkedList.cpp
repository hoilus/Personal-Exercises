/*
https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
https://github.com/kamal-choudhary/singly-linked-list/blob/master/Linked%20List.cpp
*/

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

  // insert at start
  void insert_start(int value) {
    node *tmp = new node;
    tmp->data = value;
    tmp->next = head;
    head = tmp;
  }

  // insert position
  void insert_position(int pos, int value) {
    node *pre = new node;
    node *cur = new node;
    node *tmp = new node;
    cur = head;
    for (int i = 1; i < pos; i++) 
      pre = cur, cur = cur->next;
    
    tmp->data = value;
    pre->next = tmp;
    tmp->next = cur;
  }

  // delete first
  void delete_first() {
    node *tmp = new node;
    tmp = head;
    head = head->next;
    delete tmp;
  }

  // delete last
  void delete_last() {
    node *pre = new node;
    node *cur = new node;
    cur = head;
    while (cur->next != NULL) {
      pre = cur;
      cur = cur->next;
    }

    tail = pre;
    tail->next = NULL;
    delete cur;
  }

  // delete position
  void delete_position(int pos) {
    node *pre = new node;
    node *cur = new node;
    cur = head;
    for (int i = 1; i < pos; i++) 
      pre = cur, cur = cur->next;

    pre->next = cur->next;
  }

}; // end of list

// main
int main(int argn, char *argv[]) {
  list obj;
  obj.createnode(25);
  obj.createnode(30);
  obj.createnode(35);
  obj.createnode(40);
  cout << "\n********************************************************\n";
  cout << "*******************Displaying All Nodes*********************";
  cout << "\n********************************************************\n";
  obj.display();
  cout << "\n********************************************************\n";
  cout << "*******************Insertion at End*********************";
  cout << "\n********************************************************\n";
  obj.createnode(55);
  obj.display();
  cout << "\n********************************************************\n";
  cout << "*******************Insertion at Head*********************";
  cout << "\n********************************************************\n";
  obj.insert_start(50);
  obj.display();
  cout << "\n********************************************************\n";
  cout << "*******************Insertion at Particular*********************";
  cout << "\n********************************************************\n";
  obj.insert_position(5, 60);
  obj.display();
  cout << "\n********************************************************\n";
  cout << "*******************Deletion at Head*********************";
  cout << "\n********************************************************\n";
  obj.delete_first();
  obj.display();
  cout << "\n********************************************************\n";
  cout << "*******************Deletion at End*********************";
  cout << "\n********************************************************\n";
  obj.delete_last();
  obj.display();
  cout << "\n********************************************************\n";
  cout << "*******************Deletion at Particular*********************";
  cout << "\n********************************************************\n";
  obj.delete_position(4);
  obj.display();

  return 0;
}


