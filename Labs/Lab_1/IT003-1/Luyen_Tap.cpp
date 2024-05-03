/*
 - BT.INP: Nhap vao thong tin cua n sinh vien gom:
 + MSSV
 + Ho ten
 + Nam sinh
 + Que quan
 + Gioi tinh
 + Diem Toan, Ly, Hoa
 + MSSV can tim
 Va tinh diem trung binh cua tung hoc sinh.
 
 - BT.OUT:
 + Xuat cac thong tin moi sinh vien 1 dong
 + 1: la co MSSV sinh vien can tim, 0: k co ten sinh vien can tim
 */

#include <string>
#include <iostream>

using namespace std;
string MSSV_S;
float dTB_S;
class Students
{
    private:
        string HT, QQ, GT;
        float dT, dL, dH;
    public:
        float dTB;
        string MSSV;
        void input(Students A[]);
        void output();
        void solve();
        void normalize(string &st1);
        int sequential_search(Students a[], int n, string X);
        void Swap(Students x[], Students y[]);
        void B_sort(Students A[], int n);
        friend class Students_IO;
        
};



class Students_IO
{
    public:
        void inputs(Students A[], int &N);
        void outputs(Students A[], int N);
        
};

void Students_IO::inputs(Students A[], int &N)
{
    for (int i = 0; i < N; i++)
        A[i].input(A);
}

void Students::input(Students A[])
{
    cin.ignore();
    getline(cin, MSSV);
//    getline(cin, HT);
//    getline(cin, QQ);
//    getline(cin, GT);
    cin >> dT >> dH >> dL;
}


void Students::normalize(string &st1)
{
    int64_t n = st1.length();
    for (int i = 0; i<n; i++)
        st1[i]=tolower(st1[i]);
    
    for (int i = 0; i<n; i++)
    {
        if (st1[0] == ' ')
            st1.erase(st1.begin() + 0);
        if (st1[n-1] == ' ')
            st1.erase(st1.begin() + (n-1));
    }
        
    for (int i = 0; i < n; i++)
        if ((st1[i] == ' ') and (st1[i+1] == ' '))
            st1.erase(st1.begin() + i);

    st1[0] = toupper(st1[0]);

    for (int i = 0; i < n; i++)
            if (st1[i] == ' ')
                st1[i+1] = toupper(st1[i+1]);
}


void Students::output()
{
    cout << HT << " " << dT << " " << dL << " " << dH << " " << dTB << endl;
}

void Students_IO::outputs(Students A[], int N)
{
    for (int i = 0; i < N; i++)
        A[i].output();
}

void Students::solve()
{
    dTB = (dT + dL + dH)/3;
    normalize(HT);
    normalize(QQ);
    normalize(GT);
}
    
int sequential_search(Students a[], int n, string X)
{
    for (int i = 0; i < n; i++)
        if (X == a[i].MSSV)
            return 1;
    return 0;
}

int binary_search(Students a[], int n, float X)
{
    int left, right, mid;
    left = 0; right = n - 1;
    do
    {
        mid = (left + right)/2;
        if (a[mid].dTB == X)
            return 1;
        else if (a[mid].dTB < X)
            left = mid + 1;
        else
            right = mid - 1;
    }
    while (left <= right);
    return 0;
}



void search(Students A[], int n)
{
    fflush (stdin);
    cout << "Nhap MSSV can tim: ";
    getline(cin, MSSV_S);
    {
        if (sequential_search(A, n, MSSV_S) == 1)
            cout << "Co" << endl;
        else
            cout << "Khong" << endl;
    }
    
    cout << "Nhap diem SV can tim: ";
    cin >> dTB_S;
    if (binary_search(A, n, dTB_S) == 1)
        cout << "Co" << endl;
    else
        cout << "Khong" << endl;
    
}


int main()
{
    Students A[1000];
    Students_IO N;
    int n;
    cin >> n;
    N.inputs(A, n);
    for (int i = 0; i < n; i++)
        A[i].solve();
    search(A, n);
    N.outputs(A, n);
}
