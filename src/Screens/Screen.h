#pragma once
#include <iostream>
#include <string>

using namespace std;

class Screen {
protected:
    static void _drawScreenHeader(string title, string subtitle = "") {
        cout << "\n\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (subtitle != "") {
            cout << "\n\t\t\t\t\t  " << subtitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }
};