#pragma once
#include <vector>
#include <algorithm>
#include "Products.h"
using std::vector;
namespace Repository{
class Repo{
    private:
        vector<Domain::Product> & elems;
    public:
        Repo(vector<Domain::Product> &);
        void add(const Domain::Product&);
        Domain::Product & search(const string &, const string &) const;
        void remove(const Domain::Product&);
        void update(const Domain::Product&, const Domain::Product&);
        vector<Domain::Product> & get_elems() const;
};
}