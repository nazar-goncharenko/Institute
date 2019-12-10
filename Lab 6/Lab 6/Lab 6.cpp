#include <iostream>
using namespace std;




int fact(int a)
{
	if (a == 0)
		return 1;
	else
		return a * fact(a - 1);
}

void Print(int* a,int r);

void Func(int n, int r)
{
	int* a = new int[r];
	for (int i = 0; i < r; i++)
	{
		a[i] = 1;
	}
	for (int i = 0; i < (int)pow(n,r); i++)
	{
		Print(a, r);
		cout << endl;
		for (int k = r - 1; k >= 0; k--)
		{
			
			if (a[k] < n)
			{
				a[k]++;
				for (int y = k + 1; y < r; y++)
				{
					a[y] = 1;
				}
				break;
			}
			else
			{
				a[k] = 1;
				for (int y = k; y >= 0; y--)
				{

					if (a[y] < n)
					{
						a[y]++;
						break;
					}
					else
					{
						cout << "wkwefkwekef\n";
						--i;
						break;
					}
					break;
				}
			}
		}

	}



}

void Print(int* a, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << a[i];
	}
}



int bci(int n, int k)
{
	return fact(n) / (fact(k) * fact(n - k));
}


void binom(int x, int y,int n)
{
	int j = 0 , i = n;
	cout << "(" << x << "-" << y << ")^7=";
	for (int k = 0; k < n / 2 + 1; k++)
	{
		if (!(k % 2))
			cout << "+";
		else
			cout << "-";
		cout << bci(n, k) << "*" << x << "^" << i << "*" << y << "^" << j << " ";
		i--;
		j++;
	}
	for (int k = n / 2 + 1; k < n + 1; k++)
	{
		if (!(k % 2))
			cout << "+";
		else
			cout << "-";
		cout << bci(n, k) << "*" << x << "^" << i << "*" << y << "^" << j << " ";
		i--;
		j++;

	}
	
}


int main()
{
	int n,r;
	cout << "Enter n: "; cin >> n;
	cout << "Enter r: "; cin >> r;
	Func(n, r);
	cout << endl;
	binom(3, 4,7);



}