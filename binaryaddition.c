#include <stdio.h>

void binadd(int x[4], int y[4], int result[4]);
void compliment1(int arr[4], int result[4]);
void compliment2(int arr[4], int result[4]);
void binsubtract(int x[4], int y[4], int negb[4]);

int main()
{
    int a[4], b[4];
    int answeradd[4] = {0, 0, 0, 0};
    int answersub[4] = {0, 0, 0, 0};
    printf("Enter first number: ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter second number: ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &b[i]);
    }

    binadd(a, b, answeradd);

    printf("\nResult addition (4-bit binary): ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d", answeradd[i]);
    }

    binsubtract(a, b, answersub);
    printf("\nResult subtraction (4-bit binary): ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d", answersub[i]);
    }

    return 0;
}
/*Get the no do mod%2 of the result reminder 1 or 0 suppose then sum=2 then carry=1 which holds
 same for sum=3 carry=1 since it is int */
void binadd(int x[4], int y[4], int result[4])
{
    int carry = 0;
    for (int i = 3; i >= 0; i--)
    {
        int sum = x[i] + y[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}
//Ulta then just change
void compliment1(int arr[4], int result[4])
{
    for (int i = 0; i < 4; i++)
    {
        result[i] = arr[i] == 0 ? 1 : 0;
    }
}
//add 1 to comp1
void compliment2(int arr[4], int result[4])
{
    int one[4] = {0, 0, 0, 1};
    int temp[4];

    compliment1(arr, temp);
    binadd(temp, one, result);
}

//get comp2 and subtract
void binsubtract(int x[4], int y[4], int result[4])
{
    int negy[4];
    compliment2(y, negy);
    binadd(x, negy, result);
}
/*111+101= users enter convert dec to binary 4)additon subtraction 1's compliment 2's compliment 2's complimwnt 8 bit represemtatipn  accept 2 compliment 4bit 5 bit pass 2 compliment
pass to 1's compliment
add 2 no'a funciton
subtract 2's no
call 2nd second pass to 2's compliment of it
call 1's compliment in 2's compliment
*/