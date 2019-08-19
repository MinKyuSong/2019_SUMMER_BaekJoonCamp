// bool check[10] 을 이용해서 사용한 숫자를 확인하자
// 중복 없이 선택만 하면 오름차순은 하나밖에 없다 int selected로 포함된 개수를 조절하자

#include<iostream>
using namespace std;

static bool nArr[10];
int N,M;

void MakeNum(int idx, int selected)
{
    if(idx>N+1)
        return;
    if(selected == M)
    {
        for(int i=1;i<10;i++)
            if(nArr[i])
                cout<<i<<' ';
        cout<<endl;
        return;
    }
    nArr[idx]=true;
    MakeNum(idx+1,selected+1);
    nArr[idx]=false;
    MakeNum(idx+1,selected);
    return;
}

int main(void)
{
    cin>>N>>M;
    
    MakeNum(1,0);

    return 0;
}