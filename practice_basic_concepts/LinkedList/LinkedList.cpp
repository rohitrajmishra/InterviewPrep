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

void printList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
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
  printList(head);
}