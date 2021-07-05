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

    // Tortoise and hare method, two pointer kindof
    // fase moves two step, and slow move one step      
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


//---------------------------------------------------------------------------------------------------------------------------//


