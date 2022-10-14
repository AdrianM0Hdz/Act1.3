/**
 * @file Stack.hpp
 * @author Adrian Hernandez
 * @brief 
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "./StackNode.hpp"

template <class T>
class Stack {
    private:
        StackNode<T>* top;
    public:
        Stack();
        
        bool isEmpty() const;
        
        void push(T);
        T pop();
};