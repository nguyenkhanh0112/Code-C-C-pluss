#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class thisinh
{
private:
    string masv, hoten;
    double dt, dl, dh;
    double tong = 0;

public:
    thisinh();
    thisinh(string, string, double, double, double);
    void nhap(thisinh &);
    void xuat();
    string gethoten()
    {
        return hoten;
    }
    double tong3mon();
};
thisinh::thisinh()
{
    this->masv = "";
    this->hoten = "";
    this->dt = this->dl = this->dh = 0;
}
thisinh::thisinh(string masv, string hoten, double dt, double dl, double dh)
{
    this->masv = masv;
    this->hoten = hoten;
    this->dt = dt;
    this->dl = dl;
    this->dh = dh;
}
void thisinh::nhap(thisinh &ts)
{
    cout << "\nnhap masv: ";
    getline(cin, masv);
    cout << "\nnhap ho ten: ";
    getline(cin, hoten);
    cout << "\nnhap dt: ";
    cin >> dt;
    cout << "\nnhap dl: ";
    cin >> dl;
    cout << "\nnhap dh: ";
    cin >> dh;
}

void thisinh::xuat()
{
    cout << setw(10) << left << "masv";
    cout << setw(25) << left << "ho ten";
    cout << setw(10) << left << "diem toan";
    cout << setw(10) << left << "diem ly";
    cout << setw(10) << left << "diem hoa";
    cout << setw(10) << right << "diemtb" << endl;
    cout << setw(75) << "-" << endl;
    cout << setw(10) << left << masv;
    cout << setw(25) << left << hoten;
    cout << setw(10) << left << dt;
    cout << setw(10) << left << dl;
    cout << setw(10) << left << dh;
    cout << setw(10) << right << tong;
}
double thisinh::tong3mon()
{
    tong = (dt + dl + dh) / 3;
    return tong;
}
void diemtb(thisinh *ts, int n)
{
    for (int i = 0; i < n; i++)
    {
        ts[i].tong3mon();
    }
}

void sapxep(thisinh *ts, int n)
{
    thisinh temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((ts[i].gethoten()).size() > (ts[j].gethoten()).size())
            {
                temp = ts[i];
                ts[i] = ts[j];
                ts[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    thisinh *ts = new thisinh[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nnhap danh sach sinh vien thu: " << i + 1 << endl;
        cin.ignore();
        ts[i].nhap(ts[i]);
    }
    diemtb(ts, n);
    sapxep(ts, n);
    for (int i = 0; i < n; i++)
    {
        cout << "\ndanh sach sinh vien thu: " << i + 1 << endl;
        ts[i].xuat();
    }
    return 0;
}