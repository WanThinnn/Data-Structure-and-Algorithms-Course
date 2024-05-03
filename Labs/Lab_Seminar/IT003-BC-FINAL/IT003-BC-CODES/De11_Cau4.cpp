#include <iostream>

using namespace std;

const int M = 7; // Kích thước bảng băm

//Khai bao phan tu cua bang bam
typedef struct
{
    int key; //khoa cua nut tren bang bam
} Node;

int N; //bien toan cuc chi so nut hien co tren bang bam

Node HashTable[M]; // Khai báo bảng băm


// Hàm băm H1(k) = k % M
int hashFunction1(int k)
{
    return k % M;
}

// Hàm băm H2(k) = (M-2) - [k%(M-2)].
int hashFunction2(int k)
{
    return ((M-2) - (k%(M-2)));
}

// Hàm thêm khóa vào bảng băm
void insertKey(int k)
{
    int index = hashFunction1(k); // Băm khóa vào vị trí ban đầu
    
    // Kiểm tra xem vị trí ban đầu có trống hay không
    if (HashTable[index].key == 0)
    {
        HashTable[index].key = k;
    }
    else
    {
        int step = hashFunction2(k); // Bước nhảy để xử lý đụng độ
        int i = 0;
        while (i < M)
        {
            index = (index + step) % M; // Tính toán vị trí mới
            
            // Kiểm tra xem vị trí mới có trống hay không
            if (HashTable[index].key == 0)
            {
                HashTable[index].key = k;
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
    int keys[] = {76, 93, 40, 47, 10, 55};
    int numKeys = sizeof(keys) / sizeof(keys[0]);
    
    // Khởi tạo bảng băm
    for (int i = 0; i < M; i++)
    {
        HashTable[i].key = 0;
    }
    
    // Thêm các khóa vào bảng băm
    for (int i = 0; i < numKeys; i++)
    {
        insertKey(keys[i]);
    }
    
    // In ra bảng băm kết quả
    for (int i = 0; i < M; i++)
    {
        cout << "Index " << i << ": ";
        if (HashTable[i].key != 0)
        {
            cout << HashTable[i].key;
        }
        cout << endl;
    }
    return 0;
}

