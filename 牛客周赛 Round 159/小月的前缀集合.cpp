#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int MAX_N = 2e5 + 10;

int q;

int different_prefix_amount = 0;
// 前缀出现的次数
unordered_map<string, int> prefix_cnt;
// 当前字符串有多少个
unordered_map<string, int> str_cnt;

void insert(const string &s)
{
	int len = s.length();
	str_cnt[s]++;
	for (int i = 0; i < len; i++)
	{
		string prefix = s.substr(0, i + 1);
		if (prefix_cnt[prefix] == 0)
		{
			different_prefix_amount++;
		}
		prefix_cnt[prefix]++;
	}
}

void remove(const string &s)
{
	int len = s.length();
	auto cnt = str_cnt[s];
	str_cnt[s] = 0;
	for (int i = 0; i < len; i++)
	{
		string prefix = s.substr(0, i + 1);
		prefix_cnt[prefix] -= cnt;
		if (prefix_cnt[prefix] == 0)
		{
			different_prefix_amount--;
		}
	}
}

int main()
{
	cin >> q;
	while (q--)
	{
		char op;
		string s;
		cin >> op >> s;
		if (op == '+')
		{
			insert(s);
		}
		else
		{
			remove(s);
		}

		cout << different_prefix_amount << endl;
	}
	return 0;
}