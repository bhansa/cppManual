#include<stdio.h>
#include<string.h>
#include<iostream>
/*
@author bhansa
*/
using namespace std;

struct info{
  string name;
  int price;
}st[3];

int sum=0;
int sales=0;
//supermarket class as super class
class superMarket{
public:
  int count;
  void get(int price1){
    cout<<"Qty: ";
  cin>>qty;
  price=price1;
  }
  void menu(){
    cout<<"Enter Mode: \n1.Retail\n2.WholeSale(30% Discount)\n3.DoorStep Delivery (Extra Charge May Apply)";
  }

  int getTotal(){
    return price*qty;
  }
  /*
  void getRetailSales();
  void getWholeSales();
  void getDoorSales();*/
private:
  int qty,price;
  string name;
};

class retailSale:public superMarket{
public:
  void retailsale(superMarket s){
    int z=s.getTotal();
    sum=sum+z;
    sales++;
  }
};
class wholeSale:public retailSale{
  public:
    void wholesale(superMarket s){
    int z=s.getTotal();
    z=z-(z*30.0)/100;
    sum=sum+z;
    sales++;
  }
};
class doorSale:public wholeSale{
public:
  void doorsale(superMarket s){
    int z=s.getTotal();
    z=z+40;
    sum=sum+z;
    sales++;
    cout<<"Sales: "<<sales;
  }
};

int main()
{
  superMarket s[20];
  st[0].name="bourbon";
  st[0].price=50;
  st[1].name="maggi";
  st[1].price=20;
  int x=1;
  int ch;
  int i=0;
  int chm;
  while(x!=0){
    s[i].menu();
    cin>>chm;
    for(int j=0;j<2;j++){
      if(j==0){
        cout<<"\nNo.\t\t"<<"Name\t\t\t"<<"Price\t\t";
      cout<<"\n-----------------------------------------------------\n";
    }
    cout<<j+1<<"\t|\t"<<st[j].name<<"\t\t|\t"<<st[j].price<<"\t|\t\n";
    if(j==1)
      cout<<"-----------------------------------------------------\n";
    }
  cin>>ch;
  s[i].get(st[ch-1].price);
if(chm==1){
  retailSale rt;
  rt.retailsale(s[i]);
}
  else if(chm==2){
  wholeSale wh;
  wh.wholesale(s[i]);
}
  else if(chm==3){
  doorSale ds;
  ds.doorsale(s[i]);
}
cout<<"\nEnter More(press 0)::";
cin>>x;
i++;
}
  cout<<sum;
  cout<<"\nTotal Sales::"<<sales<<endl;
  return 0;
}
