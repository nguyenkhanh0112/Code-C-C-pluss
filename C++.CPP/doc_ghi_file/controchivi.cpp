// CON TRỎ CHỈ VỊ ?

// HÀM DỊCH CHUYỂN CON TRỎ CHỈ VỊ TRONG FILE
// seekg(x,y);
// - x: số byte cần dịch chuyển(int,long long);
//             + âm: dịch về bên tay trái 
//             + dương: dịch về bên tay phải 
// - y: vị trí bắt dầu  dịch 
//             + y = 0: đầu file <=> ios::beg <=> SEEK_SET
//             + y = 1: vị trí hiện tại <=> ios::cur <=> SEEK_CUR
//             + y = 2: cuối file <=> ios::end <=> SEEK_END
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    ifstream filein;
    filein.open("INPUT.txt",ios_base::in);
    filein.seekg(3,ios::beg);
    int  x;
    filein>>x;
    cout<<x;
    filein.close();
    system("pause");
    return 0;
}

