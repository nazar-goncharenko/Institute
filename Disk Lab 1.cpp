#include <iostream>

using namespace std;
int i = 1;
string line = "------------------------------";

// кон*юкція
bool kon(int a, int b) {
	if ((a && b) == 1) {
		cout << ::i << "\t\t" << a << " &&  " << b << "\t" << 1 << endl;
		::i++;
		return 1;
	}
	else {
		cout << ::i << "\t\t" << a << " &&  " << b << "\t" << 0 << endl;
		::i++;
		return 0;
	}
}
// диз*юкція
bool diz(int a, int b) {
	if ((a || b) == 1) {
		cout << ::i << "\t\t" << a << " ||  " << b << "\t" << 1 << endl;
		::i++;
		return 1;
	}
	else {
		cout << ::i << "\t\t" << a << " ||  " << b << "\t" << 0 << endl;
		::i++;
		return 0;
	}
}
// імпліфікація
bool imp(int a, int b) {
	if ((a == 1) && (b == 0)) {
		cout << ::i << "\t\t" << a << " --> " << b << "\t" << 0 << endl;
		::i++;
		return 0;
	}
	else {
		cout << ::i << "\t\t" << a << " --> " << b << "\t" << 1 << endl;
		::i++;
		return 1;
	}
}
// заперечення , "не"
bool zap(int a) {
	if (a == 0) {
		cout << ::i << "\t\t" << "  !" << a << "  \t" << 1 << endl;
		::i++;
		return 1;
	}
	else {
		cout << ::i << "\t\t" << "  !" << a << "  \t" << 0 << endl;
		::i++;
		return 0;
	}
}
// альтернативне "або"
bool altdiz(int a, int b) {
	if (a != b) {
		cout << ::i << "\t\t" << a << " xor " << b << "\t" << 1 << endl;
		::i++;
		return 1;
	}
	else {
		cout << ::i << "\t\t" << a << " xor " << b << "\t" << 0 << endl;
		::i++;
		return 0;
	}
}
// еквівалентність
bool ekv(bool a, bool b)
{
	if (a == b)
	{
		cout << ::i << "\t\t" << a << " <=> " << b << "\t" << 1 << endl;
		::i++;
		return 1;
	}
	else
	{
		cout << ::i << "\t\t" << a << " <=> " << b << "\t" << 0 << endl;
		::i++;
		return 0;
	}
}

int main() {
	bool p, q, r, k;
	cout << "Write x, y, z: ";
	cin >> p;
	cin >> q;
	cin >> r;
	if (((q == 0 || q == 1) && (p == 0 || p == 1)) && (r == 0 || r == 1))
	{
		// delete /* to switch
		/* <-- delete to switch no table{

		cout << "write task: ";
		cin >> k;}
	*/
		cout << "Input: " << "x = " << p << " |\t" << "y = " << q << " |\t" << "z = " << r << "\n" << ::line << endl;
		// Write task here 
		{
			k = imp( imp( p , imp( q , r ) ) , imp( kon( p , q ) , r ));
		}
		cout << "   Answer " << k << endl;
	}
	else 
	{
		cout << "You entered incorrect data." << endl;

	}
	{

	}
	return 0;
}
