#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string,int> cnt;
vector<string> words;

string repr(const string &s){
    string ans=s;
    for(long long unsigned int i=0;i<s.length();i++){
    //s.length 返回的是long long unsigned int 没有-1
       ans[i]=tolower(s[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    string s;
    while(cin>>s){
        if(s[0]=='#') break;
        //筛出标点
        long long unsigned int i=0;
        while(i<s.length()){
            //20th 
            if(!isalpha(s[i])){
                s.erase(i,1);
                i=0;
            }
            else i++;
        }
        words.push_back(s);
        string r=repr(s);
        if(!cnt.count(r)) cnt[r]=0;
        cnt[r]++;    
    }
    vector<string> new_word;
    for(int i=0;i<words.size();i++)
        if(cnt[repr(words[i])]==1)
            new_word.push_back(words[i]);
    sort(new_word.begin(),new_word.end());
    for(int i=0;i<new_word.size();i++)
        cout<<new_word[i]<<endl;
    return 0;
}