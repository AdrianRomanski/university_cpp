//
// Created by Adrian Romanski on 07/12/2021.
//

#include <iostream>
#include <string>
#include <utility>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;

    Node() = default;
    explicit Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
void showList(Node<T> *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

template <typename T>
void insert(Node<T> **headPointer, T item) {
    auto *temp = new Node<T>(item);
    Node<T> *tempPointer;
    if (*headPointer == nullptr) {
        *headPointer = temp;
    }
    else {
        tempPointer = *headPointer;
        while (tempPointer->next != nullptr) {
            tempPointer = tempPointer->next;
        }
        tempPointer->next = temp;
    }
}

template <typename T>
void deleteNode(Node<T> *head, Node<T> *forDeletion){
    if(head == forDeletion){
        head->data = head->next->data;
        forDeletion = head->next;
        head->next = head->next->next;
        free(forDeletion);
    } else {
        Node<T> *prev = head;
        while(prev->next != nullptr && prev->next != forDeletion) {
            prev = prev->next;
        }
        prev->next = prev->next->next;
        free(forDeletion);
    }
}

template <typename T>
Node<T> *arrayToList(const T a[], size_t size) {
    Node<T> *head;
    for (int i = 0; i < size; i++) {
        insert(&head, a[i]);
    }
    return head;
}

template<typename T, typename Pred>
Node<T>* extract(Node<T>* head, Pred predicate) {
    static Node<T> *newHead;
    static Node<T> *tempNode = head;
    while (tempNode != nullptr) {
        if (predicate(tempNode->data) == 1) {
            insert(&newHead, tempNode->data);
            deleteNode(head, tempNode);
        }
        tempNode = tempNode->next;

    }
    return newHead;
}

template <typename T>
void deleteList(Node<T>* head) {
    Node<T> *tempPointer = head;
    int pointerToDelete;
    while (true) {
        pointerToDelete=tempPointer->data;
        cout << "DEL " << pointerToDelete << " ";
        deleteNode(head, tempPointer);
        if(head->next == nullptr) {
            cout << "DEL " << head->data << " ";
            free(head);
            break;
        }
    }
    cout << endl;
}


int  main() {
    const int tabi[] = { 2, 1, 4, 3, 6, 5, 7, 8 };
    size_t sizei = sizeof(tabi)/sizeof(tabi[0]);
    Node<int>* listAi = arrayToList(tabi, sizei);
    showList(listAi);
    Node<int>* listBi = extract(listAi,
[](int n) {
        return n % 2 == 0;
    });
    cout << endl;
    showList(listAi);
    showList(listBi);

    deleteList(listBi);
    deleteList(listAi);

    string tabs[]{ "Kasia", "Ola", "Ala",
                        "Zosia", "Ela", "Basia" };
    size_t sizes = sizeof(tabs)/sizeof(tabs[0]);
    Node<string>* listAs = arrayToList(tabs, sizes);
    showList(listAs);
    return 0;
}
