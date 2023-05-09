bool check(const char *time) {
    int hh = atoi(time);
    int mm = atoi(time + 3);
    if (hh < 24 && mm < 60) {
        return true;
    } else {
        return false;
    }
}

void dfs(char *time, int pos, int *res) {
    if (time[pos] == '\0') {
        if (check(time)) {
            (*res)++;
        }
        return;
    }
    if (time[pos] == '?') {
        for (int i = 0; i <= 9; i++) {
            time[pos] = '0' + i;
            dfs(time, pos + 1, res);
            time[pos] = '?';
        }
    } else {
        dfs(time, pos + 1, res);
    }
}

int countTime(char * time){
    int res = 0;
    dfs(time, 0, &res);
    return res;
}
