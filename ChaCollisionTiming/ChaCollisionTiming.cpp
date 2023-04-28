#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {
    srand(time(0));
    double first= 0;
    for (int i = 0; i < 1000; i++) {
        LinearTable l;
        for (int j = 1; j <= 29; j++) {
            l.add(rand() % 100 + 1, j);
        }
        first += l.getFirstCollsion();
    }
    first /= 1000;
    cout << "Linear inserts before first collision: " << first << endl;

    first = 0;
    for (int i = 0; i < 1000; i++) {
        QuadraticTable q;
        for (int j = 1; j <= 29; j++) {
            q.add(rand() % 100 + 1, j);
        }
        first += q.getFirstCollsion();
    }
    first /= 1000;
    cout << "Quadratic inserts before first collision: " << first << endl;
}