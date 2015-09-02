#include <cstring>
#define N 10000
#define MAX 0x3f3f3f3f
using namespace std;
int matrix[N][N];
int Prim(int ans[],int n)
{
    memset(ans,0,sizeof(ans));
    int sum = 0;
    int min = MAX;
    int temp1=0,temp2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(matrix[i][j]<min&&i!=j)
            {
                min = matrix[i][j];
                temp1 = i;
                temp2 = j;
            }
        }
    }
    if(!temp1)
        return sum;
    ans[temp2] = temp1;
    sum += min;
    for(int i=0;i<n-2;i++)
    {
        min = MAX;
        temp1 = temp2 = 0;
        for(int j=1;j<=n;j++)
        {
            if(ans[j])
                continue;
            for(int k=1;k<=n;k++)
            {
                if(ans[k]&&matrix[j][k]<min)
                {
                    min = matrix[j][k];
                    temp1 = j;
                    temp2 = k;
                }
            }
        }
        if(!temp1)
            return sum;
        sum += min;
        ans[temp2] = temp1;
    }
    return sum;
}
