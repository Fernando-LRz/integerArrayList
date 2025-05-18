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
    
    cout << endl << endl;
}