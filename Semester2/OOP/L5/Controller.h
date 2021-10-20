#pragma once
#include <string>
#include "Repo.h"

namespace Service{
    class Controller{
        private:
            Repository::Repo & repo;
            vector<Domain::Car> client_favourites;
        public:
            Controller(Repository::Repo& repo);
            void add_car(const string &model, const string &mark, int year_first_reg, int km, int price, int performance, const string &fuel);
            void add_favourite(int id);
            vector<Domain::Car> return_favourite() const;
            void remove_car(int id);
            void update_car(int id, string &model, string &mark, string &year_first_reg, string &km, string &price, string &performance, string &fuel);
            void initialise_cars();
            vector<Domain::Car> return_by_mark(const string &) const;
            vector<Domain::Car> return_by_model(const string &) const;
            vector<Domain::Car> return_by_km(int) const;
            vector<Domain::Car> return_by_age(int) const;
            vector<Domain::Car> sort_by_price() const;
            std::vector<Domain::Car> get_car_list();
    };
}