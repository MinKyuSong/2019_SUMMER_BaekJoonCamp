choiceList=[0,0,0,0]
N=int(input())
nResList=[]

def MakeChoice(idx,selected):
    if(idx>3):
        return
    if(selected==N):
        temp=0
        temp+=choiceList[0]
        temp+=(choiceList[1]*5)
        temp+=(choiceList[2]*10)
        temp+=(choiceList[3]*50)
        nResList.append(temp)
        return
    choiceList[idx]+=1
    MakeChoice(idx,selected+1)
    choiceList[idx]-=1
    MakeChoice(idx+1,selected)
    return
MakeChoice(0,0)
print(len(set(nResList)))