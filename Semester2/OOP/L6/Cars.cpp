#include "Cars.h"
namespace Domain{

Car::Car(const int &new_id,const string &new_model,const string &new_mark,const int &new_year,const int &new_km,const double &new_price,const int &new_performance,const string &new_fuel)
{
    id=new_id;
    model=new_model;
    mark=new_mark;
    year_first_reg=new_year;
    km=new_km;
    price=new_price;
    performance=new_performance;
    fuel=new_fuel;
}

Car::Car(const Car & c){
    id=c.Get_id();
    model=c.Get_model();
    mark=c.Get_mark();
    year_first_reg=c.Get_year();
    km=c.Get_km();
    price=c.Get_price();
    performance=c.Get_performance();
    fuel=c.Get_fuel();
}

Car::Car(){

}
/*
void & operator=(const Car& other){
    id  = other.Get_id();
    model=c.Get_model();
    mark=c.Get_mark();
    year_first_reg=c.Get_year();
    km=c.Get_km();
    price=c.Get_price();
    performance=c.Get_performance();
    fuel=c.Get_fuel();
}*/
const int &Car::Get_id() const {
    return this->id;
}

const string &Car::Get_model() const {
    return this->model;
}

const string &Car::Get_mark() const {
    return this->mark;
}

const int &Car::Get_year() const {
    return this->year_first_reg;
}

const int &Car::Get_km() const {
    return this->km;
}

const double &Car::Get_price() const {
    return this->price;
}


const int &Car::Get_performance() const {
    return this->performance;
}

const string &Car::Get_fuel() const {
    return this->fuel;
}

void Car::Set_id(const int &p) {
    this->id = p;
}

void Car::Set_model(const string &p) {
    this->model = p;
}

void Car::Set_mark(const string &p) {
    this->mark = p;
}

void Car::Set_year(const int &p) {
    this->year_first_reg = p;
}

void Car::Set_km(const int &p) {
    this->km = p;
}

void Car::Set_price(const double &p) {
    this->price = p;
}

void Car::Set_performance(const int &p) {
    this->performance = p;
}

void Car::Set_fuel(const string &p) {
    this->fuel = p;
}

const string Car::car_to_string() const
{
    return "Car ID: " + std::to_string(id)+ " Model: " + model + " Mark: " + mark + " Year first registration: " + std::to_string(year_first_reg) + " KM: " +std::to_string(km)+" Price: "+std::to_string(int(price))+" Performance: "+std::to_string(performance)+"PS Fuel: "+fuel;
}

const string Car::car_to_csv() const
{
    return model+","+mark+","+std::to_string(year_first_reg)+","+std::to_string(km)+","+std::to_string(price)+","+std::to_string(performance)+","+fuel;
}

}