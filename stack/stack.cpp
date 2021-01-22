#include "./stack.hpp"
#include "./stack_exception.hpp"

template<typename T>
T Stack<T>::pop(){
    if(this->top == nullptr){
        throw StackException("empty stack");
    }
    T data =this->top->data;
    this->top=this->top->next;
    _size--;
    return data;
}


template<typename T>
void Stack<T>::push(T e){
    Node<T> *temp = new Node<T>(e);
    temp->next = this->top;
    top = temp;
    _size++;
}

template<typename T>
unsigned Stack<T>::size() const{
    return this->_size;
}

template<typename T>
bool Stack<T>::empty() const{
    return this->top == nullptr && this->size() == 0 ? true: false;
}

