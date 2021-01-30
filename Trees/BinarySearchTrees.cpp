#include<bits/stdc++.h>
using namespace std;

class BST{
        struct node{
            int data;
            node* left;
            node* right;

            node(){
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

    tree.inOrder();
    tree.preOrder();
    tree.postOrder();
    tree.levelOrder();
    tree.deleteNode(70);
    tree.levelOrder();
    tree.inOrder();

    cout << tree.maxElement() << " " << tree.minElement() << "\n";
    cout << "height: " << tree.height() << "\n";

    
}