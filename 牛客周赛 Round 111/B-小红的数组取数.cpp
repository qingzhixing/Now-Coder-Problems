#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max_number{-100}, min_number{100};
	int max_index, min_index;

	int value;

	for (auto i = 1; i <= n; i++)
	{
		cin >> value;
		if (value < min_number)
		{
			min_number = value;
			min_index = i;
		}
	}

	for (auto i = 1; i <= n; i++)
	{
		cin >> value;
		if (value > max_number)
		{
			max_number = value;
			max_index = i;
		}
	}

	printf("%d %d\n", min_index, max_index);
	return 0;
}