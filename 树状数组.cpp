#define N 10000
int n;
int treeArray[N];
int lowbit(int i)
{
    return i&(-i);
}
void update(int i,int val)
{
    while(i<=n)
    {
        treeArray[i]+=val;
        i+=lowbit(i);
    }
}
int getsum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=treeArray[i];
        i-=lowbit(i);
    }
    return sum;
}
