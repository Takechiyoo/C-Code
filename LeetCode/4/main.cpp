#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class point
{
public:
    double x;
    double y;
    point(double a, double b): x(a),y(b){}
};

class points
{
public:
    double d;
    int l;
    int r;
    points(double s, int a, int b): d(s), l(a), r(b){}
};

void find_points(vector<point> p)
{
    vector<points> t;
    for(int i = 0; i < p.size(); i++)
        for(int j = i+1; j < p.size(); j++)
        {
            double d = pow((p[i].x - p[j].x), 2) + pow((p[i].y - p[j].y), 2);
            points a(d, i, j);
            t.push_back(a);
        }
    int m = 0;
    for(int i = 1; i < t.size(); i++)
    {
        if(t[i].d < t[m].d)
            m = i;
    }
    cout << "(" << p[t[m].l].x << "," << p[t[m].l].y << ") " << "(" << p[t[m].r].x << "," << p[t[m].r].y << ")" << endl;
}
int main()
{
    vector<point> p;
    srand((int)time(0));
    for(int i = 0; i < 8; i++)
    {
        int x = rand()%100;
        int y = rand()%100;
        //cout << x << " " << y << endl;
        point t(rand()%100, rand()%100);
        p.push_back(t);
    }
    find_points(p);
    cout << "Hello world!" << endl;
    return 0;
}
