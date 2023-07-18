#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p1(10, 20);
    pair<int, int> p3;
    pair<int, string> p2(10, "string");
    cout << p1.second << " <- it is 2nd value \n";
    cout << p1.first << " <- it is 1st value \n";
    cout << p2.first << " <- it is 1st value \n";
    cout << p2.second << " <- it is 2nd value \n";
    cout << p3.first << " <- it is 1st value \n";
    cout << p3.second << " <- it is 2nd value \n";
    p3.second = 100;
    cout << p3.second << " <- it is 2nd value \n";

    pair<int, int> pair1(1, 13), pair2(1, 12), pair3(12, 12), pair4(12, 13);
    cout << " \n1 and 2 \n";
    cout << (pair2 == pair1) << " ";
    cout << (pair2 != pair1) << " ";
    cout << " \n3 and 1 \n";
    cout << (pair3 == pair1) << " ";
    cout << (pair3 != pair1) << " ";
    cout << " \n4 and 1 \n ";
    cout << (pair4 == pair1) << " ";
    cout << (pair4 != pair1) << " ";
    cout << "\n3 and 4 \n";
    cout << (pair3 == pair4) << " ";
    cout << (pair3 != pair4) << " ";
    cout << "\n3 and 2 \n";
    cout << (pair3 == pair2) << " ";
    cout << (pair3 != pair2) << " ";
    cout << "\n4 and 2 \n";
    cout << (pair4 == pair2) << " ";
    cout << (pair4 != pair2) << " ";
    return 0;
}