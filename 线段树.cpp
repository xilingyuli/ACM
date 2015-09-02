#include<cstring>
#define N 10000
#define INF -1
using namespace std;
int tree[4*N];
int build[N];
void Init()
{
    memset(tree,INF,sizeof(tree));
}

int Find(int a,int b)
{
    return a>b?a:b;
}
void Build(int left,int right,int index)
{
    if(left==right)
    {
        tree[index] = build[left];
        return;
    }
    int mid = (left+right)/2;
    Build(left,mid,index*2);
    Build(mid+1,right,index*2+1);
    tree[index] = Find(tree[index*2],tree[index*2+1]);
}

void modify(int start,int end,int value,int left,int right,int index)
{
    if(start<=left&&right<=end)
        tree[index] = value;
    if(left==right)
        return;
    int mid = (left+right)/2;
    if(mid<end)
        modify(start,end,value,mid+1,right,index*2+1);
    if(mid>=start)
        modify(start,end,value,left,mid,index*2);
    tree[index] = Find(tree[index*2],tree[index*2+1]);
}

int query(int start,int end,int left,int right,int index)
{
    if(start<=left&&right<=end)
        return tree[index];
    //if(left==right)  //avoid start>end
    //    return INF;
    int mid = (left+right)/2;
    int temp1 = INF,temp2 = INF;
    if(mid<end)
        temp1 = query(start,end,mid+1,right,index*2+1);
    if(mid>=start)
        temp2 = query(start,end,left,mid,index*2);
    return Find(temp1,temp2);
}
