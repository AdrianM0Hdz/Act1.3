/**
 * @file Stack.cpp
 * @brief Stack implementation
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <Stack.hpp>

#include "./StackNode.cpp"

template<class T>
Stack<T>::Stack() {
    this->top = nullptr;
}

template<class T>
bool Stack<T>::isEmpty() const {
    return this->top == nullptr;
}

template<class T>
void Stack<T>::push(T data) {
    StackNode<T> *newTop = new StackNode<T>(data);
    newTop->next = this->top;
    this->top = newTop;
}

template<class T>
T Stack<T>::pop() {
    T data = this->top->data;
    StackNode<T> *newTop = this->top->next;
    
    delete this->top;
    this->top = newTop;
    
    return data;
}