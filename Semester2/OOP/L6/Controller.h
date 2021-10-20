#pragma once
#include <string>
#include "Cars.h"
#include "Users.h"
//#include "Repo.h"
#include "CRUD_Repository.h"
namespace Service{
    class Controller{
        private:
            //Repository::Repo & repo;
            CrudRepository<Domain::Car> &repo; 
            CrudRepository<Domain::User> &user_repo;
            vector<Domain::User> clients;
            string current_user;
        public:
            Controller(CrudRepository<Domain::Car> &repo,CrudRepository<Domain::User> &user_repo);
            void add_car(const string &model, const string &mark, int year_first_reg, int km, int price, int performance, const string &fuel);
            void add_favourite(const string &username,const int &id) const;
            void add_favourite_current(const int &id) const;
            vector<Domain::Car> return_favourite_cars(string username) const;
            vector<Domain::Car> return_favourite_current() const;
            void remove_car(int id);
            void update_car(int id, string &model, string &mark, string &year_first_reg, string &km, string &price, string &performance, string &fuel);
            void initialise_cars();
            void read_in_cars();
            void print_out_cars() const;
            int pos_by_username(const string &username) const;
            int pos_by_id(const int &find_id) const;
            void add_user(const string &username) const;
            void set_current_user(const string &username);
            void remove_all_occurances(const int id);
            vector<Domain::Car> return_by_mark(const string &) const;
            vector<Domain::Car> return_by_model(const string &) const;
            vector<Domain::Car> return_by_km(int) const;
            vector<Domain::Car> return_by_age(int) const;
            vector<Domain::Car> sort_by_price() const;
            std::vector<Domain::Car> get_car_list();
    };
}