#include "list.h"

using namespace std;

// Private

void List::copyAll(const List& list) {
    int i(0);
    while(i <= list.last) {
        data[i] = list.data[i];
        i++;
    }
    last = list.last;
}

bool List::isValidPosition(const int& position) {
    return position >= 0 and position <= last;
}

// Public

List::List() : last(-1) {}

List::List(const List& list) {
    copyAll(list);
}

bool List::isEmpty() {
    return last == -1;
}

bool List::isFull() {
    return last == 499;
}

void List::insertElement(const int& position, const int& element) {
    if(isFull()) {
        throw ListException("[insertElement] The list is full; no more elements can be inserted.");
    }

    if(position != -1 and !isValidPosition(position)) {
        throw ListException("[insertElement] The position is invalid.");
    }

    int i(last);
    while(i > position) {
        data[i + 1] = data[i];
        i--;
    }

    data[position + 1] = element;
    last++;
}

void List::deleteElement(const int& position) {
    if(!isValidPosition(position)) {
        throw ListException("[deleteElement] The position is invalid.");
    }

    int i(last);
    while(i < last) {
        data[i] = data[i + 1];
        i++;
    }

    last--;
}

int List::getFirstPosition() {
    if(isEmpty()) {
        return -1;
    }

    return 0;
}

int List::getLastPosition() {
    return last;
}

int List::getPreviousPosition(const int& position) {
    if(position == getFirstPosition() or !isValidPosition(position)) {
        return -1;
    }

    return position - 1;
}

int List::getNextPosition(const int& position) {
    if(position == getLastPosition() or !isValidPosition(position)) {
        return -1;
    }

    return position + 1;
}

int List::getElement(const int& position) {
    if(!isValidPosition(position)) {
        throw ListException("[getElement] The position is invalid.");
    }

    return data[position];
}

string List::toString() {
    string result;
    int i(0);

    while(i <= last) {
        result += to_string(data[i]) + ", ";
        i++;
    }

    result += "\n";
    return result;
}

void List::deleteAll() {
    last = -1;
}

List& List::operator = (const List& list) {
    copyAll(list);
    
    return *this;
}