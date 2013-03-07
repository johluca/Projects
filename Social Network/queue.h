//
//  queue.h
//
//
//  Created by Jack Lucas on 2/18/13.
//
//

#ifndef _queue_h
#define _queue_h
#include <iostream>
#include "llist.h"
using namespace std;

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();
    int size() const;
    void push_back(const T& value); //enqueue
    void pop_front();  // dequeue
    T& front();
    T& back();
    bool empty() const;
    void clear();
private:
    LList<T> Lqueue;
    
};

template <typename T>
Queue<T>::Queue()
{
    
}

template <typename T>
Queue<T>::~Queue()
{
    
}

template <typename T>
int Queue<T>::size() const
{
    return Lqueue.size();
}

template <typename T>
void Queue<T>::push_back(const T& value)
{
    Lqueue.push_back(value);
}

template <typename T>
void Queue<T>::pop_front()
{
    Lqueue.pop_front();
}

template <typename T>
T& Queue<T>::front()
{
    return Lqueue.peek_front();
}

template <typename T>
T& Queue<T>::back()
{
    return Lqueue.peek_back();
}

template <typename T>
bool Queue<T>::empty() const
{
    return Lqueue.empty();
}

template <typename T>
void Queue<T>::clear()
{
    Lqueue.clear();
}

#endif
