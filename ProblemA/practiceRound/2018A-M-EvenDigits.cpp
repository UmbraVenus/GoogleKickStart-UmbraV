#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<int, int> Digits; // convert N to string

int Plus(map<int, int>);
int Minus(map<int, int>);
int Count(int);

int main()
{
    int T;
    int Number;
    int i;
    int y;
    int COUNT; // count 1-17

    cin >> T;

    for (i = 1; i <= T; i++)
    {
        cin >> Number;
        int n = Number;
        COUNT = Count(n);
        int c = COUNT; // c = e + 1

        if (c == 1) // if single digit
        {
            y = 1;
            cout << "Case #" << i << " " << y << endl;
            Digits.clear();
        }
        else
        {
            //generate map Digits
            int j = 0;
            while (j <= c - 1)
            {
                Digits[c - j] = n % 10;
                j++;
                n = n / 10;
            }
            int yPlus = abs(Plus(Digits) - Number);
            int yMinus = abs(Number - Minus(Digits));
            int y = min(yPlus, yMinus);
            cout << "Case #" << i << " " << y << endl;
            Digits.clear();
        }
    }
    return 0;
}

int Plus(map<int, int> digits)
{
    int c = digits.size();
    int y;
    string perfect;

    if (c > 0)
    {
        for (int e = 1; e <= c; e++)
        {
            if (digits[e] % 2 != 0) // odd
            {
                if (digits[e] == 9 && (digits[e - 1] % 2) != 0)
                {
                    digits[e] = 0;
                    digits[e - 1] += 1;
                    while (e <= c - 1)
                    {
                        digits[e + 1] = 0;
                        e++;
                    }
                    break;
                }
                else if (digits[e] == 9 && (digits[e - 1] % 2) == 0)
                {
                    digits[e] = 0;
                    digits[e - 1] += 2;
                    while (digits[e - 2] % 2 == 0)
                    {
                        digits[e - 2] == 0;
                        if (digits.count(e - 3) == 0)
                        {
                            digits[e - 4] == 2;
                        }
                        else
                        {
                        }
                        e--;
                    }

                    break;
                }
                else
                {
                    digits[e] += 1;
                    while (e <= c - 1)
                    {
                        digits[e + 1] = 0;
                        e++;
                    }
                    break;
                }
            }
        }
    }
    for (auto &it : digits)
    {
        // Do stuff
        perfect += to_string(it.second);
    }
    int even = stoi(perfect);
    even = abs(even);
    return even;
}

int Minus(map<int, int> digits)
{
    int c = digits.size();
    int y;
    string perfect;

    if (c >= 1)
    {
        for (int e = 1; e <= c; e++)
        {
            if (digits[e] % 2 != 0)
            {
                digits[e] = digits[e] - 1;
                while (e <= c - 1)
                {
                    digits[e + 1] = 8;
                    e++;
                }
                break;
            }
        }
    }
    for (auto &it : digits)
    {
        // Do stuff
        perfect += to_string(it.second);
    }
    int even = stoi(perfect);
    even = abs(even);
    return even;
}

int Count(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}