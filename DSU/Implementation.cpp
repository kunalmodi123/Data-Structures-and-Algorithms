#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Get(vector<int> &parent, ll a){ //implemented using PATH COMPRESSION
    return parent[a] = (parent[a] == a ? a : Get(parent, parent[a]));
}

void Union(vector<int>& parent, vector<int>& rank, ll a, ll b){// implemeted using UNION BY RANK/SIZE
    a = Get(parent, a);
    b = Get(parent, b);
    if(rank[a] == rank[b])
        rank[a]++;
    if(rank[a] > rank[b])
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    int n=10;
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    for(int i=1; i<=n; i++)
        parent[i] = i;


    // start using get or union
    //......  
    //......
}

//OFFLINE QUERIES - say we are to answer Q queries
// if we are asked "remove edge" operation but we know DSU only supports union,
// so we can think of a bottom up approach. remove edge will become union if we
// perform the following operations in reverse order of queries