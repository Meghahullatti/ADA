/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int count = 0;
    
    struct ListNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (count == n)
        return head->next;

    temp = head;
    for (int i = 0; i < count - n - 1; i++) {
        temp = temp->next;
    }

    temp->next = temp->next->next;
    return head;
}
