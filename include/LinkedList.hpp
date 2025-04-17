#pragma once
#include <stdlib.h>

template<typename T>
class LinkedList {
private:
    struct Node {
        T value;
        Node *next;
    };

    Node *head = nullptr;
    int size = 0;

public:
    LinkedList() = default;

    LinkedList(const T& items, int count){
        for (int i = 0; i < count; ++i) {
            append(items[i]);
        }
        size = count;
    }

    LinkedList(const LinkedList& other) {
        this->size = other.size;
        for (int i = 0; i < other.size; ++i) {
            this->append(other.get(i));
        }
    }

    void append(T value) {
        if (head == nullptr) {
            head = new Node;
            head->value = value;
            head->next = nullptr;
            size = 1;
            return;
        }

        Node* last = head;
        for (int i = 1; i < size; i++) {
            last = last->next;
        }
        last->next = new Node;
        last->next->value = value;
        last->next->next = nullptr;
        size++;
    }

    void prepend(T value) {
        if (head == nullptr) {
            head = new Node;
            head->value = value;
            head->next = nullptr;
            size = 1;
            return;
        }

        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
        size++;
    }

    T GetFirst() const {
        if (head == nullptr) {
            throw std::runtime_error("cannot get first node");
            return 0;
        }
        return head->value;
    }
    T GetLast() const {
        if (head == nullptr) {
            throw std::runtime_error("cannot get last node");
            return 0;
        }
        Node *current = head;
        while (current->next!= nullptr) {
            current = current->next;
        }
        return current->value;
    }
    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("index out of range");
            return 0;
        }

        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    int GetLength() const {
        return size;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) const {
        if (startIndex < 0 || startIndex >= size || endIndex < 0 || endIndex >= size || startIndex > endIndex) {
            throw std::out_of_range("index out of range");
        }
        LinkedList<T>* result = new LinkedList<T>();
        Node* current = head;
        for (int i = 0; i < startIndex; ++i) {
            current = current->next;
        }
        for (int i = startIndex; i <= endIndex; ++i) {
            result->append(current->value);
            current = current->next;
        }
    
        return result;
    }
    
    LinkedList<T> *Concat(const LinkedList<T> &other) const{
        LinkedList<T>* result = new LinkedList<T>(*this);
        Node *current = other.head;
        while (current!= nullptr) {
            result->append(current->value);
            current = current->next;
        }
        return result;
    }

    void InsertAt(T item, int index){
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
            return;
        }

        if (index == 0) {
            prepend(item);
            return;
        }

        Node *newNode = new Node;
        newNode->value = item;
        Node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    ~LinkedList() {
        Node* next = nullptr;
        Node* now = this->head;

        while (now != nullptr) {
            next = now->next;
            delete now;
            now = next;
        }
    }
};
