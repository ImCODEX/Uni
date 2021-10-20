#pragma once

#include <string>
#include <iostream>

using std::string;
namespace Domain{
class Car {
private:
    int id;//unique
    string model;
    string mark;
    int year_first_reg;
    int km;
    double price;
    int performance;
    string fuel;
public:
    Car(const int &new_id,const string &new_model,const string &new_mark,const int &new_year,const int &new_km,const double &new_price,const int &new_performance,const string &new_fuel);
    Car(const Car &);
    Car();
    const int &Get_id() const;
    const string &Get_model() const;
    const string &Get_mark() const;
    const int &Get_year() const;
    const int &Get_km() const;
    const double &Get_price() const;
    const int &Get_performance() const;
    const string &Get_fuel() const;
    const int &Get_age() const;
    void Set_id(const int &new_id);
    void Set_model(const string &new_model);
    void Set_mark(const string &new_mark);
    void Set_year(const int &new_year);
    void Set_km(const int &new_km);
    void Set_price(const double &new_price);
    void Set_performance(const int &new_performance);
    void Set_fuel(const string &new_fuel);
    const string car_to_string() const;
    const string car_to_csv() const;
};
}