#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

set<string> dict;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    string buf,s;
    while(cin>>s){
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';//这里直接删除也行
        }
        dict.insert(s);
    }
    //it作为迭代器 就是指针
    //set容器已经排好序了
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
        cout<<*it<<"\n";
    return 0;

}