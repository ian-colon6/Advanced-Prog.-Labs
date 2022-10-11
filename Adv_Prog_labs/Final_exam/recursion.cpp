#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int intLog(int n, int b)
{
    if(n <= 1) return 0;

    return 1 + intLog(n/b, b);

}





int main(){

    (intLog(1024,2) == 10) ? cout << "Passed" << endl : cout << "Failed" << endl;

    return 0;
}
