#include<cstdio>
#include<string.h>
using namespace std;
bool net[1000001];
int main(void)
{
    memset(net,true,1000001);
    for(int i=2;i<=1000000;i++)
    {
        if(net[i])
        {
            for(int j=i+i;j<=1000000;j+=i)
               net[j]=false;
        }
    }
    int nInput;
    scanf("%d",&nInput);
    while(nInput!=0)
    {
        int a=0, b=0;
        bool check=false;
        for(int i=3;i<=nInput/2;i+=2)
        {
            if(net[i]&&net[nInput-i])
            {
                a=i;
                b=nInput-i;
                check=true;
                break;
            }
        }
        if(check)
            printf("%d = %d + %d\n",nInput,a,b);
        else
            printf("Goldbach's conjecture is wrong.\n");
        
        scanf("%d",&nInput);
    }
    
    return 0;
}