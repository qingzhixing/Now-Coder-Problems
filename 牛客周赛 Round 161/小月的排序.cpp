#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 10;

// return: popcount, lower_1 digit
pair<int, int> popcount(int number)
{
	int cnt = 0;
	int current_digit = 1;
	int lower_1_digit = 0;

	while (number)
	{
		if (number & 1)
		{
			cnt++;
			if (lower_1_digit == 0)
			{
				lower_1_digit = current_digit;
			}
		}
		current_digit++;
		number >>= 1;
	}

	if (lower_1_digit == 0)
	{
		lower_1_digit = 31;
	}

	return {cnt, lower_1_digit};
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> a(n + 10);

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	sort(a.begin() + 1, a.begin() + 1 + n, [](int a, int b) -> bool
		 {
			 auto [popcount_a, lower_a] = popcount(a);
			 auto [popcount_b, lower_b] = popcount(b);
			 if (popcount_a < popcount_b)
			 {
				 return true;
			 }

			 if (popcount_a > popcount_b)
			 {
				 return false;
			 }

			 if (lower_a < lower_b)
			 {
				 return true;
			 }

			 if (lower_a > lower_b)
			 {
				 return false;
			 }

			 return a < b; });

	cout << a[k] << endl;
	return 0;
}