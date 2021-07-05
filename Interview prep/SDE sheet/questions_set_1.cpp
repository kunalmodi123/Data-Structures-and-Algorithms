#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------//

// 1. Sort an Array with 0s, 1s and 2s

// https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2
// https://leetcode.com/problems/sort-colors/

// Dutch National Flag Algorithm
// Most optimal solution to sort an array of only 0s, 1s, 2s 
void sortColors(vector<int>& nums) {
    int n = nums.size();
    //We take toal of 3 pointers i.e, left, right and mid
    // Here we try to put all zeroes before left pointer
    // All 2s after right
    // and all 1s between left and right pointer
    int l=0, r = n-1;
    int mid = 0;

    while(mid <= r){
        if(nums[mid] == 0){
            swap(nums[mid++], nums[l++]);
        }
        else if(nums[mid] == 1)
            mid++;
        else{
            swap(nums[mid], nums[r--]);
        }
    }

} // T.C - O(N)
  // S.C - O(1)

//--------------------------------------------------------------------------------------------------------------------------//

// 2. Find Repeated and Missing number

// https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

void repeatedAndMissing(vector<int> nums){
    int x = 0;
    int n = nums.size();
    for(int i=0; i<n; i++)
        x ^= nums[i];
    
    for(int i=1; i<=n; i++)
        x ^= i;       // x contains X^Y i.e. XOR of missing and repeating number

    // now we seperate these numbers into two buckets according to the right most set bit(we can take any set bit) in x
    int buck1 = 0, buck2 = 0;
    // getting the rightmost set bit
    int set_bit = x&(~(x - 1)); // important

    // seperated into two buckets and took xor
    for(int i=0; i<n; i++){
        if(nums[i] & set_bit)
            buck1 ^= nums[i];
        else buck2 ^= nums[i];
    }

    // 1 .... N are seperated into two buckets and took xor
    for(int i=1; i<=n; i++){
        if(i & set_bit)
            buck1 ^= i;
        else buck2 ^= i;
    }

    // finally, buck1 and buck2 contains missing and repeated numbers
    // to find which is missing and repeated, we traverse through nums array and check

    int flag = 0;
    for(int i=0; i<n; i++){
        if(buck1 == nums[i])
            flag = 1;
    }

    if(flag){
        cout << "Repeated No.: " << buck1 << "\n";
        cout << "Missing No.: " << buck2 << "\n";
    }
    else{
        cout << "Repeated No.: " << buck2 << "\n";
        cout << "Missing No.: " << buck1 << "\n";
    }
} //TC: O(5n) ~ O(n)

//-------------------------------------------------------------------------------------------------------------------//

// 3. Merge two sorted arrays in O(1) space

// https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4
// https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

// First method is to,
/*
1. Traverse through the first array and compare its elements with the first element of second array
2. If the 1st element is smaller in 2nd array, swap it with first array's current element and move the pointer ahead
3. Then sort the 2nd array, as the remaining array except 1st element is already sorted in 2nd array, we can just put
    the 1st element to its right place by swapping it with its neighbours(insertion sort style)
4. If 1st element is not smaller in 2nd array, move the pointer ahead in 1st array

finally we will get the required answer
TC: O(n1*n2) SC: O(1)
*/ 


//Efficient Solution - GAP method

int nextGap(int gap){
    if(gap <= 1) return 0;;
    return (gap/2 + gap%2);
}

void mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    int gap = nextGap(n + m);
    int i, j;

    while(gap > 0){
        // comparing elements in 1st array
        for(i = gap; i + gap < n; i++){
            if(arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        // comparing elements in both arrays
        for(j = (gap>n)?(gap-n):0; i < n && j < m; i++, j++){ // *** important trick to swap in two different arrays
            if(arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        // comparing elements in 2nd array
        if(j < m){
            for(j=0; j + gap < m; j++){
                if(arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }

        gap = nextGap(gap);
    }
}
//TC - O(n+m(log(m+n))), SC - O(1)

//----------------------------------------------------------------------------------------------------------------------//

// 4. Kadane's Algorithm (To find maximum subarray sum (array contains negative numbers also))

// https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=5 
// https://leetcode.com/problems/maximum-subarray/

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxi = nums[0];
        
    for(auto x: nums){
        sum += x;
        maxi = max(maxi, sum);
        if(sum < 0) sum=0; // this resets the sum and ensures we dont take any negative subarray sum in our answer
    }
        
    return maxi;
}
//TC: O(n)

//-------------------------------------------------------------------------------------------------------------------//

// 5. Merge Overlapping Intervals

//https://www.youtube.com/watch?v=2JzRBPFYbKE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7
//https://leetcode.com/problems/merge-intervals/

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int r = intervals.size();
        int c = intervals[0].size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end()); // sort the intervals wrt starting point
        vector<int> temp = intervals[0];
        
        for(auto x: intervals){
            if(x[0] <= temp[1]){ // checking if the next intervals staring point lies inside the temp(merged interval so on)
                temp[1] = max(x[1], temp[1]); 
               // temp[0] = min(x[0], temp[0]); // we dont need this
            }
            else{
                ans.push_back(temp);
                temp = x;
            }
        }
        ans.push_back(temp);
        
        return ans;
        
    }   //TC: O(nlogn) + O(n) ~ O(nlogn)

//----------------------------------------------------------------------------------------------------------------------//

// 6. Find duplicate in an array of N+1 integers

// https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2
// https://leetcode.com/problems/find-the-duplicate-number/solution/

// we do it using Floyd's tortoise and hare method similar to finding cycle in linked list
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);
        
        fast = nums[0];
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
    //TC: O(n)  SC: O(1) , most efficient solution
//------------------------------------------------------------------------------------------------------------------------//

// 7. Set Matrix Zeroes

// https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7
// https://leetcode.com/problems/set-matrix-zeroes/

// Solution using extra space. 
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dx(n, 1), dy(m, 1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    dx[i] = 0;
                    dy[j] = 0;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dx[i] == 0 or dy[j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
    // TC: O(n*m), SC: O(n+m) - auxiliary space

// Efficient solution - In Place

// here we use the first row and column as hash map
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // this col variable is used to ensure that the column hashmap remains intact and also if it colum 1 elements
        // need to changed to zero then it can be done without effecting the other places in the matrix
        int col = 1;
        
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0) col = 0;
            for(int j=1; j<m; j++){
                // if element is 0, we unset the leftmost and topmost column and row respectively
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        // traversing backwards to ensure column hashmap does not change before changing the other matrix elements
        // with its help
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=1; j--){
                if(matrix[i][0] == 0 or matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            // here is where col variable comes to rescue
            if(col == 0) matrix[i][0] = 0;
        }
    } // TC - O(N), SC - O(1)

//-------------------------------------------------------------------------------------------------------------------------------//

// 8. Pascal Triangle

// https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9
// https://leetcode.com/problems/pascals-triangle/

// The problem can have 3 variations:

// 1> Finding the while pascal triangle

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1);
            for(int j=0; j<=i; j++){
                if(j == 0 or j == i) ans[i][j] = 1;
                else
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        
        return ans;
    }
    // TC - O(N^2), SC - O(N^2)  

// 2> Returning a value of specific row r and column c
// Solution:  (r-1)C(c-1)
//TC - O(N)  SC- O(1)

// 3> Returing a specific row of the pascal triangle
// Solution:

// Use the short combination trick,
// say we need to find for row 5, so we will have
//   1    4       6           4               1
// 4C0   4C1     4C2         4C3             4C4              which can be written as (here 4 in general is (row - 1))
// 1     4/1   4*3/1*2   4*3*2/1*2*3   4*3*2*1/1*2*3*4

//this can be done easily using a for loop
//TC - O(N)  SC- O(N)

//---------------------------------------------------------------------------------------------------------------------//

// 9. Next Permutation

// https://www.youtube.com/watch?v=LuLCLgMElus&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9 
// https://leetcode.com/problems/next-permutation/

// here we follow 4 steps
// 1> traverse from back and find the index of first element where a[i] < a[i+1], say it as ind1
// 2> traverse from back again and find the index of first element greater than a[ind1], say it as ind2
// 3> swap(a[ind1], a[ind2])
// 4> reverse(ind1+1, last)

    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        for(k = n-2; k >= 0; k--){
            if(nums[k] < nums[k+1])
                break;
        }
        
        // if there is no break point,
        // i.e. if we get no index where a[i] < a[i+1], implies it is the last permutation possible
        // so return the first possible permutation which can be obtained by reversing the original string
        if(k < 0) reverse(nums.begin(), nums.end());
        else{
            for(l = n-1; l > k; l--){
                if(nums[l] > nums[k])
                    break;
            }
            
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
    //TC: O(N), SC: O(1)
    // watch the above video for intuition

//---------------------------------------------------------------------------------------------------------------------//

// 10. Inversion of Array (merge sort related problem)

// https://www.youtube.com/watch?v=kQ1mJlwW-c0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=11
// https://www.geeksforgeeks.org/counting-inversions/

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

            // as the left array is sorted, so every element is guaranteed to to larger than the current element in right half
            // so we add the number of elements from left index to mid in the left half to the answer(cnt variable)
            cnt += mid - left + 1; // **only difference in the merge sort code
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


//---------------------------------------------------------------------------------------------------------------------//
// 11. Stock, Buy and Sell

// https://www.youtube.com/watch?v=eMSfBgbiEjk&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int temp = prices[0];
        for(int i=1; i<n; i++){
            if(temp > prices[i]) // keeping track of the leftmost minimal
                temp = prices[i];
            else{
                maxi = max(prices[i] - temp, maxi); // soring the maximum difference from the minimal we can get
            }
        }
        
        return maxi;
    }
 // TC - O(N)

//----------------------------------------------------------------------------------------------------------------------//

// 12. Rotate Matrix

// https://www.youtube.com/watch?v=Y72QeX0Efxw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12
// https://leetcode.com/problems/rotate-image/

// Steps:
// 1> We take transpose of the matrix
// 2> We reverse every row of the matrix

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){ // **Remember the way to take transpose of a matrix
            for(int j=0; j<i; j++) // we are basically only traversing in the left lower triangle of the matrix
                swap(matrix[i][j], matrix[j][i]);
        }
        
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    // TC: O(n*m)

