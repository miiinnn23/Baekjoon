#include <iostream>
#include <cmath>
#define ERR 1e-10
// https://doublik.tistory.com/6
using namespace std;

int A[2], B[2], C[2], D[2];
double distance(double x1, double y1, double x2, double y2);
pair<double, double> Minho(double p);
pair<double, double> Kangho(double p);

int main(void) {
    cin >> A[0] >> A[1] >> B[0] >> B[1] >> C[0] >> C[1] >> D[0] >> D[1];
    double low = 0, high = 100;
    double result = distance(A[0], A[1], C[0], C[1]);

    while(high - low >= ERR) {
        double p1 = (low * 2 + high) / 3.0;
        double p2 = (low + high * 2) / 3.0;

        pair<double, double> M1 = Minho(p1);
        pair<double, double> M2 = Minho(p2);
        pair<double, double> K1 = Kangho(p1);
        pair<double, double> K2 = Kangho(p2);

        double temp1 = distance(M1.first, M1.second, K1.first, K1.second);
        double temp2 = distance(M2.first, M2.second, K2.first, K2.second);

        double min_temp = (temp1 < temp2 ? temp1 : temp2);
        result = (result < min_temp ? result : min_temp);

        if(temp1 < temp2) high = p2; // 범위 : [low, p2]
        else low = p1; // 범위 : [p1, high]
    }
    cout << fixed;
    cout.precision(10);
    cout << result << "\n";
    return 0;
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

pair<double, double> Minho(double p) {
    double Mx = (B[0] - A[0]) * (p / 100) + A[0];
    double My = (B[1] - A[1]) * (p / 100) + A[1];

    return (pair<double, double> (Mx, My));
}
pair<double, double> Kangho(double p) {
    double Kx = (D[0] - C[0]) * (p / 100) + C[0];
    double Ky = (D[1] - C[1]) * (p / 100) + C[1];

    return (pair<double, double> (Kx, Ky));
}