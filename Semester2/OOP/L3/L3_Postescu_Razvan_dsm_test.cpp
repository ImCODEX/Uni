/* Labor3 
POSTESCU RAZVAN
*/

#include "L3_Postescu_Razvan_DSM.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

int main() {
    cout << "Test begin" << endl;
    DSM dsm = DSM(4);
    dsm.set_element_name(0, "Auto");
    dsm.set_element_name(1, "Motor");
    dsm.set_element_name(2, "Getriebe");
    dsm.set_element_name(3, "Raeder");
    dsm.set_element_name(4, "Sitze");
    dsm.set_element_name(5, "Kupplung");
    assert(dsm.size() == 6);
    //Test for set_element_name with not correct index
    try {
        dsm.set_element_name(-1, "ung");
        assert(false);
    } catch (DSMException &e) {
        assert(true);
        //cout << e.get_msg() << endl;
    }
    dsm.add_link("Motor", "Kupplung", 1);
    dsm.add_link("Kupplung", "Motor", 1);
    dsm.add_link("Kupplung", "Getriebe", 1);
    dsm.add_link("Getriebe", "Raeder", 2);
    dsm.add_link("Auto", "Tueren", 2);

    assert(dsm.size() == 7);
    assert(dsm.get_name(6) == "Tueren");

    assert(dsm.count_from_links("Motor") == 1);

    dsm.delete_link("Motor", "Kupplung");
    dsm.delete_link("Kupplung", "Motor");
    
    assert(dsm.have_link("Motor", "Kupplung") == 0);
    assert(dsm.have_link("Kupplung", "Motor") == 0);

    assert(dsm.have_link("Auto", "Tueren"));
    assert(dsm.have_link("Getriebe", "Raeder"));
    assert(dsm.have_link("Raeder", "Getriebe") == 0);

    assert(dsm.link_weight("Kupplung", "Getriebe") == 1);
    assert(dsm.link_weight("Getriebe", "Raeder") == 2);

    assert(dsm.count_all_links() == 3);
    assert(dsm.count_to_links("Getriebe") == 1);
    assert(dsm.count_from_links("Getriebe") == 1);

    assert(dsm.get_name(0) == "Auto");
    assert(dsm.get_name(5) == "Kupplung");
    assert(dsm.calculate_matrix_density() < 1);
    //Test for accessing an index out of range
    try {
        dsm.get_name(8);
        assert(false);
    } catch (DSMException &e) {
        assert(true);
        //cout << e.get_msg() << endl;
    }

    cout << "Test end";
    return 0;
}