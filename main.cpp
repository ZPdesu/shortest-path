#include<iostream>
#include<stack>
using namespace std;
int main()
{

    int edge;
    int points;
    int dis[10];
    int flag[10];
    int infinity=1000000;
    cin>>points>>edge;
    int start ,end;
    cin>>start>>end;
    int source;
    source=start;
    int edg[10][10];
    int father[10];
    for (int i=1;i<=points;i++)
    {
        father[i]=0;
        for (int j=1;j<=points;j++)
        {
            if (i==j)
            {
                edg[i][j]=0;
            }
            else
            {
                edg[i][j]=infinity;
            }
        }
    }
    int point1,point2,weight;
    for (int i=1;i<=edge;i++)
    {
        cin>>point1>>point2>>weight;
        edg[point1][point2]=weight;
        father[point2]=point1;
    }
    for (int i=1;i<=points;i++)
    {
        dis[i]=edg[source][i];//
    }
    for (int i=1;i<=points;i++)
    {
        flag[i]=0;
    }
    flag[source]=1;
    int min,u;
    for (int i=1;i<=points-1;i++)
    {
        min=infinity;
        for (int j=1;j<points;j++)
        {
            if (flag[j]==0&&dis[j]<min)
            {
                min=dis[j];
                u=j;
            }
        }
        flag[u]=1;
        for (int v=1;v<=points;v++)
        {
            if (edg[u][v]<infinity)
            {
                if (dis[v]>dis[u]+edg[u][v])
                {
                    dis[v]=dis[u]+edg[u][v];
                    father[v]=u;
                }
            }
        }
    }
    cout<<dis[end]<<" ";
    cout<<endl;
    int tmp;
    stack<int>si;
    si.push(end);
    while (start!=end)
    {
        tmp=father[end];
        if (tmp==0)
        {
            cout<<"没有路径"<<endl;
            return 0;
        }
        si.push(tmp);
        end=tmp;
    }
    while(!si.empty())
    {
        cout<<si.top()<<" ";
        si.pop();
    }
    cout<<endl;
}