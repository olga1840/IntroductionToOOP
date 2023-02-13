#include"String.h"

#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	String str(5);
    str.print();

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
	str4.print();

	/*str1 = str3;
	cout << str1 << endl;*/
#endif // BASE_CHECK

}
