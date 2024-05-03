#include <iostream>

using namespace std;

#define M 10

typedef struct nodes
{
    int key;
    struct nodes* Next;
} Node;

//khai báo kiểu con trỏ chỉ nút
typedef Node* HNode;

// khai báo mảng HASHTABLE chứa M con trỏ
HNode HashTable[M];

// Hàm băm H(k) = k % M
int HashFunction(int k)
{
    return k % M;
}

void AddTail(int k, int index)
{
    HashTable[index] = new Node;
    HashTable[index]->key = k;
    HashTable[index]->Next = NULL;
}

void AddNext(HNode CurrentNode, int k)
{
    CurrentNode->Next = new Node;
    CurrentNode->Next->key = k;
    CurrentNode->Next->Next = NULL;
}

// Hàm thêm khóa vào bảng băm
void InsertKey(int k)
{
    int index = HashFunction(k); // Băm khóa vào vị trí ban đầu
    
    // Kiểm tra xem vị trí ban đầu có trống hay không
    if (HashTable[index] == NULL)
        AddTail(k, index);
    
    else
    {
        //Tạo 1 con trỏ Node trỏ đến đầu danh sách của vị trí i trong HashTable
        HNode CurrentNode = HashTable[index];
        
        // Tìm vị trí cuối cùng của danh sách liên kết
        while (CurrentNode->Next != NULL)
            CurrentNode = CurrentNode->Next;
        
        // Thêm khóa vào cuối danh sách liên kết
        AddNext(CurrentNode, k);
    }
}

int main()
{
    int keys[] = {32, 53, 22, 92, 17, 34, 24, 37, 56};
    int numKeys = sizeof(keys) / sizeof(keys[0]);
    
    // Khởi tạo bảng băm
    HashTable[numKeys] = {0};
    
    // Thêm các khóa vào bảng băm
    for (int i = 0; i < numKeys; i++)
        InsertKey(keys[i]);
    
    // In ra bảng băm kết quả
    for (int i = 0; i < numKeys; i++)
    {
        cout << "Index " << i << ": ";
        HNode CurrentNode = HashTable[i];
        while (CurrentNode != NULL)
        {
            cout << CurrentNode->key << " ";
            CurrentNode = CurrentNode->Next;
        }
        cout << endl;
    }
    
    // Giải phóng bộ nhớ
    for (int i = 0; i < M; i++)
    {
        HNode CurrentNode = HashTable[i];
        while (CurrentNode != NULL)
        {
            HNode temp = CurrentNode;
            CurrentNode = CurrentNode->Next;
            delete temp;
        }
    }
    return 0;
}

