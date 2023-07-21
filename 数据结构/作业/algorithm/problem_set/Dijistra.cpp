#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define clr(str,x) memset(str,x,sizeof(str))
#define FRER() freopen("in.txt","r",stdin);
#define FREW() freopen("out.txt","w",stdout);
#define INF 0x3f3f3f3f
#define maxn 1000
 
typedef long long int ll;
using namespace std;
int n,m,S,D;
int len[maxn][maxn];//两点之间的距离，没有路记为INF
int sum[maxn];//到i点救援队的最大数量
int pre[maxn];//记录第i个点的前一个点
int d[maxn];//d[i]从S点到i点的最短距离
int man[maxn];//i点救援队数量
int Min,minid;//最小值、最小值的下标
bool vis[maxn];//记录这个点是否经过过了
int coun[maxn];//S到i点有多少条最短路
void Dijkstra()
{
    clr(vis,false);
    for(int i=0; i<n; i++)
    {
        d[i]=len[S][i];
        if(len[S][i]!=0&&len[S][i]!=INF)
            sum[i]+=sum[S];//如果S与i之间有路，i的救援队总数更新
        pre[i]=-1;
        coun[i]=1;
    }
    vis[S]=1;
    d[S]=0;
    for(int k=0; k<n; k++)
    {
        Min=INF,minid=-1;
        for(int j=0; j<n; j++)
        {
            if(!vis[j]&&d[j]<Min)
            {
                Min=d[j];
                minid=j;
            }
        }
        if(minid==-1)
            break;
        vis[minid]=1;
        for(int j=0; j<n; j++)
        {
            if(d[j]>Min+len[minid][j]&&!vis[j])
            {
                coun[j]=coun[minid];//更新S到第i个点的最短路数量
                pre[j] = minid;
                d[j]=Min+len[minid][j];
                sum[j] = man[j]+sum[minid];
            }
            else if(d[j]==Min+len[minid][j]&&!vis[j])
            {
                coun[j]=coun[j]+coun[minid];
                if(sum[j]<sum[minid]+man[j])//如果救援队数有更大的，就更新
                {
                    sum[j]=sum[minid]+man[j];
                    pre[j]=minid;
                }
            }
        }
    }
}
int main()
{
    //FRER()
    //FREW()
    int p1,p2,lens;
    scanf("%d%d%d%d",&n,&m,&S,&D);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
                len[i][j]=0;
            else
                len[i][j]=INF;
        }
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&man[i]);
        sum[i]=man[i];
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&p1,&p2,&lens);
        len[p1][p2]=lens;
        len[p2][p1]=lens;
    }
    Dijkstra();
    printf("%d %d\n",coun[D],sum[D]);
    int road[maxn];
    memset(road,0,sizeof(road));
    int pos=0,t=D;//从终点开始往前找
    road[pos++]=D;
    while(pre[t]!=-1)
    {
        road[pos++]=pre[t];
        t=pre[t];
    }
    road[pos++]=S;
    for(int i=pos-1; i>=0; i--)
    {
        if(i==pos-1)
            printf("%d",road[i]);
        else
            printf(" %d",road[i]);
    }
    printf("\n");
    return 0;
}