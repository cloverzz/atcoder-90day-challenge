#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int N, K, L;
vector<int> A;


bool check(int T) {
    int cnt = 0, pre = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] - pre >= T && L - A[i] >= T) {
            cnt++;
            pre = A[i];
        }
    }
    return cnt >= K;
}

int main(){
    cin >> N >> L;
    cin >> K;
    A = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int l = 0, r = L;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l << endl;
    return 0;
}
