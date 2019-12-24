//Detect loop in cycle
//Find the starting point of loop

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;  
        if(!head || head->next==NULL)
            return NULL;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow)
                break;
        }
        if(fast!=slow)
            return NULL; //no cycle
        //find starting point of cycle
        while(head && slow){
            if(head==slow)
                return head;
            head = head->next;
            slow = slow->next;
        }
        return NULL;
    }
};

//Using set
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> ptr_set;
        while(head){
            if(ptr_set.find(head)!=ptr_set.end())
                return head;
            ptr_set.insert(head) ;
            head = head->next;
        }
        return NULL;
    }
};