// #include <bits/stdc++.h>
// using namespace std;
// int equilibrium_index(int *a, int n)
// {
//     int left_sum = 0, right_sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // left_sum = 0;
//         for (int j = 0; j < i + 1; j++)
//         {
//             left_sum += a[i];
//         }
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             right_sum += a[i];
//         }
//         if (left_sum == right_sum)
//         {
//             return i;
//         }
//     }
// }
// int main()
// {
//     int n;
//     cout << "N-> ";
//     cin >> n;
//     cout << endl;
//     int *a = new int[n]; // Allocate memory for the array

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int equi = equilibrium_index(a, n);
//     cout << "Equilibirum index -> " << equi;
//     return 0;
// }
#include <iostream>
#include <vector>

using namespace std;
int get_equi(const vector<int> &v)
{
    int n = v.size();
    int left_sum = 0;
    int right_sum = 0;
    for (int i = 0; i < n; i++)
    {
        right_sum += v[i];
    }
    for (int i = 0; i < n; i++)
    {
        right_sum -= v[i];
        if (left_sum == right_sum)
        {
            return i;
        }
        left_sum += v[i];
    }
    return -1;
}
int findEquilibriumIndex(const vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    int leftSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; ++i) {
        totalSum += nums[i];
    }

    for (int i = 0; i < n; ++i) {
        // Calculate the right sum for the current equilibrium index
        int rightSum = totalSum - leftSum - nums[i];

        // Check if the equilibrium condition is met
        if (leftSum == rightSum) {
            return i; // Found equilibrium index
        }

        // Update the leftSum for the next index
        leftSum += nums[i];
    }

    // If no equilibrium index found, return -1
    return -1;
}

int main() {
    // Example usage
    vector<int> nums = {-7, 1, 5, 2, -4, 3, 0};
    int equilibriumIndex = findEquilibriumIndex(nums);

    if (equilibriumIndex != -1) {
        cout << "Equilibrium index found at index " << equilibriumIndex << endl;
    } else {
        cout << "No equilibrium index found in the array." << endl;
    }

    return 0;
}
