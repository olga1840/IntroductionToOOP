#include<iostream>
using namespace std;

class String
{
	int size;		//размер строки
	char* str;		//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	//				Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}

	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}
	std::ostream& operator<<(std::ostream& os, const String& obj)
	{
		return obj.print(os);
	}

	//				Methods:
	std::ostream& print(std::ostream& os)const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*String str1(5);
	str1.print();*/

	String str1 = "Hello";
	cout << str1 << endl;
}
