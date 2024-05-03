//
//  main.cpp
//  De11_Cau3
//
//  Created by Trần Thế Hữu Phúc on 04/06/2023.
//

#include <iostream>
using namespace std;

//Cấu trúc dữ liệu của 1 node
struct Node {
    int key;
    Node* left;
    Node* right;
};

//Cấu trúc dữ liệu của 1 cây
typedef Node* Tree;

//Tạo 1 cây rỗng
void CreateTree(Tree &root) {
    root = NULL;
}

//Tạo nút có key bằng x
Node* CreateNode(int x) {
    Node* node = new Node;
    node->key = x;
    node->left = node->right = NULL;
    return node;
}

//Thêm 1 nút vào cây
void AddNode(Tree &root, Node* node) {
    if (root == NULL) {
        root = node;
    } else {
        if (node->key < root->key)
            return AddNode(root->left, node);
        if (node->key > root->key)
            return AddNode(root->right, node);
        else
            return;
    }
}

//Duyệt cây LRN
void LRN(Tree root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

//Hàm in các node trên mức k
void Print_Nodes(Tree root, int k) {
    if (root != NULL) {
        if (k == 0)
            cout << root->key << " "; //in nút khi đạt điều kiện
        else { //xuống mức tiếp theo
            k--; //giảm k đi 1 đơn vị
            if (root->left != NULL)
                Print_Nodes(root->left, k);
            if (root->right != NULL)
                Print_Nodes(root->right, k);
        }
    }
}

int main() {
    Tree root;
    CreateTree(root);
    //Khai báo mảng chứa các nút số nguyên trong cây
    int Array[12] = {33, 12, 47, 5, 17, 35, 65, 8, 57, 71};
    //Tạo cây với mảng số nguyên vừa khai báo
    for (int i = 0; i < 10; i++) {
        AddNode(root, CreateNode(Array[i]));
    }
    cout << "\nNhập mức k bạn muốn in các node: ";
    int k;
    cin >> k;
    cout << "Kết quả: " ;
    Print_Nodes(root, k);
    return 0;
}

