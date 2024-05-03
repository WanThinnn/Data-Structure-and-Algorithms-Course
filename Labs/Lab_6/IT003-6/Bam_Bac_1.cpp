#include <iostream>

using namespace std;

const int M = 10; // Kích thước bảng băm

//Khai bao phan tu cua bang bam
typedef struct
{
    int key; //khoa cua nut tren bang bam
} Node;

int N; //bien toan cuc chi so nut hien co tren bang bam

Node HashTable[M]; // Khai báo bảng băm


// Hàm băm H(k) = k % M
int HashFunction(int k)
{
    return k % M;
}

// Hàm thêm khóa vào bảng băm
void insertKey(int k)
{
    int index = HashFunction(k); // Băm khóa vào vị trí ban đầu
    
    // Kiểm tra xem vị trí ban đầu có trống hay không
    if (HashTable[index].key == 0)
        HashTable[index].key = k;
    
    else
    {
         // Bước nhảy để xử lý đụng độ
        int i = 1;
        while (i < M)
        {
            int hi = (index + i) % M; // Tính toán vị trí mới
            
            // Kiểm tra xem vị trí mới có trống hay không
            if (HashTable[hi].key == 0)
            {
                HashTable[hi].key = k;
                break;
            }
            i++;
        }
        
        if (i == M)
        {
            cout << "Khong the them khoa " << k << " vao bang bam." << endl;
        }
    }
}

int main() {
    int keys[] = {32, 53, 22, 92, 17, 34, 24, 37, 56};
    int numKeys = sizeof(keys) / sizeof(keys[0]);
    
    // Khởi tạo bảng băm
    HashTable[M] = {0};
    
    // Thêm các khóa vào bảng băm
    for (int i = 0; i < numKeys; i++)
        insertKey(keys[i]);
    
    // In ra bảng băm kết quả
    for (int i = 0; i < M; i++)
    {
        cout << "Index " << i << ": ";
        if (HashTable[i].key != 0)
            cout << HashTable[i].key;
        cout << endl;
    }
    return 0;
}

