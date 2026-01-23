#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("./example.txt");
    if (!outFile) {cout<<"Can't open example.txt";}
    outFile<<"Hello World";
    outFile.close();
}
