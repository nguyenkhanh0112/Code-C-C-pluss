/*
Dữ liệu trong File: INPUT.TXT gồm các thông tin sau:
- Dòng đầu tiên: Số lượng các phân số.
- Các dòng tiếp theo, mỗi dòng lưu thông tin 1 phân số
1. Rút gọn các phân số và lưu vào file RUTGONPHANSO.TXT 
2. Tìm phân số lớn nhất - kết quả ghi ra file: OUTPUT.TXT

VD:
INPUT.TXT
4
2/4
2/3
6/8
4/5

OUTPUT.TXT
4/5
*/
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

struct PHANSO{
    int tuso;
    int mauso;
};

struct DanhSach{
    PHANSO PS[100];
    int n;
};
void doc_1ps(PHANSO &ps,ifstream &filein){
    filein>>ps.tuso;
    char x;
    filein>>x;
    filein>>ps.mauso;
}
void doc_n_ps(DanhSach &ds,ifstream &filein){
    filein>>ds.n;
    for(int i=0;i<ds.n;i++){
        doc_1ps(ds.PS[i],filein);
    }
    filein.close();
}
void in(DanhSach &ds){
    for(int i=0;i<ds.n;i++){
        cout<<ds.PS[i].tuso<<"/"<<ds.PS[i].mauso<<endl;
    }
}
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void rut_gon_1ps(PHANSO &ps){
    int x=gcd(ps.mauso,ps.tuso);
    ps.tuso/=x;
    ps.mauso/=x;
}
void rutgon_n_ps(DanhSach &ds,ofstream &fileout){
    fileout.open("RUTGONPHANSO.TXT",ios_base::out);
    for(int i=0;i<ds.n;i++){
        rut_gon_1ps(ds.PS[i]);
    }
    for(int i=0;i<ds.n;i++){
        fileout<<ds.PS[i].tuso<<"/"<<ds.PS[i].mauso<<endl;
    }
    fileout.close();
}
void max(DanhSach &ds,ofstream &fileout){
    fileout.open("OUTPUT.TXT",ios_base::out);
    for(int i=0;i<ds.n;i++){
        rut_gon_1ps(ds.PS[i]);
    }
    float max=(1.0*ds.PS[0].tuso)/ds.PS[0].mauso;
    int k=0;
    for(int i=1;i<ds.n;i++){
        float temp=ds.PS[i].tuso/(ds.PS[i].mauso*1.0);
        if(max<temp){
            max=temp;
            k=i;
        }
    }
    fileout<<ds.PS[k].mauso<<"/"<<ds.PS[k].tuso;
    fileout.close();
}
int main(){
    DanhSach ds;
    ifstream filein;
    ofstream fileout;
    filein.open("INPUT.TXT",ios_base::in);
    doc_n_ps(ds,filein);
    rutgon_n_ps(ds,fileout);
    max(ds,fileout);
    in(ds);
    system("pause");
    return 0;
}