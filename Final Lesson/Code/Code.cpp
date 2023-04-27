

#include <iostream>
using namespace std;
void check(string s) {
    int max = 0;
    int min = 400;
    char cash = '1';
    int mn = 1;
    bool fl = false, fl2 = true;
    for (char c : s) {
        cout << c << " "<< (int)c << endl;
        if ((int)c != 32) {
            if ((int)cash == 45) {
                mn = -1;
            }
            else {
                mn = 1;
            }
            if ((int)c*mn > max) {
                max = (int)c;
                if (mn == -1) {
                    fl = true;
                }
                else {
                    fl = false;
                }
            }
            if ((int)c*mn < min) {
                min = (int)c;
                if (mn == -1) {
                    fl2 = true;
                }
                else {
                    fl2 = false;
                }
            }
        }
        cash = c;
        

    }
    if (fl) {
        cout << "-" << (char)max;
    }
    else {
        cout << (char)max;
    }
    if (fl2) {
        cout << "-" << (char)min;
    }
    else {
        cout << (char)min;
    }
}

int main()
{
    check("1 0 9 -4 5");
}
