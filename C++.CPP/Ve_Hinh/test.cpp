#include <iostream>

using namespace std;

int main(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (i % 2 == 0){
                cout << "   ";
            }
            if (j % 2 != 0){
                cout << "*";
            }
            if (i % 2 != 0){
                cout << "   ";
            }
        }
        cout << endl;
    }
    return 0;
}