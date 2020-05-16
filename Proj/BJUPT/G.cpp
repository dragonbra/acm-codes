#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

char s[N];
map <char, int> idx;

struct node {
    char c;
} ss[N];

bool cmp(node a, node b) {
    return idx[a.c] < idx[b.c];
}

int main() {

    cin >> s; int len = strlen(s);
    for (int i=0; i<len; i++) {
        ss[i].c = s[i];
    }

    for (int i=1;i<=26;i++) {
        char t;
        cin >> t;
        idx[t] = i;
    }

    sort(ss, ss+len, cmp);

    for (int i=0; i<len; i++) cout << ss[i].c;
    cout << endl;

    return 0;
}