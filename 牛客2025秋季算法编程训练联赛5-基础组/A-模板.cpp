#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, m;
	string s1, s2;
	cin >> n >> m;
	cin >> s1 >> s2;
	int modify_tail = abs(n - m);
	int front_size = min(n, m);
	int modify_front = 0;
	for (int i = 0; i < front_size; i++)
	{
		if (s1[i] != s2[i])
			modify_front++;
	}

	cout << modify_front + modify_tail << endl;
	return 0;
}