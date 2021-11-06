// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool pls = false;
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        ListNode *last = new ListNode();
        while(node1 != nullptr && node2 != nullptr){
            node1->val += node2->val;
            if(pls){
                node1->val += 1;
                pls = false;
            }
            if(node1->val > 9){
                node1->val -= 10;
                pls = true;
            }
            if(node1->next == nullptr){
                if(node2->next == nullptr && pls){
                    node1->next = last;
                }else{
                    node1->next = node2->next;
                    node2->next = nullptr;
                }   
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        while(node1 != nullptr){
            if(pls){
                node1->val += 1;
                pls = false;
            }
            if(node1->val > 9){
                node1->val -= 10;
                pls = true;
            }
            if(node1->next == nullptr && pls){
                
                node1->next = last;
            }
            node1 = node1->next;
        }
        return l1;
    }
};