#include "Repo.h"
#include "Error.h"
#include <algorithm>
namespace Repository{
Repo::Repo(vector<Domain::Product> &elems) : elems{elems} {

}

void Repo::add(const Domain::Product &e) {
    auto it = std::find(this->elems.begin(), this->elems.end(), e);
    if (it != this->elems.end())
        it->set_quantity(e.get_quantity());
    else
        this->elems.push_back(e);
}

Domain::Product &Repo::search(const string &product_name, const string &product_origin) const {
    auto it = std::find_if(this->elems.begin(), this->elems.end(), [&product_name, &product_origin](const auto &x) {
        return x.get_name() == product_name && x.get_origin() == product_origin;
    });
    if (it == this->elems.end())
        throw CustomError("Product not in list");
    return *it;
}

void Repo::remove(const Domain::Product &e) {
    auto it = std::find(this->elems.begin(), this->elems.end(), e);
    if (it == this->elems.end())
        throw CustomError("Product not in list");
    this->elems.erase(it);
}

void Repo::update(const Domain::Product &t, const Domain::Product &t_new) {
    auto it = std::find(this->elems.begin(), this->elems.end(), t);
    if (it == this->elems.end())
        throw CustomError("Product not in list");
    auto it2 = std::find(this->elems.begin(), this->elems.end(), t_new);
    if (it2 != this->elems.end())
        throw CustomError("New Product can't be in list");
    *it = t_new;
}

vector<Domain::Product> & Repo::get_elems() const {
    return this->elems;
}
}