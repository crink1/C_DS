//#include<stdio.h>
//
//#define ADD(X,Y) ((X)+(Y))
//
//int main()
//{
//	int a = ADD(2, 3);
//	printf("%d", a);
//}
//
//
//typedef struct {
//    int key;
//    UT_hash_handle hh;
//} HashItem;
//
//HashItem* hashFindItem(HashItem** obj, int key) {
//    HashItem* pEntry = NULL;
//    HASH_FIND_INT(*obj, &key, pEntry);
//    return pEntry;
//}
//
//bool hashAddItem(HashItem** obj, int key) {
//    if (hashFindItem(obj, key)) {
//        return false;
//    }
//    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = key;
//    HASH_ADD_INT(*obj, key, pEntry);
//    return true;
//}
//
//void hashFree(HashItem** obj) {
//    HashItem* curr = NULL, * tmp = NULL;
//    HASH_ITER(hh, *obj, curr, tmp) {
//        HASH_DEL(*obj, curr);
//        free(curr);
//    }
//}
//
//int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
//    int dirs[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
//    int px = 0, py = 0, d = 1;
//    HashItem* mp = NULL;
//    for (int i = 0; i < obstaclesSize; i++) {
//        hashAddItem(&mp, obstacles[i][0] * 60001 + obstacles[i][1]);
//    }
//    int res = 0;
//    for (int i = 0; i < commandsSize; i++) {
//        int c = commands[i];
//        if (c < 0) {
//            d += c == -1 ? 1 : -1;
//            d %= 4;
//            if (d < 0) {
//                d += 4;
//            }
//        }
//        else {
//            for (int i = 0; i < c; i++) {
//                if (hashFindItem(&mp, (px + dirs[d][0]) * 60001 + py + dirs[d][1])) {
//                    break;
//                }
//                px += dirs[d][0];
//                py += dirs[d][1];
//                res = fmax(res, px * px + py * py);
//            }
//        }
//    }
//    hashFree(&mp);
//    return res;
//}
