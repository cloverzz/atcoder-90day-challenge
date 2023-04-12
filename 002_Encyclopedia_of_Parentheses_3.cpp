#include <iostream>

using namespace std;

bool validate(string S) {
    int sum = 0;
    for (auto c : S) {
        if (c == '(') sum++;
        else sum--;
        if(sum < 0) return false;
    }
    return sum == 0;
}

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < (1 << N); i++) {
        string candidate = "";
        for (int j = N - 1; j >= 0; j--) {
            if (((i >> j) & 1) == 0) {
                candidate += "(";
            } else {
                candidate += ")";
            }
        }
        if (validate(candidate)) {
            cout << candidate << endl;
        }
    }
    return 0;
}