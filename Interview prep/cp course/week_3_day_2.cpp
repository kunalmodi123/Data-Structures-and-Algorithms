//DIVIDE AND CONQUER ALGORITHMS (Merge Sort and related problems, Meet in the Middle Algorithm
// with problems, Matrix Exponentiation, Kadane's Algorithm)

#include<bits/stdc++.h>
using namespace std;

//Priority queue problem - Seating Arrangements
// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/seating-arrangement-6b8562ad/
void seatingArrangements(){
    int n, k;
	cin >> n >> k;
    string pref;
    cin >> pref;
    map<int, int> mp;
    priority_queue<pair<int, int>> pq;
    pq.push({n, -1});
    for(int i=1; i<=k; i++){
        int len = pq.top().first;
        int sind = -1 * pq.top().second;
        int eind = sind + len -1;
        pq.pop();

        int mid = (sind+eind)/2;
        if(len%2 == 0 and pref[i-1] == 'R') mid += 1;
        mp[mid] = i;
        if(mid != sind)
            pq.push({mid - sind, -1*sind});
        if(mid != eind)
            pq.push({eind - mid, -1*(mid+1)});
    }

    int q;
	cin >> q;
    while(q--){
        int x;
        cin >> x;
		if(!mp[x]) cout << -1 << "\n";
		else
        	cout << mp[x] << "\n";
    }
}


//--------------------------------------------------------------------------------------------------------------//

//merge two sorted arrays
void merge(int l, int mid, int h, vector<int>& arr){
    int left = l;
    int right = mid+1;
    vector<int> temp;
    while(left <= mid and right <= h){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= h){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=l; i<=h; i++){
        arr[i] = temp[i-l];
    }
}

void mergeSort(int l, int h, vector<int>& arr){
    if(l >= h) return;

    int mid = (l + h) >> 1;

    //divide into two halves
    mergeSort(l, mid, arr);
    mergeSort(mid+1, h, arr);

    // then merge the two sorted halves
    merge(l, mid, h, arr);
} //TC - O(nlogn)

//----------------------------------------------------------------------------------------------------------------//

// D&C problem - Inversions Count (leetcode)
// https://leetcode.com/problems/global-and-local-inversions/discuss/242101/Count-inversions
void countInversionsUtil(int l, int mid, int h, vector<int>& arr, int &cnt){
    int left = l;
    int right = mid+1;
    vector<int> temp;
    while(left <= mid and right <= h){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= h){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=l; i<=h; i++){
        arr[i] = temp[i-l];
    }
}

void countInversions(int l, int h, vector<int>& arr, int& cnt){
    if(l >= h) return;

    int mid = (l + h) >> 1;

    countInversions(l, mid, arr, cnt); // O(logn)
    countInversions(mid+1, h, arr, cnt); // O(logn)
    countInversionsUtil(l, mid, h, arr, cnt); // O(n)
}//TC - O(nlogn)

//-------------------------------------------------------------------------------------------------//
// int cnt = 0;
// https://leetcode.com/problems/reverse-pairs/
void reversePairs(int l, int r, vector<int>& arr, int k, int &cnt){
    if(l >= r) return;

    int mid = (l + r) >> 1;
    reversePairs(l, mid, arr, k, cnt);
    reversePairs(mid+1, r, arr, k, cnt);
    int left = l;
    for(int right = mid+1; right <= r; right++){
        // it can show signed int overflow so, write { 1.0*arr[left]/k <= a[right]  }
        while(left <= mid and arr[left] <= arr[right]*k) 
            left++;
        
        cnt += (mid - left) + 1;
    }
    merge(l, mid, r, arr);
}

//----------------------------------------------------------------------------------------------------------------------------------------//

//MEET IN THE MIDDLE ALGO
//Find count of subsets with sum = x, N = 40
// Here, power Set and solely recursive implementation will not work as N = 40 (2^40 will exceed time constraints)

