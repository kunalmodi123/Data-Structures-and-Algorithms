#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//------------------------------------------------------------------------------------------------------------------------------//

// 1. Reverse a Linked List

// https://www.youtube.com/watch?v=iRtLEoL-r-g&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=27
// https://leetcode.com/problems/reverse-linked-list/

// Iterative solution
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while(head != NULL){
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    // TC - O(N)

    // Recursive solution
    

//----------------------------------------------------------------------------------------------------------------------------//

// 2. Find middle of Linked List

// https://www.youtube.com/watch?v=sGdwSH8RK-o&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=27
// https://leetcode.com/problems/middle-of-the-linked-list/

    // Tortoise and hare method, two pointer kind of
    // fast moves two step, and slow move one step      
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    // TC - O(N/2), better than simple iteration solution

//---------------------------------------------------------------------------------------------------------------------------//

// 3. Merge two sorted Linked List 

// https://www.youtube.com/watch?v=Xb4slcp1U38&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=28 
// https://leetcode.com/problems/merge-two-sorted-lists/

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val > l2->val) swap(l1, l2);
        ListNode* res = l1;
        
        while(l1 and l2){
            ListNode *tmp = NULL;
            while((l1 != NULL) and (l1->val <= l2->val)){
                tmp = l1;
                l1 = l1->next;
            }
            
            tmp->next = l2;
            swap(l1, l2);
        }
        
        return res;
    }
    // TC - O(N), SC - O(1) i.e. in-place

//------------------------------------------------------------------------------------------------------------------------------//

// 4. Remove N-th node from back of LinkedList 

// https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=29 
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Better Approach:
/*
    // counting the total nodes say cnt, then calulating cnt-n, traversing to it and deleting it
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            l++;
        }
        cout << l << " ";
        l = l-n-1;
        temp = head;
        if(l < 0){
            head = head->next;
            return head;
        }
        while(l > 0) {
            temp = temp->next;
            l--;
        }
        
        ListNode* temp2 = temp->next;
        temp->next = temp2->next;
    
        
        return head;
    }
    // TC - O(2N), SC - O(1)

*/

// Efficient Solution

// solves the problem in only one iteration
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we take two pointer, f and s
        ListNode *f = head, *s = head;
        
        // we move f to n places forward
        while(f and n--){
            f = f->next;
        }
        // if f is NULL, it means first node is to be deleted(edge case)
        if(!f)
            return head->next; // return the next node to head
        
        // else, we move both s and f forward till f->next becomes NULL
        while(f->next){
            s = s->next;
            f = f->next;
        }
        
        // this results in s pointer to be just before the node to be deleted
        ListNode* temp;
        temp = s->next;
        s->next = temp->next;
        delete(temp);
        
        return head;
    }
    // TC - O(N), SC - O(1)

//---------------------------------------------------------------------------------------------------------------------------//

// 5. Delete a given Node when a node is given. (0(1) solution) 

// https://www.youtube.com/watch?v=icnp4FJdZ_c&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=31
// https://leetcode.com/problems/delete-node-in-a-linked-list/

    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = temp->next;
        delete(temp);
    }
    // TC - O(1)

// if say we are also given that i.e. the deleting node can be the tail node,
// then we can simply have a if else check(check if its next is = NULL), and then assign NULL to the node

//-----------------------------------------------------------------------------------------------------------------------------//

// 6. Add two numbers as LinkedList  

// https://www.youtube.com/watch?v=LBVsXSMOIk4&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=32
// https://leetcode.com/problems/add-two-numbers/

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 or l2 or carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum/10;
            
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        
        return dummy->next;
    }
    // TC - O(N)

//-----------------------------------------------------------------------------------------------------------------------------//

// 7. Intersection point of Y linked list

// https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=33
// https://leetcode.com/problems/intersection-of-two-linked-lists/

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return NULL;
        if(!headB) return NULL;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        // if a & b have diffrent len, then we will stop the loop after second iteration
        while(a != b){
            // after the end of first iteration, we set the pointer to the head of another Linked List
            a = (a == NULL)? headB : a->next;
            b = (b == NULL)? headA : b->next;
        }
        
        // return the common node as the loop stopped when a == b
        return a;
    }
    // TC - O(N)
    // watch video for understanting the intuition

    // one solution would have been to calculate the length of both linked lists, find their difference, move the longer
    // list's head ahead the difference we got, and then move both the heads simultaneously till we reach the common node.
    // the TC of the solution is similar but the code is lengthy