//------------------------------------------------------------------------------------------------------------------------//

// 13. Search in 2D array

// https://www.youtube.com/watch?v=ZYpYur0znng&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=14

// This problem has two variations:

// 1> Row wise sorted + 1st integer of each row is greater than last integer of previous row(so automatically column wise sorted)
// https://leetcode.com/problems/search-a-2d-matrix/

// solution: 
// here we take continuos index serially from (0, 0) to (n-1, m-1);
// the max value of index will be (m*n-1);
// for retrieving the original index,
// i = index/(col size), j = index%(col size);
// we can directly apply binary search then, this was possible as in the transformed index system,
// because it can be assumed as a (m*n) size sorted array

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0;
        int h = (m*n)-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(matrix[mid/m][mid%m] == target)
                return true;
            else if(matrix[mid/m][mid%m] > target)
                h = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
    // TC - O(log(m+n))

// 2> row wise + column wise sorted
// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

// we star from top-right corner of matrix;
// if the value is greater than target, we move to left (as we have smaller elements in left than the current element);
// if the value is smaller than target, we move down (as we have larger elements in down than the current element);
// if found the target, return true;
// if the element goes out of bounds, return false;

    bool searchMatrixGFG(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        int i=0, j = m-1;

        while(i < n && j >= 0){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
                j--;
            else i++;
        }

        return false;
    }
    // TC: O(n+m)

//--------------------------------------------------------------------------------------------------------------------------//

// 14. Pow(x, n)

// https://www.youtube.com/watch?v=l0YC3876qxg&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=15
// https://leetcode.com/problems/powx-n/

    double myPow(double x, int n) {
        double ans = 1.0;

        // storing n to to different variable as after computation, its value is not lost and can be used later
        long nn = n;

        // if vakue of n is -ve, change it to positive
        if(nn < 0) nn = -1*nn;

        //binary exponentiation
        while(nn != 0){
            if(nn&1){
                ans = ans*x;
                nn = nn-1;
            }else{
                x = x*x;
                nn = nn/2;
            }
        }

        // if n was negative in first place, we return the inverse
        if(n < 0) ans = double(1.0)/(double(ans));

        /// else the calculated answer
        return ans;
    }// TC - O(logN)

//-------------------------------------------------------------------------------------------------------------------------//

// 15. Majority element (>N/2 times)

// MOORE'S VOTING ALGORITHM
// https://www.youtube.com/watch?v=AoX3BPWNnoE&t=593s
// https://leetcode.com/problems/majority-element/

