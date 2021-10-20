#include "Controller.h"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
namespace Service {
    Controller::Controller(Repository::Repo &repo) : repo{repo} {}

    void Controller::initialise_products() {
        repo.add(Domain::Product("Rosii", "Italia", "10/01/2021", 10, 2));
        repo.add(Domain::Product("Rosii", "Spania", "10/02/2021", 140, 3));
        repo.add(Domain::Product("Mere", "Romania", "10/03/2021", 30, 4));
        repo.add(Domain::Product("Banane", "Germania", "21/03/2021", 10, 2));
        repo.add(Domain::Product("Capsuni", "Spania", "11/03/2021", 40, 15));
        repo.add(Domain::Product("Ananas", "Equator", "17/10/2021", 100, 1));
        repo.add(Domain::Product("Salak", "Indonesia", "20/10/2021", 140, 1));
        repo.add(Domain::Product("Nebunele", "Tunarii de Sus", "05/05/1971", 140, 1));
    }

    void Controller::add_product(const string &name, const string &origin, const string &expiry_date, int quantity, int price) {
        Domain::Product p(name, origin, expiry_date, quantity, price);
        repo.add(p);
    }

    void Controller::remove_product(const string &name, const string &origin) {
        repo.remove(repo.search(name, origin));
    }

    void Controller::update_product(const string &name_old, const string &origin_old, string name, string origin, string expiry_date, string quantity, string price) {
        Domain::Product p_old = repo.search(name_old, origin_old);
        if (name.empty())
            name = p_old.get_name();
        if (origin.empty())
            origin = p_old.get_origin();
        if (expiry_date.empty())
            expiry_date = p_old.get_expiry_date();
        if (quantity.empty())
            quantity = std::to_string(p_old.get_quantity());
        if (price.empty())
            price = std::to_string(p_old.get_price());
        Domain::Product p_new(name, origin, expiry_date, std::stoi(price), std::stoi(quantity));
        repo.update(p_old, p_new);
    }

    vector<Domain::Product> Controller::get_product_list() {
        return repo.get_elems();
    }

    vector<Domain::Product> Controller::return_by_string(const string &s) const {
        vector<Domain::Product> new_vector;
        if (s.empty())
            new_vector = repo.get_elems();
        else
            std::copy_if(repo.get_elems().begin(), repo.get_elems().end(), std::back_inserter(new_vector),[&s](const auto &element) { return element.get_name().find(s) != std::string::npos; });
        std::sort(new_vector.begin(), new_vector.end(), [](auto element1, auto element2) { return element1.get_name() < element2.get_name(); });
        return new_vector;
    }

    vector<Domain::Product> Controller::return_less_than_x(const int &x) const {
        vector<Domain::Product> new_vector;
        std::copy_if(repo.get_elems().begin(), repo.get_elems().end(), std::back_inserter(new_vector), [&x](const auto &element) { return element.get_quantity() < x; });
        return new_vector;
    }

    vector<Domain::Product> Controller::return_sorted_by_expiry_date() const {
        vector<Domain::Product> new_vector = repo.get_elems();
        std::sort(new_vector.begin(), new_vector.end(), [](auto element1, auto element2) {
            std::string a = element1.get_expiry_date();
            std::string b = element2.get_expiry_date();
            int index = a.find('/');

            int ad = stoi(a.substr(0, index));
            int am = stoi(a.substr(index + 1, a.find('/', index)));
            index = a.find('/', index + 1);
            int ay = stoi(a.substr(index + 1));

            index = b.find('/');
            int bd = stoi(b.substr(0, index));
            int bm = stoi(b.substr(index + 1, b.find('/', index)));
            index = b.find('/', index + 1);
            int by = stoi(b.substr(index + 1));

            if (ay < by)
                return true;
            if (ay == by && am < bm)
                return true;
            if (ay == by && am == bm && ad < bd)
                return true;

            return false;
        });
        return new_vector;
    }
}