#include <iostream>
using namespace std;

struct node
{
    char data;
    node *next;
};

typedef struct node NODE;
struct stack
{
    NODE *top;
};

typedef struct stack STACK;

void Init (STACK &s)
{
s.top = NULL;
}

NODE* CreateNode (char x)
{
    NODE *p;
    p = new NODE;
    if (p==NULL)
    {
        cout << "KHONG DU BO NHO!";
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

bool IsEmpty(STACK s)
{
    if (s.top == NULL)
        return true;
    return false;
}

void Push (STACK &s, char x)
{
    NODE *NewNode = CreateNode(x);
    if (NewNode != NULL)
    {
        if (IsEmpty(s))
        {
            s.top = NewNode;
        }
        else
        {
            NewNode->next = s.top;
            s.top = NewNode;
        }
    }
}
    
char Pop (STACK &s)
{
    NODE *p;
    char x;
    {
        p = s.top;
        s.top = p->next;
        x = p->data;
        delete p;
    }
    return x;
}
        
        

int count(STACK s)
{
    int n = 0;
    NODE *p = s.top;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

void InputStack(STACK &s)
{
    string ST;
    cin >> ST;
    for (int i = 0; i < ST.length(); i++)
    {
        Push(s, ST[i]);
    }
}

void PrintList(STACK s)
{
    NODE *p;
    p = s.top;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

bool kiemTraChuoiNgoacCanBang(string chuoi)
{
    STACK s;
    char x = '\0';
    Init(s);
    for (int i = 0; i < chuoi.length(); i++)
    {
        if (chuoi[i] == '(' or chuoi[i] == '[' or chuoi[i] == '{')
        {
            Push(s,chuoi[i]);
            continue;
        }
        
        if (IsEmpty(s) == true)
            return 0;
        
        switch (chuoi[i])
        {
            case ')':
                x = Pop(s);
                if (x == '{' or x == '[')
                    return false;
                break;
            case '}':
                x = Pop(s);
                if (x == '(' or x == '[')
                    return false;
                break;
            case ']':
                x = Pop(s);
                if (x == '(' or x == '{')
                    return false;
                break;
        }
    }
    return (IsEmpty(s));
}

int main()
{
    string st;
    STACK s;
    Init(s);
    cin >> st;
    if (kiemTraChuoiNgoacCanBang(st) == 1)
        cout << "Ngoac dung";
    else
        cout << "Ngoac sai";
    cout << endl;
    InputStack(s);
    PrintList(s);
    
}
