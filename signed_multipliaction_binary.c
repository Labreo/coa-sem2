#include <stdio.h>
#include <string.h>

void binadd(int x[4], int y[4], int result[4]);
void binsubtract(int x[4], int y[4], int result[4]);
void compliment1(int arr[4], int result[4]);
void compliment2(int arr[4], int result[4]);
void shiftleft(int a[4], int q[4]);

int main() {
    int count; 
    int result[4];
    int a[4] = {0, 0, 0, 0};

    printf("Enter number of bits (must be 4): ");
    scanf("%d", &count);

    if (count != 4) {
        printf("This program only supports 4-bit division.\n");
        return 1;
    }

    int m[4], q[4];
    for (int i = 0; i < 4; i++) {
        m[i] = q[i] = 0;
    }

    char input[100];
    printf("Enter M (4 bits): ");
    scanf("%s", input);
    if ((int)strlen(input) != 4) {
        printf("Invalid input. Enter exactly 4 bits.\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        m[i] = (input[i] == '1') ? 1 : 0;
    }

    printf("Enter Q (4 bits): ");
    scanf("%s", input);
    if ((int)strlen(input) != 4) {
        printf("Invalid input. Enter exactly 4 bits.\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        q[i] = (input[i] == '1') ? 1 : 0;
    }

    int steps = 4;
    while (steps != 0) {
        shiftleft(a, q);             
        binsubtract(a, m, result);   

        for (int i = 0; i < 4; i++) a[i] = result[i];

        if (a[0] == 0) {
            q[3] = 1;
        } else {
         
            binadd(a, m, result);
            for (int i = 0; i < 4; i++) a[i] = result[i];
            q[3] = 0;
        }
        --steps;
    }

    printf("\nQuotient (Q): ");
    for (int i = 0; i < 4; i++) printf("%d", q[i]);

    printf("\nRemainder (A): ");
    for (int i = 0; i < 4; i++) printf("%d", a[i]);

    printf("\n");
    return 0;
}

void compliment1(int arr[4], int result[4]) {
    for (int i = 0; i < 4; i++) {
        result[i] = arr[i] == 0 ? 1 : 0;
    }
}

void compliment2(int arr[4], int result[4]) {
    int one[4] = {0, 0, 0, 1};
    int temp[4];
    compliment1(arr, temp);
    binadd(temp, one, result);
}

void binadd(int x[4], int y[4], int result[4]) {
    int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int sum = x[i] + y[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}

void binsubtract(int x[4], int y[4], int result[4]) {
    int negy[4];
    compliment2(y, negy);    
    binadd(x, negy, result); 
}

void shiftleft(int a[4], int q[4]) {
    for (int i = 0; i < 3; i++) {
        a[i] = a[i + 1];
    }
    a[3] = q[0];  
    for (int i = 0; i < 3; i++) {
        q[i] = q[i + 1];
    }
    q[3] = 0;     
}
