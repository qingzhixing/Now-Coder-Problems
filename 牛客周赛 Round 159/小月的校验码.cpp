#include <iostream>
#include <string>
using namespace std;

// 2^20 < 2e7
const int MAX_N = 2e7;

// 树根为 0
bool exist[MAX_N];

#define LEFT_CHILD(x) (2 * x + 1)
#define RIGHT_CHILD(x) (2 * x + 2)

int n, b;

void insert(const string &s)
{
	int current_node = 0;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '0')
		{
			current_node = LEFT_CHILD(current_node);
		}
		else
		{
			current_node = RIGHT_CHILD(current_node);
		}
		exist[current_node] = true;
	}
}

int main()
{
	cin >> n >> b;

	// 公共根存在
	exist[0] = true;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		insert(s);
	}

	// 查询每一层
	// cnt[i] 表示第 i 层产生的 单点差分码 的数量
	int cnt[30] = {};
	// amount 表示 总共 差分码 数量
	int amount = 0;
	for (int i = 0; i < b; i++)
	{
		// 第 i 层的编号 (2 ^ i - 1) ~ (2 ^ (i + 1) - 2)
		int left = (1 << i) - 1;
		int right = (1 << (i + 1)) - 2;
		for (int id = left; id <= right; id++)
		{
			bool have_left = false;
			bool have_right = false;
			int left_child = LEFT_CHILD(id);
			int right_child = RIGHT_CHILD(id);
			if (left_child < MAX_N && exist[left_child])
			{
				have_left = true;
			}
			if (right_child < MAX_N && exist[right_child])
			{
				have_right = true;
			}
			if (have_left && have_right)
			{
				cnt[i]++;
				amount++;
			}
		}
	}

	// 输出
	cout << amount << endl;
	for (int i = 0; i < b; i++)
	{
		cout << cnt[i] << ' ';
	}
	cout << endl;
	return 0;
}