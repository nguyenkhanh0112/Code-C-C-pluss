/*Câu 13: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào hai ma trận đồng cấp. Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn). 
    In ra màn hình hai ma trận ban đầu và ma trận kết quả.*/



#include<iostream>
#include<math.h>

using namespace std;

class Matrix{   
    private:
        int n,m;
        double matrix1[100][100],matrix2[100][100],matrix3[100][100];
    public:
        Matrix(){
            this->m=0;
            this->n=0;
        };
        void ImportMatrix1();
        void ImportMatrix2();
        void ExportMatrix(Matrix);
        friend void sumMatrix(Matrix);
};

void Matrix::ImportMatrix1(){
    cout<<"import row matrix 1: ";cin>>n;
    cout<<"impoer col matrix 1: ";cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"matrix["<<i<<"]"<<"["<<j<<"]";
            cin>>matrix1[i][j];
        }
    }
}
void Matrix::ExportMatrix(Matrix matrix){
    cout<<"--------------------------------\n";
    cout<<"MATRIX1\n";
    for(int i=0;i<matrix.n;i++){
        for(int j=0;j<matrix.m;j++){
            cout<<matrix.matrix1[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void Matrix::ImportMatrix2(){
    cout<<"import row matrix 2: ";cin>>n;
    cout<<"impoer col matrix 2: ";cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"matrix["<<i<<"]"<<"["<<j<<"]";
            cin>>matrix2[i][j];
        }
    }
}
void sumMatrix(Matrix matrix){
    for(int i=0;i<matrix.n;i++){
        for(int j=0;j<matrix.m;j++){
            matrix.matrix3[i][j]=matrix.matrix1[i][j]+matrix.matrix2[i][j];
        }
    }
    cout<<"-------------------------\n";
    cout<<"SUM MATRIX1 AND MATRIX2\n";
    for(int i=0;i<matrix.n;i++){
        for(int j=0;j<matrix.m;j++){
            cout<<matrix.matrix3[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    Matrix matrix;
    matrix.ImportMatrix1();
    matrix.ExportMatrix(matrix);
    matrix.ImportMatrix2();
    sumMatrix(matrix);
    return 0;
}
