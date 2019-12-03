#include<iostream>

using namespace std;

int H,W,N;
int nArrRC[3][100];

int main(void)
{
    cin>>H>>W;
    cin>>N;

    for(int i=0;i<N;i++)
        {
            cin>>nArrRC[0][i]>>nArrRC[1][i];
            nArrRC[2][i]=nArrRC[0][i]*nArrRC[1][i];
        }

    int nResult=0;

    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            int width, height;
            //i 그대로 j 그대로
            {
                width=nArrRC[0][i]+nArrRC[0][j];
                height=(nArrRC[1][i]>nArrRC[1][j])?nArrRC[1][i]:nArrRC[1][j];
                if(width<=W&&height<=H)
                    if(nResult<nArrRC[2][i]+nArrRC[2][j])
                        nResult=nArrRC[2][i]+nArrRC[2][j];

                width=(nArrRC[0][i]>nArrRC[0][j])?nArrRC[0][i]:nArrRC[0][j];
                height=nArrRC[1][i]+nArrRC[1][j];
                if(width<=W&&height<=H)
                    if(nResult<nArrRC[2][i]+nArrRC[2][j])
                        nResult=nArrRC[2][i]+nArrRC[2][j];
            }
            //i 그대로 j 돌리기
            {
                width=nArrRC[0][i]+nArrRC[1][j];
                height=(nArrRC[1][i]>nArrRC[0][j])?nArrRC[1][i]:nArrRC[0][j];
                if(width<=W&&height<=H)
                    if(nResult<nArrRC[2][i]+nArrRC[2][j])
                        nResult=nArrRC[2][i]+nArrRC[2][j];

                width=(nArrRC[0][i]>nArrRC[1][j])?nArrRC[0][i]:nArrRC[1][j];
                height=nArrRC[1][i]+nArrRC[0][j];
                if(width<=W&&height<=H)
                    if(nResult<nArrRC[2][i]+nArrRC[2][j])
                        nResult=nArrRC[2][i]+nArrRC[2][j];
            }
            //i 돌리기 j 그대로
            {
                width=nArrRC[1][i]+nArrRC[0][j];
                height=(nArrRC[0][i]>nArrRC[1][j])?nArrRC[0][i]:nArrRC[1][j];
                if(width<=W&&height<=H)
                    if(nResult<nArrRC[2][i]+nArrRC[2][j])
                        nResult=nArrRC[2][i]+nArrRC[2][j];

                width=(nArrRC[1][i]>nArrRC[0][j])?nArrRC[1][i]:nArrRC[0][j];
                height=nArrRC[0][i]+nArrRC[1][j];
                if(width<=W&&height<=H)
                    if(nResult<nArrRC[2][i]+nArrRC[2][j])
                        nResult=nArrRC[2][i]+nArrRC[2][j];
            }
            //i 돌리기 j 돌리기
            {
                width=nArrRC[1][i]+nArrRC[1][j];
                height=(nArrRC[0][i]>nArrRC[0][j])?nArrRC[0][i]:nArrRC[0][j];
                if(width<=W&&height<=H)
                    if(nResult<nArrRC[2][i]+nArrRC[2][j])
                        nResult=nArrRC[2][i]+nArrRC[2][j];

                width=(nArrRC[1][i]>nArrRC[1][j])?nArrRC[1][i]:nArrRC[1][j];
                height=nArrRC[0][i]+nArrRC[0][j];
                if(width<=W&&height<=H)
                    if(nResult<nArrRC[2][i]+nArrRC[2][j])
                        nResult=nArrRC[2][i]+nArrRC[2][j];
            }
        }
    }
    cout<<nResult<<endl;
    return 0;
}