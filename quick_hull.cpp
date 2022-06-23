#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x,y;
    
    Point(){}

    Point(int x,int y) {
        this->x = x;
        this->y = y;
    }

    bool operator<(const Point &o) const {
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
};

int find_side(Point a,Point b, Point p) {
    int res = (p.y-a.y)*(a.x-b.x)-(a.y-b.y)*(p.x-a.x);

    if(res<0) return -1;
    else if(res>0) return 1;
    else return 0;
}

int dist(Point a, Point b, Point p) {
    int res = (p.y-a.y)*(a.x-b.x)-(a.y-b.y)*(p.x-a.x);
    return abs(res);
}

set<Point>convex_hull;
vector<Point>points;

void quick_hull(int n,Point a, Point b,int side) {
    int mx = 0, idx = -1;

    for(int i=0;i<n;i++) {
        if(mx < dist(a,b,points[i]) and find_side(a,b,points[i])==side) {
            mx = dist(a,b,points[i]);
            idx = i;
        }
    }

    if(idx==-1) {
        convex_hull.insert(a);
        convex_hull.insert(b);
        return;
    }

    quick_hull(n,a,points[idx],-find_side(a,points[idx],b));
    quick_hull(n,points[idx],b,-find_side(points[idx],b,a));
}

void print_convex_hull(int n) {
    if(n<3) {
        cout<<"Convex hull not possible !\n";
        return;
    }

    int mx_x = 0, mn_x = 0;

    for(int i=1;i<n;i++) {
        if(points[i].x > points[mx_x].x) {
            mx_x = i;
        }
        if(points[i].x < points[mn_x].x) {
            mn_x = i;
        }
    }

    quick_hull(n,points[mn_x],points[mx_x],1);
    quick_hull(n,points[mn_x],points[mx_x],-1);

    cout<<"Following are the points of convex hull -> \n\n";

    for(const auto &u:convex_hull) {
        cout<<u.x<<' '<<u.y<<"\n";
    }
}

int main() {
    int n;
    cin>>n;

    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;

        points.push_back(Point(x,y));
    }

    print_convex_hull(n);
}