//-----------------------------------------------------------------------------------------------------------------------------//

// 8. Detect a cycle in Linked List

// https://www.youtube.com/watch?v=354J83hX7RI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34 
// https://leetcode.com/problems/linked-list-cycle/

// floyd's cycle detection algo using tortoise and hare concept
    bool hasCycle(ListNode *head) {
        if(!head or !head->next) return false;
        
        ListNode *slow = head, *fast = head;
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true;
        }
        
        return false;
    }
    // TC - O(N)

//-----------------------------------------------------------------------------------------------------------------------------//

// 9. Reverse a LinkedList in groups of size k

// https://www.youtube.com/watch?v=Of0HPkk3JgI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=35 
// https://leetcode.com/problems/reverse-nodes-in-k-group/

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *curr = head, *nex = dummy, *pre = dummy;
        
        int cnt = 0;
        while(curr != NULL){
            curr = curr->next;
            cnt++;
        }
        
        while(cnt >= k){
            curr = pre->next;
            nex = curr->next;
            
            for(int i=1; i<k; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            
            cnt -= k;
            pre = curr;
        }
        
        return dummy->next;
    }
    // TC - O(N), SC - O(1)
    // it is a hard problem, so do watch the video for intuition and logic that how it works

//-----------------------------------------------------------------------------------------------------------------------------//

// 10. Check if LInked List Palindrome or not

// https://www.youtube.com/watch?v=-DtNInqFUXs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=36
// https://leetcode.com/problems/palindrome-linked-list/submissions/

    bool isPalindrome(ListNode* head) {
        ListNode *f = head, *s = head;
        
        // find the middle of linked list
        // if even nodes, then find the first middle
        while(f->next and f->next->next){
            s = s->next;
            f = f->next->next;
        }
        
        // find reverse of the list next to s pointer
        s->next = reverseList(s->next);

        // move s to next
        s = s->next;
        // initialize f again to head
        f = head;
        

        // check for palindrome
        while(s != NULL){
            if(s->val != f->val)
                return false;
            s = s->next;
            f = f->next;
        }
        
        return true;
    }
    // TC - O(n/2 + n/2 + n/2)
    // SC - O(1)

//-----------------------------------------------------------------------------------------------------------------------------//

// 11. Find the starting of loop in given linked list

// https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=37
// https://leetcode.com/problems/linked-list-cycle-ii/

    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) 
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ // if cycle is found, then we start moving slow and entry pointer by one move
                while(slow != entry){ // it is bound to meet in the starting point of the loop
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        
        return NULL;
    }
    //TC - O(n)

    // also watch the video for intuition, important**

//-----------------------------------------------------------------------------------------------------------------------------//

// 12. Flattening of a Linked List

// https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=37
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

    struct NodeB{
        int data;
        struct NodeB * next;
        struct NodeB * bottom;
        
        NodeB(int x){
            data = x;
            next = NULL;
            bottom = NULL;
        }
    };

    // important merge function. merged in diffrent weay than before. Do learn this too.
    // it works fine in (merge two sorted array problem as well)
    NodeB* merge(NodeB* a, NodeB* b){
        NodeB *temp = new NodeB(0);
        NodeB* res = temp;
        
        while(a != NULL and b != NULL){
            if(a->data <= b->data){
                temp->bottom = a;
                temp = temp->bottom;
                a = a->bottom;
            }
            else{
                temp->bottom = b;
                temp = temp->bottom;
                b = b->bottom;
            }
        }
        
        if(a) temp->bottom = a;
        else temp->bottom = b;
        
        return res->bottom;
    }    
    
    
    NodeB *flatten(NodeB *root)
    {
        if(root == NULL or root->next == NULL)
            return root;
        
        root->next = flatten(root->next);
        
        root = merge(root, root->next);
        
        return root;
    }

//----------------------------------------------------------------------------------------------------------------------------//

// 13. Rotate a Linked List

// https://www.youtube.com/watch?v=9VPm6nEbVPA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=39
// https://leetcode.com/problems/rotate-list/

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k == 0) return head;
        
        ListNode *curr = head;
        int n = 1; // it will store the length of the linked list
        while(curr->next){ // we traverse till last
            n++;
            curr = curr->next;
        }
        
        k = k%n; // when k >= n
        k = n - k;
        curr->next = head; // connecting the last node to the head
        while(k--)
            curr = curr->next;
        
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
    // TC - O(N)

//---------------------------------------------------------------------------------------------------------------------------//

// 14. Clone a linked list with random pointers

