#ifndef CINEMA_CPP
#define CINEMA_CPP

#include <vector>
#include <string>
#include "03_Screen.cpp"
using namespace std;

class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(const string& name, int numberOfScreens) : name(name) {
        for (int i = 1; i <= numberOfScreens; ++i)
            screens.emplace_back(i);
    }

    string getName() const { return name; }
    vector<Screen>& getScreens() { return screens; }
};

#endif
