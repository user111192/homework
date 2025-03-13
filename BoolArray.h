// Copyright (c) 2025. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by 陈子昂 on 2025/3/10.
//

#ifndef BOOLARRAY_H
#define BOOLARRAY_H
#include <iostream>
using namespace std;



template<int N>
class BoolArray {
    int a[N]{};
    int size1,bytes;
public:
    BoolArray() {
        size1 = N;
        bytes = N/8;
        if (N%8) bytes++;
        for (int i = 0; i < bytes; ++i) {
            a[i] = 0;
        }
    }

    BoolArray(const bool* begin, const bool* end) {
        size1 = N;
        bytes = N/8;
        if (N%8) bytes++;
        int i=0;
        if (end - begin > size1) {
            throw "size error";
        }
        for(auto it = begin; it != end; ++it) {
            a[i/8]|=*it<<i%8;
            i++;
        }
        for (; i < bytes; ++i) {
            a[i] = 0;
        }
    }

    int size() {
        return size1;
    }

    bool operator[](int i) {
        if (i >= size1) {
            throw "index error";
        }
        return a[i/8]&(1<<i%8);
    }

    bool set(int i, bool x) {
        if (i >= size1) {
            throw "index error";
        }
        if (x) {
            a[i/8]|=1<<i%8;
        } else {
            a[i/8]&=~(1<<i%8);
        }
        return x;
    }
};



#endif //BOOLARRAY_H
