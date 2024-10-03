#include <bits/stdc++.h>

using namespace std;

int concentrar_chakra(int x, int y);

pair<int, int> tesoro(int n, int m) {
    int lX = 1, rX = n;
    int lY = 1, rY = m;
    int mX, mY;
    while (true) {
        mX = (lX + rX + 1) / 2;
        mY = (lY + rY) / 2;
        if (rX - lX <= 2 || rY - lY <= 2) break;
        int cuadrante = concentrar_chakra(mX, mY);
        if (rX - lX <= 3 && rY - lY <= 3) {
            if (cuadrante == 1 || cuadrante == 3) mY++;
            if (cuadrante == 0 || cuadrante == 1) mX--;
            break;
        }
        if (cuadrante == 1 || cuadrante == 3) {
            lY = mY + 1;
        } else {
            rY = mY;
        }
        if (cuadrante == 2 || cuadrante == 3) {
            lX = mX;
        } else {
            rX = mX - 1;
        }
        if (lX > 1) lX--;
        if (rX < n) rX++;
        if (lY > 1) lY--;
        if (rY < m) rY++;
    }
    return {mX, mY};
}