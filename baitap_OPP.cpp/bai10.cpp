/*Câu 10: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp nhân sự với các thuộc tính: mã nhân viên, họ tên, năm sinh.
Khai báo lớp cán bộ kế thừa từ lớp nhân sự và thêm các thuộc tính: lương cơ bản, hệ số lương.
2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng nhân sự, cán bộ.
3.	Nhập vào n cán bộ. 
    Thực hiện tính lương cho các cán bộ. In ra màn hình danh sách cán bộ theo thứ tự giảm dần của tiền lương.*/

#include<iostream>

using namespace std;

class NhanSu{
    protected:
        string manv,hoten;
        int namsinh;
};
class CanBo :public NhanSu{
    private:
        float luongcoban;
        float hesoluong;
    public:
        void import(CanBo&);
        void exportc(CanBo);
        float luonghangthang();
        void importnCanBo(CanBo *,int);
        void exportNCanBo(CanBo *,int);
        void QuickSortluonghangthang(CanBo*,int);
        void sapxep(CanBo*,int );
};
void CanBo::import(CanBo &CB){
    cout << "import manv: "; getline(cin,CB.manv);
    cout << "import hoten: "; getline(cin,CB.hoten);
    cout << "import namsinh: "; cin >> CB.namsinh;
    cout << "import hesoluong: "; cin >> CB.hesoluong;
    cout << "import luongcoban: "; cin >> CB.luongcoban;
}
float CanBo::luonghangthang(){
    return hesoluong*luongcoban;
}
void CanBo::exportc(CanBo CB){
    cout << "manv: " << CB.manv<<"\n";
    cout << "hoten: " << CB.hoten<<"\n";
    cout << "namsinh: " << CB.namsinh<<"\n";
    cout<< "hesoluong: " << CB.hesoluong<<"\n";
    cout<< "luongcoban: " << CB.luongcoban<<"\n";
    cout << "luong can bo: " << CB.luonghangthang() << "\n";
}
void CanBo::importnCanBo(CanBo *CB,int n){
    for(int i=0;i<n;i++){
        cout << "NHAP VAO CAN BO THU: " << i+1<<endl;
        cin.ignore();
        CB[i].import(CB[i]);
    }
}
void CanBo::exportNCanBo(CanBo *CB,int n){
    cout << "DANH SACH CAC CAN BO" << endl;
    for(int i=0;i<n;i++){
        cout<<"------------------------------\n";
        CB[i].exportc(CB[i]);
    }
}
// void CanBo::QuickSortluonghangthang(CanBo *CB,int l,int r ){
//     int i=l;
//     int j=r;
//     int x=CB[(l+r)/2];
//     do{
//         while(CB[i]<x)i++;
//         while(CB[j]>x)j--;
//             if(i<=j){
//                 CanBo temp=CB[i];
//                 CB[i]=CB[j];
//                 CB[j]=temp;
//                 i++;
//                 j--;
//             }
//     }while(i<=j);
//     if(l<j) QuickSortluonghangthang(CB,l,j);
//     if(i<r) QuickSortluonghangthang(CB,i,r);
// }
void CanBo::sapxep(CanBo *CB,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(CB[i].luonghangthang()>CB[j].luonghangthang()){
                CanBo temp=CB[i];
                CB[i]=CB[j];
                CB[j]=temp;
            }
        }
    }
}
int main(){
    int n;
    cout<<"NHAP SO LUONG CAN BO: ";cin>>n;
    CanBo *CB = new CanBo[n];
    CB->importnCanBo(CB,n);
    CB->exportNCanBo(CB,n);
    cout<<"DANH SACH CAC CAN BO SAU KHI DC SAP XEP LA:\n";
    CB->sapxep(CB,n);
    CB->exportNCanBo(CB,n);
    delete CB;
    return 0;
}
