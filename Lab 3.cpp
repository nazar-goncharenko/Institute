#include <iostream>
#include <fstream>
#include "windows.h"




using namespace std;

int Name_Array = 65; 


double* File_List(ifstream* read, int);										//--------Створення Множини--------------------
void Matrix(double a[], double b[], int power);								//--------Створення і відобреження матриці-----
double* Create_List(int);													//--------Створення Множини--------------------
void Refl(double** Matrix, int N);											//--------Рефлективність-----------------------
void Simetric(double** Matrix, int N);										//--------Симетричність------------------------
void Tranz(double** Matrix, int N);											//--------Транзитивність-----------------------
void File_type();				//  ------Введення файлами -----------
void Hard_Type();				//	------Введення в ручну -----------



int main()
{
	cout << "Enter number for choose:"
		<< "\nFor write type enter		1"
		<< "\nFor file type enter		2\nEnter: ";
	int k = 11;
	cin >> k;
	if ( k == 1 ) Hard_Type();
	else if (k == 2) File_type();
	else
	{
		cerr << "Error";
		exit(2);
	}
	return 0;
}


//template <class A, class P>
void Matrix(double a[], double b[], int power)
{
	double** Matrix = new double*[power];
	for (int i = 0; i < power; i++)
	{
		Matrix[i] = new double[power];
	}
	for (int y = 0; y < power; y++)
	{
		for (int x = 0; x < power; x++)
		{
			if (2 * a[x] < b[y]) Matrix[x][y] = 1;
			else Matrix[x][y] = 0;
		}
	}
	


	for (int y = 0; y < power; y++)
	{
		for (int x = 0; x < power; x++)
		{
			cout << Matrix[x][y] << "   ";
		}
		cout << "\n" <<endl;
	}
	Refl(Matrix, power);
	Simetric(Matrix, power);
	Tranz(Matrix, power);
	cout << "\n\n";
	delete[] Matrix;
}



double* Create_List(int n)
{
	cout << "Enter " << n << " elements for array " << char(Name_Array) << " : ";
	::Name_Array++;
	double* List = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> List[i];
	}
	return List;
}





void Refl(double** Matrix, int N)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		if (Matrix[i][i] == 0)
		{
			cout << "Не рефлексивне.\n";
			temp = 1;
			break;
		}
	}
	if (temp == 0) cout << "Рефлексивне.\n";
}

void Simetric(double** Matrix, int N)
{
	int temp = 0,T=0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
// --------Симетрична----------------- //
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Matrix[i][j] == 1 && i != j) T++;
			if ((Matrix[i][j] == 1 ) && (Matrix[j][i] != 1))
			{
				temp = 1;
				goto antisim;
				break;
			}
		}
	}
	goto end;
// --------Антисиметрична------------ //
antisim:
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Matrix[i][j] == 1 && Matrix [j][i] == 1 && i != j)
			{
				temp = 2;
				break;
			}
		}
	}
end:
	if (temp == 0 && T !=0) cout << "Симетричне.\n";
	if (temp == 1) cout << "Антисиметричне.\n";
	if (temp == 2 || (temp == 0 && T == 0)) cout << "Асиметричне.\n";
}


void Tranz(double** Matrix, int N)
{
	int temp = 0,T=0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if ((Matrix[i][j] == 1) && ( Matrix[j][k] == 1))
				{
					if (Matrix[i][k] != 1)
					{
						temp = 1;
						break;
					}
				}
			}
		}
	}
	if (temp == 0) cout << "Транзитивне.\n";
	if (temp == 1) cout << "Не транзитивне.\n";
}


double* File_List(ifstream* read,int power)
{
	double* List_f = new double[power];
	for (int i=0; i < power; i++)
	{
		*read >> List_f[i];
	}
	return List_f;
}


void File_type()
{
	int x;
	ifstream read1("test1.txt");									//Не рефлексивне. Асиметричне. Транзитивне.
	read1 >> x;
	Matrix(File_List(&read1, x), File_List(&read1, x), x);
	ifstream read2("test2.txt");									//Рефлексивне Acиметричне Транзитивне
	read2 >> x;
	Matrix(File_List(&read2, x), File_List(&read2, x), x);
	ifstream read3("test3.txt");									//Не рефлексивне Антисиметричне Транзитивне
	read3 >> x;
	Matrix(File_List(&read3, x), File_List(&read3, x), x);
	ifstream read4("test4.txt");									//Не рефлексивне. Асиметричне. Не транзитивне.
	read4 >> x;
	Matrix(File_List(&read4, x), File_List(&read4, x), x);			
	}
void Hard_Type()
{
	int x;
	cout << "Enter a power of arraies : ";
	cin >> x;
	Matrix(Create_List(x), Create_List(x), x);
}