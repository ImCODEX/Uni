#include "Controller.h"
#include "Error.h"
#include <algorithm>
#include <sstream>

namespace Service {
    Controller::Controller(Repository::Repo &repo) : repo{repo} {}

    bool Compare_Price(Domain::Car x,Domain::Car y)
    {
    return(x.Get_price()<y.Get_price());
    }

    void Controller::initialise_cars() {
        repo.add("Octavia","Skoda",2001,200000,500,90,"Diesel");
        repo.add("Logan","Dacia",2006,500000,1500,89,"Petrol");
        repo.add("Model 3","Tesla",2020,50000,35000,300,"Electric");
        repo.add("330e","BMW",2018,100000,15000,290,"Hybrid");
        repo.add("1310","Dacia",1992,200000,500,75,"Petrol");
        repo.add("Focus","Ford",2004,210000,1000,90,"Diesel");
        repo.add("Golf 4","Volkswagen",2003,200000,1500,90,"Diesel");
        repo.add("Astra","Opel",2005,200000,700,90,"Diesel");
    }

    void Controller::add_car(const string &model, const string &mark, int year_first_reg, int km, int price, int performance, const string &fuel) {
        repo.add(model, mark, year_first_reg, km, price, performance, fuel);
    }

    void Controller::add_favourite(int id){
        if (repo.pos_by_id(id) != -1)
            client_favourites.push_back(repo.search_by_id(id));
        else
            throw CustomError("Id not valid");
    }

    vector<Domain::Car> Controller::return_favourite() const{
        return client_favourites;
    }

    void Controller::update_car(int id, string &model, string &mark, string &year_first_reg, string &km, string &price, string &performance, string &fuel) {
        Domain::Car c_old = repo.search_by_id(id);
        if (model.empty())
            model = c_old.Get_model();
        if (mark.empty())
            mark = c_old.Get_mark();
        if (year_first_reg.empty())
            year_first_reg = std::to_string(c_old.Get_year());
        if (km.empty())
            km = std::to_string(c_old.Get_km());
        if (price.empty())
            price = std::to_string(c_old.Get_price());
        if (performance.empty())
            performance = std::to_string(c_old.Get_performance());
        if (fuel.empty())
            fuel=c_old.Get_fuel();
        Domain::Car c_new(id,model, mark, std::stoi(year_first_reg), std::stoi(km), std::stod(price), std::stoi(performance), fuel);
        repo.update(id, c_new);
    }

    void Controller::remove_car(int id) {
        if (repo.pos_by_id(id) != -1)
            repo.remove(id);
        else
            throw CustomError("Id not valid");
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
            for(int i=0;i<input_vector.size();i++)
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
            for(int i=0;i<input_vector.size();i++)
                if(input_vector[i].Get_model()==s)
                    new_vector.push_back(input_vector[i]);
        return new_vector;
    }

    vector<Domain::Car> Controller::return_by_km(int x) const {
        vector<Domain::Car> new_vector;
        vector<Domain::Car> input_vector=repo.Get_array();
        for(int i=0;i<input_vector.size();i++)
                if(input_vector[i].Get_km()<=x)
                    new_vector.push_back(input_vector[i]);
        return new_vector;
    }

    vector<Domain::Car> Controller::return_by_age(int x) const {
        vector<Domain::Car> new_vector;
        vector<Domain::Car> input_vector=repo.Get_array();
        for(int i=0;i<input_vector.size();i++)
                if(2021-input_vector[i].Get_year()<=x)
                    new_vector.push_back(input_vector[i]);
        return new_vector;
    }

    vector<Domain::Car> Controller::sort_by_price() const {
        vector<Domain::Car> new_vector = repo.Get_array();
        sort(new_vector.begin(),new_vector.end(),Compare_Price);
        
        return new_vector;
    }

    
}
