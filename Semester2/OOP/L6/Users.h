#pragma once

#include <string>
#include <iostream>
#include <vector>
using std::string;
namespace Domain{
class User{
private:
    std::vector<int> favourite_car_id;
    string username;
public:
    User(string new_username);
    void add_car_id(const int);
    void remove_car_id(const int);
    //void delete_car_id(const int);
    std::vector<int> return_car_array() const;
    string get_username() const;
    void set_array(std::vector<int> new_array);

};
}