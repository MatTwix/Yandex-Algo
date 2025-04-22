#include <iostream>
#include <fstream>

using namespace std;

int main (void) {
    int a, b;
    
    ifstream input("input.txt");
    ofstream output("output.txt");

    input >> a >> b;
    input.close();
    
    output << a + b;
    output.close();

    return 0;
}