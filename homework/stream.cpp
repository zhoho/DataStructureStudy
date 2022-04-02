#include <fstream>
using namespace std;

int main()
{
    ifstream f1("a.dat");
    ofstream f2("b.dat");
    int n, count = 0, sum = 0;
    double average;

    while(!f1.eof())
    {
        f1 >> n;
        count ++;
        sum += n;
    }
    average = (double) sum / count;
    f2 << "input size" << count << "\n";
    f2 << "Total sum" << sum << "\n";
    f2 << "average" << sum / average << "\n";

    f1.close();
    f2.close();

    return 0;
}