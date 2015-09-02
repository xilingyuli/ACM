#include <cstring>
#define N 10000
#define MAX 0x3f3f3f3f
using namespace std;
int matrix[N][N];
void Dijkstra(int ans[],int n,int start)
{
    bool used[n];
    memset(used,0,sizeof(used));
    memset(ans,MAX,sizeof(ans));
    ans[start] = 0;
    used[start] = true;
    for(int i=1;i<=n;i++)
    {
        ans[i] = matrix[start][i];
    }
    for(int i=0;i<n-1;i++)
    {
        int min=MAX,mint=0;
        for(int j=1;j<=n;j++)
        {
            if(!used[j]&&ans[j]<min)
            {
                min = ans[j];
                mint = j;
            }
        }
        if(!mint)
            break;
        used[mint] = true;
        for(int j=1;j<=n;j++)
        {
            if(!used[j]&&matrix[mint][j]+ans[mint]<ans[j])
                ans[j] = matrix[mint][j]+ans[mint];
        }
    }
}
