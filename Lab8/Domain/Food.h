#pragma once
#include <iostream>
#include "Order.h"
using namespace std;

class Food : public Order{
 public:
    Food();
    Food(const string &, const string &, const list<string> &, int);
    Food &operator=(const Food &);
    bool operator==(const Food &);
    bool operator<(const Food &);
    friend ostream &operator<<(ostream &os, const Food &s);
    friend istream &operator>>(istream &, Food &);
};
