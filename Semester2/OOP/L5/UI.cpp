#include "UI.h"
#include <cstdlib>
#include <string>
#include <regex>
#include "Error.h"

namespace UI{
Console::Console(Service::Controller &Controller) : controller{Controller} {}

bool Console::Check_Double_Valid(string s)
{
    if(s==""||s==".")
        return false;
    std::regex pattern("^[0-9]*[.]?[0-9]*$");
    std::smatch result;

    if(!regex_search(s, result, pattern))
        return false;

    return true;
}

bool Console::Check_Int_Valid(string s)
{
    std::regex pattern("^[0-9]+$");
    std::smatch result;

    if(!regex_search(s, result, pattern))
        return false;

    return true;
}

void Console::run_console() {
    bool done = false;
    std::cout << "Welcome!\n";
    int running_mode = ui_choose_mode();
    while (!done) {
        try {
            switch (running_mode) {
                case 1: {
                    print_manager_menu();
                    std::string choice = get_choice("123456789ux");
                    if (choice == "1")
                        manager_add_car();
                    else if (choice == "2")
                        manager_remove_car();
                    else if (choice == "3")
                        manager_update_car();
                    else if (choice == "4")
                        print_cars();
                    else if (choice == "5")
                        search_by_mark();
                    else if (choice == "6")
                        search_by_model();
                    else if (choice == "7")
                        filter_by_km();
                    else if (choice == "8")
                        filter_by_age();
                    else if (choice == "9")
                        sort_by_price();
                    else if (choice == "u") {
                        running_mode = 2;
                        std::cout << "\n";
                    } else if (choice == "x")
                        done = true;
                    break;
                }
                case 2: {
                    print_user_menu();
                    std::string choice = get_choice("12345678mx");
                    if (choice == "1")
                        print_cars();
                    else if (choice == "2")
                        search_by_mark();
                    else if (choice == "3")
                        search_by_model();
                    else if (choice == "4")
                        filter_by_km();
                    else if (choice == "5")
                        filter_by_age();
                    else if (choice == "6")
                        sort_by_price();
                    else if (choice == "7")
                        add_user_favourites();
                    else if (choice == "8")
                        print_user_favourites();
                    else if (choice == "m") {
                        running_mode = 1;
                        std::cout << "\n";
                    } else if (choice == "x")
                        done = true;
                    break;
                }
                default:
                    std::cout << "Something went wrong!\n";
                    done = true;
                    break;
            }
        } catch (const CustomError &e) {
            std::cout << e.get_msg() << '\n';
        }
    }
}

int Console::ui_choose_mode() {
    std::string user_choice;
    std::cout << "Choose what mode to run the application in:" << std::endl << "\t1. Manager" << std::endl
              << "\t2. User" << std::endl << "Your choice:";
    std::getline(std::cin, user_choice);
    while (user_choice != "1" && user_choice != "2") {
        std::cout << "Invalid choice!" << std::endl << "Your choice:";
        std::getline(std::cin, user_choice);
    }
    std::cout << std::endl;
    return std::stoi(user_choice);
}

void Console::print_user_menu() {
    std::cout << "\nAvailable choices:\n";
    std::cout << "\t1. See all Cars\n";
    std::cout << "\t2. Search Car by Mark\n";
    std::cout << "\t3. Search Car by Model\n";
    std::cout << "\t4. Filter Car by km\n";
    std::cout << "\t5. Filter Car by age\n";
    std::cout << "\t6. Sort Car by price\n";
    std::cout << "\t7. Add Car to Favourites\n";
    std::cout << "\t8. Show Favourites\n";
    std::cout << "\tm. Switch to manager mode\n";
    std::cout << "\tx. Exit\n";
}

void Console::print_manager_menu() {
    std::cout << "\nAvailable choices:\n";
    std::cout << "\t1. Add Car\n";
    std::cout << "\t2. Delete Car\n";
    std::cout << "\t3. Edit Car\n";
    std::cout << "\t4. See all Cars\n";
    std::cout << "\t5. Search Car by Mark\n";
    std::cout << "\t6. Search Car by Model\n";
    std::cout << "\t7. Filter Car by km\n";
    std::cout << "\t8. Filter Car by age\n";
    std::cout << "\t9. Sort Car by price\n";
    std::cout << "\tu. Switch to user mode\n";
    std::cout << "\tx. Exit\n";
}

std::string Console::get_choice(std::string choice_template) {
    std::string choice;
    std::cout << "Your choice:";
    std::getline(std::cin, choice);
    while (choice_template.find(choice) == std::string::npos || choice.length()!=1) {
        std::cout << "Invalid choice!\n";
        std::cout << "Your choice:";
        std::getline(std::cin, choice);
    }
    return choice;
}


void Console::manager_add_car() {
    std::string make, model, year_of_production, km, price, performance, fuel;
    std::cout << "\nEnter new Car name:";
    std::getline(std::cin, make);
    std::cout << "\nEnter new Car origin:";
    std::getline(std::cin, model);
    std::cout << "\nEnter new Car year of production:";
    std::getline(std::cin, year_of_production);
    while(!Check_Int_Valid(year_of_production))
    {
        std::cout << "Year is invalid\n";
        std::cout << "Enter new Car year of production:";
        std::getline(std::cin, year_of_production);
    }
    std::cout << "\nEnter new Car km:";
    std::getline(std::cin, km);
    while(!Check_Int_Valid(km))
    {
        std::cout << "Car km is invalid\n";
        std::cout << "Enter new Car km:";
        std::getline(std::cin, km);
    }
    std::cout << "\nEnter new Car price:";
    std::getline(std::cin, price);
    while(!Check_Double_Valid(price))
    {
        std::cout << "Car price is invalid\n";
        std::cout << "Enter new Car price:";
        std::getline(std::cin, price);
    }
    std::cout << "\nEnter new Car performance:";
    std::getline(std::cin, performance);
    while(!Check_Int_Valid(performance))
    {
        std::cout << "Car performance is invalid\n";
        std::cout << "Enter new Car performance:";
        std::getline(std::cin, performance);
    }
    std::cout << "\nEnter new Car fuel:";
    std::getline(std::cin, fuel);
    controller.add_car(make, model, stoi(year_of_production), stoi(km), stod(price), stoi(performance), fuel);
    std::cout << "\nSuccessfully added the Car!\n\n";
}

void Console::manager_remove_car() {
    std::string id_old;
    std::cout << "Enter Car ID:";
    std::getline(std::cin, id_old);
    while(!Check_Int_Valid(id_old))
    {
        std::cout << "ID is invalid\n";
        std::cout << "Enter Car ID:";
        std::getline(std::cin, id_old);
    }
    controller.remove_car(stoi(id_old));
    std::cout << "\nSuccessfully removed Car!\n\n";
}

void Console::manager_update_car() {
    std::string id_old, make, model, year_of_production, km, price, performance, fuel;
    std::cout << "Enter Car ID:";
    std::getline(std::cin, id_old);
    while(!Check_Int_Valid(id_old))
    {
        std::cout << "ID is invalid\n";
        std::cout << "Enter Car ID:";
        std::getline(std::cin, id_old);
    }
    std::cout << "\nEnter new Car name (empty to leave unchanged):";
    std::getline(std::cin, make);
    std::cout << "\nEnter new Car origin (empty to leave unchanged):";
    std::getline(std::cin, model);
    std::cout << "\nEnter new Car year of production (empty to leave unchanged):";
    std::getline(std::cin, year_of_production);
    while(!Check_Int_Valid(year_of_production) && year_of_production!="")
    {
        std::cout << "Year is invalid\n";
        std::cout << "Enter new Car year of production (empty to leave unchanged):";
        std::getline(std::cin, year_of_production);
    }
    std::cout << "\nEnter new Car km (empty to leave unchanged):";
    std::getline(std::cin, km);
    while(!Check_Int_Valid(km))
    {
        std::cout << "Car km is invalid\n";
        std::cout << "Enter new Car km (empty to leave unchanged):";
        std::getline(std::cin, km);
    }
    std::cout << "\nEnter new Car price (empty to leave unchanged):";
    std::getline(std::cin, price);
    while(!Check_Double_Valid(price))
    {
        std::cout << "Car price is invalid\n";
        std::cout << "Enter new Car price (empty to leave unchanged):";
        std::getline(std::cin, price);
    }
    std::cout << "\nEnter new Car performance (empty to leave unchanged):";
    std::getline(std::cin, performance);
    while(!Check_Int_Valid(performance))
    {
        std::cout << "Car performance is invalid\n";
        std::cout << "Enter new Car performance (empty to leave unchanged):";
        std::getline(std::cin, performance);
    }
    std::cout << "\nEnter new Car fuel (empty to leave unchanged):";
    std::getline(std::cin, fuel);
    controller.update_car(stoi(id_old), make, model, year_of_production, km, price, performance, fuel);
    std::cout << "\nSuccessfully updated Car!\n\n";
}

void Console::print_cars() {
    for (auto &element : controller.get_car_list())
        std::cout << element.car_to_string() << "\n";
}

void Console::add_user_favourites(){
    std::string id_old;
    std::cout << "Enter Car ID:";
    std::getline(std::cin, id_old);
    controller.add_favourite(stoi(id_old));
}

void Console::print_user_favourites() {
    for (auto &element : controller.return_favourite())
        std::cout << element.car_to_string() << "\n";
}

void Console::search_by_mark() {
    std::string mark;
    std::cout << "Enter Car Mark:";
    std::getline(std::cin, mark);
    for (auto &element : controller.return_by_mark(mark)) {
        std::cout << element.car_to_string() << "\n";
    }
}

void Console::search_by_model() {
    std::string model;
    std::cout << "Enter Car Model:";
    std::getline(std::cin, model);
    for (auto &element : controller.return_by_model(model)) {
        std::cout << element.car_to_string() << "\n";
    }
}

void Console::filter_by_km() {
    std::string km;
    std::cout << "Enter Car Km:";
    std::getline(std::cin, km);
    while(!Check_Int_Valid(km))
    {
        std::cout << "Car Km is not valid!\n";
        std::cout << "Enter Car Km:";
        std::getline(std::cin, km);
    }
    for (auto &element : controller.return_by_km(stoi(km))) {
        std::cout << element.car_to_string() << "\n";
    }
}

void Console::filter_by_age() {
    std::string age;
    std::cout << "Enter Car age:";
    std::getline(std::cin, age);
    while(!Check_Int_Valid(age))
    {
        std::cout << "Car age is not valid!\n";
        std::cout << "Enter Car age:";
        std::getline(std::cin, age);
    }
    for (auto &element : controller.return_by_age(stoi(age))) {
        std::cout << element.car_to_string() << "\n";
    }
}

void Console::sort_by_price() {
    for (auto &element : controller.sort_by_price())
        std::cout << element.car_to_string() << "\n";
}

}