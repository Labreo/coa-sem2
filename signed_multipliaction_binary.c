#include <stdio.h>

void compliment1(int arr[4], int result[4]);
void compliment2(int arr[4], int result[4]);
void binadd(int x[4], int y[4], int result[4]);
void ari_shift_right(int a[4], int q[4], int q1[1]);
void binsubtract(int x[4], int y[4], int result[4]);

int main() {
    char multiplicand_str[5];
    char multiplier_str[5];
    int count = 4;

    int m[4];                  
    int a[4] = {0, 0, 0, 0};
    int q[4];                
    int q1[1] = {0};          
    int result[4];             

    
    printf("Enter multiplicand (4 bits): ");
    scanf("%s", multiplicand_str);
    printf("Enter multiplier (4 bits): ");
    scanf("%s", multiplier_str);

    
    for (int i = 0; i < 4; i++) {
        m[i] = multiplicand_str[i] - '0';
        q[i] = multiplier_str[i] - '0';
    }

   
    while (count > 0) {
        if (q[3] == 1 && q1[0] == 0) {
            
            binsubtract(a, m, result);
            for (int i = 0; i < 4; i++) a[i] = result[i];
        }
        else if (q[3] == 0 && q1[0] == 1) {
           
            binadd(a, m, result);
            for (int i = 0; i < 4; i++) a[i] = result[i];
        }
       
        ari_shift_right(a, q, q1);
        count--;
    }

    printf("\nResult: ");
    for (int i = 0; i < 4; i++) printf("%d", a[i]);
    for (int i = 0; i < 4; i++) printf("%d", q[i]);
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


void ari_shift_right(int a[4], int q[4], int q1[1]) {
    int sign = a[0];      
    q1[0] = q[3];         

    for (int i = 3; i > 0; i--) {
        q[i] = q[i - 1];
    }
    q[0] = a[3];

   
    for (int i = 3; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = sign;          
}

void binsubtract(int x[4], int y[4], int result[4]) {
    int negy[4];
    compliment2(y, negy);    
    binadd(x, negy, result); 
}
