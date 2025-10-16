#include <iostream>
#include <math.h>
using namespace std;

long long n;

long long factor_count(long long num)
{
	// printf("Num: %lld\n", num);
	long long cnt = 0;
	for (long long i = 1; i <= sqrt(num * 1.0); i++)
	{
		if (num % i == 0)
		{
			if (i * i != num)
			{
				// 两因数不相等：另一个因数不是i
				cnt += 2;
			}
			else
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	cin >> n;
	long long result = 0;
	while (n != 2)
	{
		n = factor_count(n);
		result++;
	}
	cout << result << endl;
	return 0;
}