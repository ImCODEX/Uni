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

    int Repo::pos_by_id(const int find_id) const
    {
        for(unsigned int i=0;i<elems.size();i++)
        {
            if(elems[i].Get_id()==find_id)
                return i;
        }
        return -1;
    }

    const Domain::Car &Repo::search_by_id(const int find_id) const
    {
        if(pos_by_id(find_id)==-1)
            throw CustomError("Car not in list");
        return this->elems[pos_by_id(find_id)];
    }

    vector<Domain::Car> Repo::Get_array() const {
        return this->elems;
    }

    void Repo::add(Domain::Car & c)
    {
        c.Set_id(id_new_elem);
        id_new_elem++;
        this->elems.push_back(c);
    }
    
    void Repo::remove(const int find_id)
    {
        if(pos_by_id(find_id)==-1)
            throw CustomError("Car not in list");
        elems.erase(elems.begin()+pos_by_id(find_id));
    }

    void Repo::update(const Domain::Car &new_car)
    {
        int pos=new_car.Get_id();
        if(pos_by_id(pos)==-1)
            throw CustomError("Car not in list");
        if(new_car.Get_model()!="")
            elems[pos].Set_model(new_car.Get_model());
        if(new_car.Get_mark()!="")
            elems[pos].Set_mark(new_car.Get_mark());
        if(new_car.Get_year()!=-1)
            elems[pos].Set_year(new_car.Get_year());
        if(new_car.Get_km()!=-1)
            elems[pos].Set_km(new_car.Get_km());
        if(new_car.Get_price()!=-1)
            elems[pos].Set_price(new_car.Get_price());
        if(new_car.Get_performance()!=-1)
            elems[pos].Set_performance(new_car.Get_performance());
        if(new_car.Get_fuel()!="")
            elems[pos].Set_fuel(new_car.Get_fuel());
        

    }

    UserRepo::UserRepo(){}

    vector<Domain::User> UserRepo::Get_array() const {
        return this->elems;
    }

    void UserRepo::add(Domain::User & new_user)
    {
        this->elems.push_back(new_user);
    }

    const int UserRepo::pos_by_username(const string find_user) const{
        for(unsigned int i=0;i<elems.size();i++)
        {std::cout<<"Here";
            if(elems[i].get_username()==find_user)
                return i;
        }
        return -1;
    }

    void UserRepo::update(const Domain::User &new_user){
        int pos = pos_by_username(new_user.get_username());
        //int pos=0;
        if(pos==-1)
            throw CustomError("User not in list");
        //elems = new_user.return_car_array();
        elems[pos].set_array(new_user.return_car_array());
    }


    void UserRepo::remove(const int find_id){}
    const Domain::User &UserRepo::search_by_id(const int find_id) const
    {
        Domain::User temp = Domain::User("");
        return temp;
    }
}