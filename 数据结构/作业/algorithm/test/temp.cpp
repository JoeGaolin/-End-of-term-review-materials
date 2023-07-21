void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    int Q[1000];
    int f=0,r=0;
    Q[r++]=S;
    Visit(S);
    Visited[S]=true;
    while(f!=r)
    {
        PtrToAdjVNode p;
        p=Graph->G[Q[f]].FirstEdge;
        f++;
        while(p)
        {
            int v=p->AdjV;
            if(Visited[v]==false)
            {
                Visit(v);
                Q[r++]=v;
                Visited[v]=true;
            }
            p=p->Next;
        }

    }
}