#include <stdio.h>
void binadd(int x[4], int y[4], int result[4], int c[1]);
void shiftright(int c[1], int a[4], int q[4]);
int main() {
    int c[1] = {0};
    int a[4] = {0,0,0,0};
    int binresult[4] = {0,0,0,0};
    char multiplicand[5];
    char multiplier[5];
    int count = 4;
    int m[4], q[4];
    printf("Enter multiplicand number: ");
    scanf("%s", multiplicand);
    printf("Enter multiplier number: ");
    scanf("%s", multiplier);
    for (int i = 0; i < 4; i++) {
        m[i] = multiplicand[i] - '0';
        q[i] = multiplier[i] - '0';
    }
    while (count != 0) {
        if (q[3] == 1) {
            binadd(a, m, binresult, c);
            for (int i = 3; i >= 0; i--) {
                a[i] = binresult[i];
            }
            shiftright(c, a, q);
        } else {
            shiftright(c, a, q);
        }
        count = count - 1;
    }
    printf("\nResult (8-bit binary): ");
    for (int i = 0; i < 4; i++) {
        printf("%d", a[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%d", q[i]);
    }
    printf("\n");
    return 0;
}
void binadd(int x[4], int y[4], int result[4], int c[1]) {
    int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int sum = x[i] + y[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
    c[0] = carry;
}
void shiftright(int c[1], int a[4], int q[4]) {
    int last_a = a[3];
    for (int i = 3; i > 0; i--) {
        q[i] = q[i-1];
    }
    q[0] = last_a;
    int temp_a0 = c[0];
    for (int i = 3; i > 0; i--) {
        a[i] = a[i-1];
    }
    a[0] = temp_a0;
    c[0] = 0;
}
