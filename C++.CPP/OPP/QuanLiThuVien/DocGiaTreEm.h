#pragma once
#include<string>
#include"DocGia.h"

using namespace std;

class CDocGiaTreEm: public CDOCGIA{
    private:
        string hotennguoidaidien;
    public:
    void Input();
    void Output();
    int tinh_tien_lam_the();
        CDocGiaTreEm(){};
        ~CDocGiaTreEm(){};
};
void CDocGiaTreEm::Input(){
    CDOCGIA::Input();
    cin.ignore();
    cout<<"nhap ho ten nguoi dai dien: ";
    getline(cin,hotennguoidaidien);

}
int CDocGiaTreEm::tinh_tien_lam_the(){
    return sothangcohieuluccuathe*5000;
}
void CDocGiaTreEm::Output(){
    CDOCGIA::Output();
    cout<<"ho ten nguoi dai dien: "<<hotennguoidaidien<<endl;
    cout<<"tien lam the cua tre: "<<tinh_tien_lam_the()<<endl;
    
}