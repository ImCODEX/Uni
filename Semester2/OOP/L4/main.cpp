#include "UI.h"
#include "Error.h"
#include <cassert>
using namespace::std;

void test_function(){
    std::vector<Domain::Product> product_vector;
    Repository::Repo r(product_vector);
    Service::Controller c(r);
    c.add_product("Rosii", "Italia", "10/01/2021", 10, 2);
    assert(product_vector[0] == Domain::Product("Rosii", "Italia", "10/01/2021", 10, 2));
    c.add_product("Rosii", "Italia", "10/01/2021", 10, 20);
    assert(product_vector[0] == Domain::Product("Rosii", "Italia", "10/01/2021", 10, 20));
    c.add_product("Rosii", "Spania", "10/02/2021", 140, 3);
    c.update_product("Rosii", "Spania", "Kiwi", "Maroc", "05/05/2021", "10", "");
    assert(product_vector[1] == Domain::Product("Kiwi", "Maroc", "05/05/2021", 10, 3));
    c.add_product("Mere", "Romania", "10/03/2021", 30, 4);
    c.add_product("Banane", "Germania", "21/03/2021", 10, 2);
    c.add_product("Capsuni", "Spania", "11/03/2021", 40, 15);
    c.remove_product("Rosii", "Italia");
    try{
        c.remove_product("Rosii", "Italia");
        assert(false);
    }
    catch(CustomError &e){
        assert(e.get_msg() == "Product not in list");
    }
    
}
void run_application() {
    std::vector<Domain::Product> product_vector;
    Repository::Repo r(product_vector);
    Service::Controller c(r);
    c.initialise_products();
    UI::Console con(c);
    con.run_console();
}

int main() {
    test_function();
    run_application();
    return 0;
}