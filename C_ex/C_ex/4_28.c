//#define MOST_INDEX          180000
//#define INVALID_VALUE       -1
//#define FATHER_NODE(x)      ((0 == (x)) ? INVALID_VALUE : ((x) - 1 >> 1))
//#define LEFT_NODE(x)        (((x) << 1) + 1)
//#define RIGHT_NODE(x)       (((x) << 1) + 2)
//
///* ����ڵ㶨�塣 */
//typedef struct ValListNode_s
//{
//    int val;
//    struct ValListNode_s* next;
//}
//ValListNode;
//
///* ��С�Ѷ��塣 */
//typedef struct
//{
//    int* array;
//    int arraySize;
//}
//HeapNode;
//
///* �����塣 */
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
///* �Զ����С����push��pop��������������ʵ�ּ��¡� */
//extern void heapPush(HeapNode* heap, int index);
//extern void heapPop(HeapNode* heap);
//
///* �������� */
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
///* push������ */
//void dinnerPlatesPush(DinnerPlates* obj, int val)
//{
//    int index = 0;
//    ValListNode* node = NULL;
//    /* �����ǰpushableΪ�գ��������״�ʹ��Ҳ������ǰ�漸��ջ���������򿪱��������� */
//    if (0 == obj->pushable.arraySize)
//    {
//        index = obj->popable.arraySize;
//        /* ������������Ϸ�����߽��ƶ�ʱ�������µ�ͼʱ�ĳ�ʼ��������
//        ��δ����maxIndex������£���Щflag[index]��number[index]��head[index]��ǰ���Ȼ�Ѿ��������ˡ� */
//        if (obj->maxIndex < index)
//        {
//            obj->maxIndex = index;
//            obj->flag[index] = false;
//            obj->number[index] = 0;
//            obj->head[index] = NULL;
//        }
//        /* �»�ȡ��index���뵽pushable���С� */
//        heapPush(&obj->pushable, index);
//    }
//    /* �Ѷ�������С�Ŀ�push�±꣬�ڴ˴���ջ������Ԫ�ء� */
//    index = obj->pushable.array[0];
//    node = (ValListNode*)malloc(sizeof(ValListNode));
//    node->val = val;
//    node->next = obj->head[index];
//    obj->head[index] = node;
//    obj->number[index]++;
//    /* �³��ֵ�ջ������֮ǰ����±겢δ��popable�У�����뵽popable�С� */
//    if (1 == obj->number[index] && false == obj->flag[index])
//    {
//        /* ������flag������ע�⣬����popable��ʵ���ǡ�������ֵ��ȥindex���Ĳ�ֵ�� */
//        obj->flag[index] = true;
//        heapPush(&obj->popable, MOST_INDEX - index);
//    }
//    /* �����ջ�����������������������push�ˣ��ʹ�pushable���Ƴ��� */
//    if (obj->capacity == obj->number[index])
//    {
//        heapPop(&obj->pushable);
//    }
//    return;
//}
//
///* pop������ */
//int dinnerPlatesPop(DinnerPlates* obj)
//{
//    /* ����ֵ�ȳ�ʼ��Ϊ��Чֵ-1�� */
//    int index = 0, val = INVALID_VALUE;
//    ValListNode* node = NULL;
//    /* ��popAtStack����ʱ�������п�ջ����Ӧ��indexδ���ѵģ����Ƚ��ʱ�����ѡ� */
//    while (0 < obj->popable.arraySize && 0 == obj->number[MOST_INDEX - obj->popable.array[0]])
//    {
//        obj->flag[MOST_INDEX - obj->popable.array[0]] = false;
//        heapPop(&obj->popable);
//    }
//    /* �������������һ����popable��Ȼ�ǿգ������ѡȡ���е�����±��ˡ� */
//    if (0 < obj->popable.arraySize)
//    {
//        /* ע�⣬�����������ֵ��ȥ�Ѷ���Сֵ����������������pop�±ꡣ */
//        index = MOST_INDEX - obj->popable.array[0];
//        node = obj->head[index];
//        val = node->val;
//        obj->head[index] = node->next;
//        free(node);
//        obj->number[index]--;
//        /* ���ԭ������ջ�����ڱ���˷���ջ������԰�index���뵽pushable�����ˡ� */
//        if (obj->capacity - 1 == obj->number[index])
//        {
//            heapPush(&obj->pushable, index);
//        }
//        /* �����Ϊ��ջ�����popable���Ƴ��� */
//        if (0 == obj->number[index])
//        {
//            obj->flag[index] = false;
//            heapPop(&obj->popable);
//        }
//    }
//    return val;
//}
//
///* popAtStack������ */
//int dinnerPlatesPopAtStack(DinnerPlates* obj, int index)
//{
//    /* ����ֵ�ȳ�ʼ��Ϊ��Чֵ-1�� */
//    int val = INVALID_VALUE;
//    ValListNode* node = NULL;
//    /* û�г�����֪��ͼ�߽磬�Ҹô��ǿ�ջ��ʱ�򣬿���ȡ�ô�ջ��Ԫ�ء� */
//    if (obj->maxIndex >= index && 0 < obj->number[index])
//    {
//        node = obj->head[index];
//        val = node->val;
//        obj->head[index] = node->next;
//        free(node);
//        obj->number[index]--;
//        /* ���ԭ������ջ�����ڱ���˷���ջ������԰�index���뵽pushable�����ˡ� */
//        if (obj->capacity - 1 == obj->number[index])
//        {
//            heapPush(&obj->pushable, index);
//        }
//        /* �����Ϊ��ջ�����±꣨��Ӧ��ֵ��������popable�ĶѶ�Ԫ��ʱ�����popable���Ƴ���
//        �����ɿ�ջ�����±꣨��Ӧ��ֵ������popable�Ѷ�Ԫ�أ��������ţ�����pop����ʱ����ʱ���Ƴ��� */
//        if (0 == obj->number[index] && index == MOST_INDEX - obj->popable.array[0])
//        {
//            obj->flag[index] = false;
//            heapPop(&obj->popable);
//        }
//    }
//    return val;
//}
//
///* ɾ������ */
//void dinnerPlatesFree(DinnerPlates* obj)
//{
//    int x = 0;
//    ValListNode* node = NULL, * next = NULL;
//    /* �Ƴ�ʣ���ջ��Ԫ�ء� */
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
//    /* �ͷŶ����еĸ�������ռ䣬�Ͷ����� */
//    free(obj->number);
//    free(obj->flag);
//    free(obj->head);
//    free(obj->pushable.array);
//    free(obj->popable.array);
//    free(obj);
//    return;
//}
//
///* �Զ����С����push������ */
//void heapPush(HeapNode* heap, int index)
//{
//    int son = heap->arraySize, father = FATHER_NODE(son);
//    /* ��size��һ���¼����indexĬ�Ϸŵ���β��Ȼ����ݽڵ�͸��ڵ�Ĵ�С��ϵ������λ�õ����� */
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
///* �Զ����С����pop������ */
//void heapPop(HeapNode* heap)
//{
//    int father = 0, left = LEFT_NODE(father), right = RIGHT_NODE(father), son = 0, index = 0;
//    /* ��size��һ���Ѷ��Ƴ���Ŀ�ȱĬ����ԭ��βԪ�����Ȼ������µĽڵ��������ӽڵ�Ĵ�С��ϵ������λ�õ����� */
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