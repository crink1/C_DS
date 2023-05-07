int numPairsDivisibleBy60(int* time, int timeSize) {
    int cnt[60];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < timeSize; i++) {
        cnt[time[i] % 60]++;
    }
    long long res = 0;
    for (int i = 1; i < 30; i++) {
        res += cnt[i] * cnt[60 - i];
    }            
    res += (long long)cnt[0] * (cnt[0] - 1) / 2 + (long long)cnt[30] * (cnt[30] - 1) / 2;
    return (int)res;
}
