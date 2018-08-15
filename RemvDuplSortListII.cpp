#include "RemvDuplSortListII.h"

class Solution {
public:
  node* deleteDuplicates(node *head) {
    if (!head || !head->next) return head;

    node *start = new node;
    start->next = head;
    node *pre = start;
    while (pre->next) {
      node *cur = pre->next;
      while (cur->next && cur->next->data == cur->data) cur = cur->next;
      if (cur == pre->next) pre = pre->next;
      else pre->next = cur->next; 
    }

    return start->next;
  }
};

int main(int argn, char *argv[]) {
  list obj;
  obj.createnode(1);
  obj.createnode(1);
  obj.createnode(1);
  obj.createnode(2);
  obj.createnode(3);
  obj.createnode(3);
  obj.createnode(4);
  obj.createnode(6);

  // print obj
  obj.display();

  Solution sol;
  obj.reposHead(sol.deleteDuplicates(obj.getHead()));
  obj.display();

  return 0;
}
