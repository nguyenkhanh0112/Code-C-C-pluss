/*doc cac so nguyen tu file input.txt biet 
chi co 1 dong duy nhat chua cac so nguyen
vd: input.txt
    === yeu cau ===
    tim cac phan tu la amstrong trong mang so nguyen do va ghi vao file amstrong.txt
*/


#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
int dem(int n){
    int count =0;
    while(n!=0){
        count++;
        n/=10;
    }
    return count;
}
bool soamstrong(int n){
    int count=dem(n);
    int x=n;
    int temp=0;
    while(n>0){
        temp=temp+pow(n%10,count);
        n=n/10;
    }
    if(temp==x)
        return true;
    else
        return false;
}
int main(){
    ifstream filein;
    filein.open("INPUT.txt",ios_base::in);
    int arr[100];
    int i=0,dem=0;
    while(!filein.eof()){
        filein>>arr[i];
        i++;
        dem++;
    }
    for(int i=0;i<dem;i++){
        if(soamstrong(arr[i]))
            cout<<arr[i]<<" ";
    }
    ofstream fileout;
    fileout.open("AMSTRONG.txt",ios_base::out);
    for(int i=0;i<dem;i++){
        if(soamstrong(arr[i])==true)
            fileout<<arr[i]<<" ";
    }
    filein.close();
    fileout.close();
    system("pause");
    return 0;
}