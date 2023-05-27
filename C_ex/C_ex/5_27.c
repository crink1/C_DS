//double* sampleStats(int* count, int countSize, int* returnSize) {
//    int n = countSize;
//    int total = 0;
//    for (int i = 0; i < n; i++) {
//        total += count[i];
//    }
//    double mean = 0.0;
//    double median = 0.0;
//    int minnum = 256;
//    int maxnum = 0;
//    int mode = 0;
//
//    int left = (total + 1) / 2;
//    int right = (total + 1) / 2 + ((total + 1) & 1);
//    int cnt = 0;
//    int maxfreq = 0;
//    long long sum = 0;
//    for (int i = 0; i < n; i++) {
//        sum += (long long)count[i] * i;
//        if (count[i] > maxfreq) {
//            maxfreq = count[i];
//            mode = i;
//        }
//        if (count[i] > 0) {
//            if (minnum == 256) {
//                minnum = i;
//            }
//            maxnum = i;
//        }
//        if (cnt < right && cnt + count[i] >= right) {
//            median += i;
//        }
//        if (cnt < left && cnt + count[i] >= left) {
//            median += i;
//        }
//        cnt += count[i];
//    }
//    mean = (double)sum / total;
//    median = median / 2.0;
//    double* ret = (double*)calloc(5, sizeof(double));
//    ret[0] = (double)minnum;
//    ret[1] = (double)maxnum;
//    ret[2] = mean;
//    ret[3] = median;
//    ret[4] = (double)mode;
//    *returnSize = 5;
//    return ret;
//}