#include <iostream>
#include <math.h>
#define MAX 1000
using namespace std;
struct Point {
    float x, y;
};
float KhoangCach(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int TimDiemGanNhat(Point p, Point a[], int soLuong)
{
    int ans = 0;
    float minn = KhoangCach(p, a[0]);
    for (int i = 1; i < soLuong; i++)
    {
        if (minn > KhoangCach(p, a[i]))
        {
            minn = KhoangCach(p, a[i]);
            ans = i;
        }
    }
    return ans;
}
int main() {
    int soLuong;
    cout << "Nhap so luong: ";
    cin >> soLuong;
    Point a[MAX];
    for (int i = 0; i < soLuong; i++) {
        cout << "Nhap q.x" << i+1<< ": ";
        cin >> a[i].x;
        cout << "Nhap q.y" <<i+1 <<": ";
        cin >> a[i].y;
    }
    Point p;
    cout << "Nhap diem p: " << endl;
    cout << "Nhap x: ";
    cin >> p.x;
    cout << "Nhap y: ";
    cin >> p.y;
    int ans = TimDiemGanNhat(p, a, soLuong);
    cout << "Diem Gan p Nhat Thuoc Mang a La: (" << a[ans].x << "," << a[ans].y << ")";
    cout << "\nCo vi tri: " << ans+1 << endl;
    return 0;
    
}
