#include <bits/stdc++.h>
#define MaxVerNum 501
#define INF 0x3f3f3f3f
using namespace std;

int rescue_teams[MaxVerNum];//每个顶点的救援队数目
int Pre[MaxVerNum],dis[MaxVerNum];
typedef struct Graph{
    int vexnum;
    int arcnum;
    int start,Destination;
    int arc[MaxVerNum][MaxVerNum];
}Graph,*PtrOfGraph;

struct ArcNode{
    int Data;
    ArcNode *next;
};
typedef struct adjacency_list{
    //邻接表存储路径
    ArcNode *firstarc;
    int sum=0;
}Path[MaxVerNum];

void InitGraph(PtrOfGraph &G){
    int n,m,S,D;
    cin>>n>>m>>S>>D;
    G->start=S;
    G->Destination=D;
    G->vexnum=n;
    G->arcnum=m;
    //边的初始化
    for(int i=0;i<G->vexnum;i++)
    {
        for(int j=0;j<G->vexnum;j++)
        {
            if(i==j)
                G->arc[i][j]=0;
            else 
               G->arc[i][j]=INF;
        }
    }
    for(int i=0;i<G->vexnum;i++){
        int teams;
        cin>>teams;
        rescue_teams[i]=teams;
    }
    for(int i=0;i<G->arcnum;i++){
        int v1,v2,weight;
        cin>>v1>>v2>>weight;
        G->arc[v1][v2]=weight;
        G->arc[v2][v1]=weight;
    }
}

void Dijistra(PtrOfGraph &G){
    int visited[MaxVerNum];
    memset(visited,0,sizeof(visited));
    for(int t=0;t<G->vexnum;t++){
        dis[t]=G->arc[G->start][t];
    }
    visited[G->start]=1;
    for(int t=0;t<G->vexnum;t++){
        int minn=INF,temp;
        for(int i=0;i<G->vexnum;i++){
            if(!visited[i]&&dis[i]<minn){
                minn=dis[i];
                temp=i;
            }
        }
        visited[temp]=1;
        for(int i=0;i<G->vexnum;i++){
            
            if(G->arc[temp][i]+dis[temp]<dis[i])
                dis[i]=G->arc[temp][i]+dis[temp];
        }
    }
    
}

int main(){
    PtrOfGraph G=new(Graph);
    InitGraph(G);
    Dijistra(G);   
    cout<<dis[G->Destination];
    return 0;
}