// here whenever the count gets to zero, assume we give a breakpoint there
// it implies the cadidate majority element we selected is cancelled by minorities
// by doing this, it is guaranteed that the majority will lie in the laft suffix window
// as it have to be greater than floor(n/2) so it will not be cancelled by minorities
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = 0;
        
        for(auto it: nums){
            if(cnt == 0) candidate = it;
            
            if(candidate == it) cnt++;
            else cnt--;
        }
        
        return candidate;
    }
    // TC: O(N), SC: O(1)
    // for intuition do watch the video above(important)

    //in this problem, it was guaranteed than there was a majority element, but if it is not
    // then we traverse the array and count the aoccurences of the candidate we got
    // if the count > n/2, then it is the answer, otherwise there is no answer

//-------------------------------------------------------------------------------------------------------------------------//

// 16. Majority element (>N/3 times)

// https://www.youtube.com/watch?v=yDbkQd9t2ig&t=198s
// https://leetcode.com/problems/majority-element-ii/

// BOYER MOORE's VOTING ALGO

// extension of previous majority element problem
    vector<int> majorityElement2(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
        for(auto it: nums){
            if(num1 == it) cnt1++;
            else if(num2 == it) cnt2++;
            else if(cnt1 == 0){
                num1 = it;
                cnt1++;
            }
            else if(cnt2 == 0){
                num2 = it;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=0, cnt2=0;
        for(auto it: nums){
            if(it == num1) cnt1++;
            else if(it == num2) cnt2++;
        }
        
        vector<int> ans;
            
        if(cnt1 > n/3) ans.push_back(num1);
        if(cnt2 > n/3) ans.push_back(num2);
        
        return ans;
    }
    // TC - O(N), SC - O(1)
    // watch the video above for intuition(important)
//-------------------------------------------------------------------------------------------------------------------------//

// 17. Grid Unique Paths

// https://www.youtube.com/watch?v=t_f0nwwdg5o&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18
// https://leetcode.com/problems/unique-paths/

// recursive solution memoized
// simply we count solutions for every path(we can move left or up, as we start frfom bottom right) possible reaching the destination
    int uniquePathsUtil(int m, int n, vector<vector<int>>& dp){
        if(m == 0 and n == 0)
            return 1;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int path1 = 0, path2 = 0;

        // 
        if(m > 0) path1 = uniquePathsUtil(m-1, n, dp);
        if(n > 0) path2 = uniquePathsUtil(m, n-1, dp);
        
        return dp[m][n] = (path1 + path2);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return uniquePathsUtil(m-1, n-1, dp);
    }
    // TC - O(n*m), SC - O(n*m)

//---------------------------------------------------------------------------------------------------------------------------//

// 18. Reverse Pairs (leetcode)

// https://www.youtube.com/watch?v=S6rsAlj_iB4
// https://leetcode.com/problems/reverse-pairs/

// function to merge two sorted arrays
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

    // cnt will store the answer after the function call is complete
    void reversePairs(int l, int r, vector<int>& arr, int k, int &cnt){
        if(l >= r) return;

        int mid = (l + r) >> 1;
        reversePairs(l, mid, arr, k, cnt);
        reversePairs(mid+1, r, arr, k, cnt);
        int left = l;
        long long one = 1;

        // at this point, left half and right half of the array is sorted
        for(int right = mid+1; right <= r; right++){ // O(N)

            // we find the index where the arr[left] <= 2*arr[right] condition holds true
            // also we dont have to start the left again from first as the array is sorted so we will definely
            // get our answer beyond the last left we found
            while(left <= mid and arr[left] <= 2LL*arr[right]) //overall O(N)
                left++;

            // now the left out elements in the right side of the left half of array till mid is added to the answer
            cnt += (mid - left) + 1;
        } // O(N+N)

        merge(l, mid, r, arr);
    }
    //TC - O(NlogN), SC - O(N)

//---------------------------------------------------------------------------------------------------------------------------//

// 19. Two Sum

// https://www.youtube.com/watch?v=dRUpbt8vHpo&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=2
// https://leetcode.com/problems/two-sum/

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mpp.find(target - nums[i]) != mpp.end()){
                ans.push_back(mpp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
    // TC - O(N), SC - O(N)
    

//---------------------------------------------------------------------------------------------------------------------------//

// 20. 4 Sum

// https://www.youtube.com/watch?v=4ggF3tXIAp0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=21
// https://leetcode.com/problems/4sum


// first sort the array
// then, use two pointers(as in two loops), and (find the 2 sum in sorted array(also using two pointers approach))
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int target_2 = target - (nums[i] + nums[j]);
                int left = j+1;
                int right = n-1;
                
                while(left < right){
                    int sum = nums[left] + nums[right];
                    
                    if(sum < target_2) left++;
                    else if(sum > target_2) right--;
                    else{
                        vector<int> ds(4, 0);
                        
                        ds[0] = nums[i];
                        ds[1] = nums[j];
                        ds[2] = nums[left];
                        ds[3] = nums[right];
                        
                        ans.push_back(ds);
                        
                        // to avoid duplicates
                        while(left < n and nums[left] == ds[2]) left++;
                        while(right >= 0 and nums[right] == ds[3]) right--;
                    }
                }
                // to avoid duplicates
                while(j+1 < n and nums[j+1] == nums[j]) j++;
            }

            // to avoid duplicates
            while(i+1 < n and nums[i+1] == nums[i]) i++;
        }
        
        return ans;
    }
    //TC - O(n^3), SC - O(1) , generally dont count the space complexity used to return the answer

