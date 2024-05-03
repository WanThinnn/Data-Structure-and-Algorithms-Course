#include <iostream>
using namespace std;

#define M 8

struct Node
{
    int key;
    int next;
};

void insertKey(Node hashTable[], int k)
{
    int index = k % M;
    int temp = M;
    
    if (hashTable[index].key == 0)
    {
        hashTable[index].key = k;
        hashTable[index].next = -1;
    }
    
    else
    {
        while (hashTable[temp].key != 0)
            temp--;

        hashTable[temp].key = k;
        hashTable[temp].next = -1;
        
        if (hashTable[index].next == -1)
            hashTable[index].next = temp;

        else if (hashTable[index].next != -1)
        {
            for (int i = M; i > 0; i--)
                if (hashTable[i].next == -1)
                    if (hashTable[i].key%M == hashTable[index].key%M)
                    {
                        hashTable[i].next = temp;
                        break;
                    }
        }
        
            
        
    }
}

void printHashTable(Node hashTable[])
{
    cout << "i:     ";
    for (int i = 0; i < M; i++) {
        cout << i << "   ";
    }
    cout << endl;
    
    cout << "key:   ";
    for (int i = 0; i < M; i++) {
        cout << hashTable[i].key << "   ";
    }
    cout << endl;
    
    cout << "next:  ";
    for (int i = 0; i < M; i++) {
        cout << hashTable[i].next << "   ";
    }
    cout << endl;
}

int main()
{
    Node hashTable[M] = {0};
    
    int keys[] = {8, 18, 20, 16, 24, 26, 32, 10};
    int numKeys = sizeof(keys) / sizeof(keys[0]);
 
    for (int i = 0; i < numKeys; i++)
        insertKey(hashTable, keys[i]);
    
    printHashTable(hashTable);
    
    return 0;
}
