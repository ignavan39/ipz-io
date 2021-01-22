#include "./queue.hpp"
#include "./queue_exception.hpp"

template <typename T>
bool Queue<T>::empty() const
{
    if (this->size() == 0)
    {
        return true;
    }
    return false;
}

template <typename T>
int Queue<T>::size() const
{
    return this->_size;
}

template <typename T>
T Queue<T>::get()
{
    if (this->empty())
    {
        throw QueueException("queue is empty");
    }

    T x;
    Node<T> *ptr;
    this->_size--;
    x = this->first->data;
    ptr = first;
    first = first->next;
    delete ptr;

    return x;
}

template <typename T>
void Queue<T>::insert(T elem)
{

    this->_size++;
    Node<T>* temp = new Node<T>(elem);
    if(this->last == nullptr){
        this->last = this->first = temp;
        return;
    }
    this->last->next = temp;
    this->last = temp;
}

template <typename T>
Queue<T>::~Queue(){
    while(!this->empty()){
        this->get();
    }
}


template<typename T>
typename Queue<T>::QueueIterator Queue<T>::end(){
    QueueIterator itr(this->last);
    return itr;
}

template<typename T>
typename Queue<T>::QueueIterator Queue<T>::begin(){
    QueueIterator itr(this->first);
    return itr;
}

template<typename T>
T &Queue<T>::QueueIterator::retrieve() const {
    return current->data;
}

template<typename T>
T Queue<T>::QueueIterator::operator*() const {
   return this->current->data;
}

template<typename T>
typename Queue<T>::QueueIterator &Queue<T>::QueueIterator::operator++() {
    this->current = this->current->next;
    return *this;
}

template<typename T>
typename Queue<T>::QueueIterator &Queue<T>::QueueIterator::operator--() {
    this->current = this->current->prev;
    return *this;
}


template<typename T>
bool Queue<T>::QueueIterator::operator==(const Queue::QueueIterator &rhs) const{
    return current == rhs.current;
}

template<typename T>
bool Queue<T>::QueueIterator::operator!=(const Queue::QueueIterator &rhs) const{
    return !(rhs == *this);
}