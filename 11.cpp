#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class allrounder;
class player
{
public:
  string name,country;
  //int age,total_matches;
  //float average,strike_rate;
  /*void display_player(player obj[],string country,int n){
    for(int i=0;i<n;i++){
      if(strcmp(obj[i].country,country)==0){
        cout<<obj[i].name;
      }
    }
  }*/
};
class batsmen:public player{
public:
 //int no_of_50s,no_of_100s,no_of_notouts;
 int total_runs;
 void display_bat(){

     if(total_runs>6000){
       cout<<name<<endl;

   }
 }
};
class bowler:public batsmen{
public:
  int total_wickets, no_of_5wkts;
  void display_bowler(){

      if(no_of_5wkts>5){
        cout<<name<endl;

    }
  }
};
class allrounder:public bowler{
public:
  void display_all(){
      if(total_runs>5000 && total_wickets>200){
        cout<<name<<endl;
    }
  }
};
int main()
{
allrounder all[10],all3;
 batsmen all1;
 bowler all2;
for(int i=0;i<3;i++){
  cin>>all[i].name>>all[i].country>>all[i].total_runs>>all[i].total_wickets>>all[i].no_of_5wkts>>endl;
}
//all1.display_player(all,"india",3);
for(int i=0;i<3;i++)
{
all[i].display_bat();
all[i].display_bowler();
all[i].display_all();
}
}
