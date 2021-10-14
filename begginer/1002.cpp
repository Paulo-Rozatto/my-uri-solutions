#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    double r;
    cin >> r;
    r = 3.14159 * pow(r,2);
    cout << fixed << setprecision(4);
    cout << "A=" << r << endl;
    return 0;
}