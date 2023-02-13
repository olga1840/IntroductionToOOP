#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
std::istream& operator>>(std::istream& in, Fraction& fraction)

class Fraction
{
	int integer;    //целая часть
	int numerator; //числитель
	int denominator; //знаменатель

public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//                 Constructors:
	Fraction();
	Fraction(double decimal);
	explicit Fraction(int integer);
	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	//Operators
	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);

	//    Type-cast operators

	explicit operator int()const;
	explicit operator double()const;


	//Metods:
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	std::ostream& print(std::ostream& os)const;
};