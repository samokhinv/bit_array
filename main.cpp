//
// Created by Valentin on 09.03.2018.
//
#include "BitArray.h"

using namespace std;

int main(){
    TestAll();

    BitArray check(10);
    for (int i = 0; i < 10; i++){
        check.assign(i, i%2);
    }

    for (int i = 0; i < 10; i++){
        cout << check.at(i) << endl;
    }

    check.assign(3, false);

    cout << endl;

    for (int i = 0; i < 10; i++){
        cout << check.at(i) << endl;
    }
    return 0;
}