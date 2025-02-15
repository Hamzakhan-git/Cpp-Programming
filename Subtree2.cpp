#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class TreeNode {
public:
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(string array[], int size, int index = 0) {
    if (index >= size || array[index] == "null" || array[index] == "end") {
        return nullptr;
    }
    TreeNode* node = new TreeNode(array[index][0]);
    node->left = constructTree(array, size, 2 * index + 1);
    node->right = constructTree(array, size, 2 * index + 2);
    return node;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

bool isSameTree(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) {
        return true;
    }
    if (!t1 || !t2) {
        return false;
    }
    return t1->value == t2->value && isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

bool isSubtree(TreeNode* mainTree, TreeNode* subTree) {
    if (!subTree) {
        return true;
    }
    if (!mainTree) {
        return false;
    }
    if (isSameTree(mainTree, subTree)) {
        return true;
    }
    return isSubtree(mainTree->left, subTree) || isSubtree(mainTree->right, subTree);
}

void getInputArray(string array[], int& size) {
    string input;
    size = 0;
    cout << "Enter elements of the array (type 'end' to finish): ";
    while (cin >> input && input != "end") {
        array[size++] = input;
        if (size >= MAX_SIZE) {
            break;
        }
    }
}

int main() {
    string array1[MAX_SIZE];
    string array2[MAX_SIZE];
    int size1, size2;

    cout << "Input for main tree:" << endl;
    getInputArray(array1, size1);

    cout << "Input for subtree:" << endl;
    getInputArray(array2, size2);

    TreeNode* mainTree = constructTree(array1, size1);
    TreeNode* subTree = constructTree(array2, size2);

    cout << "In-order traversal of main tree: ";
    inorderTraversal(mainTree);
    cout << endl;

    cout << "In-order traversal of subtree: ";
    inorderTraversal(subTree);
    cout << endl;

    bool result = isSubtree(mainTree, subTree);
    cout << "Is the second tree a subtree of the first? " << (result ? "Yes" : "No") << endl;

    return 0;
}
