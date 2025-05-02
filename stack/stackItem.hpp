#ifndef STACKITEM_HPP
#define STACKITEM_HPP

template <typename T>
class StackItem {
private:
    T value;
    StackItem<T>* next;
public:
    StackItem(T value); 
    T getValue() const; 
    void setNext(StackItem<T>* ptr);
    StackItem<T>* getNext();
    ~StackItem(); 
};

template <typename T>
StackItem<T>::StackItem(T value) {
    this->value = value;
    this->next = nullptr;
}

template <typename T>
T StackItem<T>::getValue() const {
    return this->value;
}

template <typename T>
void StackItem<T>::setNext(StackItem<T>* ptr) {
    this->next = ptr;
}

template <typename T>
StackItem<T>* StackItem<T>::getNext() {
    return this->next;
}

template <typename T>
StackItem<T>::~StackItem() {}

#endif
