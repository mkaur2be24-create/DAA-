#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else
        return c;
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = -9999;

    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = -9999;

    for (int i = m + 1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;

    return max(
        maxSubArraySum(arr, l, m),
        maxSubArraySum(arr, m + 1, h),
        maxCrossingSum(arr, l, m, h));
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;

    cout << "Maximum subarray sum is: "
         << maxSubArraySum(arr, 0, n - 1);

    return 0;
}