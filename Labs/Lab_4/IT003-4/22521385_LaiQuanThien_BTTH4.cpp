#include <iostream>
using namespace std;

struct Date
{
    int day, month, year;
    void inputDate()
    {
        cout << "+ Enter day: ";
        cin >> day;
        cout << "+ Enter month: ";
        cin >> month;
        cout << "+ Enter year: ";
        cin >> year;
    }
    void outputDate() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

struct Computers
{
    string ID, Name;
    Date exportDate;
    int exportPrice;
};

struct Node
{
    Computers data;
    Node *Next;
};

struct List
{
    Node *Head;
    Node *Tail;
};

void CreateList (List &l) {l.Head = l.Tail = NULL;}

Node* CreateNode(Computers x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    else
    {
        p->data = x;
        p->Next = NULL;
    }
    return p;
}

int IsEmpty (List &Q)
{
    if (Q.Head == NULL)
        return 1; //Queue rỗng return 1;
    else
        return 0;
}

void EnQueue(List &Q, Node *Tam) //Thêm 1 phần tử vào Queue
{
    if(Q.Head==NULL)
    {
        Q.Head = Tam;
        Q.Tail = Tam;
    }
    else
    {
        Q.Tail->Next = Tam;
        Q.Tail = Tam;
    }
}

int DeQueue(List &Q, Computers &trave) //Lay 1 phan tu khoi Queue
{
    Node *p;
    if (IsEmpty(Q) != 1)
        if (Q.Head != NULL)
        {
            p = Q.Head;
            trave = p->data;
            Q.Head = Q.Head->Next;
            Q.Tail = NULL;
            if(Q.Head == NULL)
                return 1;
            delete p;
        }
    return 0;
}

istream& operator >> (istream& in, Computers &computer)
{
    cout << "- Enter computer ID: ";
    in >> computer.ID;
    cout << "- Enter computer name: ";
    in.ignore();
    getline(in, computer.Name);
    cout << "- Enter export price (in million VND): ";
    in >> computer.exportPrice;
    cout << "- Enter export date:\n";
    computer.exportDate.inputDate();
    cout << endl;
    return in;
}

ostream& operator << (ostream& out, Computers computer)
{
    out << "- Computer ID: " << computer.ID << endl;
    out << "- Computer name: " << computer.Name << endl;
    out << "- Export date: ";
    computer.exportDate.outputDate();
    out << "- Export price: " << computer.exportPrice << " million VND" << endl << endl;
    return out;
}

void InputExportComputers(List &l)
{
    int n;
    Computers x;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        EnQueue(l, CreateNode(x));
    }
}

void PrintList(List l)
{
    Node *p = l.Head;
    while (p != NULL)
    {
        cout << p->data;
        p = p->Next;
    }
}

bool FindID(List l, string x)
{
    Node *p = l.Head;
    bool found = false;
    cout << "** Computers with ID " << p->data.ID << ": **" << endl;
    while (p != NULL)
    {
        if (p->data.ID == x)
        {
            cout << p->data;
            found = true;
        }
        p = p->Next;
    }
    if (found == false)
        cout << "** No computers with ID " << x << " found. **" << endl;
    
    return found;
}

void DisplayExportedComputers(List l)
{
    if (IsEmpty(l) == true)
        cout << "** No computers have been exported. **" << endl;
    else
    {
        cout << "** Exported computers **" << endl;
        PrintList(l);
    }
}


int main()
{
    List L;
    CreateList(L);
    Computers computer;
    
    //CAU 1:
    cout << "* Enter computer information:\n";
    cin >> computer;
    cout << "\n* Computer information:\n";
    cout << computer;
    
    //CAU_2
    cout << "* Enter computer information:\n";
    InputExportComputers(L);
    cout << "\n* Computer information:\n";
    PrintList(L);

    //CAU 3
    FindID(L, "007");

    //CAU 4
    DisplayExportedComputers(L);
    return 0;
}
