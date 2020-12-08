int highbit(int x) {
    // leftest digit of 1
    // nearly O(1)
    union { double a; int b[2]; };
    a = x;
    return (b[1] >> 20) - 1023;
}

{   // 我爱发明
    vector<long long> p(32);

    void init() {
        p[0] = 1;
        for (int i=1; i<=31; i++) p[i] = p[i-1] * 2;
    }

    int highbit(int x) {
        return upper_bound(p.begin(), p.end(), x) - p.begin() - 1;
    }
}