#include "Repo.h"
#include "Error.h"
#include <algorithm>
namespace Repository{
        
    Repo::Repo(){
        id_new_elem=0;
    }

    const int Repo::GetSize() const
    {
        return this->elems.size();
    }

    int Repo::pos_by_id(const int &find_id) const
    {
        for(int i=0;i<elems.size();i++)
        {
            if(elems[i].Get_id()==find_id)
                return i;
        }
        return -1;
    }

    const Domain::Car &Repo::search_by_id(const int &find_id) const
    {
        if(pos_by_id(find_id)==-1)
            throw CustomError("Car not in list");
        return this->elems[pos_by_id(find_id)];
    }

    vector<Domain::Car> Repo::Get_array() const {
        return this->elems;
    }

    void Repo::add(const string &new_model,const string &new_mark,const int &new_year,const int &new_km,const double &new_price,const int &new_performance,const string &new_fuel)
    {
        Domain::Car new_car=Domain::Car(id_new_elem,new_model,new_mark,new_year,new_km,new_price,new_performance,new_fuel);
        id_new_elem++;
        this->elems.push_back(new_car);
    }
    
    void Repo::remove(const int &find_id)
    {
        if(pos_by_id(find_id)==-1)
            throw CustomError("Car not in list");
        elems.erase(elems.begin()+pos_by_id(find_id));
    }

    void Repo::update(const int &find_id,const Domain::Car &new_car)
    {
        if(pos_by_id(find_id)==-1)
            throw CustomError("Car not in list");
        this->elems[pos_by_id(find_id)]=new_car;
    }
}