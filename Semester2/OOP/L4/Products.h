#pragma once

#include <string>
#include <iostream>

using std::string;
namespace Domain{
class Product {
private:
    string name;
    string origin;
    string expiry_date;
    int quantity{};
    int price{};
public:
    Product();

    Product(const string &, const string &, const string &, const int &, const int &);

    bool operator==(const Product &);

    const string &get_name() const;

    const string &get_origin() const;

    const string &get_expiry_date() const;

    int get_price() const;

    int get_quantity() const;

    void set_price(const int &);

    void set_quantity(const int &);

    friend std::ostream &operator<<(std::ostream &, const Product &);
};
}