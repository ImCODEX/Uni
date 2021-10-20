#include "UI.h"
#include "Controller.h"
#include "Repo.h"
#include "Cars.h"
#include <iostream>
#include "Error.h"
#include <cassert>
using namespace::std;

void test_function(){
    Repository::Repo r;
    Service::Controller c(r);
    c.add_car("Model 3","Tesla",2020,50000,35000,300,"Electric");
    assert(r.GetSize() == 1);
    c.add_car("Model S","Tesla",2020,10000,110000,1100,"Electric");
    assert(r.GetSize() == 2);
    c.add_car("Model Y","Tesla",2020,10000,50000,400,"Electric");
    assert(r.GetSize() == 3);
    c.remove_car(2);
    assert(r.GetSize() == 2);
    try{
        c.remove_car(3);
        assert(false);
    }
    catch(CustomError &e){
        assert(e.get_msg() == "Id not valid");
    }
    
}
void run_application() {
    Repository::Repo r;
    Service::Controller c(r);
    c.initialise_cars();
    UI::Console con(c);
    con.run_console();
}

int main() {
	//Team AG17 Popescu Dragos-Septimiu,Postescu Razvan
    test_function();
    run_application();
    return 0;
}