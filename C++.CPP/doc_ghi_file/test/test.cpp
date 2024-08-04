/*
    doc 1 so nguyen tu file INPUT.TXT
    ghi du lieu vao file KETQUA.TXT
    + ghi vao true- neu so nguyen do la so nguyen to 
    + ghi vao false - neu so nguyen do khong phai la so nguyen to     
*/

#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;
// ham kiem tra so nguyento
bool kiemtra(int n){
    if(n<2)
        return false;
    else{
        if(n%2==0)
            return false;
        else{
            for(int i =2 ;i<sqrt(n);i++){
                if(n%i==0)
                    return false;
            }
        }
    }
    return true;
}
// doc 1 day so nguyen tu fule input.txt
//+ dong dau tien la so luong cac so nguyen hien co trong file 
//+ dong tiep theo la 1 day cac so nguyen
/*  5
1 2 3 4 5

ghi vao file KETQUA.TXT cac so nguyen to co trong mang 
*/
int main(){
    ifstream filein;
    filein.open("INPUT.txt",ios_base::in);
    if(filein.fail()==true){
        cout<<"\nfile ko ton tai\n";
        return 0;
    }
    int arr[100];
    int i=0;
    int dem=0;
    while(filein.eof()==false)//<=> !filein.eof()
    {
        filein>>arr[i];// doc tung so nguyen co trong file;
        i++;
        dem++;
    }
    for(int i=0;i<dem;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    ofstream fileout;
    fileout.open("OUTPUT.txt",ios_base::out);
    for(int i=0;i<dem;i++){
        if(kiemtra(arr[i])){
            fileout<<arr[i]<<" ";
        }
    }
    fileout.close();
    filein.close();
    system("pause");
    return 0;
}