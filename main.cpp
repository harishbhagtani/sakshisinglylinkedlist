#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNewNode(int data) {
    Node *newPtr = new Node();
    newPtr->data = data;
    newPtr->next = nullptr;
    return newPtr;
}
void insertAtEnd(Node*& head,int data){
    if(head== nullptr){
        head=createNewNode(data);
        return;
    }
    Node* temp=head;
    while (temp->next!= nullptr){
        temp=temp->next;
    }
    Node* newptr;
    newptr=createNewNode(data);
    temp->next=newptr;


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
void insertAtMid(Node* &head,int data,int insertAfter){
    if(head== nullptr){
        head=createNewNode(data);
        return;
    }
    Node* temp=head;
    while (temp->data!=insertAfter && temp->next!= nullptr){
        temp=temp->next;
    }
    if (temp->data==insertAfter){
        Node* newptr;
        newptr=createNewNode(data);
        newptr->next=temp->next;
        temp->next=newptr;
    }else{
        cout<<"key not found";
    }

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
int count(Node* head){
    if(head== nullptr){
        cout<<"list is empty"<<endl;
        return 0;
    }
    Node* temp=head;
    int count=0;
    while (temp!= nullptr){
        temp=temp->next;
        count++;
    }
    return count;

}
void deleteAtFront(Node* &head){
    if (head== nullptr){
        cout<<"list is empty";
        return;
    }
    if (head->next== nullptr){
        delete head;
        head= nullptr;
    }
    Node* temp=head;
    head=temp->next;
    delete temp;
}
void deleteFromEnd(Node* &head){
    if (head== nullptr){
        cout<<"list is empty";
        return;
    }
    Node* temp=head;
    Node* prev=head;
    while (temp->next!= nullptr){
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    prev->next= nullptr;

}


int main() {
    Node* head = nullptr;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    insertAtEnd(head,17);
    insertAtMid(head,20,17);
    insertNewNodeAtFront(head,0);
    deleteAtFront(head);
    deleteFromEnd(head);
    printLinkedList(head);

   cout<<"number of elements are"<< count(head);

    return 0;
}
