#include <iostream>
using namespace std;

int n, k;

int main()
{
	cin >> n >> k;
	int gold = (n + 9) / 10;
	if (k <= gold)
	{
		cout << "Gold Medal" << endl;
		return 0;
	}
	if (k > gold && k <= gold * 3)
	{
		cout << "Silver Medal" << endl;
		return 0;
	}
	if (k > gold * 3 && k <= gold * 6)
	{
		cout << "Bronze Medal" << endl;
		return 0;
	}
	cout << "Da Tie" << endl;
	return 0;
}