#pragma once
#include <iostream>
#include "Order.h"
using namespace std;

class Shopping : public Order{
 public:
    Shopping();
    Shopping(const string &, const string &, const list<string> &, int);
    Shopping &operator=(const Shopping &);
    bool operator==(const Shopping &);
    bool operator<(const Shopping &);
    friend ostream &operator<<(ostream &os, const Shopping &s);
    friend istream &operator>>(istream &, Shopping &);
};
