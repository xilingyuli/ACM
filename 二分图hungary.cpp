#include<cstring>
#include<vector>
#include<algorithm>
#define U 10005
#define V 10005
#define INF -1
using namespace std;

vector<int> G[U];

int u,v;
int matchingu[U];
int matchingv[V];
bool used[V];

void connect(int u,int v)
{
    G[u].push_back(v);
}

bool dfs(int u)
{
    for (int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if (!used[v])
        {
            used[v] = true;
            if (matchingv[v]==INF || dfs(matchingv[v]))
            {
                matchingv[v] = u;
                matchingu[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungarian()
{
    int ans = 0;
    memset(matchingu, INF, sizeof(matchingu));
    memset(matchingv, INF, sizeof(matchingv));
    for(int i=0;i<u;i++)
    {
        if(matchingu[i]==INF)
        {
            memset(used, 0, sizeof(used));
            if(dfs(i))
                ans++;
        }
    }
    return ans;
}


