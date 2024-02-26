#include <bits/stdc++.h>
 
using namespace std;
 
using vd = vector<double>;
using Mat = vector<vd>;
 
const int N = 8, T = 64;
 
const int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
 
#define idx(r, c) (r)*N+(c)
 
bool valid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}
 
const int MOVES = 4;
 
void calc(int r, int c, Mat &m) {
    int validMoves = 0;
    for (int i = 0; i < MOVES; i++) {
        if (valid(r + dr[i], c + dc[i])) validMoves++;
    }
    double p = 1.0 / validMoves;
    for (int i = 0; i < MOVES; i++) {
        if (valid(r + dr[i], c + dc[i])) m[idx(r, c)][idx(r + dr[i], c + dc[i])] = p;
    }
}
 
Mat build() {
	Mat m(T, vd(T, 0.0));
	for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            calc(r, c, m);
        }
    }
	return m;
}
 
 
Mat mul(Mat a, Mat b) {
	Mat c(T, vd(T, 0.0));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            for (int k = 0; k < T; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
	return c;
}
 
Mat binpow(Mat a, int k) {
    Mat res(T, vd(T, 0.0));
    for (int i = 0; i < T; i++) {
        res[i][i] = 1.0;
    }
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
	return res;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int k;
	cin >> k;
	
    Mat a = build();
	Mat m = binpow(a, k);
	double res = 0.0;
	for (int i = 0; i < T; i++) {
		double p = 1.0;
		for (int j = 0; j < T; j++) {
            p *= 1.0 - m[j][i];
        }
		res += p;
	}
	cout << setprecision(6) << fixed << res << '\n';
	
	return 0;
}
