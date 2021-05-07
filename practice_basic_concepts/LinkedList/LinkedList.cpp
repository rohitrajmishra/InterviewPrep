#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
  // Termination at -1 input
  // O(n) complexity with tail node
  int data;
  Node *head = NULL;
  Node *tail = NULL;
  cin >> data;

  while (data != -1)
  {
    Node *newNode = new Node(data);
    // First node
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }

    cin >> data;
  }
  return head;
}

int length(Node *head)
{
  int len = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}

void printList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

Node *insertNode(Node *head, int pos, int data)
{
  Node *newNode = new Node(data);

  // Traverse till node before required pos
  // Handle insert at 0th pos corner case
  if (pos == 0)
  {
    newNode->next = head->next;
    head = newNode;
    return head;
  }

  int count = 0;
  Node *temp = head;
  while (temp != NULL && count < pos - 1)
  {
    temp = temp->next;
    count++;
  }

  if (temp != NULL)
  {
    newNode->next = temp->next;
    temp->next = newNode;
  }

  return head;
}

// Delete node
Node *deleteNode(Node *head, int i)
{
  int index_count = 0;

  // Deleting at 0th postion
  if (i == 0)
  {
    Node *to_delete = head;
    head = head->next;

    delete to_delete;

    return head;
  }

  Node *temp = head;
  // Deleting in the middle
  while (temp->next != NULL && index_count < (i - 1))
  { //temp->next != NULL , e.g. trying to delete index 4 when LL is till 3
    index_count++;
    temp = temp->next;
  }

  if (temp->next != NULL)
  {
    Node *to_delete = temp->next;
    temp->next = to_delete->next;

    delete to_delete;
  }

  return head;
}

int lengthRecursive(Node *head)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */

  Node *temp = head;
  // Base
  if (temp == NULL)
  {
    return 0;
  }

  int result = length(temp->next);

  result++;

  return result;
}

Node *insertNodeRec(Node *head, int i, int data)
{
  Node *temp = head;

  //Base case
  if (temp == NULL && i != 0)
  {
    return temp;
  }

  if (i == 0)
  {
    Node *new_head = new Node(data);
    new_head->next = temp;

    return new_head;
  }

  //Recursion
  Node *smallOut_head = insertNodeRec(head->next, i - 1, data);
  temp->next = smallOut_head;

  return temp;
}

Node *deleteNodeRec(Node *head, int i)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  //Base case
  if (head == NULL)
  {
    return head;
  }

  if (i == 0)
  {
    Node *to_delete = head;
    head = head->next;

    delete to_delete;
    return head;
  }

  //Recursion
  Node *smallOut_head = deleteNodeRec(head->next, i - 1);
  head->next = smallOut_head;

  return head;
}

int main()
{
  // Node *head = NULL;

  // Node *n1 = new Node(5);
  // Node *n2 = new Node(10);
  // Node *n3 = new Node(15);
  // Node *n4 = new Node(20);

  // head = n1;
  // n1->next = n2;
  // n2->next = n3;
  // n3->next = n4;

  Node *head = takeInput();
  // printList(head);
  // cout << "length: " << length(head) << endl;

  // insertNode test
  // cout << endl;
  // cout << "Enter pos and data for insertion: " << endl;
  // int pos, data;
  // cin >> pos >> data;
  // head = insertNode(head, pos, data);

  // printList(head);

  // == Test deleteNode
  // cout << endl;
  // cout << "Enter position index for deletion: " << endl;
  // int pos;
  // cin >> pos;

  // head = deleteNode(head, pos);
  // printList(head);

  // == Test: lengthRecursive
  cout << "lengthRecursive: " << lengthRecursive(head) << endl;
}