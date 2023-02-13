#include"Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}

//                 Constructors:
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefaultConstructor:\t " << this << endl;
}
Fraction::Fraction(double decimal)
{
	this->integer = decimal;
	decimal -= integer;
	this->denominator = 1e+9;
	this->numerator = decimal * denominator;
	reduce();
	cout << "DConstructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1ArgConstructor:\t " << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t " << this << endl;
}

Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t " << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t " << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}
//Operators
Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this = *this - other;
}

//    Type-cast operators

Fraction::operator int()const
{
	return Fraction(*this).to_proper().integer;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}


//Metods:
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()
{
	int more, less, rest = 0;
	if (numerator > denominator)more = numerator, less = denominator;
	else less = numerator, more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;
	numerator /= GCD; //GCD - наибольший общий делитель
	denominator /= GCD;
	return *this;
}
Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction& Fraction::operator--()
{
	integer--;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;
}

std::ostream& Fraction::print(std::ostream& os)const
{
	if (integer)os << integer;
	if (numerator)
	{
		if (integer)os << "(";
		os << numerator << "/" << denominator;
		if (integer)os << ")";
	}
	else if (integer == 0)os << 0;
	//os << endl;
	return os;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	//Fraction result;
	/*(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);*/
	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/

	//явно вызываем конструктор и создаем временный безым€нный объект, 
	//который сразу же возвращаетс€ на место вызова
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()

	).to_proper().reduce();
}


//bool operator==(const Fraction& left, const Fraction& right)
//{
//	return
//		(
//			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) == (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
//		);
//}
//bool operator!=(const Fraction& left, const Fraction& right)
//{
//	return
//		(
//			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) != (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
//		);
//}
//bool operator>(const Fraction& left, const Fraction& right)
//{
//	return
//		(
//			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) > (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
//		);
//}
//bool operator<(const Fraction& left, const Fraction& right)
//{
//	return
//		(
//			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) < (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
//		);
//}
//bool operator>=(const Fraction& left, const Fraction& right)
//{
//	return
//		(
//			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) >= (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
//		);
//}
//bool operator<=(const Fraction & left, const Fraction & right)
//{
//	return
//		(
//			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) <= (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
//		);
//}


//Fraction operator*=(Fraction& left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//	Fraction result
//	(
//		left.get_numerator() * right.get_numerator(),
//		left.get_denominator() * right.get_denominator()
//	);
//	return left = result.to_improper().to_proper();
//}

//Fraction& operator/=(Fraction& left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//	Fraction result = (left * right.inverted());
//	return (left = result.to_improper().to_proper());
//}

//Fraction& operator+=(Fraction& left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//	Fraction result
//	(
//		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
//		left.get_denominator() * right.get_denominator()
//	);
//	return (left = result.to_improper().to_proper());
//}

//Fraction& operator-=(Fraction& left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//
//	Fraction result
//	(
//		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
//		left.get_denominator() * right.get_denominator()
//	);
//	return (left = result.to_improper().to_proper());
//}

//////////////////////////////////////////////////////////////////
/////////////////  Comparison operators    //////////////////////
/////////////////////////////////////////////////////////////////

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, Fraction& right)
{
	return!(left == right);    //не равно
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	//return left < right || left == right;
	return !(left > right);
}

//////////////////////////////////////////////////////////////////


std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
	return os << "÷елое число =" << fraction.get_integer() << "\t „ислитель = " << fraction.get_numerator() << "\t «наменатель = " << fraction.get_denominator();
}
std::istream& operator>>(std::istream& in, Fraction& fraction)
{
	//int integer, numerator, denominator;
	//in >> integer >> numerator >> denominator;
	//fraction(integer, numerator, denominator);
	//return in;

	int number[3] = {};
	const int SIZE = 32;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";

	//is >> buffer;
	in.getline(buffer, SIZE);

	int n = 0;	//счетчик чисел в веденной строке
	//https://legacy.cplusplus.com/reference/cstring/strtok/
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);	//функци€ atoi(...) ASCII-string to integer преобразует строку в число, если строка €вл€етс€ числом, т.е., содержит цифры.
	//https://legacy.cplusplus.com/reference/cstdlib/atoi/

	switch (n)
	{
	case 1:fraction.set_integer(number[0]); break;
	case 2:
		fraction.set_numerator(number[0]);
		fraction.set_denominator(number[1]);
		break;
	case 3:fraction(number[0], number[1], number[2]);
	}
	return in;
}