#include <math.h>
#include <algorithm>
#include <vector>
#define EPS 1e-6
using namespace std;
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vec;
Vec operator +(Vec A,Vec B){return Vec(A.x+B.x,A.y+B.y);}
Vec operator -(Point A,Point B){return Vec(A.x-B.x,A.y-B.y);}
int dcmp(double x)
{
	if(fabs(x)<EPS)
        return 0;
    else
        return x<0 ? -1: 1;
}
bool operator == (const Point& a,const Point &b)
{
	return dcmp(a.x-b.x)==0 &&dcmp(a.y-b.y) == 0;
}
bool operator <(const Point& a,const Point& b)
{
	return a.x<b.x || (a.x == b.x && a.y<b.y);
}
double Cross(Vec A,Vec B)
{
    return A.x*B.y - A.y*B.x;
}
double Length(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
vector<Point> ConvexHull(vector<Point> p)
{
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	int n = p.size();
	vector<Point> ch(n+1);
	int m = 0;
	for(int i=0;i<n;i++)
    {
		while(m>1 && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])) <= 0)
            m--;         //若需要把边线上的点也算上，把等号去掉
		ch[m++] = p[i];
	}
	int k = m;
	for(int i=n-2;i>=0;i--)
	{
		while(m>k && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])) <= 0)
            m--;
		ch[m++] = p[i];
	}
	if(n>1)
        m--;
	ch.resize(m);
	return ch;
}
double RotatingCalipers(const vector<Point>& p)
{
	int n = p.size();
	double ans = 0;
	Point v;
	int cur = 1;
	for(int i=0;i<n;i++)
    {
		v = p[i]-p[(i+1)%n];
		while(dcmp(Cross(v,p[(cur+1)%n]-p[cur]))<0)
			cur = (cur+1)%n;
		ans = max(ans,max(Length(p[i],p[cur]),Length(p[(i+1)%n],p[(cur+1)%n])));
	}
	return ans;
}
