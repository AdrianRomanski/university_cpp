//
// Created by Adrian Romanski on 20/11/2021.
//

#include <iostream>
using namespace std;

struct LinkedListNode {
    LinkedListNode(int data,
                   LinkedListNode *previous = nullptr,
                   LinkedListNode *next = nullptr)
                   : Data(data), Previous(previous), Next(next) {}
    int Data;
    LinkedListNode* Previous;
    LinkedListNode* Next;
};

struct LinkedList {
    LinkedList() : Head(nullptr) {}
    ~LinkedList() = default;
    LinkedListNode* Head;

    void PushBack(int value);

    void print(const LinkedList& linkedList);

};

void LinkedList::PushBack(int value) {
    if(Head == nullptr) {
        Head = new LinkedListNode(value);
    } else {
        LinkedListNode* Current = Head;
        while(Current->Next != nullptr) {
            Current = Current->Next;
        }
        auto* Temp = new LinkedListNode(value, Current, nullptr);
        Current->Next = Temp;
    }
}

void LinkedList::print(const LinkedList &linkedList) {
    LinkedListNode* Current = linkedList.Head;
    while(Current != nullptr) {
        cout << Current -> Data << " ";
        Current = Current->Next;
    }
}



int main() {

    LinkedList linkedList;
    linkedList.PushBack(1);
    linkedList.PushBack(2);
    linkedList.print(linkedList);
}