void solve1(int ind, int sum, vector<int>& arr, vector<int>& v){
    if(ind == arr.size()){
        v.push_back(sum);
        return;
    }

    solve1(ind+1, sum + arr[ind], arr, v);
    solve1(ind+1, sum, arr, v);
}

void solve2(int ind, int sum, vector<int>& arr, map<int, int>& mp){
    if(ind == arr.size()){
        mp[sum]++;
        return;
    }

    solve2(ind+1, sum + arr[ind], arr, mp);
    solve2(ind+1, sum, arr, mp);
}

void solveMIM(int n, int S, vector<int>& arr){
    vector<int> leftArr, rightArr;
    int mid = n/2;

    for(int i=0; i<mid; i++)
        leftArr.push_back(arr[i]);
    for(int i=mid; i<n; i++)
        rightArr.push_back(arr[i]);

    vector<int> subsetSum;
    map<int, int> mpp;

    int cnt = 0;
    solve1(0, 0, leftArr, subsetSum);
    solve2(0, 0, rightArr, mpp);

    for(auto x: subsetSum)
        cnt += mpp[S - x];
    
    cout << cnt << "\n";
}

// count number of subsets with sum <= x, N = 40
// also usees binary search
void solveMIM_2(int n, int S, vector<int>& arr){
    vector<int> leftArr, rightArr;
    int mid = n/2;

    for(int i=0; i<mid; i++)
        leftArr.push_back(arr[i]);
    for(int i=mid; i<n; i++)
        rightArr.push_back(arr[i]);

    vector<int> subsetSum1;
    vector<int> subsetSum2;

    int cnt = 0;
    solve1(0, 0, leftArr, subsetSum1);
    solve1(0, 0, rightArr, subsetSum2);
    sort(subsetSum2.begin(), subsetSum2.end());

    for(auto x: subsetSum1)
        cnt += upper_bound(subsetSum2.begin(), subsetSum2.end(), S-x) - subsetSum2.begin();
    
    cout << cnt << "\n";
}

// count subsets whose sum%k == 0, N = 40
void solve1_3(int ind, int sum, int k, vector<int>& arr, map<int, int>& mp){
    if(ind == arr.size()){
        mp[sum%k]++;
        return;
    }

    solve1_3(ind + 1, sum + arr[ind], k, arr, mp);
    solve1_3(ind + 1, sum, k, arr, mp);
}
//doubt in this code
void solveMIM_3(int n, int k, vector<int>& arr){
    vector<int> leftArr, rightArr;
    int mid = n/2;

    for(int i=0; i<mid; i++)
        leftArr.push_back(arr[i]);
    for(int i=mid; i<n; i++)
        rightArr.push_back(arr[i]);

    map<int, int> mp1;
    map<int, int> mp2;

    int cnt = 0;
    solve1_3(0, 0, k, leftArr, mp1);
    solve1_3(0, 0, k, rightArr, mp2);

    for(auto x: mp1){
        int a = x.first;
        int b = x.second;
        cnt += b*mp2[k - a];
    }    
    cout << cnt << "\n";
}

//-------------------------------------------------------------------------------------------------------------------------------// 


int main(){
    vector<int> arr = {1, 2, 3, 3, 6, 1};
    int l = 0;
    int h = arr.size() - 1;

    // mergeSort(l, h, arr);
    // for(auto x: arr){
    //     cout << x << " ";
    // }
    // cout << "\n";

    // int cnt=0;

    // countInversions(l, h, arr, cnt);
    // cout << "inversions count: " << cnt << "\n";
    // int cnt1 = 0;
    // reversePairs(l, h, arr, 2, cnt1);
    // cout << "reverse pair counts: " << cnt1 << "\n";
    solveMIM(h+1, 10, arr);   
    cout << "\n";
    solveMIM_2(h+1, 10, arr); 
    solveMIM_3(h+1, 3, arr);
}