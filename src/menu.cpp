#include "../header/menu.hpp"

void Menu::print() {
    cout << menuDisplay << endl;
}

string Menu::getMenuDisplay() { // for testing
    return this->menuDisplay;
}