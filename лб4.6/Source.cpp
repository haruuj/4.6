#include <iostream>
#include <cmath>

using namespace std;

double calculateUsingWhile(int maxI, int maxK) {
    double product = 1.0;
    int i = 1;
    while (i <= maxI) {
        int k = 1;
        while (k <= maxK - i + 1) {
            product *= (sin(i * i * k) + cos(i * i * k)) / (k * k + i * i);
            k++;
        }
        i++;
    }
    return product;
}

double calculateUsingDoWhile(int maxI, int maxK) {
    double product = 1.0;
    int i = 1;
    do {
        int k = 1;
        do {
            product *= (sin(i * i * k) + cos(i * i * k)) / (k * k + i * i);
            k++;
        } while (k <= maxK - i + 1);
        i++;
    } while (i <= maxI);
    return product;
}

double calculateUsingForIncreasing(int maxI, int maxK) {
    double product = 1.0;
    for (int i = 1; i <= maxI; i++) {
        for (int k = 1; k <= maxK - i + 1; k++) {
            product *= (sin(i * i * k) + cos(i * i * k)) / (k * k + i * i);
        }
    }
    return product;
}

double calculateUsingForDecreasing(int maxI, int maxK) {
    double product = 1.0;
    for (int i = maxI; i >= 1; i--) {
        for (int k = maxK - i + 1; k >= 1; k--) {
            product *= (sin(i * i * k) + cos(i * i * k)) / (k * k + i * i);
        }
    }
    return product;
}

int main() {
    const int maxI = 3;
    const int maxK = 4;

    double resultWhile = calculateUsingWhile(maxI, maxK);
    double resultDoWhile = calculateUsingDoWhile(maxI, maxK);
    double resultForIncreasing = calculateUsingForIncreasing(maxI, maxK);
    double resultForDecreasing = calculateUsingForDecreasing(maxI, maxK);

    cout << " (while): " << resultWhile << endl;
    cout << " (do-while): " << resultDoWhile << endl;
    cout << " (for 1): " << resultForIncreasing << endl;
    cout << " (for 2): " << resultForDecreasing << endl;

   
    if (fabs(resultWhile - resultDoWhile) < 1e-6 &&
        fabs(resultWhile - resultForIncreasing) < 1e-6 &&
        fabs(resultWhile - resultForDecreasing) < 1e-6) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}