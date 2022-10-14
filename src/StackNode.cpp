/**
 * @file StackNode.cpp
 * @author A01747038 
 * @brief Stack node implementation
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <StackNode.hpp>

template<class T>
StackNode<T>::StackNode(T data) {
    this->data = data;
}