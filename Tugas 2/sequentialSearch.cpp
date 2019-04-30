#include <iostream>

using namespace std;

main(){
    int arr_n[10] = {1,2,5,6,7,9,12,14,16,23};
    int y = 5;
    bool found;
    int i = 0;
    int idx = 0;

    found = false;
    while (i < 10 && !found) {
        if (arr_n[i] == y)
            found = true;
        else
            i++;
    }

    if (found) {
        idx = i;
        cout << "elemen ke-" << idx;
    } else
        cout << 0;

}