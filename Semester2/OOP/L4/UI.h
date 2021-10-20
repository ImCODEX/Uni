#pragma once
#include "Controller.h"

namespace UI {
    class Console {
    private:
        Service::Controller &controller;
        static void print_menu();
        void add_product();
        void remove_product();
        void update_product();
        void search_name();
        void search_by_quantity();
        void search_by_expiry_date();
        void print_products();
        void print_sorted_by_string();
        void print_by_less_than_x();
        void print_sorted_by_expiry_date();
        static string get_choice();


    public:
        Console(class Service::Controller &controller);
        void run_console();
    };
}
