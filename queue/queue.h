#ifndef MYQUEUE_H
#define MYQUEUE_H
#pragma once
#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    explicit Node(T d)
    {
        data = d;
        next = nullptr;
    }
};

template <typename T>
class Queue
{
public:
    class QueueIterator
    {
    public:
        QueueIterator() : current(nullptr){};
        explicit QueueIterator(Node<T> *p) : current(p){};

        T operator*() const;
        QueueIterator &operator++();
        QueueIterator &operator--();

        bool operator==(const QueueIterator &rhs) const;
        bool operator!=(const QueueIterator &rhs) const;

    private:
        Node<T> *current;
        T &retrieve() const;
        friend class Queue<T>;
    };

    explicit Queue() : first(nullptr), last(nullptr), _size(0){};

    [[nodiscard]] bool empty() const;
    [[nodiscard]] int size() const;

    T get();
    void insert(T elem);

    QueueIterator begin();
    QueueIterator end();

    ~Queue();

private:
    Node<T> *first;
    Node<T> *last;
    int _size;
};

#endif //MYQUEUE_H