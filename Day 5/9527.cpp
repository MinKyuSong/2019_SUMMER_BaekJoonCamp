#include<iostream>
using namespace std;

long long A, B, ans = 0;
int baseA, baseB;
static long long baseCumm[55];

int getBase(long long n)
{
	int nResult = 0;
	while (n > 1)
	{
		nResult++;
		n /= 2;
	}
	return nResult;
}
long long getBlock(int n)
{
	long long nResult = 1;
	for (int i = 1; i <= n; i++)
	{
		nResult *= 2;
	}
	return nResult;
}
long long getCount(long long from, long long to)
{
	long long nResult = 0;
	int fromBase = getBase(from);
	int toBase = getBase(to);

	for (long long i = from; i < getBlock(fromBase + 1); i++)
		nResult += __builtin_popcountll(i);
	for (int i = fromBase + 1; i < toBase; i++)
		nResult += (baseCumm[i] - baseCumm[i - 1]);
	for (long long i = getBlock(toBase); i <= to; i++)
		nResult += __builtin_popcountll(i);

	return nResult;
}
int main(void)
{
	cin >> A >> B;

	baseA = getBase(A);
	baseB = getBase(B);

	baseCumm[0] = 1; baseCumm[1] = 4;
	for (int i = 2; i <= baseB; i++)
	{
		baseCumm[i] = 1;
		for (int j = 0; j < i; j++)
			baseCumm[i] *= 2;
		baseCumm[i] += 2*baseCumm[i - 1];
	}
	ans = getCount(A, B);
	cout << ans << endl;
	return 0;
}