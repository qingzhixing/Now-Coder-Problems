#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

void Solution()
{
	cin >> n;

	vector<int> nums(2 * n + 10);

	for (int index = 1; index <= 2 * n; index++)
	{
		cin >> nums[index];
	}

	/*
	 * 从高位往低位试填
	 */
	vector<bool> disabled(2 * n + 10);
	// for(int bit=45) TODO:Coding Here
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Solution();
	}
	return 0;
}