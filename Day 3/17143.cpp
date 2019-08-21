// simulation

#include<iostream>
#include<vector>
using namespace std;

typedef struct fish
{
    int r,c,s,d,z;
}fish;
int R,C,M;
vector<fish> map[200][200];
int dx[]={0,0,0,1,-1};
int dy[]={0,-1,1,0,0};
void move()
{
    // 이동
    vector<fish> next;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
            if(map[i][j].size()>0)
            {
                fish t1(map[i][j][0]);
                for(int k=1;k<=t1.s;k++)
                {
                    if(t1.r+dy[t1.d]<1||t1.r+dy[t1.d]>R||t1.c+dx[t1.d]<1||t1.c+dx[t1.d]>C)
                    {
                        switch (t1.d)
                        {
                        case 1:
                            t1.d=2;
                            break;
                        case 2:
                            t1.d=1;
                            break;
                        case 3:
                            t1.d=4;
                            break;
                        case 4:
                            t1.d=3;
                            break;
                        default:
                            break;
                        }
                    }
                    t1.r+=dy[t1.d];
                    t1.c+=dx[t1.d];
                }
                next.push_back(t1);
                map[i][j].clear();
            }
        }
    for(int i=0;i<next.size();i++)
    {
        map[next[i].r][next[i].c].push_back(next[i]);
    }
    // 포식
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
            if(map[i][j].size()>1)
            {
                int tmax=-1;
                int t;
                for(int k=0;k<map[i][j].size();k++)
                {
                    if(map[i][j][k].z>tmax)
                    {
                        tmax=map[i][j][k].z;
                        t=k;
                    }
                }
                fish t1(map[i][j][t]);
                map[i][j].clear();
                map[i][j].push_back(t1);
            }
        }
}

int main(void)
{
    cin>>R>>C>>M;
    for(int i=0;i<M;i++)
    {
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        fish fin;
        fin.r=r;fin.c=c;fin.s=s;fin.d=d;fin.z=z;
        map[r][c].push_back(fin);
    }
    int nResult=0;
    for(int l=0;l<=C;)
    {
        // 낚시왕 이동
        l++;
        // 상어잡기
        for(int i=1;i<=R;i++)
        {
            if(map[i][l].size()>0)
            {
                nResult+=map[i][l][0].z;
                map[i][l].clear();
                break;
            }
        }
        // 상어 이동
        move();
    }
    cout<<nResult<<endl;
    return 0;
}