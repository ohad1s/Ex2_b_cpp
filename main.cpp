#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int,unordered_map<std::pair<int,int>,char >> my_notebook;
//    map_data[7]["hello"] = 3.1415926;
    pair<int, int> pair = make_pair(1,2);
    my_notebook[0][pair]='c';
    if(my_notebook[0][pair] == 'c'){
        cout<<1<<endl;
    }
    return 0;
}
