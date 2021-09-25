#include <iostream>
using namespace std;

void func(string s, char arr[], int i, int j, int n) {
    if (i == n) {
        arr[j] = '\0';
        cout << arr << endl;
        return;
    }
    arr[j] = s[i];
    func(s, arr, i+1, j+1, n);
    arr[j] = ' ';
    arr[j+1] = s[i];
    func(s, arr, i+1, j+2, n);
}

void addSpaces(string s) {
    int n = s.size();
    char arr[2*n];
    arr[0] = s[0];
    func(s, arr, 1, 1, n);
}

int main() {
    addSpaces("abc");
    addSpaces("abcef");
    return 0;
}
