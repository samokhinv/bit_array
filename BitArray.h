//
// Created by Valentin on 09.03.2018.
//

#ifndef BIT_ARRAY_BITARRAY_H
#define BIT_ARRAY_BITARRAY_H

#endif //BIT_ARRAY_BITARRAY_H
#pragma once

#include <iostream>
#include <stdlib.h>
#include <exception>
#include <stdexcept>
#include <cassert>

using namespace std;

class BitArray{
    char* pointer_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
public:
    explicit BitArray(size_t capacity);

    void push_back(const bool& flag);

    bool at(const int& n);

    void assign(const int& to, const bool& value);

    size_t length();

    ~BitArray();
};

void TestAll();