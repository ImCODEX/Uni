#include "L2_Razvan_Postescu_AufgabeA_rational.h"
#include <iostream>
#include <stdlib.h>
#include <exception>

//default constructor
Rational::Rational(){
    zahler = 0;
    nenner = 1;
}

//initialize constructor
//test if nenner == 0
/*Rational::Rational(int z, int n)
{
    zahler = z;
    if(n==0)
    {
        std::cout << "error: divide 0" << std::endl;
        exit(0);
    }
    else
        nenner = n;

}
*/
Rational::Rational(int z, int n): nenner{n}, zahler{z}{
    if (n == 0){
        throw std::exception();
    }
}

//zahler getter
int Rational::get_zahler(){
    return zahler;
}

//nenner getter
int Rational::get_nenner(){
    return nenner;
}

//zahler setter
void Rational::set_zahler(int other){
    zahler = other;
}

//nenner setter
void Rational::set_nenner(int other){
    nenner = other;
}

//print method
void Rational::printRational()
{
   std::cout << zahler << "/" << nenner << std::endl ;
}

//greatest common divisor with absolute values for the numbers (works with negative numbers)
int Rational::gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(abs(b), abs(a) % abs(b));
}

//reduce method, makes use of gcd 
void Rational::reduce(){
    int x = gcd(zahler, nenner);
    zahler = zahler / x;
    nenner = nenner / x;
}

//addition method
//doesn't reduce by default
Rational Rational::add(const Rational &b){
    return Rational(zahler * b.nenner + b.zahler * nenner , nenner * b.nenner);
}

//add with operator
Rational Rational::operator +(const Rational &b){
    return add(b);
}

//subtract method
//doesn't reduce by default
Rational Rational::sub(const Rational &b){
    return Rational(zahler * b.nenner - b.zahler * nenner , nenner * b.nenner);
}

//sub with operator
Rational Rational::operator -(const Rational &b){
    return sub(b);
}

//multiply method
Rational Rational::multiply(const Rational &b){
    return Rational(zahler * b.zahler, nenner * b.nenner);
}

//multiply with operator
Rational Rational::operator *(const Rational &b){
    return multiply(b);
}

//divide method
Rational Rational::divide(const Rational &b){
    return Rational(zahler * b.nenner, nenner * b.zahler);
}

//divide with operator
Rational Rational::operator /(const Rational &b){
    return divide(b);
}

//inverse of the rational number method
//also checks if the nenner will become 0 
//and stops the execution of the program in that case
void Rational::inverse(){
    int aux;
    if(zahler == 0){
        std::cout << "error: divide 0" << std::endl;
        exit(0);
    }
    aux = zahler;
    zahler = nenner; 
    nenner = aux;
    

}

//compare method for 2 Rational objects
//ex: Rational1.compare(Rational2);
//output:
//1: Rational1 > Rational2
//0: Rational1 = Rational2
//-1: Rational1 < Rational2
int Rational::compare(const Rational &b){
    if(zahler * b.nenner > b.zahler * nenner)
        return 1;
    if(zahler * b.nenner == b.zahler * nenner)
        return 0; 
    return -1; 
}