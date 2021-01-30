/*
Minimum time taken by each job to be completed given by a Directed Acyclic Graph

Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

Examples:

Input: N = 10, E = 13, Below is the given graph:

// graph is pre made in the program itself

Output: 1 1 2 2 2 3 4 5 2 6  
Explanation:
Start the jobs 1 and 2 at the beginning and complete them at 1 unit of time. 
Since, jobs 3, 4, 5, and 9 have the only dependency on one job (i.e 1st job for jobs 3, 4, and 5 and 2nd job for job 9). So, we can start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
Similarly, 
Job 6 can only be done after 3rd and 4th jobs are done. So, start it at 2nd unit of time and complete it at 3rd unit of time.
Job 7 can only be done after job 6 is done. So, you can start it at 3rd unit of time and complete it at 4th unit of time.
Job 8 can only be done after 4th, 5th, and 7th jobs are done. So, start it at 4th unit of time and complete it at 5th unit of time.
Job 10 can only be done after the 8th job is done. So, start it at 5th unit of time and complete it at 6th unit of time.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << "=" << x << endl
const int mod = 1e9+7;
const int N = 2e5;

vector<int> g[N];

void igraph(int u, int v, vector<int>& inDeg){
        g[u].push_back(v);
        inDeg[v]++;
}

void topologicalSort(int n){

    vector<int> inDeg(n+1, 0); // number of incoming edges in each node
    igraph(2, 3, inDeg);
    igraph(2, 8, inDeg);
    igraph(2, 9, inDeg);
    igraph(1, 3, inDeg);
    igraph(1, 4, inDeg);
    igraph(1, 5, inDeg);
    igraph(3, 6, inDeg);
    igraph(4, 6, inDeg);
    igraph(4, 8, inDeg);
    igraph(5, 8, inDeg);    
    igraph(6, 7, inDeg);    
    igraph(7, 8, inDeg);    
    igraph(8, 10, inDeg);    

    queue<int> q;
    vector<int> dist(n+1, 0);
    for(int i=1; i<=n; i++){
        if(inDeg[i] == 0){
            q.push(i);
            dist[i] = 1;
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto x: g[node]){
            inDeg[x]--;
            if(inDeg[x] == 0){ // if the node has no dependancy (inDegree will become 0)
                q.push(x);
                dist[x] = dist[node] + 1;
            }
        }
    }

    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    cout << "\n";
}

void solve(){
    int n = 10;
    topologicalSort(n);
}

int main(){

    int t = 1;
   // cin >> t;
    while(t--)
        solve();
}