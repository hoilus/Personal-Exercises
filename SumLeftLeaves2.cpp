/* Find sum of all left leaves in a given binary tree*/

/* Iterative Approach:
   Idea is to perform Depth-First-TRaversal on the tree (either Inorder, Preorder or Postorder) 
   using a stack and checking if the left child is a leaf node. If it is, then add the nodes 
   value to the sum variable. */

#include <iostream>
#include <stack>

using namespace std;

// tree node
struct Node {
  int key;
  struct Node *left, *right;
};

// create a new node
Node *newNode (char k) {
  Node *node = new Node;
  node->key = k;
  node->left = NULL, node->right = NULL;
  return node;
}

// function to check whether the node is leaf
bool isLeaf(Node *node) {
  if (node == NULL)
    return false;
  if (node->left == NULL && node->right == NULL)
    return true;
  return false;
}

// function to return sum of all left leaves using iterative appoach
// start from root node
int SumLeftLeaves(Node *node) {
  if (node == NULL)
    return 0;
  
  // using a stack for Depth-first Traversal of the tree
  stack<Node*> stk;
  stk.push(node);

  // define result
  int res = 0;

  while (stk.size()) {
    Node *curNode = stk.top(); // 
    stk.pop(); // pop return void

    if (curNode->left != NULL) {
      stk.push(curNode->left);
      // if left child is leaf
      if (isLeaf(curNode->left))
        res += curNode->left->key;
    }

    // if right child exist
    if (curNode->right != NULL)
      stk.push(curNode->right);
  }

  // return result
  return res;
}

// Drive code
int main(int argn, char *argv[]) {
  Node *root = newNode(20);
  root->left = newNode(9);
  root->right = newNode(49);
  root->right->left = newNode(23);
  root->right->right = newNode(52);
  root->right->right->left = newNode(50);
  root->left->left = newNode(5);
  root->left->right = newNode(12);
  root->left->right->right = newNode(12);

  cout << "Sum of left leaves is " << SumLeftLeaves(root) << "\n";

  return 0; 
}
