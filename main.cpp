
#include <iostream>
#include <vector>
#include <fstream>

#include "Event.h"

using namespace std;

int main()
{
    vector<Event> listEvent;

    readTxt(listEvent);

    cout << "hola" << endl;

    return 0;
}

void readTxt(vector<Event> listEvent) {

    // Ope
    ifstream arch("txt.txt");

};
