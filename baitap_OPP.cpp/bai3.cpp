#include<iostream>

using namespace std;


class date{
    private:
        int day;
        int month,year;
    public:
        date(){
            this->day=this->month=this->year=0;
        }
        date(int day,int month,int year){
            this->day=day;
            this->month=month;
            this->year = year;
        }
        void nhap();
        void xuattruoc();
        void xuatsau();
        ~date(){};
       
};
void date::nhap(){
    cout<<"nhap day: ";
        cin>>day;
        cout<<"\nnhap month: ";
        cin>>month;
        cout<<"\nnhap year: ";
        cin>>year;
}
bool kiemtranamnhuan(int year){
    if(year%4==0&&year%100!=0||year%400==0)
        return true;
    return false;
}
int timsongaytrongthang(int month,int year){
    int DayInMonth;
    switch(month){
        case 1: case 3: case 5: case 7: case 9: case 11:
            DayInMonth=30;
            break;
        case 4: case 6: case 8: case 10: case 12:
            DayInMonth=31;
            break;
        
        default:
            if(kiemtranamnhuan(year))
               DayInMonth=28;
            DayInMonth=29;
            break;
        return DayInMonth;
    }
}

void date::xuattruoc(){
    int newday=day;
    int newmonth=month;
    int newyear=year;
    if(newday>0&&(newmonth>0&&newmonth<13)&&newday<=timsongaytrongthang(newmonth,newyear)){
        if(newday<timsongaytrongthang(newmonth,newyear))
            newday++;
        else if(newmonth<12){
            newday=1;
            newmonth++;
        }
        else{
            newday=newmonth=1;
            newyear++;
        }
    }
    if(newday<10&&newmonth<10)
        cout<<"\nngay trc do: "<<"0"<<newday<<"-"<<"0"<<newmonth<<"-"<<newyear;
    else if(newday<10)
        cout<<"\nngay trc do:"<<"0"<<newday<<"-"<<newmonth<<"-"<<newyear;
    else if(newmonth<10)
        cout<<"\nngay trc do: "<<newday<<"-"<<"0"<<newmonth<<"-"<<newyear;
}
void date::xuatsau(){
     int newday=day;
     int newmonth=month;
     int newyear=year;
      if(newday>0&&(newmonth>0&&newmonth<13)&&newday<=timsongaytrongthang(newmonth,newyear)){
        if(newday==1&&newmonth==1){
            newday=31;
            newmonth=12;
            newyear--;
        }
        else if(newday<=timsongaytrongthang(newmonth,newyear)){
            if(newday==1){
                    newmonth--;
                    newday=timsongaytrongthang(newmonth,newyear);
                }
            }
        else newday--;
      }
    if(newday<10&&newmonth<10)
        cout<<"\nngay sau do: "<<"0"<<newday<<"-"<<"0"<<newmonth<<"-"<<newyear;
    else if(newday<10)
        cout<<"\nngay sau do:"<<"0"<<newday<<"-"<<newmonth<<"-"<<newyear;
    else if(newmonth<10)
        cout<<"\nngay sau do: "<<newday<<"-"<<"0"<<newmonth<<"-"<<newyear;
}

int main(){
    date d;
    d.nhap();
    d.xuattruoc();
    d.xuatsau();
    return 0;
}
