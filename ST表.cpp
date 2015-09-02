#define N 50005
int st[20][N];

int Find(int a,int b)
{
    return a>b?a:b;
}

int Search(int start,int end)
{
    if(start==end)
        return st[0][start];
    int length,i;
    for(i=0,length=1;length<=end-start;i++,length*=2);
    i--;
    length/=2;
    return Find(Search(start+length,end),st[i][start]);
}

void ST(int n)
{
    int length = 1;
    for(int i=1;length<n;i++,length*=2)
    {
        int j;
        for(j=1;j+length<=n;j++)
        {
            st[i][j] = Find(st[i-1][j],st[i-1][j+length]);
        }
        n = j;
    }
}
