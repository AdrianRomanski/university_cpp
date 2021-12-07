//
// Created by Adrian Romanski on 20/11/2021.
//

#include <iostream>

using namespace std;

struct Node {
    explicit Node(int data, Node *next = nullptr)
            : data(data), next(next) {}
    int data;
    Node* next;
};

void showList(Node* headPointer) {
    if(headPointer == nullptr) {
        cout << "Empty list";
    } else {
        Node* currentPrint = headPointer;
        while(currentPrint != nullptr) {
            cout << currentPrint -> data << " ";
            currentPrint = currentPrint->next;
        }
        cout << endl;
    }
}

struct LinkedList {
    LinkedList() : head(nullptr) {}
    Node* head;

    void push(int value) {
        if(head == nullptr) {
            head = new Node(value);
        } else {
            Node* Current = head;
            while(Current->next != nullptr) {
                Current = Current->next;
            }
            auto* Temp = new Node(value, nullptr);
            Current->next = Temp;
        }
    }
    
    Node* removeOdd() {
        Node* current = head;
        Node* before;
        Node* next;
        bool foundedOdd;
        while(current != nullptr) {
            next=current->next;
            if(current->data%2!=0) {
                cout << "DEL: " << current->data << endl;
                if(head->data == current->data) {
                    head=next;
                }
                before->next=next;
                foundedOdd=true;
            } else {
                foundedOdd=false;
            }
            before=current;
            if(foundedOdd==1) {
                delete current;
            }
            current=next;
        }
        return head;
    }

    void deleteList() const {
        Node* currentNode = head;
        while(currentNode) {
            Node* temp = currentNode;
            currentNode = currentNode->next;
            cout << "del: " << temp->data;
            delete temp;
        }

    }
};

Node* arrayToList(const int arr[], size_t size, LinkedList* linkedList) {
    for(int i =0; i < size; i++) {
        linkedList->push(arr[i]);
    }
    return linkedList->head;
}

int main() {
    LinkedList linkedList;
    int arr[] = {1,2,3,4,5,6};
    size_t size = sizeof(arr)/sizeof(*arr);
    Node* head;
    head = arrayToList(arr,size, &linkedList);
    showList(head);
    head = linkedList.removeOdd();
    showList(head);
    linkedList.deleteList();
    showList(head);
}