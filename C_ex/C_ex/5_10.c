// 定义一个哈希表的元素结构体，含有键值 key 和指向哈希表的指针
typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem; 

// 在哈希表中查找键值为 key 的元素，返回找到的元素指针
HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    // 使用 UT_hash_handle 库中的 HASH_FIND_INT 宏实现
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

// 在哈希表中添加键值为 key 的元素，如果已存在则返回 false，否则返回 true
bool hashAddItem(HashItem **obj, int key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    // 创建一个新的元素结构体，并设置键值
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    // 使用 UT_hash_handle 库中的 HASH_ADD_INT 宏将元素添加到哈希表中
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

// 释放哈希表 obj 中所有元素的内存
void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    // 使用 UT_hash_handle 库中的 HASH_ITER 宏遍历哈希表
    HASH_ITER(hh, *obj, curr, tmp) {
        // 使用 UT_hash_handle 库中的 HASH_DEL 宏从哈希表中删除元素
        HASH_DEL(*obj, curr);  
        // 释放元素的内存
        free(curr);
    }
}

// 解决问题的函数
int smallestRepunitDivByK(int k) {
    // 初始化余数为 1，长度为 1，并创建一个空的哈希表
    int resid = 1 % k, len = 1;
    HashItem *st = NULL;
    // 在哈希表中添加余数
    hashAddItem(&st, resid);
    // 当余数不为 0 时，重复以下操作
    while (resid != 0) {
        // 计算下一个余数
        resid = (resid * 10 + 1) % k;
        // 长度加 1
        len++;
        // 如果哈希表中已经存在该余数，则说明已经出现循环，直接返回 -1
        if (hashFindItem(&st, resid) != NULL) {
            hashFree(&st);
            return -1;
        }
        // 在哈希表中添加余数
        hashAddItem(&st, resid);
    }
    // 释放哈希表的内存，返回长度
    hashFree(&st);
    return len;
}
