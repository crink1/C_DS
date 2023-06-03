//static inline int min(int a, int b) {
//    return a < b ? a : b;
//}
//
//static inline int max(int a, int b) {
//    return a > b ? a : b;
//}
//
//int maxRepOpt1(char* text) {
//    int len = strlen(text);
//    int count[26];
//    memset(count, 0, sizeof(count));
//    for (int i = 0; i < len; i++) {
//        count[text[i] - 'a']++;
//    }
//
//    int res = 0;
//    for (int i = 0; i < len; ) {
//        // step1: �ҳ���ǰ������һ�� [i, j)
//        int j = i;
//        while (j < len && text[j] == text[i]) {
//            j++;
//        }
//        int cur_cnt = j - i;
//
//        // step2: �����һ�γ���С�ڸ��ַ����ֵ�����������ǰ�������п�λ����ʹ�� cur_cnt + 1 ���´�
//        if (cur_cnt < count[text[i] - 'a'] && (j < len || i > 0)) {
//            res = max(res, cur_cnt + 1);
//        }
//
//        // step3: �ҵ���һ�κ�����֮���һ����ͬ�ַ�����һ�� [j + 1, k)������������� k = j + 1 
//        int k = j + 1;
//        while (k < len && text[k] == text[i]) {
//            k++;
//        }
//        res = max(res, min(k - i, count[text[i] - 'a']));
//        i = j;
//    }
//    return res;
//}