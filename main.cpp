#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

// PURPOSE: Models Binary Tree Node
struct BinaryTreeNode {
    int data; // value of the node
    BinaryTreeNode* left; // pointer to the left node
    BinaryTreeNode* right; // pointer to the right node
    BinaryTreeNode(int new_val) : data(new_val), left(NULL), right(NULL) {}
};

void find_and_print_sum_of_nodes(BinaryTreeNode* T, int desired_sum, int cur_sum, string buffer) {
    if (!T) return;
    
    int new_sum = cur_sum + T->data;
    
    string new_buffer = buffer + " " + to_string(T->data);
    
    if (new_sum == desired_sum)
        cout << new_buffer << endl;
    
    // down left subtree
    find_and_print_sum_of_nodes(T->left, desired_sum, new_sum, new_buffer);
    
    // down right subtree
    find_and_print_sum_of_nodes(T->right, desired_sum, new_sum, new_buffer);
    
    // restart from left subtree
    find_and_print_sum_of_nodes(T->left, desired_sum, cur_sum, buffer);
    
    // restart from right subtree
    find_and_print_sum_of_nodes(T->right, desired_sum, cur_sum, buffer);
    
}

// PURPOSE: Runs demonstrative tests
void test01() {
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(1);
    root->left->left = new BinaryTreeNode(-1);
    root->left->right = new BinaryTreeNode(8);
    root->right->right = new BinaryTreeNode(11);
    root->left->left->left = new BinaryTreeNode(18);
    root->left->right->left = new BinaryTreeNode(6);
    
    find_and_print_sum_of_nodes(root, 17, 0, " ");
    
    cout << endl << endl ;
}

void test02() {
    BinaryTreeNode* root = new BinaryTreeNode(0);
    root->left = new BinaryTreeNode(20);
    root->right = new BinaryTreeNode(22);
    root->left->left = new BinaryTreeNode(23);
    root->left->right = new BinaryTreeNode(5);
    root->right->left = new BinaryTreeNode(20);
    root->right->right = new BinaryTreeNode(-2);
    root->left->left->right = new BinaryTreeNode(-1);
    root->left->right->left = new BinaryTreeNode(37);
    root->right->left->right = new BinaryTreeNode(0);
    root->right->right->right = new BinaryTreeNode(7);
    
    find_and_print_sum_of_nodes(root, 42, 0, " ");
    
    cout << endl << endl;
}

void test03() {
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(-2);
    root->right = new BinaryTreeNode(7);
    root->right->left = new BinaryTreeNode(0);
    root->right->right = new BinaryTreeNode(-9);
    root->right->left->right = new BinaryTreeNode(-1);
    
    find_and_print_sum_of_nodes(root, -1, 0, " ");
    
    cout << endl << endl;
}

int main() {
    test01();
    test02();
    test03();
    return 0;
}