// https://www.youtube.com/watch?v=VNf6VynfpdM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=40
// https://leetcode.com/problems/copy-list-with-random-pointer/

    class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };

    Node* copyRandomList(Node* head) {

        // Step 1: Putting a copy node after every node in the original linked list
        Node *itr = head, *front = head;
        while(itr != NULL){
            front = itr->next;
            Node* node = new Node(itr->val);
            itr->next = node;
            node->next = front;
            itr = itr->next->next;
        }

        // Step 2: Establish connection between the random pointers of deep copy nodes
        itr = head;
        while(itr != NULL){
            if(itr->random != NULL){
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }
        

        // Step 3: Seperate both the lists
        itr= head;
        front = head;
        Node* pseudo_head = new Node(0);
        Node* copy = pseudo_head;
        
        while(itr != NULL){
            front = itr->next->next;
            copy->next = itr->next;
            itr->next = front;
            copy = copy->next;
            itr = itr->next;
        }
        
        return pseudo_head->next;
    }
    // TC - O(3N) ~ O(N), SC - O(1)

//---------------------------------------------------------------------------------------------------------------------------//


// 15. Implementation of Stacks using Arrays

// https://www.youtube.com/watch?v=GYptUgnIM_I&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=69
// https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1


    class MyStack{
        private:
            int arr[1000];
            int top;
        public:
            MyStack(){top=-1;}
            int pop();
            void push(int);
    };

    //Function to push an integer into the stack.
    void MyStack :: push(int x){
        arr[++top] = x;
    } // first increment top, then insert

    //Function to remove an item from top of the stack.
    int MyStack :: pop(){
        int x;
        if(top == -1) // when stack is empty
            x = -1;
        else{
            x = arr[top];
            top--;
        }
        
        return x;
    } 
    // TC - O(1) for both Push and Pop operations

//-----------------------------------------------------------------------------------------------------------------------------//

// 16. Implemetation of Queue using Arrays

// https://www.youtube.com/watch?v=M6GnoUDpqEE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=73

int arr[1000];
int n = sizeof(arr)/sizeof(arr[0]);
int cnt = 0;
int front = 0, rear = 0;

void push(int x){
    if(cnt == n)
        cout << "Queue is full!";
    
    arr[rear%n] = x;
    rear++;
    cnt++;
}

void pop(){
    if(cnt == 0)
        cout << "Queue is empty!";

    arr[front%n] = -1;
    front++;
    cnt--; 
}

int top(){
    if(cnt == 0)
        return -1;
    return arr[front%n];
}

//----------------------------------------------------------------------------------------------------------------------------//

// 17. Implement Stack usign Queue(using single queue)

// https://www.youtube.com/watch?v=jDZQKzEtbYQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=72

class MyStackUsingQueue {
public:
    
    queue<int> que;
    /** Initialize your data structure here. */
    MyStackUsingQueue() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = que.front(); 
        que.pop(); 
        return x; 
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.size() == 0; 
    }
}; // TC - O(N), SC - O(N)

// If asked in interview, first give the approach using TWO QUEUES
/*
    push(x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q2.pop();
        }

        swap(q1, q2);
    }

    pop(){
        q1.pop();
    }

    top(){
        return q1.front();
    }
*/

//----------------------------------------------------------------------------------------------------------------------//

// 18. Implement Queue using Stacks

// https://www.youtube.com/watch?v=3Et9MrMc02A&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=74
// https://leetcode.com/problems/implement-queue-using-stacks/submissions/

    class MyQueue {
        public:
        /** Initialize your data structure here. */
        stack<int> input;
        stack<int> output;
        
        MyQueue() {
            
        }
        
        /** Push element x to the back of queue. */
        void push(int x) {
            input.push(x);
        }
        
        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            if(output.empty()){
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
            }
            int x = output.top();
            output.pop();
            return x;
        }
        
        /** Get the front element. */
        int peek() {
            if(output.empty()){
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
            }
            
            return (output.top());
        }
        
        /** Returns whether the queue is empty. */
        bool empty() {
            if(input.empty() and output.empty())
                return true;
            return false;
        }
        // TC - O(1) amortized for all functions
    };

//----------------------------------------------------------------------------------------------------------------------//

// 19. Valid Parentheses

