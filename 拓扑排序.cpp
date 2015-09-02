#include <cstring>
#define N 10000
using namespace std;
int message[N][2];
int topology_sort(int ans[],int n,int m)
{
    bool used[n];
    memset(used,0,sizeof(used));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(used[j])
                continue;
            int k;
            for(k=0;k<m;k++)
            {
                if(message[k][1]==j&&!used[k])
                    break;
            }
            if(k==m)
            {
                ans[i] = j;
                used[j] = true;
                break;
            }
        }
    }
}
