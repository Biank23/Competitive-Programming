#include "transfer.h"

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

vector<int> get_attachment(vector<int> source) {
	int x = 0;
    for (int i = 0; i < sz(source); i++) {
        if (source[i]) x ^= i + 1;
    }
    vector<int> code;
    int log = sz(source) == 63 ? 6 : 8;
    for (int i = 0; i < log; i++) {
        code.push_back(x >> i & 1);
    }
    code.push_back(__builtin_parity(x));
    return code;
}

vector<int> retrieve(vector<int> data) {
    int cut = sz(data) == 70 ? 63 : 255;
    vector<int> source(begin(data), begin(data) + cut);
    vector<int> code(begin(data) + cut, end(data));
    int x = 0;
    for (int i = 0; i < sz(code) - 1; i++) {
        if (code[i]) x |= 1 << i;
    }
    if (code.back() != __builtin_parity(x)) {
        return source;
    }
    for (int i = 0; i < sz(source); i++) {
        if (source[i]) x ^= i + 1;
    }
    if (x != 0) source[x - 1] ^= 1;
    return source;
}
