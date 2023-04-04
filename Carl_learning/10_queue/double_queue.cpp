
// import the package for double queue
#include <deque>
#include <iostream>
using namespace std;
// clarify a double ends queue
int main()
{
    deque<int> dq;
    // add some element to the dq from the front
    dq.push_front(1);
    dq.push_front(2);
    // add 3 elements to the dq from the back
    dq.push_back(3);
    dq.push_back(4);
    // cout all the elements in the dq via iterator
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
        cout << *it << " ";
    long long int a = 345;
    // // get the first 8 bits of a and store it in b
    // int b = a & 0xff;
    // use the memcpy function to copy the first 8 bits of a to b
    // memcpy(&b, &a, 1);
    char b;
    b = *(char *)&a;
    cout << "The difference between the b and a & 0xff is: " << (b == (a & 0xff)) << endl;
    return 0;
}