#ifndef STACK_H
#define STACK_H

#include "./stack_exception.hpp"
#include "../shared/node.hpp"

template <typename T>
class Stack
{
public:

    Stack() : _size(0), top(nullptr){};

    T pop();
    void push(T e);
    [[nodiscard]] bool empty() const;
    [[nodiscard]] unsigned size() const;

    private : Node<T> *top;
    unsigned _size;
};

#endif //STACK_H