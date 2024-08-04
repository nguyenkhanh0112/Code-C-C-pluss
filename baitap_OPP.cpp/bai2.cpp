#include <iostream>
#include <iomanip>

using namespace std;

class dathuc
{
private:
    int n;     // bac cua da thuc
    int *heso; // hệ số
public:
    dathuc();
    dathuc(int);
    dathuc operator+(const dathuc &);
    dathuc operator-(const dathuc &);
    ~dathuc()
    {
        n = 0;
        delete heso;
    };
    friend istream &operator>>(istream &in, dathuc &d);
    friend ostream &operator<<(ostream &out, dathuc &d);
};
dathuc::dathuc()
{
    this->n = 0;
    this->heso = NULL;
}
dathuc::dathuc(int n)
{
    this->n = n;
    this->heso = new int[n];
}
istream &operator>>(istream &in, dathuc &d)
{
    do
    {
        cout << "nhap bac cua da thuc: ";
        in >> d.n;
        if (d.n < 1)
            cout << "he so cua bac >=1,nhap lai he so cua bac\n ";
    } while (d.n < 1);
    d.heso = new int[d.n];
    cout << "nhap cac he so cua da thuc: ";
    for (int i = 0; i <= d.n; i++)
    {
        cout << "n[" << i << "]= ";
        in >> d.heso[i];
    }
    return in;
}
ostream &operator<<(ostream &out, dathuc &d)
{
    out << "\nda thuc: " << endl;
    if (d.n == 1)
    {
        out << d.heso[0] << "+";
        out << d.heso[1] << "x";
    }
    else
    {
        out << d.heso[0] << " + ";
        out << d.heso[1] << "x + ";
        for (int i = 2; i <= d.n; i++)
        {
            out << d.heso[i] << "x^" << i;
            if (i != d.n)
                cout << " + ";
        }
    }
    return out;
}
dathuc dathuc::operator+(const dathuc &d)
{
    int nmax = (n > d.n) ? n : d.n;
    int nmin = (n < d.n) ? n : d.n;
    dathuc sum = nmax;
    for (int i = 0; i <= nmin; i++)
    {
        sum.heso[i] = this->heso[i] + d.heso[i];
    }
    for (int i = nmin + 1; i <= nmax; i++)
    {
        sum.heso[i] = (n == nmax) ? this->heso[i] : ((n < d.n) ? d.heso[i] : heso[i]);
    }
    return sum;
}
dathuc dathuc::operator-(const dathuc &d)
{
    int nmax = (n > d.n) ? n : d.n;
    int nmin = (n < d.n) ? n : d.n;
    dathuc sub(nmax);
    for (int i = 0; i <= nmin; i++)
    {
        sub.heso[i] = this->heso[i] - d.heso[i];
    }
    for (int i = nmin + 1; i <= nmax; i++)
    {
        sub.heso[i] = (n == nmax) ? this->heso[i] : ((n < d.n) ? d.heso[i] : heso[i]);
    }
    return sub;
}

int main()
{
    dathuc a, b;
    cin >> a;
    cin >> b;
    dathuc sum = a + b;
    dathuc sub = a - b;
    cout << a << b;
    cout << "\ntong 2 da thuc: ";
    cout << sum;
    cout << "\nhieu 2 da thuc: ";
    cout << sub;
    return 0;
}