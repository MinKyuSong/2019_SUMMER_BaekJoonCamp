#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,S;
int dist[100000];
int gcd(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int findOut()
{
    int nResult=dist[0];
    for(int i=1;i<N;i++)
        nResult=gcd(nResult,dist[i]);
    return nResult;
}

int main(void)
{
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

    cin>>N>>S;
    for(int i=0;i<N;i++)
    {
        int nInput;
        cin>>nInput;
        dist[i]=abs(nInput-S);
    }
    cout<<findOut()<<endl;
    return 0;
}