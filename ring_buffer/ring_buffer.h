
#ifndef RINGBUFFER_H
#define RINGBUFFER_H



template<typename T>
class RingBuffer {
public:

    explicit RingBuffer(unsigned _size);
    RingBuffer(RingBuffer* r);

    RingBuffer& operator=(RingBuffer &r);
    RingBuffer& operator*();

    void push(T elem);

    T pop();

    T get();

    bool isEmpty();

    void make_empty();

    unsigned getSize();



    class Iterator_rb{
    public:
        explicit Iterator_rb(RingBuffer<T> &_ptr):ptr(_ptr.array),idx(0){};
        Iterator_rb(RingBuffer<T>& _ptr,int _idx):ptr(_ptr.array+idx),idx(_idx){};
        Iterator_rb& operator++();
        Iterator_rb& operator=(const Iterator_rb& other);
        T& operator*();

        bool operator==(const Iterator_rb &rhs) const;

        bool operator!=(const Iterator_rb &rhs) const;

    private:
        unsigned idx;
        T* ptr;
    };

     Iterator_rb begin();
     Iterator_rb end();

private:

    T *array;
    unsigned startIdx;
    unsigned endIdx;
    unsigned size;


};


#endif //RINGBUFFER_H