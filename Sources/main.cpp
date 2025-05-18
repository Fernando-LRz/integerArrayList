#include <iostream>
#include <random>
#include <chrono>
#include <functional>

#include "list.h"

using namespace std;

int main() {
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(111, 999);
    auto dice = bind(distribution, generator);

    List myList;
    int value;

    for(int i(0); i < 50; i++) {
        value = dice();
        cout << "Inserting: " << value << endl;
        myList.insertElement(myList.getLastPosition(), value);
    }

    cout << endl << endl;
    
    cout << "List contents ..." << endl;
    cout << myList.toString() << endl;

    cout << "Element at position 19: " << myList.getElement(19) << endl << endl;

    cout << "Inserting an element at an invalid position..." << endl;
    try {
        myList.insertElement(100, 1899);
    } catch(ListException e) {
        cout << "Something went wrong: " << e.what() << endl;
    }
    
    cout << endl << endl;
}