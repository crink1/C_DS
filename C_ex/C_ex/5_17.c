//struct Node* copyRandomList(struct Node* head) {
//
//    struct Node* cur = head;
//    while (cur)
//    {
//        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//        newnode->val = cur->val;
//        newnode->next = cur->next;
//        cur->next = newnode;
//        cur = cur->next->next;
//    }
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//        cur = copy->next;
//    }
//    struct Node* copyhead = NULL;
//    struct Node* copytail = NULL;
//    cur = head;
//
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        if (copytail == NULL)
//        {
//            copyhead = cur->next;
//            copytail = cur->next;
//        }
//        else
//        {
//            copytail->next = copy;
//            copytail = copytail->next;
//
//        }
//        cur->next = copy->next;
//        cur = copy->next;
//    }
//    return copyhead;
//}