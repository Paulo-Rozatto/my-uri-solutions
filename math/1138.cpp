// 1138 - math
#include <iostream>
#include <math.h>

using namespace std;

void fill(int arr[], int value)
{
    for (int i = 0; i < 10; i++)
    {
        arr[i] = value;
    }
}

int toInt(char value)
{
    return value - '0';
}

void increase(int arr[], int value)
{
    for (int i = 0; i < 10; i++)
    {
        arr[i] += value;
    }
}

void increase(int arr[], int value, int limit)
{
    for (int i = 0; i < limit; i++)
    {
        arr[i] += value;
    }
}

void increase(int arr[], int value, int lower, int limit)
{
    for (int i = lower; i < limit; i++)
    {
        arr[i] += value;
    }
}

void show(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i];

        if (i < 9)
            cout << " ";
    }
    cout << endl;
}

int pattern(int size)
{
    int p = 0;

    for (int i = 1; i < size; i++)
    {
        p += pow(10, i);
    }

    return p;
}

void contDigits(int cont[], string numb)
{
    int digit, length, increment, exponent;
    char charDigit;
    int lowerBound = 1;

    fill(cont, 0);
    length = numb.length();

    for (int i = 0; i < length && length > 1; i++)
    {
        digit = toInt(numb[i]);

        exponent = length - i - 2;
        increment = (exponent + 1) * pow(10, exponent) * digit;

        increase(cont, increment, 0, 10);

        increment = pow(10, exponent + 1);

        if (i < length - 1)
        {
            increase(cont, increment, lowerBound, digit);
            cont[digit] += stoi(numb.substr(i + 1)) + 1;
        }

        if (i == 0)
        {
            cont[0] -= pattern(length - 1);
            lowerBound = 0;
        }
    }

    digit = toInt(numb[length - 1]);
    increase(cont, 1, digit + 1);
}

void subtraction(int v1[], int v2[], int resul[])
{
    for (int i = 0; i < 10; i++)
        resul[i] = v2[i] - v1[i];
}

int main(int argc, char const *argv[])
{
    string numb1, numb2;
    int cont1[10], cont2[10], resul[10];
    int digit;

    cin >> numb1 >> numb2;

    while (numb1 != "0" || numb2 != "0")
    {
        contDigits(cont1, numb1);
        contDigits(cont2, numb2);

        subtraction(cont1, cont2, resul);

        for (int i = 0; i < numb1.length(); i++)
        {
            digit = toInt(numb1[i]);
            resul[digit] += 1;
        }

        show(resul);

        cin >> numb1 >> numb2;
    }

    return 0;
}