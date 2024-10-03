#include <bits/stdc++.h>

using namespace std;

const int K = 7, N = 102;

int esc[K][N], sig[K][N], mov[K][N];

void imprimir(int arr[K][N]) {
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void instrucciones(int fase, int diff, int sigFase, int dir) {
    for (int i = 0; i < N; i++) {
        esc[fase][i] = max(min(i - 1 + diff, 100), -1);
        sig[fase][i] = sigFase;
        mov[fase][i] = dir;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    const int CHEQUEO = 0, VOLVER = 1, RESTAR = 2, SUMAR = 3, RETROCEDER = 4, RESET = 5, BUSCAR_RESPUESTA = 6;
    
    instrucciones(CHEQUEO, 0, VOLVER, -1);
    sig[CHEQUEO][0] = BUSCAR_RESPUESTA;
    sig[CHEQUEO][1] = CHEQUEO;
    mov[CHEQUEO][0] = mov[CHEQUEO][1] = 1;
    
    instrucciones(VOLVER, 0, VOLVER, -1);
    sig[VOLVER][0] = RESTAR;
    mov[VOLVER][0] = 1;
    
    instrucciones(RESTAR, -1, RESTAR, 1);
    esc[RESTAR][1] = 0;
    sig[RESTAR][0] = SUMAR;
    
    instrucciones(SUMAR, 1, RETROCEDER, -1);
    
    instrucciones(RETROCEDER, 0, RESET, -1);
    
    instrucciones(RESET, 0, RESET, -1);
    sig[RESET][0] = CHEQUEO;
    mov[RESET][0] = 1;
    
    instrucciones(BUSCAR_RESPUESTA, 1, -1, 1);
    esc[BUSCAR_RESPUESTA][0] = -1;
    sig[BUSCAR_RESPUESTA][0] = BUSCAR_RESPUESTA;
    
    cout << K << "\n\n";
    imprimir(esc);
    imprimir(sig);
    imprimir(mov);
    
    
    return 0;
}