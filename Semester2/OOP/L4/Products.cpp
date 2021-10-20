#include "Products.h"
namespace Domain{
Product::Product() = default;

Product::Product(const string &name, const string &origin, const string &expiry_date, const int &price,
                 const int &quantity) : name{name}, origin{origin}, expiry_date{expiry_date}, quantity{quantity},
                                            price{price} {
}

const string &Product::get_name() const {
    return this->name;
}

const string &Product::get_origin() const {
    return this->origin;
}

const string &Product::get_expiry_date() const {
    return this->expiry_date;
}

int Product::get_price() const {
    return this->price;
}

void Product::set_price(const int &p) {
    this->price = p;
}

int Product::get_quantity() const {
    return this->quantity;
}

void Product::set_quantity(const int &p) {
    this->quantity = p;
}

std::ostream &operator<<(std::ostream &os, const Product &Product) {
    os << "Product name: " << Product.name << " Origin: " << Product.origin << " Expiry_date: " << Product.expiry_date
       << " Price: " << Product.price << " Quantity: " << Product.quantity;
    return os;
}

bool Product::operator==(const Product &other) {
    return name == other.name && origin == other.origin;
}
}