//
//  main.cpp
//  De10_Cau3
//
//  Created by Trần Thế Hữu Phúc on 03/06/2023.
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

//Hàm tính tổng các nút trên mức k
void Sum(Tree root, int k, int &s) {
    if (root != NULL) {
        if (k == 0)
            s += root->key; //cộng giá trị của nút vào biến tổng s
        else { //xuống mức tiếp theo
            k--; //giảm k đi 1 đơn vị
            if (root->left != NULL)
                Sum(root->left, k, s);
            if (root->right != NULL)
                Sum(root->right, k, s);
        }
    }
}

int main() {
    Tree root;
    CreateTree(root);
    //Khai báo mảng chứa dãy số nguyên theo đề
    int Array[12] = {38, 29, 35, 37, 32, 17, 23, 14, 44, 53, 40, 42};
    //Tạo cây với mảng số nguyên vừa khai báo
    for (int i = 0; i < 12; i++) {
        AddNode(root, CreateNode(Array[i]));
    }
    cout << "Kết quả duyệt cây theo thứ tự Left - Right - Node: ";
    LRN(root);
    cout << "\n\nNhập mức k bạn muốn tính tổng các node: ";
    int k, s = 0;
    cin >> k;
    Sum(root, k, s);
    if (s == 0) {
        cout << "Không tồn tại mức k = " << k << endl;
    } else {
        cout << "Kết quả: " << s << endl;
    }
    return 0;
}
