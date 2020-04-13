#include "Shopping.h"
using namespace std;

Shopping::Shopping() = default;

Shopping::Shopping(const string &client_name,
           const string &client_address,
           const list<string> &shopping_list,
           int price) {
    this->client_name = client_name;
    this->client_address = client_address;
    this->strings_list = shopping_list;
    this->price = price;
}

Shopping &Shopping::operator=(const Shopping &shopping) {
    if (this == &shopping) return *this;
    client_name = shopping.client_name;
    client_address = shopping.client_address;
    strings_list = shopping.strings_list;
    price = shopping.price;
    return *this;
}

//bool Shopping::operator==(const Shopping &shopping) {
//    return (client_name == shopping.client_name and client_address == shopping.client_address
//            and preparations_list == shopping.preparations_list and price == shopping.price);
//}

//bool Shopping::operator<(const Shopping &shopping) {
//    return (strcmp(client_name, shopping.client_name) < 0);
//}

ostream &operator<<(ostream &os, const Shopping &shopping) {
    os << shopping.client_name << " " << shopping.client_address << " " << shopping.price << endl;
    return os;
}

istream &operator>>(istream &is, Shopping &shopping) {
    string client_name, client_address;
    int price;
    is >> client_name;
    cin >> client_address >> price;
    shopping.set_client_name(client_name);
    shopping.set_client_address(client_address);
    shopping.set_price(price);
    return is;
}
