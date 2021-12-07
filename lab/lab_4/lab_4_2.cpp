//
// Created by Adrian Romanski on 28/11/2021.
//

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

template <typename N>
class Node {
public:
    N data;
    Node* next;
public:
    explicit Node(N data) : data(data) {}
    Node() = default;
};

template <typename Q>
class Queue {
    Node<Q> *first;
    Node<Q> *last;

public:
    void put(Q data) {
        Node<Q> temp = new Node<Q>(data);
        if(first == nullptr) {
            cout << "first" << endl;
            first=&temp;
        } else if(last == nullptr) {
            cout << "last" << endl;
            last=&temp;
            first->next=last;
        } else {
            cout << "another variables" << endl;
            Node<Q> elseTemp;
            elseTemp=*last;
            last=temp;
            elseTemp.next=last;
        }
    }

    Q get() {
        Node<Q>* temp = first;
        int tempInt = temp->data;
        first=first->next;
        return tempInt;
    }

    bool empty() {
        if(first == nullptr) {
            cout << "Is Empty";
            return true;
        } else {
            cout << "There is something inside";
            return false;
        }
    }

    void deleteElements() {
        Node<Q> temp = first;
        while(temp != nullptr) {
            Node<Q> secondTemp = temp->next;
            cout << "Deleting " << temp->data;
            delete temp;
            temp=secondTemp;
        }
    }
};



int main() {
    int data1,data2;
    auto* q = new Queue<int>();
    q->put(1);
    data1 = q->get();
    std::cout << " data1=" << data1 << std::endl;
    q->put(1);
    q->put(2);
    data1 = q->get();
    data2 = q->get();
    std::cout << " data1=" << data1
              << " data2=" << data2 << std::endl;
    q->put(1); q->put(2); q->put(3);
    q->put(4); q->put(5); q->put(6);
    while (!q->empty())
        std::cout << " " << q->get();
    std::cout << std::endl;
    q->put(1); q->put(2); q->put(3);
    delete q;
//
//    return  -1;
}

