const int LOG = 16;

typedef struct {
    int** ancestors;
    int n;
} TreeAncestor;

TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize) {
    TreeAncestor* obj = (TreeAncestor*)malloc(sizeof(TreeAncestor));
    obj->ancestors = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        obj->ancestors[i] = (int*)malloc(sizeof(int) * LOG);
        memset(obj->ancestors[i], 0xff, sizeof(int) * LOG);
    }
    for (int i = 0; i < n; i++) {
        obj->ancestors[i][0] = parent[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            if (obj->ancestors[i][j - 1] != -1) {
                obj->ancestors[i][j] = obj->ancestors[obj->ancestors[i][j - 1]][j - 1];
            }
        }
    }
    return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k) {
    for (int j = 0; j < LOG; j++) {
        if ((k >> j) & 1) {
            node = obj->ancestors[node][j];
            if (node == -1) {
                return -1;
            }
        }
    }
    return node;
}

void treeAncestorFree(TreeAncestor* obj) {
    for (int i = 0; i < obj->n; i++) {
        free(obj->ancestors[i]);
    }
    free(obj->ancestors);
    free(obj);
}