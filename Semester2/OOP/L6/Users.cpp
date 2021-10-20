#include "Users.h"
#include <algorithm>
namespace Domain{

    User::User(string new_username){
        username=new_username;
    }

    void User::add_car_id(const int id)
    {
        favourite_car_id.push_back(id);
    }

    void User::remove_car_id(const int id)
    {
        favourite_car_id.erase(std::remove(favourite_car_id.begin(), favourite_car_id.end(), id), favourite_car_id.end());
    }
    std::vector<int> User::return_car_array() const {
        return favourite_car_id;
    }

    string User::get_username() const{
        return username;
    }

    void User::set_array(std::vector<int> new_array){
        favourite_car_id=new_array;
    }

}