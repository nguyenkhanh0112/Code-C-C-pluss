/*Câu 7: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận vuông với các thuộc tính: cấp ma trận, các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập và 1 ma trận. In ra màn hình ma trận vừa nhập. 
    Tính tổng các phần tử nằm trên đường chéo chính, tổng các phần tử nằm trên đường chéo phụ của ma trận.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class matrix{
    private:
        int n,m;
        int **arr;
        void DynamicallyAllocatedArrays(){
                arr = new int*[n];
            for(int i=0;i<n;i++){
                arr[i]= new int[m];
            }
        }
    public:
        void importArray();
        void exportArray();
        int sumDiagonal();
        int sumDiagonalAuxiliary();
};
void matrix :: importArray(){
    cout<<"import row : ";cin>>n;
    cout<<"import colum : ";cin>>m;
    DynamicallyAllocatedArrays();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Arr["<<i<<"]"<<"["<<j<<"]"<<"= ";
            cin>>arr[i][j];
        }
    }
}
void matrix :: exportArray(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int matrix::sumDiagonal(){
    int sumdiagonal1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==i){
            sumdiagonal1+=arr[i][i];
            }
        }
    }
    return sumdiagonal1;
}
int matrix::sumDiagonalAuxiliary(){
    int sumAuxilia=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==n-i-1)
            sumAuxilia+=arr[i][j];
        }
    }
    return sumAuxilia;
}
int main(){
    matrix arr;
    arr.importArray();
    arr.exportArray();
    cout<<"\nTONG CAC PHAN TU NAM TREN DUONG CHEO CHINH: ";
    cout<<arr.sumDiagonal()<<endl;
    cout<<"TONG CAC PHAN TU NAM TREN DUONG CHEO PHU:";
    cout<<arr.sumDiagonalAuxiliary()<<endl;
    return 0;
}