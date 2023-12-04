#include "credits.hpp"

void Credits::print() {
    cout << creditDisplay << endl;
}

string Credits::getCreditDisplay() { // for testing
    return this->creditDisplay;
}