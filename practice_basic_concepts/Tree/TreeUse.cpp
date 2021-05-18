#include <iostream>
#include <queue>
using namespace std;

#include "TreeNode.h"

TreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter data: ";
  cin >> rootData;
  cout << endl;

  TreeNode<int> *root = new TreeNode<int>(rootData);
  int n;
  cout << "Enter num of children of " << rootData << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    TreeNode<int> *child = takeInput();
    root->children.push_back(child);
  }
  return root;
}

TreeNode<int> *takeInputLevelWise()
{
  int rootData;
  cout << "Enter root data: ";
  cin >> rootData;
  cout << endl;
  TreeNode<int> *root = new TreeNode<int>(rootData);

  queue<TreeNode<int> *> pendingNodes;
  pendingNodes.push(root);

  while (pendingNodes.size() != 0)
  {
    int n;
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter num of children of " << front->data << ": ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      int childData;
      cout << "Enter " << i << " th child of " << front->data << endl;
      cin >> childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

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

void printTreeLevelWise(TreeNode<int> *root)
{
  // Edge case
  if (root == NULL)
  {
    return;
  }

  queue<TreeNode<int> *> pendingNodes;
  pendingNodes.push(root);

  while (pendingNodes.size() != 0)
  {
    int n;
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << front->data << ": ";

    for (int i = 0; i < front->children.size(); i++)
    {
      cout << front->children[i]->data << " ";
      pendingNodes.push(front->children[i]);
    }
    cout << endl;
  }
}

int numNodes(TreeNode<int> *root)
{
  // Edge case
  if (root == NULL)
  {
    return 0;
  }
  int ans = 1;
  for (int i = 0; i < root->children.size(); i++)
  {
    ans += numNodes(root->children[i]);
  }
  return ans;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
  // Edge case
  if (root == NULL)
  {
    return;
  }

  if (k == 0)
  {
    cout << root->data << endl;
  }

  for (int i = 0; i < root->children.size(); i++)
  {
    printAtLevelK(root->children[i], k - 1);
  }
}

int numLeafNodes(TreeNode<int> *root)
{
  // Edge case
  if (root == NULL)
  {
    return 0;
  }

  // If root is leaf node itself
  if (root->children.size() == 0)
  {
    return 1;
  }

  // Recursive call on children
  int totalLeaf = 0;
  for (int i = 0; i < root->children.size(); i++)
  {
    totalLeaf += numLeafNodes(root->children[i]);
  }

  return totalLeaf;
}

int main()
{
  // TreeNode<int> *root = new TreeNode<int>(1);
  // TreeNode<int> *node1 = new TreeNode<int>(2);
  // TreeNode<int> *node2 = new TreeNode<int>(3);

  // Connection
  // root->children.push_back(node1);
  // root->children.push_back(node2);

  // 1 3 2 3 4 2 5 6 0 0 0 0
  TreeNode<int> *root = takeInputLevelWise();
  // printTree(root);
  printTreeLevelWise(root);
  cout << "numNodes: " << numNodes(root) << endl;

  cout << "printAtLevelK --> Level 2" << endl;
  printAtLevelK(root, 2);
  cout << "numLeafNodes: " << numLeafNodes(root) << endl;
}