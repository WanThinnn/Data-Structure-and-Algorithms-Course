//Gợi ý thôi nha các bạn! Các bạn phải tự làm lại nha!


#include <iostream>
using namespace std;

//cấu trúc nút
typedef struct tagNode
{
	int info;
	struct tagNode* pNext;
}Node;

//cấu trúc danh sách
typedef struct tagList
{
	Node* pHead;
	Node* pTail;
}LIST;

//tạo dsach rỗng
void CreateList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

//tạo nút
Node* CreateNode(int x)
{
	Node* p = new Node;
	p->info = x;
	p->pNext = NULL;
	return p;
}

//thêm nút vào đầu danh sách
void AddHead(LIST& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = NULL;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

//thêm nút vào cuối dsach
void AddTail(LIST& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

//in nút ra màn hình
void PrintList(LIST l)
{
	Node* p;
	p = l.pHead;

	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}

//tìm phần tử thứ n trong danh sách
int FindValue(int a, LIST l)
{
	int temp = 999;
	Node* p;
	p = l.pHead;
	for (int i = 0; i <= a; i++)
	{
		temp = p->info;
		p = p->pNext;
	}
	return temp;
}

//tìm giá trị x trong danh sách
int FindX(int x, LIST l)
{
	Node* p;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			return 1;
		else
			p = p->pNext;
	}
	return 0;
}

//them x vao sau k
void Add_x_behind_k(int x, int k, LIST& l)
{
	Node* q = CreateNode(x);
	Node* p;
	p = l.pHead;

	while (p != NULL)
	{
		if (p->info == k)
		{
			q->pNext = p->pNext;
			p->pNext = q;
			break;
		}
		else
			p = p->pNext;
	}
}

//thêm x vào vị trí của n
void Add_x_to_n_place(int x, int n, LIST& l)
{
	Node* q = CreateNode(x);
	Node* p;
	p = l.pHead;

	for (int i = 0; i < n - 1; i++)
	{
		p = p->pNext;
	}
	q->pNext = p->pNext;
	p->pNext = q;
}

//đảo ngược danh sách
LIST rev_L(LIST l)
{
	LIST rL;
	CreateList(rL);
	Node* p;
	p = l.pHead;

	while (p != NULL)
	{
		//cout << p->info << " ";
		AddHead(rL, CreateNode(p->info));
		p = p->pNext;
	}
	return rL;
}

//xóa 1 nút
int RemoveNode(LIST& l, int x)
{
	Node* p = l.pHead;
	Node* q = NULL;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
	{
		if (p == l.pTail)
			l.pTail = q;
		q->pNext = p->pNext;
		delete p;
	}
	else
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	return 1;
}

//xóa nút đầu tiên
void RemoveHead(LIST& l)
{
	Node* p;

	if (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
}

//xóa nút cuối cùng
void RemoveTail(LIST l)
{
	Node* p = l.pHead;
	Node* q = p;

	while (p->pNext != NULL)
	{
		q = p;
		p = p->pNext;
	}

	q->pNext = NULL;
	l.pTail = q;
}

//xóa toàn bộ danh sách
void RemoveList(LIST& l)
{
	Node* p;

	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
	l.pTail = NULL;
	cout << "\n -Da xoa toan bo danh sach.";
}


int main()
{
	int n;
	int count = 0;
	LIST l;
	CreateList(l);

	//Bai 1
	cout << "Bai 1. Nhap dsach:\n";
	do
	{
		cin >> n;
		if (n == 0)
			break;
		count++;
		AddTail(l, CreateNode(n));
	} while (n != 0);

	//Bai 2
	cout << "\nBai 2. Danh sach vua nhap la: ";
	PrintList(l);
	cout << endl;

	//Bai 3
	cout << "\n\nBai 3. So nut la: " << count << endl;

	//Bai 4
	cout << "\nBai 4. Nhap thu tu phan tu muon biet gia tri (>=0): ";
	int vtri;
	cin >> vtri;
	cout << "\n=> Gia tri phan tu thu " << vtri << " la: " << FindValue(vtri, l) << endl;

	//Bai 5
	cout << "\nBai 5. Nhap so nguyen x: ";
	int x;
	cin >> x;
	cout << "(0: khong / 1: co) => " << FindX(x, l);

	//Bai 6
	cout << "\nBai 6. Them a sau phan tu b: \n -Nhap a: ";
	int a6;
	cin >> a6;
	cout << " -Nhap b: ";
	int b6;
	cin >> b6;

	while (FindX(b6, l) == 0)
	{
		cout << "Nhap sai! Gia tri " << b6 << " khong co trong danh sach.";
		exit(0);
	}

	Add_a_behind_b(a6, b6, l);
	cout << "\nList da them la: ";
	PrintList(l);

	//Bai 7
	cout << "\nBai 7. Them a vao vi tri b:\n -Nhap a: ";
	int a7, b7;
	cin >> a7;
	cout << " -Nhap b: ";
	cin >> b7;
	Add_a_to_b_place(a7, b7, l);
	cout << "List sau khi them la: ";
	PrintList(l);

	//Bai 8
	cout << "\n\nBai 8. Danh sach dao nguoc: ";
	PrintList(rev_L(l));
	cout << endl;

	//Bai 9
	cout << "\nBai 9. Nhap gia tri muon xoa khoi danh sach: ";
	int a9;
	cin >> a9;
	cout << RemoveNode(l, a9) << endl;

	//Bai 10
	cout << "\nBai  10. Danh sach sau khi xoa dau la: ";
	RemoveHead(l);
	PrintList(l);

	//Bai 11
	cout << "\n\nBai 11. Danh sach sau khi xoa duoi la: ";
	RemoveTail(l);
	PrintList(l);

	//Bai 12
	cout << "\n\nBai 12. Xoa  toan bo danh sach: ";
	RemoveList(l);
	PrintList(l);
	cout << endl;

	return 0;
}