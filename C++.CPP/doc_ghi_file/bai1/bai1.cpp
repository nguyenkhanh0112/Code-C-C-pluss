/*  doc cac so nguyen tu file INPUT.txt biet
    + dong dau tien la 1 so nguyen bieu dien so luong cac so nguyen can doc
    + dong thu 2 la 1 day cac so nguyen can doc 

*/

#include<iostream>
#include<fstream>

using namespace std;

int main(){
    fstream filein;
    filein.open("INPUT.txt",ios_base::in);
    int n;
    filein>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        filein>>arr[i];
    }
    fstream fileout;
    fileout.open("KETQUA.txt",ios_base::out);
    int max=-1e9;
    for(int i=0;i<n;i++){
        if(max<arr[i])
            max=arr[i];
    }
    fileout<<max;
    filein.close();
    fileout.close();
    system("pause");
    return 0;
}