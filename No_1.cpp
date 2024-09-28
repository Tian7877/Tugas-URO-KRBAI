#include <iostream>
using namespace std;

void beepBoop(int n) {
    for (int i=0; i<=n; ++i){
        if(i%3 == 0 && i %5 == 0){
            cout<<"beepboop"<<endl;
        }
        else if (i%3==0){
            cout<<"beep"<<endl;
        }
        else if (i%5==0){
            cout<<"boop"<<endl;
        } else {
            cout<<i<<endl;
        }
    }
}

int main(){
    int bilangan;
    cout<<"Masukkan Bilangan : ";
    cin>> bilangan;
    beepBoop(bilangan);
    return 0;
}
