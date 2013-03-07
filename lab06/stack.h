//
//  stack.h
//  
//
//  Created by Jack Lucas on 2/18/13.
//
//

#ifndef _stack_h
#define _stack_h
#include <iostream>
#include "llist.h"


template<typename T>
class Stack {
public:
    Stack();
    ~Stack();
    int size() const;
    void push(const T& value);
    void pop();
    T& top();
    bool empty() const;
private:
    LList<T> Lstack;
};

template<typename T>
Stack<T>::Stack()
{
    
}

template<typename T>
Stack<T>::~Stack()
{
    
}

template<typename T>
int Stack<T>::size() const
{
    return Lstack.size();
}

template<typename T>
void Stack<T>::push(const T& value)
{

    Lstack.push_front(value);

}

template<typename T>
void Stack<T>::pop()
{
    Lstack.pop_front();
}

template<typename T>
T& Stack<T>::top()
{
    return Lstack.peek_front();
}

template<typename T>
bool Stack<T>::empty() const
{
    return Lstack.empty();
}

#endif
