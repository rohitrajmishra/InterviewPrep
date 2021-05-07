#include <iostream>
using namespace std;

#include "TreeNode.h"

void printTree(TreeNode<int> *root)
{
  // Edge case
  if (root == NULL)
  {
    return;
  }

  cout << root->data << " : ";

  for (int i = 0; i < root->children.size(); i++)
  {
    cout << root->children[i]->data << " ";
  }
  cout << endl;

  for (int i = 0; i < root->children.size(); i++)
  {
    printTree(root->children[i]);
  }
}

int main()
{
  TreeNode<int> *root = new TreeNode<int>(1);
  TreeNode<int> *node1 = new TreeNode<int>(2);
  TreeNode<int> *node2 = new TreeNode<int>(3);

  // Connection
  root->children.push_back(node1);
  root->children.push_back(node2);

  printTree(root);
}