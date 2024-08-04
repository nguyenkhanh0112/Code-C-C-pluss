#include<iostream>
#include<string>
#include"DocGia.h"
using namespace std;

class CDocGiaNguoiLon:public CDOCGIA{
    private:
        string CMND;
    public:
        void Input();
        void Output();
        int tinh_tien_lam_the();
        CDocGiaNguoiLon(){};
        ~CDocGiaNguoiLon(){};
};
void CDocGiaNguoiLon::Input(){
    CDOCGIA::Input();
    cin.ignore();
    cout<<"nhap CMND: ";
    getline(cin,CMND);
}

int CDocGiaNguoiLon::tinh_tien_lam_the(){
    return sothangcohieuluccuathe*10000;
}
void CDocGiaNguoiLon::Output(){
    CDOCGIA::Output();
    cout<<"CMND: "<<CMND<<endl;
    cout<<"tien lam the cua nguoi lon: "<<tinh_tien_lam_the()<<endl;
}