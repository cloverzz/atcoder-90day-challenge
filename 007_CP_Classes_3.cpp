#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int b;
        cin >> b;
        int p = lower_bound(A.begin(), A.end(), b) - A.begin();
        if (p == 0) {
            cout << abs(b - A[p]) << endl;
        } else if (p == A.size()) {
            cout << abs(b - A[p - 1]) << endl;
        } else {
            cout << min(abs(b - A[p]), abs(b - A[p - 1])) << endl;
        }
    }
    return 0;
}