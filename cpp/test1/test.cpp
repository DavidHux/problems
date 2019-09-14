#include <iostream>
#include <string>
using namespace std;

class Solution {
    string mi = "{}";
public:
    string smallestFromLeaf(TreeNode* root) {
        posto(root, "");
        return mi;
    }
    void posto(TreeNode* root, string prev){
        string s = prev;
        s.insert(s.begin(), 'a'+root->val);
        if(root ->left == NULL && root->right ==NULL)
            mi = min(mi, s);
        else{
            if(root->left != NULL)
                posto(root->left, s);
            if(rott->right != NULL)
                posto(root->right, s);
        }
    }
};

int main(){
    string s = "";
    s.push_back('a');
    cout<<s<<endl;
    return 0;
}