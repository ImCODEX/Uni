#include "Controller.h"
#include "Error.h"
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
#include "CRUD_Repository.h"
//#include <iostream>

namespace Service {
    Controller::Controller(CrudRepository<Domain::Car> &repo,CrudRepository<Domain::User> &user_repo) : repo{repo},user_repo{user_repo} {
        current_user="";
    }

    bool Compare_Price(Domain::Car x,Domain::Car y)
    {
    return(x.Get_price()<y.Get_price());
    }

    void Controller::initialise_cars() {
        add_car("Octavia","Skoda",2001,200000,500,90,"Diesel");
        add_car("Logan","Dacia",2006,500000,1500,89,"Petrol");
        add_car("Model 3","Tesla",2020,50000,35000,300,"Electric");
        add_car("330e","BMW",2018,100000,15000,290,"Hybrid");
        add_car("1310","Dacia",1992,200000,500,75,"Petrol");
        add_car("Focus","Ford",2004,210000,1000,90,"Diesel");
        add_car("Golf 4","Volkswagen",2003,200000,1500,90,"Diesel");
        add_car("Astra","Opel",2005,200000,700,90,"Diesel");
    }

    void Controller::add_car(const string &model, const string &mark, int year_first_reg, int km, int price, int performance, const string &fuel) {
        int nullid = 0;
        Domain::Car c = Domain::Car(nullid,model, mark, year_first_reg, km, price, performance, fuel);
        repo.add(c);
    }

    /*
    void Controller::add_favourite(int id){
        if (repo.pos_by_id(id) != -1)
            client_favourites.push_back(repo.search_by_id(id));
        else
            throw CustomError("Id not valid");
    }
    */

    int Controller::pos_by_username(const string &username) const
    {   vector<Domain::User> elems = user_repo.Get_array();
        for(int i=0;i<elems.size();i++)
        {
            if(elems[i].get_username()==username)
                return i;
        }
        return -1;
    }

    int Controller::pos_by_id(const int &find_id) const
    {   vector<Domain::Car> elems = repo.Get_array();
        for(int i=0;i<elems.size();i++)
        {
            if(elems[i].Get_id()==find_id)
                return i;
        }
        return -1;
    }

    vector<Domain::Car> Controller::return_favourite_cars(string username) const{
        vector<Domain::User> elems = user_repo.Get_array();
        int pos=pos_by_username(username);
        vector<int>temp = elems[pos].return_car_array();
        vector<Domain::Car> ret,input_cars=repo.Get_array();
        for(unsigned int i=0;i<temp.size();i++)
        {
            ret.push_back(input_cars[pos_by_id(temp[i])]);
        }
        return ret;
    }

    vector<Domain::Car> Controller::return_favourite_current() const{
        return return_favourite_cars(current_user);
    }

    void Controller::add_favourite(const string &username,const int &id) const
    {
        int pos_user = pos_by_username(username);
        int pos_car = pos_by_id(id);
        if(pos_user == -1)
            throw CustomError("Username not valid");
        if(pos_car == -1)
            throw CustomError("Car id not valid");
        vector<Domain::User> user_elems = user_repo.Get_array();
        user_elems[pos_user].add_car_id(id);
        user_repo.update(user_elems[pos_user]);
    }

    void Controller::add_favourite_current(const int &id) const
    {
        add_favourite(current_user,id);
    }

    void Controller::add_user(const string &username) const{
        if(pos_by_username(username)==-1)
        {
            Domain::User temp_user = Domain::User(username);
            user_repo.add(temp_user);
        }
    }

    void Controller::set_current_user(const string &username){
        current_user = username;
    }

    void Controller::remove_all_occurances(int id){
        vector<Domain::User> temp = user_repo.Get_array();
        for(unsigned int i=0;i<temp.size();i++)
        {
            temp[i].remove_car_id(id);
            user_repo.update(temp[i]);
        }
    }

    void Controller::update_car(int id, string &model, string &mark, string &year_first_reg, string &km, string &price, string &performance, string &fuel) {
        Domain::Car c_new(-1,"","",-1,-1,-1,-1,"");
        vector<Domain::Car> input_vector=repo.Get_array();
        if (!model.empty())
            c_new.Set_model(model);
        if (!mark.empty())
            c_new.Set_mark(mark);
        if (!year_first_reg.empty())
            c_new.Set_year(stoi(year_first_reg));
        if (!km.empty())
            c_new.Set_km(stoi(km));
        if (!price.empty())
            c_new.Set_price(stod(price));
        if (!performance.empty())
            c_new.Set_performance(stoi(price));
        if (!fuel.empty())
            c_new.Set_fuel(fuel);
        c_new.Set_id(id);
        repo.update(c_new);
    }

    void Controller::remove_car(int id) {
            repo.remove(id);
            remove_all_occurances(id);
    }

    vector<Domain::Car> Controller::get_car_list() {
        return repo.Get_array();
    }

    vector<Domain::Car> Controller::return_by_mark(const string &s) const {
        vector<Domain::Car> new_vector;
        vector<Domain::Car> input_vector=repo.Get_array();
        if (s.empty())
            new_vector = repo.Get_array();
        else
            for(unsigned int i=0;i<input_vector.size();i++)
                if(input_vector[i].Get_mark()==s)
                    new_vector.push_back(input_vector[i]);
        return new_vector;
    }

    vector<Domain::Car> Controller::return_by_model(const string &s) const {
        vector<Domain::Car> new_vector;
        vector<Domain::Car> input_vector=repo.Get_array();
        if (s.empty())
            new_vector = repo.Get_array();
        else
            for(unsigned int i=0;i<input_vector.size();i++)
                if(input_vector[i].Get_model()==s)
                    new_vector.push_back(input_vector[i]);
        return new_vector;
    }

    vector<Domain::Car> Controller::return_by_km(int x) const {
        vector<Domain::Car> new_vector;
        vector<Domain::Car> input_vector=repo.Get_array();
        for(unsigned int i=0;i<input_vector.size();i++)
                if(input_vector[i].Get_km()<=x)
                    new_vector.push_back(input_vector[i]);
        return new_vector;
    }

    vector<Domain::Car> Controller::return_by_age(int x) const {
        vector<Domain::Car> new_vector;
        vector<Domain::Car> input_vector=repo.Get_array();
        for(unsigned int i=0;i<input_vector.size();i++)
                if(2021-input_vector[i].Get_year()<=x)
                    new_vector.push_back(input_vector[i]);
        return new_vector;
    }

    vector<Domain::Car> Controller::sort_by_price() const {
        vector<Domain::Car> new_vector = repo.Get_array();
        sort(new_vector.begin(),new_vector.end(),Compare_Price);
        
        return new_vector;
    }

    void Controller::print_out_cars() const{
        std::ofstream car_file ("Cars_Persistent.csv");
        vector<Domain::Car> new_vector =repo.Get_array();
        for(unsigned int i=0;i<new_vector.size();i++)
            car_file<<new_vector[i].car_to_csv()<<'\n';
        car_file.close();
    }

    void Controller::read_in_cars()
    {
        std::ifstream car_file ("Cars_Persistent.csv");
        string temp,line,word;
        vector<string> row;
        while(getline(car_file,line))
        {
            row.clear();
            std::stringstream s(line);
            while(getline(s,word,','))
                row.push_back(word);
            Domain::Car ret = Domain::Car(-1,row[0], row[1], stoi(row[2]), stoi(row[3]), stod(row[4]), stoi(row[5]), row[6]);
            repo.add(ret);
        }
    }
    
}
