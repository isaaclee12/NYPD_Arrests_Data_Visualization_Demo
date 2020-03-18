#include <iostream>
using namespace std;

bool isPrime(int x) {
    if (x <= 0) {
        return false;
    } else if (x == 1 || x == 2) {
        return true;
    } else {
        for(int i = 2; i < x; ++i) {
            if(x % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main() {

    cout << "ENTER NUM" << endl;
    int num = 0;
    while (!(cin >> num)) {
        cout << "BAD INPUT. TRY AGAIN:" << endl;
        cin >> num;
    }

    int temp;
    bool running = true;

    while (running) {
        if (num != 1) {
            if (num % 2 == 1) {
                temp = 3 * num + 1;
                cout << temp << endl; // "IT'S ODD, x3 +1: " <<
                num = temp;
            } else {
                temp = num / 2;
                cout << temp << endl; // "IT'S EVEN, /2: " <<
                num = temp;
            }
        } else {
            running = false;
        }
    }

    /*int primeSumMaybe, a, b;
    for (int i = 0; i <= num - 1; ++i) {
        primeSumMaybe = 2 * i + 2;
        cout << "CURRENTLY TESTING:" <<  primeSumMaybe << endl;
        for (int j = 0; j < primeSumMaybe; ++j) {
            a = j;
            b = primeSumMaybe - j;
            if (isPrime(a) && isPrime(b)) {
                cout << "PRIMES ARE: " << a << " AND " << b << endl;
            }
        }

    }*/

    /*
    cout << "ENTER MAX FOR PRIMES" << endl;
    while (!(cin >> num)) {
        cout << "WRONG. TRY AGAIN:" << endl;
        cin >> num;
    }

    for (int i = 1; i <= num; ++i) {
        if (isPrime(i)) {
            primeSumMaybe = 2 * i + 2;
            cout << "FOR PRIME: " << i << ", 2n + 2 = " << primeSumMaybe << endl;
        }
        //cout << "CURRENTLY TESTING: i=" <<  i << endl;

    }*/

    return 0;
}