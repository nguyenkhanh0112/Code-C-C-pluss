/*Câu 17: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp điểm với các thuộc tính: tọa độ x, tọa độ y.
Khai báo lớp tam giác có thuộc tính 3 đỉnh là kiểu đối tượng điểm (lớp tam giác được gọi là lớp bao của lớp điểm) và thêm các thuộc tính: độ dài 3 cạnh.
2.	Xây dựng các phương thức: nhập, xuất, tính khoảng cách 2 điểm (dùng hàm bạn), áp dụng tính độ dài 3 cạnh của tam giác; nhập, xuất 3 đỉnh của tam giác.
3.	Nhập vào 1 tam giác. Kiểm tra tính chất của tam giác (thường, đều, vuông, cân, vuông cân). 
    In kết quả ra màn hình.*/


#include<iostream>
#include<bits/stdc++.h>
#include<math.h>


using namespace std;

class diem{
    private:
        double x,y;
    public:
        void import(){
            cout<<"import x: ";cin>>x;
            cout<<"import y: ";cin>>y;
        }
        void exports(){
            cout<<"x = "<<x<<"\n";
            cout<<"y = "<<y<<"\n";
        }
        friend double khoangcach(diem, diem);
};

class TamGiac{
    private:
        diem A,B,C;
        double AB,BC,CA;
    public:
        double getAB(){
            return AB;
        }
        double getBC(){
            return BC;
        }
        double getCA(){
            return CA;
        }
        friend double khoangcach(diem, diem);
        void imports();
        void  exportss();
};
double khoangcach(diem temp1,diem temp2){
    return sqrt(pow((temp1.x-temp2.x),2)+pow((temp1.y-temp2.y),2));
}
void TamGiac::imports(){
    cout<<"import A: "<<endl;
    A.import();
    cout<<"import B: "<<endl;
    B.import();
    cout<<"import C: "<<endl;
    C.import();
    AB=khoangcach(A, B);
    BC=khoangcach(B, C);
    CA=khoangcach(C, A);
}
void TamGiac::exportss(){
    cout<<"Toa do diem A: "<<endl;A.exports();
    cout<<"Toa do diem B: "<<endl;B.exports();
    cout<<"Toa do diem C: "<<endl;C.exports();
    cout<<AB<<endl;
    cout<<BC<<endl;
    cout<<CA<<endl;
}
void check(TamGiac test){
    double AB=test.getAB();
    double CA=test.getCA();
    double BC=test.getBC();
    if((AB+CA>BC)&&(BC+AB>CA)&&(CA+BC>AB)){
        if((AB==BC)||(BC==CA)||(CA==AB)){
            if((AB==BC)&&(BC==CA)){
                cout<<"\nTAM GIAC DEU "<<endl;
                return;
            }
            if((AB == sqrt(pow(BC, 2) + pow(CA, 2))) || (BC == sqrt(pow(AB, 2) + pow(CA, 2))) || (CA == sqrt(pow(BC, 2) + pow(AB, 2)))){
                cout<<"\bTAM GIAC VUONG CAN "<<endl;
                return;
            }
                cout<<"TAM GIAC CAN"<<endl;
                return;
        }
        if((AB*AB==CA*CA+BC*BC)||CA*CA==BC*BC+AB*AB||BC*BC==AB*AB+CA*CA){
            cout<<"\nTAM GIAC VUONG "<<endl;
            return;
        }
            cout<<"\nTAM GIAC THUONG "<<endl;
            return;
    }
    cout<<"\nKHONG PHAI TAM GIAC "<<endl;
}
int main(){
    TamGiac tamgiac;
    tamgiac.imports();
    tamgiac.exportss();
    check(tamgiac);
    return 0;
}