#include <iostream>
#include <string>
using namespace std;

void _xor(float a[], int power_a, float b[], int power_b, float c[], int* T);
bool is_numeric_f(string);
bool is_numeric_i(string);
void SortArr(float a[], int SIZE);
int k = 1;
void EnterArr(float a[], int power)
{
	string x;
	float T;
	cout << "Enter a numeric : ";
	for (int i = 0; i < power; i++)
	{
		cin >> x;
		if ( is_numeric_f(x) == 1)
		{
			T = stof(x);
			a[i] = T;
		}
		else cout << "You entered an incorect value."<< endl , ::k = 0;
	}
	SortArr(a, power);
}

void RandArr(float a[], int const SIZE , int k)
{
	for (int i = 0; i < SIZE ; i++)
	{
		a[i] = (rand() % k);
	}
	SortArr(a, SIZE);
}

void PrintArr(float a[], int const SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << a[i] << " ";
	}
}

void SortArr(float a[] ,int SIZE)
{
	int A = SIZE;
	for ( ; A > 0 ; A-- )
	{
		float max = 0, t;
		int max_i = 0;
		for (int i = 0; i < A; i++)
		{
			if (a[i] > max)
			{
				max = a[i];
				max_i = i;
			}
		}
		t = a[A - 1];
		a[A - 1] = max;
		a[max_i] = t;

	}
}

void Povt(float a[], int* T)
{
	for (int i = 0; i < *T; i++)
	{
		if (a[i] == a[i + 1])
		{
			for (int k = i; k < *T; k++)
			{
				a[k] = a[k + 1];
			}
			--*T;
		}
	}

}

void _xor(float a[] , int power_a, float b[], int power_b, float c[] , int *T )
{
	int k = *T, temp = 0;
	for (int i = 0; i <= power_a ; i++)
	{
		temp = 0;
		for (int j = 0; j <= power_b; j++)
		{
			if (a[i] == b[j])
			{
				temp = 1;
			}
		}
		if (temp != 1)
		{
			c[k] = a[i]; 
			k++;
		}
	}
	*T = k;
}


bool is_numeric_f(string x)
{
	char c1 = '.';
	char c2 = ',';
	for (int i = 0; i < x.size(); i++)
	{
		if (isdigit(x[i]) == 0 && x[i]!=c1 && x[i]!=c2)
		{
			return 0;
			break;
		}
	}
	return 1;
}
bool is_numeric_i(string x)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (isdigit(x[i]) == 0)
		{
			return 0;
			break;
		}
	}
	return 1;
}



int main()
{
	int const SIZE = 100;
	float A[SIZE];
	float B[SIZE];
	float C[SIZE];
	string s_p1, s_p2;
	int power1, power2, T = 0;
	cout << "Enter an array power A : ";
	cin >> s_p1;
	if (is_numeric_i(s_p1) != 0)
	{
		power1 = stoi(s_p1);
		EnterArr(A, power1);
		//RandArr(A, power1, 10);
		if (is_numeric_i(s_p1) == 0)
		{
			cout << "You entered an incorect data.\n"; 
			::k = 0;
		}
	}
	if (is_numeric_i(s_p1) == 0)	cout << "You entered an incorect data.\n",::k = 0;
	cout << "Enter an array power B : ";
	cin >> s_p2;
	if (is_numeric_i(s_p2) != 0)
	{
		power2 = stoi(s_p2);
		EnterArr(B, power2);
		//RandArr(B, power2 , 10);
	}
	if (is_numeric_i(s_p2) == 0) cout << "You entered an incorect data.", ::k = 0;
	if (::k != 0)
	{
		_xor(A, power1, B, power2, C, &T);
		_xor(B, power2, A, power1, C, &T);
		SortArr(C, T);
		Povt(C, &T);
		cout <<"Array C: ";
		PrintArr(C, T);
		cout << "\nPower of array : " << T << '.';
	}
	else if (::k == 0)
	{
		cout << "\nEntered data are incorect.";
	}
}
