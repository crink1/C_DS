//struct ListNode* lowhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//struct ListNode* lowtail = lowhead;
//struct ListNode* greaterhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//struct ListNode* greatertail = greaterhead;
//struct ListNode* cur = pHead;
//while (cur != NULL)
//{
//    if (cur->val < x)
//    {
//        lowtail->next = cur;
//        lowtail = lowtail->next;
//
//    }
//    else
//    {
//        greatertail->next = cur;
//        greatertail = greatertail->next;
//    }
//    cur = cur->next;
//}
//lowtail->next = greaterhead->next;
//greatertail->next = NULL;
//
//struct ListNode* tmp = lowhead->next;
//free(lowhead);
//free(greaterhead);
//return tmp;
//    }
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//
//    while (fast != NULL && fast->next != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//
//}
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* newhead = NULL;
//    struct ListNode* cur = head;
//    while (cur != NULL)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = newhead;
//        newhead = cur;
//        cur = next;
//
//    }
//    return newhead;
//
//}
//bool chkPalindrome(ListNode* phead) {
//    // write code here
//    struct ListNode* midnode = middleNode(phead);
//    struct ListNode* reversnode = reverseList(midnode);
//    while (reversnode)
//    {
//        if (reversnode->val != phead->val)
//        {
//            return false;
//        }
//        reversnode = reversnode->next;
//        phead = phead->next;
//    }
//    return true;
//}