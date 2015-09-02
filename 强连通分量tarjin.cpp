#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#define N 10000
#define MAX 0x3f3f3f3f
using namespace std;
vector <int> e[N];
stack <int> Stack;
int dfn[N],low[N],times;
bool used[N], instack[N];

int ans[N],sum;

void init()
{
    memset(e,0,sizeof(e));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(used,0,sizeof(used));
    memset(instack,0,sizeof(instack));
    memset(ans,0,sizeof(ans));
    while(!Stack.empty())
        Stack.pop();
    sum = times = 0;
}
void tarjin(int x)
{
	used[x] = instack[x] = true;
	dfn[x] = low[x] = ++times;
	Stack.push(x);
	for(int i=0;i<e[x].size();i++)
    {
		if(!used[e[x][i]])
		{
			tarjin(e[x][i]);
			low[x] = min(low[x],low[e[x][i]]);
		}
        else if(instack[e[x][i]])
        {
			low[x] = min(low[x],dfn[e[x][i]]);
		}
	}
	if (low[x]==dfn[x])
    {
		sum++;
		int u;
		do
		{
			u = Stack.top();
			Stack.pop();
			ans[u] = sum;
			instack[u] = false;
		}while(u!=x);
	}
}

