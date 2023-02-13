#include"Fraction.h"

//Comparison fixed

//#define CONSTRUCTORS_CHECK
//#define COMPARISON OPERATORS
//#define TYPE_CONVERSIONS_BASICS
//#define HOME_WORK_1
#define HOME_WORK_2

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