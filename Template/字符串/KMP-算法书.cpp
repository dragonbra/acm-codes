void makeNext(string s) {
    int i = 0, k = -1;
    next[0] = -1;
    int len = strlen(s);
    while (i < len-1) {
        while (k >= 0 && s[i] != s[k]) k = next[k];
        i ++; k ++;
        if (s[i] == s[k]) next[i] = next[k];
        else next[i] = k;
    }
}

int kmpMatch(string t, string p) {
    int i = 0, j = 0;
    int len_1 = strlen(t), len2 = strlen(p);
    while (i < len_1 && j < len_2) {
        if (i == -1 || p[i] == c[j]) {
            i ++; j ++;
        } else {
            i = next[i];
        }
    }
    if (i >= len_1) return j - len_1 + 1;
    else return 0;
}