// https://www.youtube.com/watch?v=wkDfsKijrZ8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=74
// https://leetcode.com/problems/valid-parentheses/

    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {{'{', '}'}, {'(', ')'}, {'[', ']'}};

        for(auto it: s){
            if(it == '{' or it == '(' or it == '[')
                st.push(it);
            else{
                if(!st.empty() and mp[st.top()] == it)
                    st.pop();
                else
                    return false;
            }
        }
        
        if(!st.empty()) return false;
        return true;
    }
    // TC - O(N), SC - O(N)

//------------------------------------------------------------------------------------------------------------------------//

// 20.Next Greater Element (to both right and left)

// https://www.youtube.com/watch?v=Du881K7Jtk8&t=32s

vector<int> ngeRight(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    
    for(int i=n-1; i>=0; i--){
        while(!st.empty() and st.top() <= arr[i])
            st.pop();
        
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        
        st.push(arr[i]);
    }
    
    return ans;
}

vector<int> ngeLeft(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    
    for(int i=0; i<n; i++){
        while(!st.empty() and st.top() <= arr[i])
            st.pop();
        
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        
        st.push(arr[i]);
    }
    
    return ans;
}
// TC - O(N), SC - O(N)

//----------------------------------------------------------------------------------------------------------------------------//

// 21. Next Smaller Element (to both right and left)

vector<int> nseRight(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    
    for(int i=n-1; i>=0; i--){
        while(!st.empty() and st.top() >= arr[i])
            st.pop();
        
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        
        st.push(arr[i]);
    }
    
    return ans;
}

vector<int> nseLeft(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    
    for(int i=0; i<n; i++){
        while(!st.empty() and st.top() >= arr[i])
            st.pop();
        
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        
        st.push(arr[i]);
    }
    
    return ans;
}
// TC - O(N), SC - O(N)

//---------------------------------------------------------------------------------------------------------------------//

// 22. LRU Cache

// https://www.youtube.com/watch?v=xDEuM5qa0zg&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=77
// https://leetcode.com/problems/lru-cache/

class LRUCache {
public:

    // doubly linked-list node structure
    class node{
        public:
        
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int _key, int _val){
            key = _key;
            val = _val;
            next = NULL;
            prev = NULL;
        }
    };
    
    // nodes for initial configuration
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node* > mp;
    
    // initial configuration
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    // add node next to the head pointer
    void addnode(node* newnode){
        node* temp = newnode;
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }
    
    // delete node from anywhere in the DLL
    void deletenode(node* delnode){
        node* delnext = delnode->next;
        node* delprev = delnode->prev;
        
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    
    // getting the value of the corresponding key
    int get(int _key) {
        // if key is found,
        // store its value into a variable;
        // delete the node(from the hash map of the corresponding key), and remove the key from map too;
        // add the node next to head(as it will last recently used node)
        // return the stored value of corresponding key in the variable
        if(mp.find(_key) != mp.end()){
            node* resnode = mp[_key];
            int res = resnode->val;
            mp.erase(_key);
            deletenode(resnode);
            addnode(resnode);
            mp[_key] = head->next;
            
            return res;
        }
        
        // if key not found
        return -1;
    }
    
    void put(int _key, int value) {
        // if key already present,
        // remove from hash map and delete node
        if(mp.find(_key) != mp.end()){
            node* existingnode = mp[_key];
            mp.erase(_key);
            deletenode(existingnode);
        }
        
        // if capacity is full, delete the Least Recently Used node(node before tail node)
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        // add node next to head
        addnode(new node(_key, value));
        mp[_key] = head->next; 
    }
};
// TC - O(1), for both PUT and GET functions

//----------------------------------------------------------------------------------------------------------------------//

// 23. Largest rectangle in histogram

// https://www.youtube.com/watch?v=X0X6G-eWgQ8
// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/

    // this next smaller element functions returns the vector which gives the index of nse for every element(to right and left)

    vector<int> _nseRight(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<pair<int, int>> st; // we take pair here to store index also

        for(int i=n-1; i>=0; i--){
            while(!st.empty() and st.top().first >= arr[i])
                st.pop();

            if(st.empty()) ans[i] = arr.size(); // instead of -1 we store arr.size() for right side
            else ans[i] = st.top().second;

            st.push({arr[i], i});
        }

        return ans;
    }

    vector<int> _nseLeft(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;

        for(int i=0; i<n; i++){
            while(!st.empty() and st.top().first >= arr[i])
                st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top().second;

            st.push({arr[i], i});
        }

        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nseR = _nseRight(heights);
        vector<int> nseL = _nseLeft(heights);
        int n = heights.size();
        
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, heights[i]*(nseR[i] - nseL[i] - 1)); // remember the formula or deduce
        
        return ans;
    }
    // TC - O(2n + 2n + n) ~ O(n), SC - O(n) 

