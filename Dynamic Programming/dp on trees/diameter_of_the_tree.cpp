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

int diameterOftree(node *root, int &res)
{
    if (root == NULL)
        return 0;
    int l = diameterOftree(root->left, res);
    int r = diameterOftree(root->right, res);

    int temp = 1 + max(l, r);
    int ans = 1 + l + r;
    res = max(res, ans);

    return temp;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int res = INT_MIN;
    int height = diameterOftree(root, res);
    cout << "diameter" << res;
}