#include <bits/stdc++.h>
using namespace std;

string m, n, s;

int main()
{
    freopen("code.inp", "r", stdin);
    freopen("code.out", "w", stdout);
    cin >> m >> n;
    cin.ignore();
    int i = 0, j = 0;
    while (i < m.size() && j < n.size()) {
        if (m[i] < n[j]) {
            s += n[j++];
        } else if (n[j] < m[i]) {
            s += m[i++];
        } else { // m[i] == n[j]
            int ti = i + 1;
            int tj = j + 1;
            while (ti < m.size() && tj < n.size() && m[ti] == n[tj] && m[ti] >= m[ti - 1]) {
                ti++;
                tj++;
            }
            s += m.substr(i, ti - i);
            if (m[ti] < n[tj]) {
                j = tj;
            } else if (m[ti] > n[tj]) {
                i = ti;
            } else { // m[ti] == n[tj]
                int tti = ti;
                int ttj = tj;
                while (m[ti] == n[tj]) {
                    ti++;
                    tj++;
                }
                if (m[ti] < n[tj]) {
                    j = ttj;
                } else {
                    i = tti;
                }
            }
        }
    }
    if (i < m.size())
        s += m.substr(i);
    if (j < n.size())
        s += n.substr(j);
    cout << s;
}
