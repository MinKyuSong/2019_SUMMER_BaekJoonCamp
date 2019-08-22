// 뒤에 0 붙이기 (A*B)%C = (A%C*B%C)%C
// 뒤에 1 붙이기 (A+B)%C = (A%C+B%C)%C 
#include<iostream>
#include<utility>
#include<queue>
#include<string>
using namespace std;
char data[20001];
bool visit[20001];
bool check(int a)
{
	int t(a);
	while (t > 0)
	{
		if (t % 10 > 1)
			return false;
		t /= 10;
	}
	return true;
}
void BFS(int target)
{
	queue<pair<string, int>>qSearch;
	qSearch.push(make_pair("1", 1));

	while (!qSearch.empty())
	{
		string src(qSearch.front().first);
		int res(qSearch.front().second);
		qSearch.pop();
        if(src.length()>100)
        {
            cout<<"BRAK"<<endl;
            return;
        }
		// 0 붙이기
		string next = src +"0";
		res = (res * (10 % target)) % target;
		if (res == 0)
		{
			cout << next << endl;
			return;
		}
		qSearch.push(make_pair(next, res));

		// 1 붙이기
		next=src+"1";
		res = (res + (1 % target)) % target;
		if (res == 0)
		{
			cout << next << endl;
			return;
		}
		qSearch.push(make_pair(next, res));
	}
	return;
}
int main(void)
{
	int T;
	cin >> T;
    memset(visit,false,sizeof(visit));
	while (T--)
	{
		int N;
		cin >> N;
		if (check(N))
		{
			cout << N << endl;
			continue;
		}
		BFS(N);
	}
	return 0;
}