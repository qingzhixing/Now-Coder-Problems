#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 210;

int n, m;

bool a[MAX_N][MAX_N];

// used 用于标记一个方格是否在其他连通块内
bool used[MAX_N][MAX_N];

const int dx4[4] = {-1, 1, 0, 0};
const int dy4[4] = {0, 0, -1, 1};

const int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = s[j - 1] - '0';
		}
	}

	// 计算 c4 s4
	// printf("Get c4, s4\n");
	int c4 = 0, s4 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			// 当前点可以开始查找连通块
			if (a[i][j] && !used[i][j])
			{
				c4++;
				int s = 0;
				queue<pair<int, int>> q4;
				q4.push({i, j});

				// printf("Starting at {%d, %d}\n", i, j);

				while (q4.size())
				{
					// 访问当前节点
					auto [x, y] = q4.front();

					// printf("Searching at {%d, %d}\n", x, y);

					q4.pop();

					if (used[x][y])
					{
						continue;
					}

					s++;
					used[x][y] = true;

					// 扩散
					for (int direction = 0; direction < 4; direction++)
					{
						int nx = x + dx4[direction];
						int ny = y + dy4[direction];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
						{
							if (a[nx][ny] && !used[nx][ny])
							{
								q4.push({nx, ny});
							}
						}
					}
				}

				s4 = max(s4, s);
			}
		}
	}

	// 计算 c8 s8
	// printf("Get c8, s8\n");
	memset(used, 0, sizeof(used));
	int c8 = 0, s8 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			// 当前点可以开始查找连通块
			if (a[i][j] && !used[i][j])
			{
				c8++;
				int s = 0;
				queue<pair<int, int>> q8;
				q8.push({i, j});

				// printf("Starting at {%d, %d}\n", i, j);

				while (q8.size())
				{
					// 访问当前节点
					auto [x, y] = q8.front();

					// printf("Searching at {%d, %d}\n", x, y);

					q8.pop();

					if (used[x][y])
					{
						continue;
					}

					s++;
					used[x][y] = true;

					// 扩散
					for (int direction = 0; direction < 8; direction++)
					{
						int nx = x + dx8[direction];
						int ny = y + dy8[direction];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
						{
							if (a[nx][ny] && !used[nx][ny])
							{
								q8.push({nx, ny});
							}
						}
					}
				}

				s8 = max(s8, s);
			}
		}
	}

	printf("%d %d %d\n", c4 - c8, s4, s8);
	return 0;
}