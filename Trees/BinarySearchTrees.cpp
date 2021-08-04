#include<bits/stdc++.h>
using namespace std;

class BST{
    private:
        struct node{
            int data;
            node* left;
            node* right;

            node(){
                left = NULL;
                right = NULL;
            }
            node(int data){
                this->data = data;
                left = NULL;
                right = NULL;
            }
        };
    
        node* root;

        node* createNode(int data){
            node* t = new node();
            t->data = data;
            return t;
        }

        node* insertNode(node* root, int data){
            if(root == NULL){
                root = createNode(data);
                return root;
            }

            else if(data > root->data)
                root->right = insertNode(root->right, data);
            else
                root->left = insertNode(root->left, data);

            return root;
        }

        node* deleteNode(node* root, int data){
            if(root == NULL) return root;
            else if(data < root->data)
                root->left = deleteNode(root->left, data);
            else if(data > root->data)
                root->right = deleteNode(root->right, data);
            
            else{
                if(root->left == NULL and root->right == NULL){
                    delete root;
                    root = NULL;
                }

                else if(root->left == NULL){
                    node* temp = root;
                    root = root->right;
                    delete temp;
                }

                else if(root->right == NULL){
                    node* temp = root;
                    root = root->left;
                    delete temp;
                }

                else{
                    node* temp = root->right;
                    while(temp->left != NULL)
                        temp = temp->left;
                    
                    root->data = temp->data;

                    root->right = deleteNode(root->right, temp->data);
                }
            }

            return root;
        }

        void inOrder(node* root){
            if(root == NULL) return;

            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }

        void preOrder(node* root){
            if(root == NULL) return;

            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }

        void postOrder(node* root){
            if(root == NULL) return;

            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }

        bool find(node* root, int data){
            if(root == NULL) return false;
            if(root->data == data)
                return true;

            if(data > root->data)
                find(root->right, data);
            else 
                find(root->left, data);
        }

        int minElement(node* root){
            if(root == NULL) return -1;

            node* temp = root;
            while(temp->left != NULL){
                temp = temp->left;
            }

            return temp->data; 
        }

        int maxElement(node* root){
            if(root == NULL) return -1;

            node* temp = root;
            while(temp->right != NULL){
                temp = temp->right;
            }

            return temp->data;
        }

        int height(node* root){
            if(root == NULL) return -1; // considering height as number of edges

            return max(height(root->left), height(root->right)) + 1;
        }

        void levelOrder(node* root){
            if(root == NULL){
                cout << "No nodes present\n";
            }
            queue<node*> q;
            q.push(root);
            cout << "Level Order Traversal: ";
            while(!q.empty()){
                node* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
        }

        bool isBST(node* root, node* &prev){
            if(!root) return true;

            if(root){
                if(!isBST(root->left, prev)) return false;

                if(prev != NULL && root->data < prev->data)
                    return false;
                prev = root;

                if(!isBST(root->right, prev)) return false;
            }

            return true;
        }

        void inorderPre(node* root, int key, node* &ans){
            if(!root) return;

            inorderPre(root->left, key, ans);

            if(root and root->data < key)
                ans = root;

            inorderPre(root->right, key, ans);
        }

        void inorderSucc(node* root, int key, node* &ans){
            if(!root) return;

            inorderSucc(root->left, key, ans);

            if(root and root->data > key){

                if(!ans or root->data < ans->data)
                    ans = root;
            }

            inorderSucc(root->right, key, ans);
        }

        int lca(node* root, int u, int v){ // assuming u < v
            if(root == NULL) return -1;
            if(root->data >= u && root->data <= v) return root->data;
            else if(root->data > u) return lca(root->left, u, v);
            else return lca(root->right, u, v);
        }

        void populateInorderSucc(node* root, vector<int> &ans, int &next){
            if(root == NULL) return;
            populateInorderSucc(root->right, ans, next);
            ans.push_back(next);
            next = root->data;
            populateInorderSucc(root->left, ans, next);
        }

        void kthLargest(node* root, int k, int& c, int& ans){
            if(root == NULL) return;
            kthLargest(root->right, k, c, ans);

            c++;
            if(c == k){
                 ans = root->data;
                 return;
            }

            kthLargest(root->left, k ,c, ans);
        }

        void kthSmallest(node* root, int k, int& c, int& ans){
            if(root == NULL) return;
            kthSmallest(root->left, k, c, ans);
            
            c++;
            if(c == k){
                 ans = root->data;
                 return;
            }

            kthSmallest(root->right, k, c, ans);
        }

    public:
        BST(){
            root = NULL;
        }

        void insertNode(int data){
            root = insertNode(root, data);
        }

        void deleteNode(int data){
            root = deleteNode(root, data);
        }

        void inOrder(){
            cout << "In-order traversal: ";
            inOrder(root);
            cout << endl;
        }

        void preOrder(){
            cout << "Pre-order traversal: ";
            preOrder(root);
            cout << endl;
        }

        void postOrder(){
            cout << "Post-order traversal: ";
            postOrder(root);
            cout << endl;
        }

        void levelOrder(){
            levelOrder(root);
            cout << "\n";
        }

        int minElement(){
            return minElement(root);
        }

        int maxElement(){
            return maxElement(root);
        }

        int height(){
            return height(root);
        }

        bool isBST(){
            node* prev = NULL;
            return isBST(root, prev);
        }

        int inorderSucc(int key){ // Inorder Successor
            node* ans = NULL;
            inorderSucc(root, key, ans);

            if(!ans) return -1;
            return ans->data;
        }

        int inorderPre(int key){ // Inorder Predecessor
            node* ans = NULL;
            inorderPre(root, key, ans);

            if(!ans) return -1;
            return ans->data;
        }

        int lca(int u, int v){
            if(u > v) swap(u, v);
            return lca(root, u, v);
        }

        void populateInorderSucc(){
            vector<int> ans;
            int next = -1;
            inOrder(root);
            cout << endl;
            populateInorderSucc(root, ans, next);
            reverse(ans.begin(), ans.end());
            for(auto x: ans) cout << x << " ";
            cout << endl;
        }

        int kthLargest(int k){
            int ans = 0, c = 0;
            kthLargest(root, k, c, ans);
            return ans;
        }
        
        int kthSmallest(int k){
            int ans = 0, c = 0;
            kthSmallest(root, k, c, ans);
            return ans;
        }
};

int main(){
    BST tree;

    tree.insertNode(50);
    tree.insertNode(30);
    tree.insertNode(70);
    tree.insertNode(40);
    tree.insertNode(45);
    tree.insertNode(60);
    tree.insertNode(20);
    tree.insertNode(80);
    tree.insertNode(75);
    tree.insertNode(65);
    tree.insertNode(72);
  //  cout << "checkpoint 1\n";
    tree.inOrder();
    tree.preOrder();
    tree.postOrder();
    tree.levelOrder();
   // tree.deleteNode(70);
    tree.levelOrder();
    tree.inOrder();
   // cout << "checkpoint 2\n";


    cout << tree.maxElement() << " " << tree.minElement() << "\n";
    cout << "height: " << tree.height() << "\n";
   // cout << "checkpoint 3\n";

    if(tree.isBST()) cout << "YES\n";
    else cout << "NO\n";

    cout << tree.inorderSucc(70) << " " << tree.inorderPre(90) << "\n";
 //   cout << "checkpoint 4\n";
    cout << "lca: " << tree.lca(40, 72) << "\n";
    tree.populateInorderSucc();
    cout << "kth smallest -- kth largest :" << tree.kthSmallest(3) << " -- " << tree.kthLargest(3);
}