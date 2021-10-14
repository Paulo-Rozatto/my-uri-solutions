#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int id, workedHours;
    float incomeHour;

    cin >> id;
    cin >> workedHours;
    cin >> incomeHour;

    cout << "NUMBER = " <<  id << endl;
    printf("SALARY = U$ %.2f\n", workedHours * incomeHour);
    return 0;
}