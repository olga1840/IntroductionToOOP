#include<iostream>
using namespace std;

class Matrix
{
	int** M;   //матрица
	int rows;   //количество строк
	int cols;   //количество столбцов
public:
	int get_M(int rows, int cols)
	{
		if ((rows > 0) && (cols > 0))return M[rows][cols];
		else return 0;
	}
	void setMij(int i, int j, int value)
	{
		if ((i < 0) || (i >= rows))return;
		if ((j < 0) || (j >= cols))return;
		M[i][j] = value;
	}

	//Constructors
	explicit Matrix()  //конструктор по умолчанию, выделяем память, инициализируем 0)
	{
		this->rows = 0;
		this->cols = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	Matrix(const int rows, int cols) //конструктор с одним параметром
	{
		this->rows = rows;
		this->cols = 0;
		this->M = new int* [rows];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Matrix(const int cols, int rows)
	{
		this->rows = 0;
		this->cols = cols;
		this->M = new int* [cols];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Matrix(int m, int n) //конструктор с двумя параметрами
	{
		this->rows = rows;
		this->cols = cols;
		M = new int* [rows];                              //выделяем память для массива указателей, количество строк, количество указателей
		for (int i = 0; i < rows; i++)this->M[i] = new int[cols];  //выделяем память для каждого указателя

		for (int i = 0; i < rows; i++)                     //заполняем массив нулями
			for (int j = 0; j < cols; j++)
				M[i][j] = 0;
		cout << "Constructor:\t\t " << this << endl;
	}
	Matrix(const Matrix& other) //конструктор копирования
	{
		this->rows = other.rows;
		this->cols = other.cols;
		int** M = new int* [rows];
		for (int i = 0; i < rows; i++)M[i] = new int[cols];
		for (int i = 0; i< rows; i++)
			for (int j = 0; j < cols; j++)
				this->M[i][j] = other.M[i][j];
		cout << "CopyConstructor\t" << this << endl;
	}
	~Matrix()
	{
		delete this->M;
		cout << "Destructor:\t" << this << endl;
	}

	//Operators
	Matrix& operator=(const Matrix& other)
	{
		if (cols > 0)for (int i = 0; i < rows; i++) delete[] M[i];
		if (rows > 0)delete[] M;
		this->rows = other.rows;
		this->cols = other.cols;
		M = new int* [rows];
		for (int i = 0; i < rows; i++)M[i] = new int[cols];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->M[i][j] = other.M[i][j];
		cout << "CopyAssignment:\t" << endl;
		return *this;
	}

	//Methods
	void Print(const char* objMatrix)
	{
		cout << "Matrix: " << objMatrix << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << M[i][j] << "\t" << endl;
		}
		cout << endl;
	}
};



void main()
{
	setlocale(LC_ALL, "");
	
	Matrix M(2, 3);
	M.Print("M");

}