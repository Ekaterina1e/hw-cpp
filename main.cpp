#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


int main() {
    
    ifstream file("in.txt");

    float xn;
    float yn;

    float x0;
    float y0;

    float final_x;
    float final_y;

    float final_x2;
    float final_y2;

    float cos = 1;
    float dist = 0;

    file >> x0 >> y0;

    while (file) {
        file >> xn >> yn;
//        cout << x0 << ' ' << y0 << ' ' << xn << ' ' << yn << endl;
//        if (x0 != 0 && y0 != 0) {
        float new_cos = (xn * x0 + yn * y0) / (sqrt(xn * xn + yn * yn) * (x0 * x0 + y0 * y0));
        if ((y0 * xn - x0 * yn) > 0) {
            cout << xn << ' ' << yn << " higher" << endl;
        }
            if (cos > new_cos) {
                cos = new_cos;
                final_x = xn;
                final_y = yn;
            }

        float new_dist = pow((xn * y0 - x0 * yn), 2);
        if (dist < new_dist) {
            dist = new_dist;
            final_x2 = xn;
            final_y2 = yn;
        }
//
//
    }
    cout << "Rightmost (angle): " << final_x << ' ' << final_y << endl;
    cout << "Leftmost (dist):" << final_x2 << ' ' << final_y2;

    return 0;
}
