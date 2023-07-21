#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    //初始化
    int t;
    cin>>t;
    map<int,int>team;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            team[x]=i;
        }
    }
    char cmd[10];
    queue<int> q,q2[1000];
        while(cin>>cmd){
        if(cmd[0]=='S') break;
        else if(cmd[0]=='D'){
            if(q.empty()) cout<<"队列为空"<<endl;
            int head=q.front();
            cout<<"队列头："<<q2[head].front()<<endl;
            q2[head].pop();
        }
        else if(cmd[0]=="E"){
            int person;
            cin>>person;
            int number=team[person];
            //队伍号码
            if(q2[number].empty()) q.push(number);
            q2[number].push(person);
            cout<<"放入成功"<<endl;
        }
    }
    return 0;
}