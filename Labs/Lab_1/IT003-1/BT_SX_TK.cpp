#include <iostream>
using namespace std;

string MSSV_S, HT_S;
float dTB_S;

class Student
{
    private:
        
        float dT, dL, dH;
    public:
        string HT;
        string MSSV;
        void input();
        void output();
        float sum_of_mark();
        void solve();
        void normalize();
};

class Students
{
    private:
        int n;
        Student A[1000];
    public:
        void input_list();
        void output_list();
        void sort();
        void swap(Student &x, Student &y);
        int sequential_search(string X);
        int binary_search(string X);
        void search();
        
        
};


void Student::input()
{
    cout << "Nhap vao MSSV: ";
    cin >> MSSV;
    cout << "Nhap vao HT: ";
    cin.ignore();
    getline(cin, HT);
    cout << "Nhap diem toan, ly, hoa: ";
    cin >> dT >> dL >> dH;
}

void Student::output()
{
    solve();
    cout << MSSV << "  " << HT << " " << dT << " " << dL << " " << dH << " " << sum_of_mark() << endl;
}

float Student::sum_of_mark(){
    return(dT + dL + dH);
}


void Students::input_list()
{
    cout << "Nhap vao so luong thi sinh: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        A[i].input();
}

void Students::output_list()
{
    for(int i = 0; i<n; i++)
        A[i].output();
}


void Students::swap(Student &x, Student &y)
{
     Student temp;
     temp = x;
     x = y;
     y = temp;
 }

void Students::sort()
{
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if (A[i].sum_of_mark() > A[j].sum_of_mark())
                swap(A[i], A[j]);
}

void Delete_spaces_1(string &st1)
{
    while (st1[0] == ' ') {
        st1.erase(st1.begin() + 0);
    }
    while (st1[st1.length() - 1] == ' ') {
        st1.erase(st1.begin() + st1.length() - 1);
    }
}

void Delete_spaces_2(string &st1)
{
    for (int i = 0; i < st1.length(); i++) {
        if (st1[i] == ' ' && st1[i + 1] == ' ') {
            st1.erase(st1.begin() + i);
            i--;
        }
    }
}

void Upper_string(string &st1)
{
    for (int i = 0; i < st1.length(); i++)
        st1[i]=tolower(st1[i]);
    
    st1[0] = toupper(st1[0]);
    
    for (int i = 0; i < st1.length() ; i++)
        if (st1[i] == ' ')
            st1[i+1] = toupper(st1[i+1]);
}



void Student::normalize()
{
    Delete_spaces_1(HT);
    Delete_spaces_2(HT);
    Upper_string(HT);
}



int Students::sequential_search(string X)
{
    for (int i = 0; i < n; i++)
        if (X == A[i].MSSV)
            return 1;
    return 0;
}

int Students::binary_search(string X)
{
    int left, right, mid;
    left = 0; right = n - 1;
    do
    {
        mid = (left + right)/2;
        if (A[mid].HT == X)
            return 1;
        else if (A[mid].HT < X)
            left = mid + 1;
        else
            right = mid - 1;
    }
    while (left <= right);
    return 0;
}

void Students::search()
{
    fflush (stdin);
    cout << "Nhap MSSV can tim: ";
    getline(cin, MSSV_S);
    if (sequential_search(MSSV_S) == 1)
        cout << "Co" << endl;
    else
        cout << "Khong" << endl;
    
    cout << "Nhap Ho Ten sinh vien can tim: ";
    getline(cin, HT_S);
    Delete_spaces_1(HT_S);
    Delete_spaces_2(HT_S);
    Upper_string(HT_S);
    if (binary_search(HT_S) == 1)
        cout << "Co" << endl;
    else
        cout << "Khong" << endl;
}

void Student::solve()
{
        normalize();
}

int main()
{
    Students ds;
    ds.input_list();
    cout << "Sap xep danh sach cac thi sinh theo thu tu tang dan ve tong diem: " << endl;
    ds.sort();
    ds.output_list();
    ds.search();
}
