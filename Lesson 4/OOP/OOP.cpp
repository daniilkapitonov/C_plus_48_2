
#include <iostream>
using namespace std;

class Wheel {
public:
    int R;
    int W;
    int cort;
    bool hole;

    Wheel() {
        cout << "make wheel def" << endl;
        hole = false;
    }

    Wheel(int R, int W, int cort) {
        this->R = R;
        this->W = W;
        this->cort = cort;
        cout << "make wheel" << endl;
        hole = false;
        this->prInfo();
    }
    void prInfo() {
        cout << "R - " << R <<endl;
        cout << "W - " << W << endl;
        cout << "cort - " << cort << endl;
    }

    void setPar(int R, int Wc, int cortc) {
        this->R = R;
        W = Wc;
        cort = cortc;
    }

    void crash() {
        hole = true;
    }

    bool checkWork() {
        if (hole) {
            return false;
        }
        else {
            return true;
        }
    }

};

int main()
{
    Wheel wh1;
    wh1.R = 18;
    wh1.W = 255;
    wh1.cort = 100;
    cout << wh1.R << wh1.W << wh1.cort << endl;
    wh1.prInfo();
    cout << endl;
    Wheel wh2;
    wh2.R = 25;
    wh2.W = 290;
    wh2.cort = 50;
    wh2.setPar(1, 1, 1);
    //cout << wh1.R << wh1.W << wh1.cort << endl;
    wh2.prInfo();
    cout << endl;
    Wheel wh3(180, 130, 200);
    cout << wh3.checkWork() << endl;
    wh3.crash();
    cout << wh3.checkWork() << endl;
    //wh3.prInfo();
}

