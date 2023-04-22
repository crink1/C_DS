//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* newhead = NULL;
//    struct ListNode* tail = NULL;
//    while (head)
//    {
//        if (head->val != val)
//        {
//            if (NULL == newhead && NULL == tail)
//            {
//                newhead = head;
//                tail = head;
//            }
//            else
//            {
//                tail->next = head;
//                tail = tail->next;
//
//
//
//            }
//            head = head->next;
//            tail->next = NULL;
//        }
//        else
//        {
//            struct ListNode* tmp = head;
//            head = head->next;
//            free(tmp);
//        }
//
//    }
//    return newhead;
//
//}
//
//
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* newhead = NULL;
//    struct ListNode* cur = NULL;
//    while (head != NULL)
//    {
//        if (NULL == newhead)
//        {
//            newhead = head;
//            head = head->next;
//            newhead->next = NULL;
//        }
//        else
//        {
//            cur = head;
//            head = head->next;
//            cur->next = newhead;
//            newhead = cur;
//        }
//    }
//    return newhead;
//
//}
//
//
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
//
//
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    struct ListNode* fast = pListHead;
//    struct ListNode* slow = pListHead;
//    // write code here
//    if (k == 0)
//    {
//        return NULL;
//    }
//    if (pListHead != NULL)
//    {
//        while (k != 0)
//        {
//            if (NULL == fast)
//            {
//                return NULL;
//            }
//            fast = fast->next;
//            k--;
//        }
//        while (fast != NULL)
//        {
//            slow = slow->next;
//            fast = fast->next;
//        }
//    }
//    return slow;
//}
//
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//
//    struct ListNode* newhead = NULL;
//    struct ListNode* tail = NULL;
//
//    while (list1 != NULL && list2 != NULL)
//    {
//        if (list1->val < list2->val)
//        {
//            if (NULL == newhead)
//            {
//                newhead = list1;
//                tail = list1;
//            }
//            else
//            {
//                tail->next = list1;
//                tail = tail->next;
//
//            }
//            list1 = list1->next;
//            tail->next = NULL;
//        }
//        else
//        {
//            if (NULL == newhead)
//            {
//                newhead = list2;
//                tail = list2;
//
//            }
//            else
//            {
//                tail->next = list2;
//                tail = tail->next;
//
//            }
//            list2 = list2->next;
//            tail->next = NULL;
//        }
//    }
//    if (list1 != NULL)
//    {
//        if (NULL == newhead)
//        {
//            return list1;
//        }
//        tail->next = list1;
//    }
//    if (list2 != NULL)
//    {
//        if (NULL == newhead)
//        {
//            return list2;
//        }
//        tail->next = list2;
//    }
//    return newhead;
//}