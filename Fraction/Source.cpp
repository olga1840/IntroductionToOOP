#include<iostream>
using namespace std;

class Fraction
{
	int integer;    //целая часть
	int numerator; //числитель
	int denominator; //знаменатель

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if(denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
};

void main()
{
	setlocale(LC_ALL, "");

}