//-------------------------------------------------------------------------------------------------------------------------//

// 21. Longest consecutive sequence

// https://www.youtube.com/watch?v=qgizvmgeyUM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22
// https://leetcode.com/problems/longest-consecutive-sequence/

// here we first put all the elements into a hash set
// then, we traverse the array again and for each element x, we check if x-1 is present in the hash set or not
// if not present, then we can say it is the starting point of a consecutive sequence
// then, for that element we check if consecutive elements are present in set or not and count it
// we take the max of all these counts which is our required answer

    int longestConsecutive(vector<int>& nums) {
     //   unordered_set<int> st; // this is showing error, so use map instead for O(1)
        set<int> st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        
        int ans = 0, cnt = 0;
        for(int i=0; i<n; i++){
            if(!st.count(nums[i] - 1)){
                cnt = 1;
                int x = nums[i];

                // O(N) is taken overall for this while loop
                while(st.count(x+1)){
                    cnt++;
                    x++;
                }
                
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
    // TC - O(N) - with unordered map or unordered set

//-------------------------------------------------------------------------------------------------------------------------//

// 22. Largest subarray with 0 sum

// https://www.youtube.com/watch?v=xmguZ6GbatA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22 
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1 

int maxLen(int A[], int n)
{
    int maxi = 0, prefSum = 0;
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++){
        // we calculate the prefix sum upto the current index
        prefSum += A[i];
        if(prefSum == 0) maxi = i+1;
        
        // if the pref sum is already present, than (current index - previous index in map) is a 0 sum subarray
        if(mp.find(prefSum) != mp.end()){
            // we take maximum of all these cases
            maxi = max(maxi, i - mp[prefSum]);

            // note: we dont update the map, because if in future we get the same pref sum, then we can get the longest
            // subarray length. Updating it will give us the shorter subarray length of 0 sum
        }
        else
            mp[prefSum] = i; // not present in map, then we store the index
    }
    
    return maxi;
}
// TC - O(N), SC - O(N)

//-------------------------------------------------------------------------------------------------------------------------//

// 23. Count number of subarrays with given XOR

// https://www.youtube.com/watch?v=lO9R5CaGRPY&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=23 
// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

int subXOR(vector<int> arr, int val){
    unordered_map<int, int> freq;
    int cnt = 0;
    int xxor = 0;

    for(auto it: arr){
        xxor ^= it;

        if(xxor == val)
            cnt++;

        // (prefix xor)^val exists in the map, 
        if(freq[xxor^val])
            cnt += freq[xxor^val];
        
        freq[xxor]++;
    }

    return cnt;
}
// TC - O(N), SC - O(N)

//-------------------------------------------------------------------------------------------------------------------------//

// 24. Longest substring without repeat

// https://www.youtube.com/watch?v=qtVh-XEpsJo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=25 
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/* Better approach: 
    we take 2 pointers l and r and initialize them with 0;
    we traverse through the string (we move 'r') and,
    we take a hash set, and keep on putting the characters of string in the hash set
    also, in the mean time we keep on calculating the length of substring by r-l+1,
    if we find the character in the hash set, we remove the s[l] from the hash set and then check
    if s[r] still present in the set or not. If present, we keep on removing s[l] from the set until s[r] is
    not present in the hash set. Then we do the whole step all over again until r reaches the last
    TC - O(2N), SC - O(N)
*/

/*
    Efficient approach:
    the logic is similar to the better approach but we optimise the the movement of l significantly.
    instead of set we take a hash map and we store the index of the character as well.
    when we find the character in the has set while traversing, we simply move l to the (value of map) + 1,
    only if value of l is smaller than (value of map) + 1; other steps are almost similar to the better approach

*/
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        vector<int> index(256, -1);
        int n = s.size();
        int len = 0;
        
        while(r < n){
            if(index[s[r]] != -1){
                l = max(index[s[r]] + 1, l);
            }
            
            len = max(len, r-l+1);
            
            index[s[r]] = r;
            r++;
        }
        
        return len;
    }


//-------------------------------------------------------------------------------------------------------------------------//

// 25. 3 Sum

// https://www.youtube.com/watch?v=onLoX6Nhvmg&t=394s
// https://leetcode.com/problems/3sum/

// Similar steps used in 4 Sum, can be said a subproblem of 4 Sum
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            int l = i+1, r = n-1;
            int target = 0 - nums[i];
            while(l < r){
                if(nums[l] + nums[r] < target) l++;
                else if(nums[l] + nums[r] > target) r--;
                else{
                    vector<int> ds(3, -1);
                    ds[0] = nums[i];
                    ds[1] = nums[l];
                    ds[2] = nums[r];
                    
                    ans.push_back(ds);
                    
                    while(l < n and nums[l] == ds[1]) l++;
                    while(r >= 0 and nums[r] == ds[2]) r--;
                }
            }
            
            while(i+1 < n and nums[i+1] == nums[i]) i++;
        }
        
        return ans;
    }
    // TC - O(N^2), SC - O(1)

