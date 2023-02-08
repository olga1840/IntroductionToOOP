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
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//                 Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t " << this << endl;
	}
	Fraction(double decimal)
	{
		this->integer = decimal;
		decimal -= integer;
		this->denominator = 1e+9;
		this->numerator = decimal * denominator;
		reduce();
		cout << "DConstructor:\t\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t " << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t " << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t " << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t " << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	            //Operators
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this/other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this+other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this-other;
	}

	//    Type-cast operators

	explicit operator int()const
	{
		return Fraction(*this).to_proper().integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	  
	            //Metods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
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
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
		
	std::ostream& print(std::ostream& os)const
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
};

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

	//Явно вызываем конструктор и создаем временный безымянный объект, 
	//который сразу же возвращается на место вызова
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
//#define COMPARISON OPERATORS
//#define TYPE_CONVERSIONS_BASICS
//#define HOME_WORK_1
#define HOME_WORK_2

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
	return os << "Целое число =" << fraction.get_integer() << "\t Числитель = " << fraction.get_numerator() << "\t Знаменатель = " << fraction.get_denominator();
}
std::istream& operator>>(std::istream& in, Fraction& fraction)
{
	int integer, numerator, denominator;
	in >> integer >> numerator >> denominator;
	Fraction(integer, numerator, denominator);
	return in;

	//int number[3] = {};
	//const int SIZE = 32;
	//char buffer[SIZE] = {};
	//char delimiters[] = "/ ()";

	////is >> buffer;
	//in.getline(buffer, SIZE);

	//int n = 0;	//счетчик чисел в веденной строке
	////https://legacy.cplusplus.com/reference/cstring/strtok/
	//for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	//	number[n++] = atoi(pch);	//функция atoi(...) ASCII-string to integer преобразует строку в число, если строка является числом, т.е., содержит цифры.
	////https://legacy.cplusplus.com/reference/cstdlib/atoi/

	//switch (n)
	//{
	//case 1:fraction.set_integer(number[0]); break;
	//case 2:
	//	fraction.set_numerator(number[0]);
	//	fraction.set_denominator(number[1]);
	//	break;
	//case 3:fraction(number[0], number[1], number[2]);
	//}
}

//Comparison fixed

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(2, 3);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
#endif // CONSTRUCTORS_CHECK
	
	/*Fraction A(2, 3, 4);
	cout << A << endl;*/
		
#ifdef COMPARISON OPERATORS
	double a = 2;
	double b = 3;
	double c = a * b;


	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	Fraction E = A + B;
	E.print();

	Fraction F = A - B;
	F.print();*/

	/*A *= B;
	A.print();

	A /= B;
	A.print();

	A += B;
	A.print();

	A -= B;
	A.print();*/

	++A;
	A.print();

	A++;
	A.print();

	--A;
	A.print();

	A--;
	A.print();

	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
	cout << (A >= B) << endl;
	cout << (A <= B) << endl;
#endif // COMPARISON OPERATORS

#ifdef TYPE_CONVERSIONS_BASICS 
	int a = 2;       //no conversions
	double b = 3;    //conversion from less to more
	int c = b;       // conversion from more to less with no data loss
	int d = 4.5;     //conversion from more to less with data loss  
#endif // TYPE_CONVERSIONS_BASICS 

	//Fraction A = 5;  //Conversion from other to class preformed by Single
	//A.print();

	//Fraction B;
	//B = 8;
	//B.print();

	/*Fraction A(11, 4);
	A.print();
	int a = A;
	cout << a << endl;*/

#ifdef HOME_WORK_1
	Fraction B(2, 3, 4);
	double b = (double)B;
	cout << b << endl;
#endif //HOME_WORK_1

#ifdef HOME_WORK_2
	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif //HOME_WORK_2

}