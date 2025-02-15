#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    char val;
    TreeNode* left=nullptr;
    TreeNode* right=nullptr;
    TreeNode( char data): val(data),left(nullptr),right(nullptr){}
};
TreeNode* constructTree(const vector<string>& array,int index=0){
if(index>array.size() || array[index]=="null"|| array[index]=="end"){
    return nullptr;
}
TreeNode* node = new TreeNode(array[index][0]);
node->left= constructTree(array,2*index+1);
node->right= constructTree(array,2*index+2);
return node;
}
void inorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
bool isSame(TreeNode* t1,TreeNode* t2){
    if(!t1 && !t2){
        return true;
    }
     if (!t1 || !t2)
    {
        return false;
    }
    return t1->val==t2->val && isSame(t1->left,t2->left) && isSame(t1->right,t2->right);
    
}
bool isSubtree(TreeNode* main, TreeNode* sub){
    if(!sub) return true;
    if(!main) return false;
    if(isSame(main,sub)) return true;
    return isSubtree(main->left,sub) || isSubtree(main->right,sub);
}

int main(){
vector<string> arr1 = {"a", "b", "c", "null", "null", "d", "e", "end"};
    vector<string> arr2 = {"b", "null", "null"};
TreeNode* main = constructTree(arr1);
TreeNode* sub = constructTree(arr2);
cout << "In-order traversal of main tree: ";
    inorder(main);
    cout << endl;

    cout << "In-order traversal of subtree: ";
    inorder(sub);
    cout << endl;

    bool result = isSubtree(main, sub);
    cout << "Is the second tree a subtree of the first? " << (result ? "Yes" : "No") << endl;
return 0;
}
