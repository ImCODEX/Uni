#pragma once
#include <string>
#include "Repo.h"
namespace Service{
class Controller{
    private:
        Repository::Repo& repo;
    public:
        Controller(Repository::Repo& repo);
        void add_product(const string&, const string&, const string&, int, int);
        void remove_product(const string&, const string&);
        void update_product(const string&, const string&, string, string, string, string, string);
        void initialise_products();
        vector<Domain::Product> return_by_string(const string &) const;
        vector<Domain::Product> return_less_than_x(const int &) const;
        vector<Domain::Product> return_sorted_by_expiry_date() const;
        std::vector<Domain::Product> get_product_list();
};
}