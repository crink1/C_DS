//int minNumberOfFrogs(char* croakOfFrogs) {
//    int len = strlen(croakOfFrogs);
//    if (len % 5 != 0) {
//        return -1;
//    }
//    int res = 0, frogNum = 0;
//    int cnt[4], map[26];
//    memset(cnt, 0, sizeof(cnt));
//    map['c' - 'a'] = 0;
//    map['r' - 'a'] = 1;
//    map['o' - 'a'] = 2;
//    map['a' - 'a'] = 3;
//    map['k' - 'a'] = 4;
//    for (int i = 0; i < len; i++) {
//        char c = croakOfFrogs[i];
//        int t = map[c - 'a'];
//        if (t == 0) {
//            cnt[t]++;
//            frogNum++;
//            if (frogNum > res) {
//                res = frogNum;
//            }
//        }
//        else {
//            if (cnt[t - 1] == 0) {
//                return -1;
//            }
//            cnt[t - 1]--;
//            if (t == 4) {
//                frogNum--;
//            }
//            else {
//                cnt[t]++;
//            }
//        }
//    }
//    if (frogNum > 0) {
//        return -1;
//    }
//    return res;
//}