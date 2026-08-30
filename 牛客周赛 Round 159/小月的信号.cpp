#include <iostream>
using namespace std;

int main()
{
	long long num;
	cin >> num;
	if (!num)
	{
		cout << "0 -1 -1" << endl;
		return 0;
	}
	int start_id = -1, end_id = -1, popcount = 0;
	int digit = 0;
	while (num)
	{
		if (num & 1)
		{
			popcount++;
			end_id = digit;
			if (start_id == -1)
			{
				start_id = digit;
			}
		}
		num >>= 1;
		digit++;
	}
	printf("%d %d %d\n", popcount, start_id, end_id);
	return 0;
}