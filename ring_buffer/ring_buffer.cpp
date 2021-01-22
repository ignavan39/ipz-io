#include "./ring_buffer.hpp"
#include "./ring_buffer_exception.hpp"

template<typename T>
RingBuffer<T>::RingBuffer(unsigned _size):array(new T[_size]), size(_size), startIdx(0), endIdx(0) {}

template<typename T>
RingBuffer<T>::RingBuffer(RingBuffer<T>* r){
    this->array = new T[r->size];
    this->size = r->size;
    this->startIdx = r->startIdx;
    this->endIdx = r->endIdx;

    for(int i=0;i<r->size;r++){
        this->array[i] = r->array[i];
    }
}

template<typename T>
RingBuffer<T>& RingBuffer<T>::operator=(RingBuffer &r){
    this->array = new T[r->size];
    this->size = r->size;
    this->startIdx = r->startIdx;
    this->endIdx = r->endIdx;

    for(int i=0;i<r->size;r++){
        this->array[i] = r->array[i];
    }
    return *this;
}

template<typename T>
RingBuffer<T>& RingBuffer<T>::operator*(){
    return *this;
}

template<typename T>
void RingBuffer<T>::push(T elem) {
    if (endIdx != (size - 1)) {
        this->array[endIdx] = elem;
    } else {
        unsigned newSize = size + 10;
        T *buff = new T[newSize];
        for (int i = 0; i < size; i++) {
            buff[i] = this->array[i];
        }
        buff[endIdx] = elem;
        delete[] this->array;
        this->array = buff;
        this->size = newSize;

    }
    endIdx++;
}

template<typename T>
T RingBuffer<T>::pop() {
    if (startIdx == (endIdx - 1)) {
        throw RingBufferException("queue empty");
    }
    T e = this->array[startIdx];
    startIdx++;
    return e;
}

template<typename T>
T RingBuffer<T>::get() {
    return this->array[startIdx];
}

template<typename T>
bool RingBuffer<T>::isEmpty() {
    return startIdx == (endIdx - 1) || (startIdx == 0 && endIdx == 0);
}

template<typename T>
void RingBuffer<T>::make_empty() {
    startIdx = 0;
    endIdx = 0;
}

template<typename T>
unsigned RingBuffer<T>::getSize() {
    return endIdx;
}


template<typename T>
 typename RingBuffer<T>::Iterator_rb RingBuffer<T>::end() {
    return Iterator_rb(*this,(endIdx));
}

template<typename T>
typename RingBuffer<T>::Iterator_rb RingBuffer<T>::begin() {
    return Iterator_rb(*this);
}


template<typename T>
typename RingBuffer<T>::Iterator_rb &RingBuffer<T>::Iterator_rb::operator++() {
    idx++;
    ptr++;
    return *this;
}

template<typename T>
typename RingBuffer<T>::Iterator_rb &RingBuffer<T>::Iterator_rb
::operator=(const RingBuffer::Iterator_rb &other) {
    if (this != &other)
    {
        ptr = other.ptr;
        idx = other.idx;
    }
    return *this;
}

template<typename T>
T& RingBuffer<T>::Iterator_rb::operator*() {
    return *ptr;
}

template<typename T>
bool RingBuffer<T>::Iterator_rb::operator==(const RingBuffer::Iterator_rb &rhs) const {
    return idx == rhs.idx &&
           ptr == rhs.ptr;
}

template<typename T>
bool RingBuffer<T>::Iterator_rb::operator!=(const RingBuffer::Iterator_rb &rhs) const {
    return !(rhs == *this);
}