//-----------------------------------------------------------------------------------------------------------------------//

// 26. Trapping Rainwater

// https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=42
// https://leetcode.com/problems/trapping-rain-water/

// Better Approach:
/*
    - Use prefix max array to store left maximum of every element
    - Use suffix max array to store right maximum of every element
    - travese the element and for every element add  (min(prefMax[i], SuffMax[i]) - arr[i]) to the answer

    TC - O(3N), SC - O(2N)
    // note: we can also use stack to solve the problem(using nge and nse concepts of stack)
    // TC and SC is very similar to the above approach
*/

// Most Optimal Approach: Two pointers

    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int l = 0, r = n-1;
        
        int ans = 0;
        
        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] >= leftMax) leftMax = height[l];
                else ans += leftMax - height[l]; 
                
                l++;
            }
            else{
                if(height[r] >= rightMax) rightMax = height[r];
                else ans += rightMax - height[r];
                
                r--;
            }
        }
        
        return ans;
    }
    // TC - O(N), SC - O(1)
    // ***important: for intuition, better to watch the video

//-------------------------------------------------------------------------------------------------------------------------//

// 27. Remove duplicates from Sorted array

// https://www.youtube.com/watch?v=Fm_p9lJ4Z_8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=43
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

    int removeDuplicates(vector<int>& nums) {
        int l=0, r=0;
        int n = nums.size();
        int k = 0;
        
        // we take two pointers here l and r initialized to first index
        // l pointer is moved slowly and it helps in putting unique elements one by one in correct position
        // r pointer finds the non repeated element
        while(r < n){
            nums[l] = nums[r]; // putting the uniwue element in the right place
            
            // getting passed the duplicates
            while(r < n and nums[l] == nums[r]) // r < n is necessary because it is possible that r reaches the value in edge case
                r++;
            
            k++; // count of unique elements
            l++; // position of unique element increased ahead
        }
        
        return k;
    }
    // TC - O(N), SC - O(1)

//------------------------------------------------------------------------------------------------------------------------//

// 28. Maximum Consecutive Ones

// https://www.youtube.com/watch?v=Mo33MjjMlyA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=43
// https://leetcode.com/problems/max-consecutive-ones/s

// simple iteration and resetting the count when element is 0; 
// also taking max everytime when count increments(when element is 1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int cnt=0, res = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0)
                cnt = 0;
            else{
                cnt++;
                res = max(res, cnt);
            }
        }
        
        return res;
    }
    // TC - O(N), SC - O(1)

//--------------------------------------------------------------------------------------------------------------------------//

