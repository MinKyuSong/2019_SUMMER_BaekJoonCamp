#include <iostream>

using namespace std;

int N, T, M;
int city[3][1001];
int special[1001];
int getDist(int a, int b)
{
	return abs(city[1][a] - city[1][b]) + abs(city[2][a] - city[2][b]);
}
int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> T;
	int nCount = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> city[0][i] >> city[1][i] >> city[2][i];
		if (city[0][i] == 1)
			special[nCount++] = i;
	}

	cin >> M;
	while (M--)
	{
		int A, B, dist;
		cin >> A >> B;
		dist = getDist(A, B);
		for (int i = 0; i < nCount - 1; i++)
			for (int j = i + 1; j < nCount; j++)
			{
				if (dist > getDist(A, special[i]) + T + getDist(special[j], B))
					dist = getDist(A, special[i]) + T + getDist(special[j], B);
				if (dist > getDist(A, special[j]) + T + getDist(special[i], B))
					dist = getDist(A, special[j]) + T + getDist(special[i], B);
			}
		cout << dist << endl;
	}
	return 0;
}