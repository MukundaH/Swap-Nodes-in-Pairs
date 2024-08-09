/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode * current=head->next->next, * previous=head, *temp=head->next;
    head = temp;
    temp->next = previous;
    previous->next = current;
    while(current!=NULL&&current->next!=NULL){
        current = current->next->next;
        temp = previous->next->next;
        temp->next = previous->next;
        previous->next = temp;
        previous = temp->next;
        previous->next = current;
    }
    return head;
}