// 29. N meeting in one room 
// https://www.youtube.com/watch?v=II6ziNnub1Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=44 
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

    static bool comp(pair<int, int> p1, pair<int, int> p2){
        if(p1.second < p2.second)
            return true;
        else if(p1.second == p2.second){
            if(p1.first < p2.first)
                return true;
        }
        return false;
            
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> times;
        for(int i=0; i<n; i++){
            times.push_back({start[i], end[i]});
        }
        
        sort(times.begin(), times.end(), comp);
        int cnt=1;
        int x = times[0].second;
        int y = times[1].first;
        
        for(int i=1; i<n; i++){
            if(x < y){
                cnt++;
                x = times[i].second;
                if(i+1 < n) y = times[i+1].first;
            }
            else
                if(i+1 < n) y = times[i+1].first;
            
        }
        
        return cnt;
    }
    // TC - O(NlogN), SC - O(N)

//-------------------------------------------------------------------------------------------------------------------------//

// 30. Minimum number of platforms required for a railway
// https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=45 
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int i = 1, j = 0;
        int plat = 1;
        int ans = 1;

        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                plat++;
                i++;
            }
            else{
                plat--;
                j++;
            }

            if(plat > ans)
                ans = plat;
        }

        return ans;
    }
    // TC - O(NlogN), SC - O(1)

//-------------------------------------------------------------------------------------------------------------------------//

// 31. Job sequencing Problem 
// https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=46 
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

    struct Job 
    { 
        int id;	 // Job Id 
        int dead; // Deadline of job 
        int profit; // Profit if job is over before or on deadline 
    };

    static bool comp1(Job j1, Job j2){
        if(j1.profit > j2.profit)
            return true;
        return false;
    }

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, comp1);
        int maxi = arr[0].dead;
        for(int i=0; i<n; i++)
            maxi = max(maxi, arr[i].dead);
        vector<int> slot(maxi + 1, 0);
        
        int profit = 0, cnt = 0;
        for(int i=0; i<n; i++){
            for(int j = arr[i].dead; j > 0; j--){
                if(slot[j] == 0){ // we are using slot as a hash map to chek if that dealine is already covered or not
                    slot[j] = 1;
                    profit += arr[i].profit;
                    cnt++;
                    
                    break;
                }
            }
        }
        
        return {cnt, profit};
    }
    // TC - O(NlogN), SC - O(1)
    // here we consider the dealine slot to do the mpst profitable work cause it will open the slots before it
    // to perform other tasks. Doing it before can have us ignore few tasks whose dealine < curr_deadline which
    // will result to wrong answer

//-------------------------------------------------------------------------------------------------------------------------//

// 32. Fractional Knapsack Problem
// https://www.youtube.com/watch?v=F_DDzYnxO14&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=48 
// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

    struct Item{
        int value;
        int weight;
    };

    // we sort the array wrt value/weight ratio
    static bool comp2(Item i1, Item i2){
        return (((double)i1.value/i1.weight) > ((double)i2.value/i2.weight));
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp2);
        int i=0;
        double sum = 0;
        while(i < n and arr[i].weight <= W){
            sum += arr[i].value;
            W -= arr[i].weight;
            i++;
        }
        
        // if weight == 0 or weight > 0, then i will be < n
        // though we ignore the condition W > 0 in the if as if W = 0, sum += ..... will anyway be 0
        if(i < n and W > 0) sum += arr[i].value * ((double) W / arr[i].weight);
        
        return sum;
    }
    // TC - O(NlogN), SC - O(1)

//-------------------------------------------------------------------------------------------------------------------------//

// 33. Greedy algorithm to find minimum number of coins
// https://www.youtube.com/watch?v=mVg9CfJvayM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47 
// https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/

    // all denominations of indian currency
    int deno[] = { 1, 2, 5, 10, 20,
               50, 100, 500, 1000 };

    vector<int> minCoins(int Value){
        int n = sizeof(deno) / sizeof(deno[0]);

        sort(deno, deno + n);

        vector<int> ans;

        for(int i=n-1; i >= 0; i--){
            while(deno[i] <= Value){
                Value -= deno[i];
                ans.push_back(deno[i]);
            }
        }

        return ans;
    }
    // so, TC - O(NlogN), considering deno array can be unsorted
    //Note: Here greedy worked because the indian denominations are such that we form any value by this process

//-------------------------------------------------------------------------------------------------------------------------//

// 34. Activity Selection (it is same as N meeting in one room) 
// https://www.youtube.com/watch?v=II6ziNnub1Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=44 
// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

/* This problem is exactly the same problem as N meetings in the room. The logic is exactly same */

//-------------------------------------------------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------------------//
int main(){

}