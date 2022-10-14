/**
 * @file StackNode.hpp
 * @author Adrian Hernandez (a01747038@tec.mx)
 * @brief Declaration of the stack node
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

template<class T>
class StackNode {
    public:
        T data;
        StackNode<T> *next;
        StackNode(T);
 };