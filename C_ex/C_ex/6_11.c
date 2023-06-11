//struct ListNode* removeZeroSumSublists(struct ListNode* head) {
//    struct ListNode* lh = (struct ListNode*)malloc(sizeof(struct ListNode));
//    lh->val = 0;
//    lh->next = head;
//    struct ListNode* curh = lh;
//    int x = 0;
//    while (curh != NULL)
//    {
//        struct ListNode* cur = curh->next;
//        while (cur != NULL)
//        {
//            x = x - cur->val;
//            if (0 == x)
//            {
//                curh->next = cur->next;
//            }
//            cur = cur->next;
//
//        }
//        curh = curh->next;
//        x = 0;
//    }
//    return lh->next;
//}