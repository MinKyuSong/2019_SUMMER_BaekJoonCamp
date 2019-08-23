#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string S;
string T;

int main(void)
{
	cin >> S;
	cin >> T;
	int ls = S.length()-1;
	int lt = T.length()-1;

	while (lt > ls)
	{
		if (T[lt] == 'B')
		{
			string t = T.substr(0,lt);
			reverse(t.begin(), t.end());
			T = t;
		}
		lt--;
	}
	int nResult = 1;
	for (int i = 0; i <= ls; i++)
	{
		if (S[i] != T[i])
		{
			nResult = 0;
			break;
		}
	}
	cout << nResult << endl;
	return 0;
}