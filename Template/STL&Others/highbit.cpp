// 求解一个数字最高位的1是第几位？

ll highbit(ll x) {
    // leftest digit of 1
    // nearly O(1)
    union { double a; int b[2]; };
    a = x;
    return (b[1] >> 20) - 1023;
}
