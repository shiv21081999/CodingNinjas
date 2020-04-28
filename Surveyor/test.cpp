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

class Point{
    public:
        double x;
        double y;
};

class Polygon{
    public:
        Point *points = new Point[1];
        Polygon(int n)
        {
            points = new Point[n];
        }
};

int area(Polygon polygon, int n)
{
    double finalarea = 0;
    for (int i = 1; i < n-1; i++)
    {
        double x1 = polygon.points[i].x - polygon.points[0].x;
        double y1 = polygon.points[i].y - polygon.points[0].y;
        double x2 = polygon.points[i+1].x - polygon.points[0].x;
        double y2 = polygon.points[i+1].y - polygon.points[0].y;
        double cross = (x1*y2 - y1*x2)/2;
        finalarea += cross;
    }
    finalarea = abs(finalarea);
    return (int)finalarea;
}

int32_t main(){
    string str;
    cin>>str;
    int n = str.length();
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Polygon polygon(n);
    polygon.points[0].x = 0;
    polygon.points[0].y = 0;
    for (int i = 0; i < n-1; i++)
    {
        double x,y;
        x = polygon.points[i].x;
        y = polygon.points[i].y;
        if(str[i] == 'N')
        {
            y +=arr[i];
        }
        else if(str[i] == 'S')
        {
            y -=arr[i];
        }
        else if(str[i] == 'E')
        {
            x +=arr[i];
        }
        else
        {
            x -=arr[i];
        }
        polygon.points[i+1].x = x;
        polygon.points[i+1].y = y;
    }
    cout<<area(polygon, n)<<endl;
    return 0;
}