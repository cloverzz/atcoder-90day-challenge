#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> M(H, vector<int>(W, 0));
    vector<int> row_sum(H, 0), col_sum(W, 0);
    for (int i = 0; i < H; i++) {
        int sum = 0;
        for (int j = 0; j < W; j++) {
            cin >> M[i][j];
            sum += M[i][j];
        }
        row_sum[i] = sum;
    }
    for (int j = 0; j < W; j++) {
        int sum = 0;
        for (int i = 0; i < H; i++) {
            sum += M[i][j];
        }
        col_sum[j] = sum;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << row_sum[i] + col_sum[j] - M[i][j];
            if (j != W - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}