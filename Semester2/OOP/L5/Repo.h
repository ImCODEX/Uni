#pragma once
#include <vector>
#include <algorithm>
#include "Cars.h"
using std::vector;
namespace Repository{
class Repo{
    private:
        vector<Domain::Car> elems;
        int id_new_elem;
    public:
        Repo();
        const int GetSize() const;
        vector<Domain::Car> Get_array() const;
        int pos_by_id(const int &find_id) const;
        const Domain::Car &search_by_id(const int &find_id) const;
        void add(const string &new_model,const string &new_mark,const int &new_year,const int &new_km,const double &new_price,const int &new_performance,const string &new_fuel);//gives its own id
        void update(const int &find_id,const Domain::Car &new_car);
        void remove(const int &find_id);
};
}