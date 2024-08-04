#include<iostream>
#include<set>


using namespace std;
//o(logn)
//size
//insert
//count
//erase
//order
//multiset<int>
//cho mang co n phan tu va so nguyen k, doi voi moi day con lien tiep khong
//in ra mduoc phan tu lon nhat trong day con do 

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int &x:a) cin>>x;
     multiset<int>ms;
    for(int i=0;i<k;i++){
        ms.insert(a[i]);
    }
    for(int i=k;i<n;i++){
        cout<<*ms.rbegin()<<" ";
        ms.erase(ms.find(a[i-k]));
        ms.insert(a[i]);
    }
    cout<<*ms.rbegin()<<endl;

}
