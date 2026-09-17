/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        //find center of linked list, reverse second half.
        //then its basically just merging two sorted linked lists

        ListNode* slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow is the center node once next iteration of fast reaches the end
        //Split LL into two and reverse second half
        ListNode* curr = slow->next;
        slow->next = nullptr;
        
        //reverse LL
        ListNode* prev = nullptr, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // printLL(prev);

        //start with head 1 and just alternate
        ListNode *head1 = head, *head2 = prev;
        bool val = false;

        while (head1 && head2)
        {
            if (!val)
            {
                next = head1->next;
                head1->next = head2;
                prev = head1;
                head1 = next;
            }
            else
            {
                next = head2->next;
                head2->next = head1;
                prev = head2;
                head2 = next;
            }
            val = !val;
        }
    }

    void printLL(ListNode* head)
    {
        ListNode* curr = head;
        
        while(curr)
        {
            cout << curr->val << "\n";
            curr = curr->next;
        }
    }
};
