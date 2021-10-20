#pragma once
#include "Controller.h"
#include <iostream>
#include <string>
//includes

namespace UI{
class Console {
private:
    Service::Controller &controller;
public:
    Console(Service::Controller &Controller);

    void run_console();

private:
    int ui_choose_mode();

    void user_login();

    bool Check_Double_Valid(string s);//checks if a string is convertable to double

    bool Check_Int_Valid(string s);//checks if a string is convertable to int

    void print_manager_menu();

    void print_user_menu();

    std::string get_choice(std::string);

    void manager_add_car();

    void manager_remove_car();

    void manager_update_car();

    void print_cars();

    void add_user_favourites();
    
    void print_user_favourites();

    void search_by_mark();

    void search_by_model();

    void filter_by_km();

    void filter_by_age();

    void sort_by_price();

    void print_out_file();

    void scan_in_file();

};
}