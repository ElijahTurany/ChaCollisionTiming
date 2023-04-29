#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {
    srand(time(0));
    double first = 0;
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

    first = 0;
    double load90 = 0;
    double load100 = 0;
    for (int i = 0; i < 1000; i++) {
        ChainTable c;
        while (c.getLoad() != 1) {
            c.add(rand() % 100 + 1, i);
        }
        first += c.getFirstCollsion();
        load90 += c.getLoadFactor90();
        load100 += c.getLoadFactor100();
    }
    first /= 1000;
    load90 /= 1000;
    load100 /= 1000;
    cout << "Chain inserts before first collision: " << first << endl;
    cout << "Chain inserts before load 90: " << load90 << endl;
    cout << "Chain inserts before load 100: " << load100 << endl;

    double length29 = 0;
    for (int i = 0; i < 1000; i++) {
        ChainTable c2;
        while (c2.getLength29() == 0) {
            c2.add(rand() % 100 + 1, 1);
        }
        length29 += c2.getLength29();
    }
    length29 /= 1000;
    cout << "Chain inserts before length 29: " << length29 << endl;
}