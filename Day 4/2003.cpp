#include<iostream>
using namespace std;

int N,M;
int nResult=0;
static int nArrIn[10001];

int main(void)
{
    cin>>N>>M;

    for(int i=0;i<N;i++)
        cin>>nArrIn[i];
    for(int i=0;i<N;)
    {
        int sum=0;
        bool check=false;
        int j=0;
        while(true)
        {
            if (i + j > N)
				break;
            sum+=nArrIn[i+j];
            if(sum==M)
            {
                check=true;
                break;
            }
            else if(sum>M)
                break;
            j++;
        }
        if(check)
        {
            i+=j;
            nResult++;
        }
        else
        {
            i++;
        }
    }

    cout<<nResult<<endl;
    return 0;
}