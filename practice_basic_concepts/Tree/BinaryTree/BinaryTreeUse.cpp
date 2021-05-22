#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>

using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
  // Base case
  if (root == NULL)
  {
    return;
  }

  cout << root->data << ":";
  if (root->left != NULL)
  {
    cout << " L" << root->left->data << " ";
  }
  if (root->right != NULL)
  {
    cout << " R" << root->right->data;
  }
  cout << endl;
  printTree(root->left);
  printTree(root->right);
}

void printTreeLevelWise(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  pendingNodes.push(NULL);
  while (!pendingNodes.empty())
  {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    if (front != NULL)
    {
      cout << front->data << ":";
      if (front->left != NULL)
      {
        pendingNodes.push(front->left);
        cout << " L" << front->left->data << " ";
      }
      if (front->right != NULL)
      {
        pendingNodes.push(front->right);
        cout << " R" << front->right->data;
      }
      cout << endl;
    }
    else
    {
      cout << endl;
      // Avoid infinite loop here, check for empty, no need to push on last level null
      if (!pendingNodes.empty())
      {
        pendingNodes.push(NULL);
      }
    }
  }
}
BinaryTreeNode<int> *takeInputLevelWise()
{
  int rootData;
  queue<BinaryTreeNode<int> *> pendingNodes;

  cout << "Enter root data ->"
       << " ";
  cin >> rootData;

  if (rootData == -1)
  {
    return NULL;
  }

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  pendingNodes.push(root);

  while (!pendingNodes.empty())
  {
    int data;
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();

    cout << "Enter leftChild of " << front->data << " : ";
    cin >> data;
    if (data != -1)
    {
      BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(data);
      front->left = leftChild;
      pendingNodes.push(leftChild);
    }
    cout << "Enter rightChild of " << front->data << " : ";
    cin >> data;
    if (data != -1)
    {
      BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(data);
      front->right = rightChild;
      pendingNodes.push(rightChild);
    }
  }

  return root;
}

BinaryTreeNode<int> *takeInput()
{
  int rootData;

  cout << "Enter root data ->"
       << " ";
  cin >> rootData;
  if (rootData == -1)
  {
    return NULL;
  }

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  BinaryTreeNode<int> *leftChild = takeInput();
  BinaryTreeNode<int> *rightChild = takeInput();

  root->left = leftChild;
  root->right = rightChild;

  return root;
}

// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main()
{
  // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
  // BinaryTreeNode<int> *left = new BinaryTreeNode<int>(2);
  // BinaryTreeNode<int> *right = new BinaryTreeNode<int>(3);

  // root->left = left;
  // root->right = right;

  // BinaryTreeNode<int> *root = takeInput();
  // printTree(root);

  BinaryTreeNode<int> *root = takeInputLevelWise();
  cout << endl;
  // printTree(root);
  printTreeLevelWise(root);
}