#include <stack>
#include <queue>
using std::stack;
using std::queue;
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return head;
        }
        queue<Node*> node_q;
        stack<Node*> node_stk;
        node_q.push(head);
        Node* tmp = nullptr;
        while(!node_q.empty()){
            tmp = node_q.front();
            node_q.pop();
            if(tmp->child != nullptr){
                if(tmp->next != nullptr){
                    node_stk.push(tmp->next);
                }
                tmp->next = tmp->child;
                tmp->next->prev = tmp;
                tmp->child = nullptr;
            }
            if(tmp->next == nullptr){
                if(!node_stk.empty()){
                    tmp->next = node_stk.top();
                    tmp->next->prev = tmp;
                    node_stk.pop();
                }
            }
            if(tmp->next != nullptr){
                node_q.push(tmp->next);
            }
        }
        return head;
    }
};