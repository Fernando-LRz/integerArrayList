#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <cstdlib>
#include <string>
#include <iostream>

#include "listexception.h"

class List {
    private:
        int data[500];
        int last;

        bool isValidPosition(const int&);
        void copyAll(const List&);
    
    public:
        List();
        List(const List&);
        
        bool isEmpty();
        bool isFull();

        void insertElement(const int&, const int&); // position, element
        void deleteElement(const int&);  // position
        
        int getFirstPosition();
        int getLastPosition();
        int getPreviousPosition(const int&);
        int getNextPosition(const int&);

        int getElement(const int&);

        std::string toString();

        void deleteAll();

        List& operator = (const List&);
};

#endif // LIST_H_INCLUDED