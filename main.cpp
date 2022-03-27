#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, unordered_map<int, char[100]>> my_notebook;
    my_notebook[0][1][1] = '\n';
    cout << my_notebook[0][1][1] << endl;
    return 0;
}
