#include <iostream>
using namespace std;

double n, x, a, b;

int main()
{
	cin >> n >> x >> a >> b;
	double all_perfect = n * a;
	double all_great = n * b;
	double expect = all_perfect * (x / 100.0) + all_great * ((100 - x) / 100.0);
	printf("%.2f", expect);
	return 0;
}