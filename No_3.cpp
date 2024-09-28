#include <iostream>
using namespace std;


int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {  
        length++;
    }
    return length; 
}


bool isPalindrome(const char str[]) {
    int n = stringLength(str);  
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false; 
        }
    }
    return true;  
}

int main() {
    char kata[100];//asumsikan tidak ada kata yang lebih dari 99 huruf 
    cout << "Masukkan kata: ";
    cin >> kata; 
    if (isPalindrome(kata)) {
        cout << kata << " adalah palindrom" << endl;
    } else {
        cout << kata << " bukan palindrom" << endl;
    }
    return 0;
}
