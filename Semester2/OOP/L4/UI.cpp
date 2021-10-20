#include "UI.h"
#include <iostream>
#include "Error.h"

using std::cout;
using std::string;

UI::Console::Console(class Service::Controller &controller) : controller{controller} {}

void UI::Console::run_console() {
    bool done = false;
    cout << "Welcome!\n";
    while (!done) {
        try {
            print_menu();
            string choice = get_choice();
            if (choice == "1")
                add_product();
            else if (choice == "2")
                remove_product();
            else if (choice == "3")
                update_product();
            else if (choice == "4")
                print_products();
            else if (choice == "5")
                print_sorted_by_string();
            else if (choice == "6")
                print_by_less_than_x();
            else if (choice == "7")
                print_sorted_by_expiry_date();
            else if (choice == "x")
                done = true;
        }
        catch (const CustomError &e) {
            cout << e.get_msg() << '\n';
        }
    }
}

void UI::Console::print_menu() {
    cout << "\nAvailable choices:\n";
    cout << "\t1. Add a new Product\n";
    cout << "\t2. Remove an existing Product\n";
    cout << "\t3. Update an existing Product\n";
    cout << "\t4. List all Products\n";
    cout << "\t5. List all Products by certain name\n";
    cout << "\t6. List all Products less than X quantity\n";
    cout << "\t7. List all Products in ascending order by expiration date\n";
    cout << "\tx. Exit\n";
}

string UI::Console::get_choice() {
    string choice, choice_template = "1234567x";
    cout << "Your choice:";
    std::getline(std::cin, choice);
    while (choice_template.find(choice) == string::npos) {
        cout << "Invalid choice!\n";
        cout << "Your choice:";
        std::getline(std::cin, choice);
    }
    return choice;
}

void UI::Console::add_product() {
    string name, origin, expiry_date, quantity, price;
    cout << "Enter Product name:";
    std::getline(std::cin, name);
    cout << "\nEnter Product origin:";
    std::getline(std::cin, origin);
    cout << "\nEnter Product expiry_date:";
    std::getline(std::cin, expiry_date);
    cout << "\nEnter the Product quantity:";
    std::getline(std::cin, quantity);
    cout << "\nEnter the price of the Product:";
    std::getline(std::cin, price);
    controller.add_product(name, origin, expiry_date, std::stoi(quantity), std::stoi(price));
    cout << "\nSuccessfully added the Product!\n\n";
}

void UI::Console::remove_product() {
    std::string name, origin;
    std::cout << "Enter Product name:";
    std::getline(std::cin, name);
    std::cout << "Enter Product origin:";
    std::getline(std::cin, origin);
    controller.remove_product(name, origin);
    std::cout << "\nSuccessfully removed Product!\n\n";
}

void UI::Console::update_product() {
    std::string name_old, origin_old, name, origin, expiry_date, quantity, price;
    std::cout << "Enter old Product name:";
    std::getline(std::cin, name_old);
    std::cout << "Enter old Product origin:";
    std::getline(std::cin, origin_old);
    std::cout << "\nEnter new Product name (empty to leave unchanged):";
    std::getline(std::cin, name);
    std::cout << "\nEnter new Product origin (empty to leave unchanged):";
    std::getline(std::cin, origin);
    std::cout << "\nEnter new Product expiry date [DD/MM/YYYY] (empty to leave unchanged):";
    std::getline(std::cin, expiry_date);
    std::cout << "\nEnter new Product quantity (empty to leave unchanged):";
    std::getline(std::cin, quantity);
    std::cout << "\nEnter new Product price (empty to leave unchanged):";
    std::getline(std::cin, price);
    controller.update_product(name_old, origin_old, name, origin, expiry_date, quantity, price);
    std::cout << "\nSuccessfully updated Product!\n\n";
}

void UI::Console::print_products() {
    for (auto &element : controller.get_product_list())
        std::cout << element << "\n";
}

void UI::Console::print_sorted_by_string() {
    std::string name;
    std::cout << "Enter product string:";
    std::getline(std::cin, name);
    for (auto &element : controller.return_by_string(name)) {
        std::cout << element <<"\n";
    }
}

void UI::Console::print_by_less_than_x() {
    std::string x;
    std::cout << "Enter X value:";
    std::getline(std::cin, x);
    for (auto &element : controller.return_less_than_x(stoi(x))) {
        std::cout << element <<"\n";
    }
}

void UI::Console::print_sorted_by_expiry_date() {
    for (auto &element : controller.return_sorted_by_expiry_date()) {
        std::cout << element <<"\n";
    }
}