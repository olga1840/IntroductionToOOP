#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n-----------------------------------"


// Класс - это тип данных;
// Структура - это тип данных

class Point     //Создавая структуру или класс, мы создаем новый тип данных.
{//Классы или структуры еще называют пользовательскими (составными) типами данных
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//                     Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

    //                   Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

		//                    Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

bool operator==(const Point& left, const Point& right)
{
	return left.get_x == right.get_x() && left.get_y() == right.get_y();
}

 bool operator!= (const Point& left, const Point& right)
 {
	 return left.get_x() != right.get_x() || left.get_y() != right.get_y();
 }

 std::ostream& operator<<(std::ostream& os, const Point&  obj)
 {
	 return os << "X = " << obj.get_x() << "\t Y = " << obj.get_y();
 }
 std::istream& operator>>(std::istream& is, Point& obj)
 {
	double x, y;
	is >> x >> y;
	obj (x, y);
	return is;
 }

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK_1
//#define ASSIGNMENT_CHECK_2

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello OOP" << endl;
#ifdef STRUCT_POINT

	int a;     //объявление переменной типа 'а' типа 'int'
	Point A;   //бъявленние переменной 'A' типа 'Point'
	//           //Объявление объекта 'А' структуры 'Point'
	//           //Создание экземпляра 'А' структуры 'Point'
	////Объекты часто называют экземплярами класса или структуры.

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;


#endif // DISTANCE_CHECK

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки А до точки B: " << A.distance(B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками B и В: " << distance(B, B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками В и А: " << distance(B, A) << endl;
	cout << delimeter << endl;
#endif //STRUCT_POINT


#ifdef CONSTRUCTORS_CHECK
	Point A;
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B(2, 3);
	B.print();

	Point C = 4;
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK_1
	//CopyAssignment
	Point A(2, 3);
	A.print();
	Point B = A;   //CopyConstructor
	B.print();
	Point C;       //DefaultConstructor
	C = B;         //Assignment operator
	C.print();
#endif // ASSIGNMENT_CHECK_1

#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point(2, 3);
	//Point(2, 3) - явный вызов конструктора, и этот конструктор создает временный безымянный объект
	//Временные безымянные объекты существуют в пределах одного выражения  
#endif // ASSIGNMENT_CHECK_2


	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	cout << delimeter << endl;
	++C;
	C.print();
	cout << delimeter << endl;
	C++;
	C.print();

	/* Точка А(2, 3);
Пункт B(4, 5);
cout << (A != B) << endl;*/

	Point A(2, 3);
	A.print();

	/*A.set_x(12);
 A.set_y(13);*/
	A (22, 33);
	//A.print();
	cout << A << endl;

	cout << "Введите координаты точки: ";

	cin >> A;

	cout << A << endl;
}

