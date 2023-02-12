// Copyright (c) 2022. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by 陈子昂 on 2022/12/14.
//

#ifndef HOMEWORK_STRING_H
#define HOMEWORK_STRING_H
#include <iostream>
#define final const
using namespace std;

class String {
    char* str;
    int len;
    static int num_strings;
public:
    static const int CINLIM = 80;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length () const {return len;}
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    operator bool() const;
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend ostream & operator<<(ostream & os, const String &st);
    friend istream & operator>>(istream & os, const String &st);
    static int HowMany();
};


#endif //HOMEWORK_STRING_H
