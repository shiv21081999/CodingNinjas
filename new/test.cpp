#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back 
const int N = 100005, M = 11;
int mod = 1000000007;

struct Point{
    double x;
    double y;
};

bool checkCorner(Point a, Point b, Point c)
{
    Point ab;
    Point ac;
    Point bc;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    ac.x = c.x - a.x;
    ac.y = c.y - a.y;
    bc.x = c.x - b.x;
    bc.y = c.y - b.y;
    if((ab.x*ac.x + ab.y*ac.y) > 0 && (ab.x*bc.x + ab.y*bc.y) < 0)
    {
        return false;
    }
    cout<<a.x<<","<<a.y<<" "<<b.x<<","<<b.y<<" "<<c.x<<","<<c.y<<endl;


    return true;
}

bool isPossible(Point a, Point b, Point *arr, int n)
{
    Point ab;
    ab.x = b.x-a.x;
    ab.y = b.y-a.y; 
    for (int i = 0; i < n; i++)
    {
        Point c = arr[i];
        Point ac;
        Point bc;
        ac.x = c.x - a.x;
        ac.y = c.y - a.y;
        bc.x = c.x - b.x;
        bc.y = c.y - b.y;
        if((ab.x*ac.x + ab.y*ac.y) > 0 && (ab.x*bc.x + ab.y*bc.y) < 0)
        {
            return false;
        }
    }
    return true;
}

double distance(Point a, Point b)
{
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    return dist;
}

int32_t main(){
    int n;
    cin>>n;
    Point* points = new Point[n];
    for (int i = 0; i < n; i++)
    {
        cin>>points[i].x;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>points[i].y;
    }
    sort(points, points + n, [&](Point a, Point b)
         {
             return a.y<b.y;
         });
    double finalmax = max(points[0].y, 200 - points[n-1].y);
    Point corner1, corner2, corner3, corner4;
    corner1.x = 0; corner2.x = 0; corner3.x = 200; corner4.x = 200;
    corner1.y = 0; corner2.y = 200; corner3.y = 0; corner4.y = 200;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(points[i].y != points[j].y && isPossible(points[i],points[j], points, n))
            {
                if(checkCorner(points[i],points[j],corner1) && checkCorner(points[i],points[j],corner2) && checkCorner(points[i],points[j],corner3) && checkCorner(points[i],points[j],corner4))
                {
                    double dist = distance(points[i], points[j]);
                    if(dist > finalmax)
                        finalmax = dist;
                }
            }
        }
        
    }
    if((double)((int)finalmax) == finalmax)
    {
        cout<<(int)finalmax -1<<endl;
    }
    else
    {
        cout<<(int)finalmax<<endl;
    }
    
    return 0;
}