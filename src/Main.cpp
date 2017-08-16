#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv){
    cout << "Hola mundo" << endl;

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(auto i: v){
        cout << i << endl;
    }

    return 0;
}
