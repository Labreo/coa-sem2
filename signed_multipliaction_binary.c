#include <stdio.h>
void compliment1(int arr[4], int result[4]);
void compliment2(int arr[4], int result[4]);
void binadd(int x[4], int y[4], int result[4]);
void ari_shift_right(int x[4], int y[4], int z[1]);
void binsubtract(int x[4], int y[4], int negb[4]);

int main()
{
    char multplicand[5];
    char multplier[5];
    int count = 4;
    int m_comp2[4];
    int q_comp2[4];
    int m[4];
    int a[4] = {0, 0, 0, 0};
    int q[4];
    int q1[1]={0};
    int result[4];

    printf("Enter multiplicand number: ");
    scanf("%s", multplicand);

    printf("Enter multiplier number: ");
    scanf("%s", multplier);

    for (int i = 0; i < 4; i++)
    {
        m[i] = multplicand[i] - '0';
        q[i] = multplier[i] - '0';
    }

    
    compliment2(q, q_comp2);
    while (count != 0)
    {
        if (q_comp2[0] == 1 && q1[0] == 0)
        {
            binsubtract(a, m, result);

            for (int i = 0; i < 4; i++)
            {
                a[i] = result[i];
            }
            ari_shift_right(a,q_comp2,q1);
        }
        else if (q_comp2[0] == 0 && q1[0] == 1)
        {
            binadd(a, m, result);

            for (int i = 0; i < 4; i++)
            {
                a[i] = result[i];
            }
            ari_shift_right(a,q_comp2,q1);
        }
        else if (q_comp2[0] == 0 && q1[0] == 0)
        {
           
            ari_shift_right(a,q_comp2,q1);
        }
        else if(q_comp2[0]==1 && q1[0]==1)
          {
            ari_shift_right(a,q_comp2,q1);
        }
        --count;
    }
    printf("\nResult: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d", a[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d", q_comp2[i]);
    }
    printf("\n%d",q1[0]);

    return 0;
}

void compliment1(int arr[4], int result[4])
{
    for (int i = 0; i < 4; i++)
    {
        result[i] = arr[i] == 0 ? 1 : 0;
    }
}
// add 1 to comp1
void compliment2(int arr[4], int result[4])
{
    int one[4] = {0, 0, 0, 1};
    int temp[4];

    compliment1(arr, temp);
    binadd(temp, one, result);
}

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
// x=a y=q z=q-1
void ari_shift_right(int x[4], int y[4], int z[1])
{
    z[0] = y[3];

    for (int i = 3; i > 0; i--)
    {
        y[i] = y[i - 1];
    }
    y[0] = x[3];
    x[0]=x[0];
    for (int i = 3; i > 0; i--)
    {
        x[i] = x[i - 1];
    }
    
}

void binsubtract(int x[4], int y[4], int result[4])
{
    int negy[4];
    compliment2(y, negy);
    binadd(x, negy, result);
}