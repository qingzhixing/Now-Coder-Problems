#include <iostream>
using namespace std;

const int MAX_N = 2e5 + 10;

struct Light
{
	bool state;
	long long start;
	long long end;
} light[MAX_N];

int m, q, b;

// 根据第 p 盏灯，找到属于它的灯带编号并返回
int find(long long p, int left_seg, int right_seg)
{
	if (left_seg > right_seg)
	{
		printf("FIND FAILED\n");
		return -1;
	}
	int mid_seg = (left_seg + right_seg) >> 1;
	auto [_, start, end] = light[mid_seg];

	// 找到了
	if (start <= p && end >= p)
	{
		return mid_seg;
	}
	// 当前灯带在我们要找到灯带的右边
	if (start >= p)
	{
		return find(p, left_seg, mid_seg - 1);
	}
	// 当前灯带在我们要找到灯带的左边
	return find(p, mid_seg + 1, right_seg);
}

int main()
{
	cin >> m >> q >> b;
	bool current_state = b;
	long long current_id = 1;
	for (int i = 1; i <= m; i++)
	{
		long long a;
		cin >> a;
		light[i] = {current_state, current_id, current_id + a - 1};
		current_state ^= 1;
		current_id += a;
	}

	while (q--)
	{
		long long p;
		cin >> p;
		int seg = find(p, 1, m);
		auto [state, start, end] = light[seg];
		long long index = p - start + 1;
		printf("%lld %lld %lld\n", state, seg, index);
	}

	return 0;
}