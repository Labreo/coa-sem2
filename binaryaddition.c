#include <stdio.h>
#include <string.h>

void binadd(int x[], int y[], int result[], int count);
void compliment1(int arr[], int result[], int count);
void compliment2(int arr[], int result[], int count);
void binsubtract(int x[], int y[], int result[], int count);

int main()
{
    int count;
    printf("Enter number of bits: ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("Invalid bit size.\n");
        return 1;
    }

    int a[count], b[count], answer[count];
    for (int i = 0; i < count; i++) {
        a[i] = b[i] = answer[i] = 0;
    }

    char input[100];
    printf("Enter first number (%d bits): ", count);
    scanf("%s", input);
    if ((int)strlen(input) != count) {
        printf("Invalid input. Enter exactly %d bits.\n", count);
        return 1;
    }
    for (int i = 0; i < count; i++) {
        a[i] = (input[i] == '1') ? 1 : 0;
    }

    printf("Enter second number (%d bits): ", count);
    scanf("%s", input);
    if ((int)strlen(input) != count) {
        printf("Invalid input. Enter exactly %d bits.\n", count);
        return 1;
    }
    for (int i = 0; i < count; i++) {
        b[i] = (input[i] == '1') ? 1 : 0;
    }

    int choice;
    printf("Choose operation:\n1. Addition\n2. Subtraction\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        binadd(a, b, answer, count);
        printf("\nResult addition (%d-bit binary): ", count);
    }
    else if (choice == 2)
    {
        binsubtract(a, b, answer, count);
        printf("\nResult subtraction (%d-bit binary): ", count);
    }
    else
    {
        printf("Invalid choice.\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d", answer[i]);
    }
    printf("\n");

    return 0;
}

void binadd(int x[], int y[], int result[], int count)
{
    int carry = 0;
    for (int i = count - 1; i >= 0; i--)
    {
        int sum = x[i] + y[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}

void compliment1(int arr[], int result[], int count)
{
    for (int i = 0; i < count; i++)
    {
        result[i] = arr[i] == 0 ? 1 : 0;
    }
}

void compliment2(int arr[], int result[], int count)
{
    int one[count];
    int temp[count];
    for (int i = 0; i < count; i++) {
        one[i] = 0;
        temp[i] = 0;
    }
    one[count - 1] = 1;
    compliment1(arr, temp, count);
    binadd(temp, one, result, count);
}

void binsubtract(int x[], int y[], int result[], int count)
{
    int negy[count];
    for (int i = 0; i < count; i++) negy[i] = 0;
    compliment2(y, negy, count);
    binadd(x, negy, result, count);
}
