// 정렬로도 풀 수 있다
#include<iostream>
#include<set>
#include<vector>
#include<stack>
using namespace std;

typedef struct vertex
{
	long long data;
	int count = 1;
	long long M2 = -1;
	long long D3 = -1;
} vertex;
int N;
vector<vertex> vGraph;
vector<vertex> vSearch;
stack<long long> sAns;
bool DFS(int v, int level)
{
	if (level == 1)
	{
		while (!sAns.empty())
			sAns.pop();
		vSearch.clear();
		for (int i = 0; i < vGraph.size(); i++)
			vSearch.push_back(vGraph[i]);
	}
	sAns.push(vSearch[v].data);
	if (level == N)
		return true;
	if (vSearch[v].M2 >= 0&&vSearch[vSearch[v].M2].count>0)
	{
		if (DFS(vSearch[v].M2, level + 1))
			return true;
	}
	if (vSearch[v].D3 >= 0 && vSearch[vSearch[v].D3].count > 0)
	{
		if (DFS(vSearch[v].D3, level + 1))
			return true;
	}
	sAns.pop();
	return false;
}
int main(void)
{
	cin >> N;
	set<long long> sTemp;
	for (int i = 0; i < N; i++)
	{
		long long nInput;
		cin >> nInput;
		if (sTemp.count(nInput) == 0)
		{
			sTemp.emplace(nInput);
			vertex vInput;
			vInput.data = nInput;
			vGraph.push_back(vInput);
		}
		else
		{
			for (int j = 0; j < vGraph.size(); i++)
			{
				if (vGraph[j].data == nInput)
				{
					vGraph[j].count++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < vGraph.size(); i++)
	{
		if (sTemp.count(vGraph[i].data * 2))
		{
			for (int j = 0; j < vGraph.size(); j++)
			{
				if (vGraph[j].data == vGraph[i].data * 2)
				{
					vGraph[i].M2 = j;
					break;
				}
			}
		}
		if (vGraph[i].data % 3 == 0 && sTemp.count(vGraph[i].data / 3))
		{
			for (int j = 0; j < vGraph.size(); j++)
			{
				if (vGraph[j].data == vGraph[i].data / 3)
				{
					vGraph[i].D3 = j;
					break;
				}
			}
		}
	}
	for (int i = 0; i < vGraph.size(); i++)
	{
		if (DFS(i, 1))
		{
			break;
		}
	}

	vector<long long> vAns;
	while (!sAns.empty())
	{
		vAns.push_back(sAns.top());
		sAns.pop();
	}
	for (int i = vAns.size() - 1; i >= 0; i--)
		cout << vAns[i] << " ";
	cout << endl;
	return 0;
}