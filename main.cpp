#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNewNode(int data){
    Node* newPtr = new Node();
    newPtr->data = data;
    newPtr->next = nullptr;
    return newPtr;
}

//TODO:Create a function to insert new node at front (Improve)
void insertNewNodeAtFront(Node*& head, int data){
    if(head == nullptr){
        head = createNewNode(data);
        return;
    }
    Node* newPtr = createNewNode(data);
    newPtr->next = head;
    head=newPtr;
}

//TODO: Create a function to traverse and print the element of linked list
void printLinkedList(Node* head){
    if(head == nullptr){
        cout<<"List is empty";
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}


int main() {
    Node* head = nullptr;
    insertNewNodeAtFront(head,6);
    insertNewNodeAtFront(head, 5);
    insertNewNodeAtFront(head, 4);
    insertNewNodeAtFront(head, 3);
    insertNewNodeAtFront(head, 2);
    insertNewNodeAtFront(head, 1);
    printLinkedList(head);
    return 0;
}
