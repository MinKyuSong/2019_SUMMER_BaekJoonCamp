#include<iostream>
using namespace std;

long long nArrPCount[51];
long long nArrBCount[51];
int N;
long long X;
long long nResult=0;
int main(void)
{
	nArrPCount[0] = 1;
	nArrBCount[0] = 0;
	cin >> N>>X;
	for (int i = 1; i <= N; i++)
	{
		nArrPCount[i] = 2 * nArrPCount[i - 1] + 1;
		nArrBCount[i] = 2 * nArrBCount[i - 1] + 2;
	}
    
    cout<<nResult;
	return 0;
}