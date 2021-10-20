/*  Labor2 - Aufgabe
    Rational Class
*/

#include "L2_Razvan_Postescu_AufgabeA_rational.h"
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
using std::exception;

int main()
{
    //Test Cases for all methods
    //Div 0 Cases are commented because the execution of the programm stops there
    //if the constructor tries to create a Rational Number with 0 as nenner
    cout << "Test 1 for add Method: " << endl;
    Rational a = Rational(1, 2);
    Rational b = Rational(1, 2);
    a = a.add(b);
    a.printRational();

    cout << "Test 2 for add Method: " << endl;
    Rational a1 = Rational();
    Rational b1 = Rational(1, 2);
    a1 = a1.add(b1);
    a1.printRational();

    cout << "Test 3 for add Method: " << endl;
    Rational a_1 = Rational(1, 2);
    Rational b_1 = Rational(1, 2);
    a_1 = a_1 + b_1;
    a_1.printRational();

    cout << "Test 1 for sub Method: " << endl;
    Rational a2 = Rational(1, 4);
    Rational b2 = Rational(1, 2);
    a2 = a2.sub(b2);
    a2.printRational();

    cout << "Test 2 for sub Method: " << endl;
    Rational a3 = Rational(1, 4);
    Rational b3 = Rational();
    a3 = a3.sub(b3);
    a3.printRational();

    cout << "Test 3 for sub Method: " << endl;
    Rational a_2 = Rational(1, 4);
    Rational b_2 = Rational(1, 2);
    a_2 = a_2 - b_2;
    a_2.printRational();

    cout << "Test 1 for multiply Method: " << endl;
    Rational a4 = Rational(1, 4);
    Rational b4 = Rational();
    a4 = a4.multiply(b4);
    a4.printRational();

    cout << "Test 2 for multiply Method: " << endl;
    Rational a5 = Rational(1, 4);
    Rational b5 = Rational(3, 7);
    a5 = a5.multiply(b5);
    a5.printRational();

    cout << "Test 3 for multiply Method: " << endl;
    Rational a_5 = Rational(1, 4);
    Rational b_5 = Rational(3, 7);
    a_5 = a_5 * b_5;
    a_5.printRational();

    cout << "Test 1 for divide Method: " << endl;
    Rational a6 = Rational(1, 4);
    Rational b6 = Rational();
    try{ 
        a6 = a6.divide(b6);
        assert(false);
    }
    catch(std::exception &){
        cout<<"div 0"<<endl;
        assert(true);
    }
    a6.printRational();

    cout << "Test 2 for divide Method: " << endl;
    Rational a7 = Rational(10, 2);
    Rational b7 = Rational(5, 1);
    a7 = a7.divide(b7);
    a7.printRational();

    cout << "Test 3 for divide Method: " << endl;
    Rational a_7 = Rational(10, 2);
    Rational b_7 = Rational(5, 1);
    a_7 = a_7 / b_7;
    a_7.printRational();

    cout << "Test 1 for reduce Method: " << endl;
    cout << "Before reduce: ";
    a1.printRational();
    a1.reduce();
    cout << "After reduce: ";
    a1.printRational();

    cout << "Test 2 for reduce Method: " << endl;
    cout << "Before reduce: ";
    a2.printRational();
    a2.reduce();
    cout << "After reduce: ";
    a2.printRational();

    cout << "Test 1 for inverse Method: " << endl;
    cout << "Before inverse: ";
    a1.printRational();
    a1.inverse();
    cout << "After inverse: ";
    a1.printRational();

    cout << "Test 2 for inverse Method: " << endl;
    cout << "Before inverse: ";
    b3.printRational();
    //b3.inverse();
    cout << "After inverse: ";
    b3.printRational();

    cout << "Test 1 for compare Method: " << endl;
    cout << " The Numbers: " << endl;
    Rational a8 = Rational(2, 4);
    Rational b8 = Rational(3, 5);
    a8.printRational();
    b8.printRational();
    cout << " Output: " << a8.compare(b8) << endl;

    cout << "Test 2 for compare Method: " << endl;
    cout << " The Numbers: " << endl;
    Rational a9 = Rational(3, 4);
    Rational b9 = Rational(3, 5);
    a9.printRational();
    b9.printRational();
    cout << " Output: " << a9.compare(b9) << endl;

    cout << "Test 3 for compare Method: " << endl;
    cout << " The Numbers: " << endl;
    Rational a10 = Rational(3, 5);
    Rational b10 = Rational(3, 5);
    a10.printRational();
    b10.printRational();
    cout << " Output: " << a10.compare(b10) << endl;

    cout << "List Addition for Rational Objects (with reduce):" << endl;
    Rational RList[6] = {Rational(1, 2), Rational(1, 3), Rational(1, 4), Rational(1, 5), Rational(1, 6), Rational()};
    Rational RSum = Rational();
    for (int i = 0; i <= 5; i++)
    {
        RSum = RSum.add(RList[i]);
        RSum.reduce();
        RSum.printRational();
    }
}