//----------------------------------------------------------------------------------------------------------------------//

// 24. Sliding Window Maximum

// https://leetcode.com/problems/sliding-window-maximum/

//-----------------------------------------------------------------------------------------------------------------------//

// 25. Implement Min Stack

// Constant time and extra space solution
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> ss;
    
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty() or val <= ss.top())
            ss.push(val);
    }
    
    void pop() {
        if(s.size() == 0)
            return;
        
        int ans = s.top();
        s.pop();
        
        if(ans == ss.top()) // if the popped element was the minimum element, then pop the element of ss stack also
            ss.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
}; // Here ss stack will keep track of the minimum element


//-----------------------------------------------------------------------------------------------------------------------//

// 26. Rotten Oranges


//-----------------------------------------------------------------------------------------------------------------------//

// 27. Subset Sum problem

// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

void subsetSumUtil(int ind, vector<int> arr, int N, int sum, vector<int>& ds){
        if(ind == N){
            ds.push_back(sum);
            return;
        }
        
        subsetSumUtil(ind + 1, arr, N, sum + arr[ind], ds);
        subsetSumUtil(ind + 1, arr, N, sum, ds);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> subsetSum;
        subsetSumUtil(0, arr, N, 0, subsetSum);
        sort(subsetSum.begin(), subsetSum.end());
        return subsetSum;
    }

// 28. Subsets II

// https://leetcode.com/problems/subsets-ii/

void findSubsets(int ind, int n, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        ans.push_back(ds);
        for(int i=ind; i<n; i++){
            if(i != ind and nums[i] == nums[i-1]) continue; // very imp, it avoids taking duplicates
            ds.push_back(nums[i]);
            findSubsets(i + 1, n, nums, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, n, nums, ans, ds);
        
        return ans;
    }

//------------------------------------------------------------------------------------------------------------------------//

// 29. Combination Sum 
// https://leetcode.com/problems/combination-sum/

    void combinationSumUtil(int ind, vector<int>& candi, int target, vector<vector<int>>& ans, vector<int>& res){
        if(ind == candi.size()){
            if(target == 0)
                ans.push_back(res);
            return;
        }
        
        if(target >= candi[ind]){
            res.push_back(candi[ind]);
        
            combinationSumUtil(ind, candi, target - candi[ind], ans, res);
            res.pop_back();
        }
        
        combinationSumUtil(ind+1, candi, target, ans, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        vector<vector<int>> ans;
        
        combinationSumUtil(0, candidates, target, ans, res);
        
        return ans;
    }

//------------------------------------------------------------------------------------------------------------------------//

// 30. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

    void findSubsets(int ind, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            if(i != ind and nums[i] == nums[i-1]) continue;
            if(nums[i] <= target){
                ds.push_back(nums[i]);
                findSubsets(i + 1, target - nums[i], nums, ans, ds);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        
        findSubsets(0, target, candidates, ans, ds);
        
        return ans;
    }

//------------------------------------------------------------------------------------------------------------------------//

// 31. Palindrome partitioning
//  https://leetcode.com/problems/palindrome-partitioning/

    bool isPalindrome(string s, int start, int end){
        int l = start;
        int r = end;
        
        while(l <= r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    
    void partitionUtil(int ind, string s, int n, vector<vector<string>>& ans, vector<string> ds){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind; i<n; i++){
            if(isPalindrome(s, ind, i)){
                ds.push_back(s.substr(ind, i - ind + 1));
                partitionUtil(i+1, s, n, ans, ds);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = s.size();
        partitionUtil(0, s, n, ans, ds);
        
        return ans;
    }

//------------------------------------------------------------------------------------------------------------------------//

// 32. Kth Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/

    string get(int n, int k, string s, vector<int> fact, vector<int>& num){
        if(n == 0)
            return s;
        
        int ind = k/fact[n-1];
        s += char(num[ind] + 48);
        auto it = num.begin() + ind;
        num.erase(it);
        
        return get(n-1, k%fact[n-1], s, fact, num);
    }
    
    string getPermutation(int n, int k) {
        vector<int> fact(n+1);
        vector<int> num;
        fact[0] = 1;
        for(int i=1; i<=n; i++){
            fact[i] = i*fact[i-1];
            num.push_back(i);
        }
        
        return get(n, k-1, "", fact, num);
    }

//--------------------------------------------------------------------------------------------------------------------------//