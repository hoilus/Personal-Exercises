/* Construct all possible BSTs for keys 1 to N */
/* The idea is to maintain a list of roots of all BSTs. 
   Recursively construct all possible left and right subtrees. 
   Create a tree for every pair of left and right subtree and 
   add the tree to list. */

#include <iostream>
#include <vector>

using namespace std;

// node structure
struct Node {
  int key;
  struct Node *left, *right;
};

// create a new BST node
Node* newNode(char k) {
  Node *node = new Node;
  node->key = k;
  node->left = NULL, node->right = NULL;
  return node;
}

// a unility function to do preorder traversal of BST
void preorder(Node *root) {
  if (root != NULL) {
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

// function for constructing trees
vector<Node*> constructTrees(int start, int end) {
  // define return
  vector<Node*> res;

  // corner case
  if (start > end) {
    res.push_back(NULL);
    return res;
  }

  // loop all numbers in the range as root node
  for (int i = start; i <= end; i++) {
    // construct all left subtress
    vector<Node*> leftSubtrees = constructTrees(start, i - 1);
 
    // construct all right subtrees
    vector<Node*> rightSubtrees = constructTrees(i + 1, end);

    // combine all possible combinations of left/right subtrees
    for (int j = 0; j < leftSubtrees.size(); j++) {
      Node *left = leftSubtrees[j];
      for (int k = 0; k < rightSubtrees.size(); k++) {
	Node *root = newNode(i);
	Node *right = rightSubtrees[k];
	root->left = left;
	root->right = right;
	res.push_back(root);
      }
    }
  }
  
  // return result
  return res;
}

// Drive program to test above functions
int main(int argn, char *argv[]) {
  // Construct all possible BSTs
  vector<Node*> totalTreesFrom1toN = constructTrees(1, 3);

  // print preorder traversal of all constructed BSTs.
  cout << "Preorder traversal of all constructed BSTs are: \n";
  for (int i = 0; i < totalTreesFrom1toN.size(); i++) {
    preorder(totalTreesFrom1toN[i]);
    cout << "\n";
  } 

  return 0;
}
