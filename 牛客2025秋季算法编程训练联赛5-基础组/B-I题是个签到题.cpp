#include <iostream>
using namespace std;

static int problem_num, people_num;
static int pass[1010];

const static int I_index = 'I' - 'A';

int main()
{
	cin >> problem_num >> people_num;
	for (int i = 0; i < problem_num; i++)
	{
		cin >> pass[i];
	}

	if ((pass[I_index] * 1.0) / people_num >= 0.8)
	{
		cout << "Yes" << endl;
		return 0;
	}

	int I_pass = pass[I_index];
	int easier = 0;
	for (int i = 0; i < problem_num; i++)
	{
		if (i == I_index)
			continue;
		if (pass[i] > I_pass)
			easier++;
	}

	cout << ((easier <= 2) ? "Yes" : "No");

	return 0;
}