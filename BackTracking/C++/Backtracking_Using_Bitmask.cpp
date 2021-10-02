#include <bits/stdc++.h>
using namespace std;

#define d (1 << n) - 1
int cnt = 0;

void solve(int row, int left, int right, int n)
{
    if(row == d)
    {
        cnt++;
        return;
    }
    int pos = d & ~(left | row | right);
    while(pos > 0)
    {
        int bit = pos & (-pos);
        pos -= bit;
        solve(row | bit, (left | bit) << 1, (right | bit) >> 1, n);
    }
}

int main() {
    int n;
    cin >> n;
    solve(0, 0, 0, n);
    cout << cnt;
}