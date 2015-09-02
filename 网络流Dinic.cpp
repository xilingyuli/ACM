#include <cstring>
#include <algorithm>
#include <vector>
#define N 10000
#define MAX 0x3f3f3f3f
using namespace std;
bool used[N];

//邻接矩阵
int matrix[N][N];
int dfs(int n,int s,int t,int f)
{
    if(s==t||!f)
        return f;
    used[s]=true;
    for(int i=1;i<=n;i++)
    {
        if(used[i]==false && matrix[s][i]>0)
        {
            int d=dfs(n,i,t,min(f,matrix[s][i]));
            if(d>0)
            {
                matrix[s][i]-=d;
                matrix[i][s]+=d;
                return d;
            }
        }
    }
    return 0;
}
//

//邻接表
struct Node
{
    int to;
    int cap;
    int rev;
};
vector<Node> v[N];

void add_Node(int from,int to,int cap)
{
    if(!cap)
        return;
    Node temp1,temp2;
    temp1.to = to;
    temp1.cap = cap;
    temp1.rev = v[to].size();
    temp2.to = from;
    temp2.cap = 0;
    temp2.rev = v[from].size();
    v[from].push_back(temp1);
    v[to].push_back(temp2);
}

int dfs(int s,int t,int f)
{
    if(s==t)
        return f;
    used[s]=true;
    for(int i=0;i<v[s].size();i++)
    {
        Node &temp = v[s][i];
        if(used[temp.to]==false && temp.cap>0)
        {
            int d=dfs(temp.to,t,min(f,temp.cap));
            if(d>0)
            {
                temp.cap-=d;
                v[temp.to][temp.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
//


int max_flow(int n,int s,int t)
{
    int flow=0;
    for(;;)
    {
        memset(used,false,sizeof(used));
        int f=dfs(n,s,t,MAX);
        if(f==0)
            return flow;
        flow+=f;
    }
}
