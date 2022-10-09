#include <iostream>
using namespace std;

int main()
{
    int score;
    cin >> score;
    char result;
    if(score <= 100 && score >= 90)
        result = 'A';
    else if(score < 90 && score >= 80)
        result = 'B';
    else if(score < 80 && score >= 70)
        result = 'C';
    else if(score < 70 && score >= 60)
        result = 'D';
    else
        result = 'F';
    
    cout << result;
    return 0;
}