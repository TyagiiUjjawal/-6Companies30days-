class Solution {
public:
    void inorder(TreeNode *root , vector<int> &inorderVal){
        if(root == NULL)
            return ;
        
        inorder(root->left , inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right , inorderVal);
        
    }
    
    vector<int> mergeArrays(vector<int> &a , vector<int> &b){
        vector<int> res(a.size() + b.size());
        
        int i = 0 , j = 0 , k = 0;
        
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                res[k++] = a[i];
                i++;
            }
            else{
                res[k++] = b[j];
                j++;
            }
        }
        
        while(i < a.size()){
            res[k++] = a[i];
            i++;
        }
        
        while(j < b.size()){
            res[k++] = b[j];
            j++;
        }
        return res;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1 , in2;
        inorder(root1 , in1);
        inorder(root2 , in2);
        
        vector<int> res = mergeArrays(in1 , in2);
        return res;
    }
};