#include <iostream>

using namespace std;

    int main(){
        int n = 10;
        int angka[n] = {1,4,3,5,7,2,12,23,9,34};
        int max = angka[0];
        int i = 1;
        
        while (i < n) {
            if (angka[i] > max)
                max = angka[i];
            i++;
        }

        cout << max;
        
    }