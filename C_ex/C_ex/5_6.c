//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//
//            while (slow != head)
//            {
//                slow = slow->next;
//                head = head->next;
//            }
//
//            return head;
//
//        }
//    }
//    return NULL;
//
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            return true;
//        }
//
//    }
//    return false;
//
//}