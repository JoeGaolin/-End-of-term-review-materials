#include <iostream>
#define max 2147483647
#define V 6
using namespace std;

int min_Key(int key[],bool visited[]){
    int min=2147483647,min_index;
    for(int v=0;v<V;v++){
        if(visited[v]==false&&key[v]<min){
            min=key[v];
            min_index=v;
        }
    }
    return min_index;
}
void print_mst(int parent[],int cost[V][V]){
    int mincost=0;
    cout<<"最小生成树为：\n";
    for(int i=1;i<V;i++){
        printf("%d - %d weight:%d\n",parent[i]+1,i+1,cost[i][parent[i]]);
        mincost+=cost[i][parent[i]];
    }
    printf("总权值为：%d",mincost);
}
void find_mst(int cost[V][V]){
    int parent[V],key[V];
    bool visited[V];
    //初始化三个数组
    for(int i=0;i<V;i++){
        key[i]=max;
        visited[i]=false;
        parent[i]=-1;
    }
    key[0]=0;
    parent[0]=-1;
    for(int x=0;x<V-1;x++){
        int u=min_Key(key,visited);
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(cost[u][v]!=0&&visited[v]==false&&cost[u][v]<key[v]){
                parent[v]=u;
                key[v]=cost[u][v];
            }
        }
    }
    print_mst(parent,cost);
}
int main(){
    int p1,p2;
    int weight;
    int cost[V][V]={0};
    while(1){
        cin>>p1>>p2;
        if(p1==-1&&p2==-1)
            break;
        cin>>weight;
        cost[p1-1][p2-1]=weight;
        cost[p2-1][p1-1]=weight;
    }
    find_mst(cost);
    return 0;
}