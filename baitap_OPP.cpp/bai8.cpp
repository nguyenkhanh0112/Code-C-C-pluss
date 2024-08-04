/*Câu 8: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào 1 ma trận. In ra màn hình ma trận vừa nhập. 
    Tính tổng các phần tử nằm trên 4 đường viền của ma trận.*/


#include<iostream>

using namespace std;

class matrix{
    private:
        int n,m;
        int **arr;
        void DynamicallyAllocatedArrays(){
             arr=new int*[n];
            for(int i=0;i<n;i++){
                arr[i]=new int[m];
            }
        }
    public:
        void importArray();
        void exportArray();
        int sum();
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
int matrix::sum(){
    int sum1=0;
    for(int j=0;j<m;j++){
        sum1+=arr[0][j]+arr[n-1][j];
    }
    for(int i=1;i<n-1;i++){
        sum1+=arr[i][0]+arr[i][m-1];
    }
    return sum1;
}


int main(){
    matrix arr;
    arr.importArray();
    arr.exportArray();
    cout<<"\nTONG 4 DUONG VIEN TRONG MANG LA: ";
    cout<<arr.sum()<<endl;
    return 0;
}