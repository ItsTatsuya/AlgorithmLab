/** change making problem*/
#include <iostream>
using namespace std;

void changeMaking(int n, int d[], int c[], int s[]) {
    int i, j, min, coin;
    c[0] = 0;
    s[0] = 0;
    for (j = 1; j <= n; j++) {
        min = j;
        for (i = 1; i <= 3; i++) {
            if (d[i] <= j && 1 + c[j - d[i]] < min) {
                min = 1 + c[j - d[i]];
                coin = i;
            }
        }
        c[j] = min;
        s[j] = coin;
    }
}

void printChange(int n, int d[], int s[]) {
    int a[100], k = 0;
    while (n > 0) {
        a[k++] = d[s[n]];
        n = n - d[s[n]];
    }
    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n = 15;
    int d[4] = {0, 1, 5, 10};
    int c[100], s[100];
    changeMaking(n, d, c, s);
    printChange(n, d, s);
    return 0;
}
