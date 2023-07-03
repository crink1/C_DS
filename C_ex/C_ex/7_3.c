//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    struct ListNode* cur1 = l1;
//    struct ListNode* cur2 = l2;
//    struct ListNode* head = NULL;
//    struct ListNode* tail = NULL;
//    int num1 = 0;
//    int num2 = 0;
//    int carry = 0;
//    while (cur1 != NULL || cur2 != NULL)
//    {
//        if (cur1 != NULL)
//        {
//            num1 = cur1->val;
//        }
//        else
//        {
//            num1 = 0;
//        }
//        if (cur2 != NULL)
//        {
//            num2 = cur2->val;
//        }
//        else
//        {
//            num2 = 0;
//        }
//        int sum = num1 + num2 + carry;
//
//        //sum = sum % 10;
//        if (head == NULL)
//        {
//            head = (struct ListNode*)malloc(sizeof(struct ListNode));
//            tail = head;
//            tail->val = sum % 10;
//            tail->next = NULL;
//        }
//        else
//        {
//            tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//            tail->next->val = sum % 10;
//            tail = tail->next;
//            tail->next = NULL;
//        }
//
//
//
//        carry = sum / 10;
//        if (cur1 != NULL)
//        {
//            cur1 = cur1->next;
//        }
//        if (cur2 != NULL)
//        {
//            cur2 = cur2->next;
//        }
//        if (carry > 0)
//        {
//            tail->next = malloc(sizeof(struct ListNode));
//            tail->next->val = carry;
//            tail->next->next = NULL;
//        }
//
//
//    }
//
//
//
//    return head;
//}