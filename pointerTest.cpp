#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int p = 10;
    cout << p << endl;
    int * px = &p;
    cout << *px << endl;
    cout << px << endl;
    int ** ppx = &px;
    cout << **ppx << endl;
    cout << ppx << endl;
    return 0;
}