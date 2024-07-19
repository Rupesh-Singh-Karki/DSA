//https://www.youtube.com/watch?v=K8mJ27S72v0

#include<iostream>
using namespace std;

int fastExpo(int a, int b ) {

    int res = 1;

    while(b > 0) {

        if(b&1) { //checking agar 1 agaya to x^n sai multiply karenge
            //odd
            res = res*a;
        }
        b = b >> 1;  //divide by 2
        a = a * a; //increasing powerr
    }
    return res;
}

int main() {

    int a,b;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b;

    cout << "Answer is: " << fastExpo(a,b) << endl;

    return 0;
}