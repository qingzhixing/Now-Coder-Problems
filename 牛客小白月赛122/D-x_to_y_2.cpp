// TODO: 不想写这题了，前面的区域，以后再来探索吧！
#include <iostream>
#include <string>
using namespace std;

string long_to_binary_string(long long number)
{
	string result{};
	do
	{
		// 高位在前，低位在后
		result = char((number & 1) + '0') + result;
		number >>= 1;
	} while (number);

	return result;
}

void Solution()
{
	long long x, y;
	cin >> x >> y;
	auto bin_x = long_to_binary_string(x);
	auto bin_y = long_to_binary_string(y);
	// printf("bin_x:%s\nbin_y:%s\n", bin_x.c_str(), bin_y.c_str());

	if (bin_x == bin_y)
	{
		cout << 0 << endl;
		return;
	}

	// 题目要找x的前缀和y的后缀最大匹配长度
	int len_x = bin_x.size();
	int len_y = bin_y.size();

	// 最多全部舍弃x
	int min_operation = len_x + 1;
	for (int judging_pointer_x = 0; judging_pointer_x < len_x; judging_pointer_x++)
	{
		// 计算y字符串对应的起点坐标
		int y_start = (len_y - 1) - (judging_pointer_x - 0);
		if (y_start < 0)
			break;

		// 如果y高位还有数字那么必定要or运算
		bool matched = true, or_flag = (y_start != 0);
		for (int bit = 0; bit <= judging_pointer_x; bit++)
		{
			int index_y = y_start + bit;
			if (bin_x[bit] == bin_y[index_y])
			{
				continue;
			}
			if (bin_y[index_y] == '1')
			{
				// 此时x对应位置是0，可以转化得来
				or_flag = true;
			}
			else
			{
				matched = false;
				break;
			}
		}

		if (matched)
		{
			int operation = len_x - (judging_pointer_x + 1);

			// printf("Matched when judging %d: operation= %d, or_flag= %s\n",
			// 	   judging_pointer_x, operation, or_flag ? "T" : "F");

			min_operation = min(min_operation, operation + or_flag);
		}
	}
	cout << min_operation << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		Solution();
	return 0;
}