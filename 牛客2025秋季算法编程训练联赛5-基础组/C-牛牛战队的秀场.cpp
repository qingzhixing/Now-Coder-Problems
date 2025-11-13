#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;

int main()
{
	double n, r;
	int i, j;
	cin >> n >> r;
	cin >> i >> j;

	double single_edge_length = 2 * r * sin(PI / n);

	double edges = min(abs(i - j), int(n - abs(i - j)));

	printf("%.6f\n", edges * single_edge_length);

	return 0;
}