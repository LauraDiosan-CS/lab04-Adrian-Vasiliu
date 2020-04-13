#pragma once
#include <iostream>
#include <list>
using namespace std;

class Order {
 protected:
    string client_name;
    string client_address;
    list<string> strings_list;
    int price;
 public:
    Order();
    Order(const string &, const string &, const list<string> &, int);
    Order(const Order &);
    ~Order();
    string get_client_name();
    string get_client_address();
    list<string> get_preparations_list();
    int get_price();
    void set_client_name(const string &);
    void set_client_address(const string &);
    void set_preparations_list(const list<string> &);
    void set_price(int);
};
