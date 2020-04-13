#include "Food.h"
using namespace std;

Food::Food() = default;

Food::Food(const string &client_name,
           const string &client_address,
           const list<string> &preparations_list,
           int price) {
    this->client_name = client_name;
    this->client_address = client_address;
    this->strings_list = preparations_list;
    this->price = price;
}

Food &Food::operator=(const Food &food) {
    if (this == &food) return *this;
    client_name = food.client_name;
    client_address = food.client_address;
    strings_list = food.strings_list;
    price = food.price;
    return *this;
}

//bool Food::operator==(const Food &food) {
//    return (client_name == food.client_name and client_address == food.client_address
//            and preparations_list == food.preparations_list and price == food.price);
//}

//bool Food::operator<(const Food &food) {
//    return (strcmp(client_name, food.client_name) < 0);
//}

ostream &operator<<(ostream &os, const Food &food) {
    os << food.client_name << " " << food.client_address << " " << food.price << endl;
    return os;
}

istream &operator>>(istream &is, Food &food) {
    string client_name, client_address;
    int price;
    is >> client_name;
    cin >> client_address >> price;
    food.set_client_name(client_name);
    food.set_client_address(client_address);
    food.set_price(price);
    return is;
}
