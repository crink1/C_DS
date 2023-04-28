//#define MOST_INDEX          180000
//#define INVALID_VALUE       -1
//#define FATHER_NODE(x)      ((0 == (x)) ? INVALID_VALUE : ((x) - 1 >> 1))
//#define LEFT_NODE(x)        (((x) << 1) + 1)
//#define RIGHT_NODE(x)       (((x) << 1) + 2)
//
///* 链表节点定义。 */
//typedef struct ValListNode_s
//{
//    int val;
//    struct ValListNode_s* next;
//}
//ValListNode;
//
///* 最小堆定义。 */
//typedef struct
//{
//    int* array;
//    int arraySize;
//}
//HeapNode;
//
///* 对象定义。 */
//typedef struct
//{
//    int capacity;
//    int maxIndex;
//    int* number;
//    bool* flag;
//    ValListNode** head;
//    HeapNode pushable;
//    HeapNode popable;
//}
//DinnerPlates;
//
///* 自定义的小根堆push、pop操作函数，具体实现见下。 */
//extern void heapPush(HeapNode* heap, int index);
//extern void heapPop(HeapNode* heap);
//
///* 创建对象。 */
//DinnerPlates* dinnerPlatesCreate(int capacity)
//{
//    DinnerPlates* obj = (DinnerPlates*)malloc(sizeof(DinnerPlates));
//    obj->capacity = capacity;
//    obj->maxIndex = INVALID_VALUE;
//    obj->number = (int*)malloc(sizeof(int) * MOST_INDEX);
//    obj->flag = (bool*)malloc(sizeof(bool) * MOST_INDEX);
//    obj->head = (ValListNode**)malloc(sizeof(ValListNode*) * MOST_INDEX);
//    obj->pushable.array = (int*)malloc(sizeof(int) * MOST_INDEX);
//    obj->pushable.arraySize = 0;
//    obj->popable.array = (int*)malloc(sizeof(int) * MOST_INDEX);
//    obj->popable.arraySize = 0;
//    return obj;
//}
//
///* push操作。 */
//void dinnerPlatesPush(DinnerPlates* obj, int val)
//{
//    int index = 0;
//    ValListNode* node = NULL;
//    /* 如果当前pushable为空（可能是首次使用也可能是前面几个栈已满），则开辟新索引。 */
//    if (0 == obj->pushable.arraySize)
//    {
//        index = obj->popable.arraySize;
//        /* 这里类似于游戏中往边界移动时，开辟新地图时的初始化操作。
//        再未超出maxIndex的情况下，这些flag[index]、number[index]、head[index]在前面必然已经操作过了。 */
//        if (obj->maxIndex < index)
//        {
//            obj->maxIndex = index;
//            obj->flag[index] = false;
//            obj->number[index] = 0;
//            obj->head[index] = NULL;
//        }
//        /* 新获取的index加入到pushable堆中。 */
//        heapPush(&obj->pushable, index);
//    }
//    /* 堆顶就是最小的可push下标，在此处的栈加入新元素。 */
//    index = obj->pushable.array[0];
//    node = (ValListNode*)malloc(sizeof(ValListNode));
//    node->val = val;
//    node->next = obj->head[index];
//    obj->head[index] = node;
//    obj->number[index]++;
//    /* 新出现的栈，且在之前这个下标并未在popable中，则加入到popable中。 */
//    if (1 == obj->number[index] && false == obj->flag[index])
//    {
//        /* 标记这个flag，并且注意，加入popable的实际是“超大常数值减去index”的差值。 */
//        obj->flag[index] = true;
//        heapPush(&obj->popable, MOST_INDEX - index);
//    }
//    /* 如果该栈已满，则后续不能再往里面push了，就从pushable中移除。 */
//    if (obj->capacity == obj->number[index])
//    {
//        heapPop(&obj->pushable);
//    }
//    return;
//}
//
///* pop操作。 */
//int dinnerPlatesPop(DinnerPlates* obj)
//{
//    /* 返回值先初始化为无效值-1。 */
//    int index = 0, val = INVALID_VALUE;
//    ValListNode* node = NULL;
//    /* 在popAtStack操作时，可能有空栈但对应的index未出堆的，就先借此时机出堆。 */
//    while (0 < obj->popable.arraySize && 0 == obj->number[MOST_INDEX - obj->popable.array[0]])
//    {
//        obj->flag[MOST_INDEX - obj->popable.array[0]] = false;
//        heapPop(&obj->popable);
//    }
//    /* 如果经过上面这一步，popable仍然非空，则可以选取其中的最大下标了。 */
//    if (0 < obj->popable.arraySize)
//    {
//        /* 注意，用这个超大常数值减去堆顶最小值，才是真正的最大可pop下标。 */
//        index = MOST_INDEX - obj->popable.array[0];
//        node = obj->head[index];
//        val = node->val;
//        obj->head[index] = node->next;
//        free(node);
//        obj->number[index]--;
//        /* 如果原本是满栈，现在变成了非满栈，则可以把index加入到pushable堆中了。 */
//        if (obj->capacity - 1 == obj->number[index])
//        {
//            heapPush(&obj->pushable, index);
//        }
//        /* 如果变为空栈，则从popable中移除。 */
//        if (0 == obj->number[index])
//        {
//            obj->flag[index] = false;
//            heapPop(&obj->popable);
//        }
//    }
//    return val;
//}
//
///* popAtStack操作。 */
//int dinnerPlatesPopAtStack(DinnerPlates* obj, int index)
//{
//    /* 返回值先初始化为无效值-1。 */
//    int val = INVALID_VALUE;
//    ValListNode* node = NULL;
//    /* 没有超出已知地图边界，且该处非空栈的时候，可以取该处栈顶元素。 */
//    if (obj->maxIndex >= index && 0 < obj->number[index])
//    {
//        node = obj->head[index];
//        val = node->val;
//        obj->head[index] = node->next;
//        free(node);
//        obj->number[index]--;
//        /* 如果原本是满栈，现在变成了非满栈，则可以把index加入到pushable堆中了。 */
//        if (obj->capacity - 1 == obj->number[index])
//        {
//            heapPush(&obj->pushable, index);
//        }
//        /* 如果变为空栈，且下标（对应差值）正好是popable的堆顶元素时，则从popable中移除。
//        如果变成空栈，但下标（对应差值）不是popable堆顶元素，则先留着，后面pop操作时会找时机移除。 */
//        if (0 == obj->number[index] && index == MOST_INDEX - obj->popable.array[0])
//        {
//            obj->flag[index] = false;
//            heapPop(&obj->popable);
//        }
//    }
//    return val;
//}
//
///* 删除对象。 */
//void dinnerPlatesFree(DinnerPlates* obj)
//{
//    int x = 0;
//    ValListNode* node = NULL, * next = NULL;
//    /* 移除剩余的栈中元素。 */
//    while (obj->popable.arraySize > x)
//    {
//        node = obj->head[MOST_INDEX - obj->popable.array[x]];
//        while (NULL != node)
//        {
//            next = node->next;
//            free(node);
//            node = next;
//        }
//        x++;
//    }
//    /* 释放对象中的各个数组空间，和对象本身。 */
//    free(obj->number);
//    free(obj->flag);
//    free(obj->head);
//    free(obj->pushable.array);
//    free(obj->popable.array);
//    free(obj);
//    return;
//}
//
///* 自定义的小根堆push操作。 */
//void heapPush(HeapNode* heap, int index)
//{
//    int son = heap->arraySize, father = FATHER_NODE(son);
//    /* 堆size加一。新加入的index默认放到堆尾，然后根据节点和父节点的大小关系，进行位置调整。 */
//    heap->arraySize++;
//    while (INVALID_VALUE != father && heap->array[father] > index)
//    {
//        heap->array[son] = heap->array[father];
//        son = father;
//        father = FATHER_NODE(son);
//    }
//    heap->array[son] = index;
//    return;
//}
//
///* 自定义的小根堆pop操作。 */
//void heapPop(HeapNode* heap)
//{
//    int father = 0, left = LEFT_NODE(father), right = RIGHT_NODE(father), son = 0, index = 0;
//    /* 堆size减一。堆顶移除后的空缺默认由原堆尾元素填补，然后根据新的节点与左右子节点的大小关系，进行位置调整。 */
//    heap->arraySize--;
//    index = heap->array[heap->arraySize];
//    while ((heap->arraySize > left && heap->array[left] < index)
//        || (heap->arraySize > right && heap->array[right] < index))
//    {
//        son = (heap->arraySize > right && heap->array[right] < heap->array[left]) ? right : left;
//        heap->array[father] = heap->array[son];
//        father = son;
//        left = LEFT_NODE(father);
//        right = RIGHT_NODE(father);
//    }
//    heap->array[father] = index;
//    return;
//}