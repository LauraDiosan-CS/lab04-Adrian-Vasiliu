#include "Order.h"
using namespace std;

Order::Order() {
    price = 0;
}

Order::Order(const string &client_name,
           const string &client_address,
           const list<string> &strings_list,
           int price) {
    this->client_name = client_name;
    this->client_address = client_address;
    this->strings_list = strings_list;
    this->price = price;
}

Order::Order(const Order &order) {
    client_name = order.client_name;
    client_address = order.client_address;
    strings_list = order.strings_list;
    price = order.price;
}

Order::~Order() {
    client_name = client_address = "";
    price = -1;
}

string Order::get_client_name() {
    return client_name;
}

void Order::set_client_name(const string &new_client_name) {
    client_name = new_client_name;

}

string Order::get_client_address() {
    return client_address;
}

list<string> Order::get_preparations_list() {
    return strings_list;
}

void Order::set_client_address(const string &new_client_address) {
    client_address = new_client_address;
}

void Order::set_preparations_list(const list<string> &new_preparations_list) {
    strings_list = new_preparations_list;
}

int Order::get_price() {
    return price;
}

void Order::set_price(int new_price) {
    price = new_price;
}
