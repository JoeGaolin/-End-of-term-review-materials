#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
freopen("test.in","r",stdin);
freopen("test.out","w",stdout);
const int maxcols=60;
void print(string &name,int len,char ch){
    cout<<name;
    for(int i=0;i<len-(int)name.length();i++){
        cout<<ch;
    }
}
int main(){
    int n,m=0;
    string filenames[1000];
    for(int i=1;i<=n;i++){
        cin>>filenames[i];
        m=max(filenames[i].length(),m);
    }
    //计算行数和列数
    int cols=(maxcols-m)/(m+2)+1,rows=n/cols+1;
    print("--",58,'-');
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
            int id=i*(j-1)+i;
            if(j==cols)
                print(filenames[id],m+2,' ');
            else
                print(filenames[id],m,' ');
        }
    }


}