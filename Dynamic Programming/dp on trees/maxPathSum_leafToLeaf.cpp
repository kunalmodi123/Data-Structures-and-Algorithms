#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"
#define INPUT freopen("input.txt", "r", stdin)
#define MOD 1000000007

struct node
{
    int data;
    node *right;
    node *left;
};

struct node *newNode(int data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

int maxPathSum_leafToLeaf(node *root, int &res)
{
    if (root == NULL)
        return 0;
    int l = maxPathSum_leafToLeaf(root->left, res);
    int r = maxPathSum_leafToLeaf(root->right, res);

    int temp = max(l, r) + root->data;
    if (root->left == NULL && root->right == NULL)
        temp = max(temp, root->data);

    int ans = max(r + l + root->data, temp);
    res = max(res, ans);

    return temp;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(30);
    root->right = newNode(6);
    root->left->left = newNode(14);
    root->left->right = newNode(15);
    int res = INT_MIN;
    int height = maxPathSum_leafToLeaf(root, res);
    cout << res;
}