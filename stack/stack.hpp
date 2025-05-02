#ifndef STACK_HPP
#define STACK_HPP

#include "stackItem.hpp"
#include <stdexcept>

template<typename Generic>
class Stack {
private:
    StackItem<Generic>* top;
public:
    Stack(); 
    int size();  
    void push(StackItem<Generic>* item);
    bool isEmpty(); 
    StackItem<Generic>* pop(); 
    ~Stack(); 
};

template<typename Generic>
Stack<Generic>::Stack() {
    this->top = nullptr;
}

template<typename Generic>
void Stack<Generic>::push(StackItem<Generic>* item) {
    if (item == nullptr) {
        throw std::invalid_argument("não é possível adicionar um valor nulo na stack.");
    }
    item->setNext(this->top);
    this->top = item;
}

template<typename Generic>
StackItem<Generic>* Stack<Generic>::pop() {
    if (this->top == nullptr) {
        throw std::underflow_error("a pilha está vazia.");
    }
    StackItem<Generic>* current = this->top;
    this->top = current->getNext();
    return current;
}

template<typename Generic>
int Stack<Generic>::size() {
    int length = 0;
    StackItem<Generic>* current = this->top;
    while (current != nullptr) {
        current = current->getNext();
        length++;
    }
    return length;
}

template<typename Generic>
bool Stack<Generic>::isEmpty() {
    return top == nullptr;
}

template<typename Generic>
Stack<Generic>::~Stack() {
    while (top != nullptr) {
        StackItem<Generic>* temp = top;
        top = top->getNext();
        delete temp;
    }
}

#endif
