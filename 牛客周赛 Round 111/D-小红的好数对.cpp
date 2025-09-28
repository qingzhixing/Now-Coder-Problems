// TODO: Wrong Code
#include <iostream>
using namespace std;

const static int MAX_N = (2e5 + 10);

int n;

int num_array[MAX_N];

bool is_good_number(int number1, int number2)
{
	int temp = number2;
	long long new_number = number1;
	while (temp)
	{
		temp /= 10;
		new_number *= 10;
	}
	new_number += number2;

	return new_number % 11 == 0;
}

int main()
{
	cin >> n;
	for (int index = 1; index <= n; index++)
	{
		cin >> num_array[index];
	}

	long long answer{};

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (is_good_number(num_array[i], num_array[j]))
			{
				answer++;
			}
		}
	}

	// 正反各自算一次
	cout << answer * 2 << endl;
	return 0;
}