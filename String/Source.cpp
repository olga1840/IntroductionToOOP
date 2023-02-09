#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;		//размер строки в байтах
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
	char* get_str()
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
	String(const char* str)
	{
		this->size = strlen(str) + 1; //функция strlen() возвращает размер строки в символах
		this->str = new char[size] {};     //но в классе хранится размер строки с учетом терминирующего нуля
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor:" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << endl;
	}
	String(String&& other)noexcept
	{
		this->size = other.size;
		this->str = other.str;       //Shallow copy
		other.size = 0;
		other.str = nullptr;         // nullptr - указатель на ноль
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//              Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char& operator[](int i)
	{
		return str[i];
	}
	const char& operator[](int i)const
	{
		return str[i];
	}

	


	//				Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}
//#define BASE_CHECK

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	/*String str1(5);
str1.print();*/

	String str1 = "Hello"; //Helo - строковая константа
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;
	cout << "\n__________________________" << endl;

	/*str1 += str2;
	cout << str1 << endl;*/

	//String str3 = str1 + str2;  //move constructor
	String str3;	//Default constructor
	str3 = str1 + str2;//Move assignment
	cout << str3 << endl;

	String str4 = str3;  //copy constructor

	/*str1 = str3;
	cout << str1 << endl;*/
#endif // BASE_CHECK

}
