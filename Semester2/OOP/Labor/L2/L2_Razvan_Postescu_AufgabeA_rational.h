#pragma once

class Rational{
    public:
        Rational();
        Rational(int, int);
        Rational(const Rational&);
        void printRational();
        int get_zahler();
        int get_nenner();
        void set_zahler(int);
        void set_nenner(int);
        Rational add(const Rational&);
        Rational operator +(const Rational&);
        Rational sub(const Rational&);
        Rational operator -(const Rational&);
        Rational multiply(const Rational&);
        Rational operator *(const Rational&);
        Rational divide(const Rational&);
        Rational operator /(const Rational&);
        int gcd(int, int);
        void reduce();
        void inverse();
        int compare(const Rational&);

    private:
        int zahler;
        int nenner; 

};