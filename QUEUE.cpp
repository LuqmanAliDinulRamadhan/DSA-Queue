#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

class Queue {
private:
  Node* head;
  Node* tail;

public:
  Queue() {
    head = NULL;
    tail = NULL;
  }

  void enqueue(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  int dequeue() {
    if (head == NULL) {
      cout << "Antrian kosong!" << endl;
      return -1;
    }

    int front = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == NULL) {
      tail = NULL;
    }

    return front;
  }

  void printQueue() {
    if (head == NULL) {
      cout << "Antrian kosong!" << endl;
      return;
    }

    Node* temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  Queue queue;

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  cout << "Antrian: ";
  queue.printQueue();

  int dequeuedValue = queue.dequeue();
  cout << "Dequeue: " << dequeuedValue << endl;
  
  cout << "Antrian: ";
  queue.printQueue();

  cout << "Enqueue: 4 " << endl;
  
  queue.enqueue(4);

  cout << "Antrian: ";
  queue.printQueue();

  return 0;
}
