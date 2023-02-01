#include<iostream>
using namespace std;

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
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t " << this << endl;
	}
	Fraction(int integer)
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
		cout << "Constructor:\t " << this << endl;
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
		
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
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

bool operator==(const Fraction& left, const Fraction& right)
{
	return
		(
			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) == (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
		);
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return
		(
			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) != (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
		);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	return
		(
			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) > (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
		);
}
bool operator<(const Fraction& left, const Fraction& right)
{
	return
		(
			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) < (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
		);
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return
		(
			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) >= (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
		);
}
bool operator<=(const Fraction & left, const Fraction & right)
{
	return
		(
			((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) <= (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()))
		);
}


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
}