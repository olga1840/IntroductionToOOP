#include<iostream>
using namespace std;


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

	// Methods:
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define DISTANCE_CHECK


#ifdef DISTANCE_CHECK
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;
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
#endif //STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "Расстояние от точки А до точки B: " << A.distance(B) << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << "Расстояние между точками B и В: " << distance(B, B) << endl;
	cout << "Расстояние между точками В и А: " << distance(B, A) << endl;
#endif // DISTANCE_CHECK
}
	