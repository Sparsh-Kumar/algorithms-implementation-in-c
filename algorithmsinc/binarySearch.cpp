

#include <iostream>
#include <cmath>

using namespace std;

int BinarySearch (int numArray [], int start, int end, int item) {

    //cout<<"[*] start = "<<start<<", end = "<<end<<" item = "<<item<<endl;
    if ((start < 0) || (end < 0) || (end < start)) {
        return -1;
    } 
    int mid = floor ((start + end) / 2);
    if (numArray [mid] == item) {
        return mid;
    } else if (numArray [mid] < item) {
        return BinarySearch (numArray, mid + 1, end, item);
    } else if (numArray [mid] > item) {
        return BinarySearch (numArray, start, mid - 1, item);
    }
    return -1;

}

int main (int argc, char *argv []) {

    int numArray [] = {
        1,
        10,
        30,
        32,
        45,
        67,
        89,
        103,
        401
    };

    int start = 0;
    int end = sizeof (numArray) / sizeof (int);
    int item = 103;
    int index = BinarySearch (numArray, start, end - 1, item);
    cout<<"The value at which the given number exists is "<<index<<endl;
}
