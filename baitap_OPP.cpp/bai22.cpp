/*Câu 22: 
Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 cho các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức.
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử = (gán), < (so sánh nhỏ hơn theo module)
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử). 
    Tìm số phức có giá trị lớn nhất, nhỏ nhất.*/

#include<iostream>
#include<math.h>
using namespace std;

class SP1{
    protected:
        int phanthuc,phanao;
    public:
        SP1(){
            this->phanthuc=0;
            this->phanao=0;
        }
        SP1(int phanthuc,int phanao){
            this->phanthuc=phanthuc;
            this->phanao=phanao;
        }
        void importSoPhuc(SP1&);
        void exportSoPhuc(SP1);
};

class SP2 :public SP1{
    public:
        void operator=(const SP2&);
        bool operator<(SP2&);
        double ModuleSoPhuc(SP2&);
        void importNSophuc(SP2*,int);
        void exportNSoPhuc(SP2*,int);
        void sapxep(SP2*,int);
        void minmax(SP2*,int);
        bool operator>(SP2&);
};
void SP1::importSoPhuc(SP1 &sp){
            cout<<"import phanthuc: ";cin>>sp.phanthuc;
            cout<<"import phanao: ";cin>>sp.phanao;
        }
void SP1::exportSoPhuc(SP1 sp){
    if(sp.phanao==0)
        cout<<sp.phanthuc<<"endl;";
    else if(sp.phanao<0)
        cout<<sp.phanthuc<<sp.phanao<<"i"<<endl;
    else 
        cout<<sp.phanthuc<<"+"<<sp.phanao<<"i"<<endl;
}
double SP2::ModuleSoPhuc(SP2 &sp){
    return sqrt(pow(1.0*sp.phanthuc,2)+pow(1.0*sp.phanao,2));
}
void SP2::importNSophuc(SP2 *sp,int n){
    cout<<"------------------------------\n";
        for(int i=0;i<n;i++){
            cout<<"NHAP SO PHUC THU: "<<i+1<<endl;
            cin.ignore();
            sp[i].importSoPhuc(sp[i]);
    }
}
void SP2::exportNSoPhuc(SP2 *sp,int n){
    cout<<"--------------------------\n";
    for(int i=0;i<n;i++){
        sp[i].exportSoPhuc(sp[i]);
    }
}
void SP2::sapxep(SP2 *sp,int n){
    cout<<"DANH SACH SAU KHI SAP XEP THEO MODULE\n";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(sp[i]>sp[j]){
                SP2 temp=sp[i];
                sp[i]=sp[j];
                sp[j]=temp;
            }
        }
    }
}
void SP2::minmax(SP2 *sp,int n){
    int indexmax,indexmin;
    double min=1e9;
    double max=-1e9;
    for(int i=0;i<n;i++){
        if(max<sp[i].ModuleSoPhuc(sp[i])){
            max=sp[i].ModuleSoPhuc(sp[i]);
            indexmax=i;
        }
    }
    for(int i=0;i<n;i++){
        if(min>sp[i].ModuleSoPhuc(sp[i])){
            min=sp[i].ModuleSoPhuc(sp[i]);
            indexmin=i;
        }
    }
    cout<<"\nBIEU THUC MAX VA MIN\n";
    sp[indexmax].exportSoPhuc(sp[indexmax]);
    sp[indexmin].exportSoPhuc(sp[indexmin]);
    cout<<"GIA TRI MAX: "<<max<<endl;
    cout<<"GIA TRI MIN: "<<min<<endl;
}
void SP2::operator=(const SP2 &temp){
    this->phanthuc=temp.phanthuc;
    this->phanao=temp.phanao;
}
bool SP2::operator<(SP2 &temp){
    return sqrt(pow(1.0*this->phanthuc,2)+pow(1.0*this->phanao,2))<sqrt(pow(1.0*temp.phanthuc,2)+pow(1.0*temp.phanao,2));
}
bool SP2::operator>(SP2 &temp){
     return sqrt(pow(1.0*this->phanthuc,2)+pow(1.0*this->phanao,2))>sqrt(pow(1.0*temp.phanthuc,2)+pow(1.0*temp.phanao,2));
}
int main(){
    int n;
    cout<<"NHAP SO LUONG SO PHUC >=2";
    cin>>n;
    SP2 *sp=new SP2[n];
    sp->importNSophuc(sp,n);
    sp->exportNSoPhuc(sp,n);
    sp->sapxep(sp,n);
    sp->exportNSoPhuc(sp,n);
    sp->minmax(sp,n);
    return 0;
}