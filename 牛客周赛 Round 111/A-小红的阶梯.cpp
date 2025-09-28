#include <iostream>
using namespace std;

int main()
{
	int number1, number2, number3;
	cin >> number1 >> number2 >> number3;
	if (number2 == (number1 + 1) && number3 == (number2 + 1))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}