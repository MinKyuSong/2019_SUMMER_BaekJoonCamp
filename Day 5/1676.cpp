#include<iostream>

using namespace std;

int main(void)
{
    int N, ans=0;
    cin>>N;
    
    for(int i=1;i<=N;i++)
    {
        int temp(i);
        while(temp>0 && temp%5==0)
        {
            ans++;
            temp/=5;
        }
        
    }

    cout<<ans<<endl;
    return 0;
}