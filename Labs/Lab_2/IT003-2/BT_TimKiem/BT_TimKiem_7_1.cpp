#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    float x, y;
};

void input(Point A[], Point &P, int &n)
{
    cout << "n = ";
    cin >> n;
    for (int i = 0; i< n; i++)
        cin >> A[i].x >> A[i].y;
    cout << "P.x = ";
    cin >> P.x;
    cout << "P.y = ";
    cin >> P.y;
    
}


int findClosestPoint(Point A[], Point P, int n)
{
    float minDistance = pow(P.x - A[0].x, 2) + pow(P.y - A[0].y, 2);
    int closestIndex = 0;

    for (int i = 1; i < n; i++)
    {
        float distance = pow(P.x - A[i].x, 2) + pow(P.y - A[i].y, 2);
        if (distance < minDistance)
        {
            minDistance = distance;
            closestIndex = i;
        }
    }

    return closestIndex;
}


int main()
{
    Point A[1000], P;
    int n;
    input(A, P, n);
    int delta = findClosestPoint(A, P, n);
    if (delta != -1)
    {
    cout << "Chi so diem q(xq, yq) gan nhat voi p(xp, yp) la: " << delta << "\n";
    }
    else
          cout << "Khong tim thay diem q(xq, yq) trong mang A\n";
    
}
