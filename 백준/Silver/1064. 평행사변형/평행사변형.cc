#include <iostream>
#include <cmath>
using namespace std;

bool Gradient(double a1, double a2, double b1, double b2, double c1, double c2) {//삼각형 안만들어지는 경우
    if ((a2 - b2)*(a1 - c1) == (a2 - c2)*(a1 - b1)) return true;
    else return false;
}

double Length(double a1, double a2, double b1, double b2) {//두점사이 거리
    double result = 0;
    double x = a1 - b1;
    double y = a2 - b2;
    result = pow(x,2) + pow(y,2);
    return sqrt(result);
}

int main() {
    double Xa, Ya, Xb, Yb, Xc, Yc;
    cin >> Xa >> Ya >> Xb >> Yb >> Xc >> Yc;
    if (Gradient(Xa, Ya, Xb, Yb, Xc, Yc)) { //한 직선 위에 있을 때
        cout << -1 << endl;
    }
    else {//평행사변형이 만들어 질 때 둘래 구하기 //두변 길이 *2 중 가장 긴것구하기
        double A[3];//3변의 길이
        A[0] = Length(Xa, Ya, Xb, Yb);
        A[1] = Length(Xa, Ya, Xc, Yc);
        A[2] = Length(Xb, Yb, Xc, Yc);
        double max = A[0];
        double min = A[0];
        for (int i = 0; i < 3; i++) {
            if (A[i] > max)
                max = A[i];
            if (A[i] < min)
                min = A[i];
        }

        double sum = A[0] + A[1] + A[2];
        double maxresult = (sum - min) * 2;
        double minresult = (sum - max) * 2;
        double result = maxresult - minresult;
        cout.precision(15);
        cout << result << endl;
    }
}