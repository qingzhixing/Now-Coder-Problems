#include <iostream>
using namespace std;

static const int MAX_N = (2e5 + 10);

long long n, k, x;
int num_array[MAX_N];

int main()
{
	cin >> n >> k >> x;

	for (auto index = 1; index <= n; index++)
	{
		cin >> num_array[index];
	}

	/*
		我们可以把抽卡操作当作迭代器指针移动
		对于[1,x]序列，操作x次序列保持不动
		余下的操作只用从末尾往前移动迭代即可
	*/

	int index = x - k % x + 1;

	// 先打印[1,x]被打乱的序列
	for (int i = 1; i <= x; i++)
	{
		if (index > x)
			index -= x;
		cout << num_array[index] << ' ';
		index++;
	}

	// 后面打印顺序序列
	for (int i = x + 1; i <= n; i++)
	{
		cout << num_array[i] << ' ';
	}
	cout << endl;
	return 0;
}