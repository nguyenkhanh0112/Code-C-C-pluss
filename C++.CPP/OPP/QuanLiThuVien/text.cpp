#include"ThuVien.h"

int main(){
    CThuVien *x=new CThuVien;
    x->Input();
    x->Output();
    cout<<"\n\n\t\tTONG TIEN LAM THE: "<<x->tinh_tong_tien_lam_the();
    delete x;
    return 0;
}