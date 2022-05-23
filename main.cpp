#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <iomanip>

using namespace std;

class CashRegister{
  public:
    int dollar100;
    int dollar50;
    int dollar20;
    int dollar10;
    int dollar5;
    int dollar1;
    int quarter;
    int dime;
    int nickel;
    int penny;
    vector<int> billcoincount;
    vector<tuple<double, int>> result;
    vector<double>denomination;
    double cash;
    void retreiveMoney();
    void addRemoveCoinBill(int, int,int,int,int,int,int,int,int,int);
    void updateBillsCoinsCount();
    void giveCountBillCoin(double);
    void minChange(double,double);
    void printMinChange();


    CashRegister(int dollar100 = 0,
      int dollar50 = 0,
      int dollar20 = 0,
      int dollar10 = 0,
      int dollar5 = 0,
      int dollar1 = 0,
      int quarter = 0,
      int dime = 0,
      int nickel = 0,
      int penny = 0 )
      {
        this->dollar100 = dollar100,
        this->dollar50 = dollar50,
        this->dollar20 = dollar20,
        this->dollar10 = dollar10,
        this->dollar5 = dollar5,
        this->dollar1= dollar1,
        this->quarter = quarter,
        this->dime = dime,
        this->nickel = nickel,
        this->penny = penny,
        this->billcoincount = {
          this->dollar100,
          this->dollar50,
          this->dollar20,
          this->dollar10,
          this->dollar5,
          this->dollar1,
          this->quarter,
          this->dime,
          this->nickel,
          this->penny
        };
        this->cash = 100 * dollar100 + 50 * dollar50 + 20 * dollar20 + 10 * dollar10 + 5 * dollar5 + dollar1 + 0.25*quarter+ 0.10 * dime + 0.05*nickel + 0.01 *penny;
        this->denomination = {100,50,20,10,5, 1,0.25,0.10,0.05,0.01};
    }
};

  void CashRegister::updateBillsCoinsCount(){
    billcoincount = {dollar100,
     dollar50,
     dollar20,
     dollar10,
     dollar5,
     dollar1,
     quarter,
     dime,
     nickel,
     penny};
   }

  void CashRegister::retreiveMoney(){
      updateBillsCoinsCount();
      cout <<"Total Cash in Register ="<< cash << endl;
  }

  void CashRegister::addRemoveCoinBill(int updatedollar100=0, int updatedollar50=0,int updatedollar20=0,int updatedollar10=0, int updatedollar5=0,int updatedollar1=0,int updatequarter=0,int updatedime=0,int updatenickel=0,int updatepenny=0){
    //cout<<"IN addRemoveCoinBill "<<nickel<<"\n";
    //cout<<"nickel + updatenickel "<<nickel + updatenickel<<"\n";

        if (dollar100 + updatedollar100 >=0) {
            dollar100 = dollar100+ updatedollar10;
          }
        if (dollar50 + updatedollar50>=0){
            dollar50 = dollar50 + updatedollar50;
          }
        if (dollar20 + updatedollar20>=0){
            dollar20 = dollar20 + updatedollar20;
          }
        if (dollar10 + updatedollar10>=0){
            dollar10 = dollar10 + updatedollar10;
          }
        if (dollar5 + updatedollar5>=0){
            dollar5 = dollar5 + updatedollar5;
          }
        if (dollar1 + updatedollar1 >=0){
              dollar1 = dollar1 + updatedollar1;
          }
        if (quarter + updatequarter>=0){
                quarter = quarter + updatequarter;
          }
        if (dime + updatedime >=0){
                dime = dime + updatedime;
          }
        if ((nickel + updatenickel) >= 0){
              //cout<<"nickel original" << nickel<<endl;
              nickel = nickel + updatenickel;
              //cout<<"nickel updated" << nickel<<endl;
          }
        if (penny + updatepenny >=0){
              penny = penny + updatepenny;
          }
        updateBillsCoinsCount();
        cash = cash + 100*updatedollar100 + 50*updatedollar50 + 20*updatedollar20+ 10*updatedollar10 + 5 * updatedollar5 + 1*updatedollar1 + 0.25*updatequarter + 0.10 * updatedime + 0.05* updatenickel + 0.01 * updatepenny;

  }

  void CashRegister::giveCountBillCoin(double denomination){
      updateBillsCoinsCount();
      //cout<<"denomination ="<<denomination<<endl;
      if (denomination == 100){
          cout << "No. of bills for $100 = " << dollar100 << endl;
        }
      else if (denomination == 50){
          cout <<"No. of bills for $50 = "<< dollar50 <<endl;
        }
      else if (denomination == 20){
          cout << "No. of bills for $20 = " << dollar20 << endl;
        }
      else if (denomination == 10){
          cout << "No. of bills for $10 = " << dollar10 << endl;
        }
      else if (denomination == 5) {
          cout <<"No. of bills for $5 = "<< dollar5 << endl;
        }
      else if (denomination == 1) {
          cout << "No. of bills for $1 = "<< dollar1 << endl;
        }
      else if (denomination == 0.25f){
          cout << "No. of coins for ¢25 = " << quarter << endl;
        }
      else if (denomination == 0.10f){
          cout << "No. of coins for ¢10 = " << dime << endl;
        }
      else if (denomination == 0.05f){
          cout <<"No. of coins for ¢5 = " << nickel << endl;
        }
      else if  (denomination == 0.01f){
          cout <<"No. of coins for ¢1 =" << penny << endl;
        }
    }

  void CashRegister::minChange(double amountpaid, double total){
      updateBillsCoinsCount();

      double changeamount = amountpaid - total;
      //cout << "changeamount = " << changeamount << endl;
      //cout << "denomination sizeof" << sizeof(denomination)/sizeof(denomination[0])<< endl;



      for(int i = 0; i < denomination.size(); i++) {
        if (billcoincount[i] !=0){

         double double_curr_denomination_count =  (changeamount/denomination[i]);

          int curr_denomination_count =  round(double_curr_denomination_count * 1000.0 ) / 1000.0;


          if (curr_denomination_count <= billcoincount[i]){
              //cout <<"Tuple = "  << denomination[i]<<"="<<curr_denomination_count << endl;
              changeamount = changeamount - (denomination[i]*curr_denomination_count);
              //cout <<"Tuple = "  << denomination[i]<<"="<<curr_denomination_count << endl;
              result.push_back(make_tuple(denomination[i],curr_denomination_count));
            }
          else{
              changeamount = changeamount + denomination[i]*billcoincount[i];
              result.push_back(make_tuple(denomination[i],billcoincount[i]));
            }
        }

      }
      printMinChange();
    }

  void CashRegister::printMinChange(){

        for(int i = 0; i < result.size(); i++){
            cout <<"Bill(s)/Coin(s) for " << get<0>(result[i]) <<" = "<<get<1>(result[i]) << endl;
    }
  }

int main() {
    int dollar100=1;
    int dollar50=0;
    int dollar20=0;
    int dollar10=0;
    int dollar5=0;
    int dollar1=0;
    int quarter=0;
    int dime=0;
    int nickel=1;
    int penny=0;
  //  keysightRegister is the object of CashRegister class

  CashRegister keysightRegister(dollar100, dollar50, dollar20, dollar10, dollar5, dollar1, quarter, dime, nickel, penny);
  keysightRegister.retreiveMoney();
  keysightRegister.giveCountBillCoin(50);
  keysightRegister.giveCountBillCoin(0.05);

  int updatedollar100=0;
  int updatedollar50=0;
  int updatedollar20=0;
  int updatedollar10=0;
  int updatedollar5=0;
  int updatedollar1=1;
  int updatequarter=3;
  int updatedime=0;
  int updatenickel=-1;
  int updatepenny=4;
  keysightRegister.addRemoveCoinBill(updatedollar100, updatedollar50, updatedollar20, updatedollar10, updatedollar5,updatedollar1, updatequarter, updatedime, updatenickel,updatepenny);
  keysightRegister.giveCountBillCoin(0.05);

  keysightRegister.minChange(5.00,3.23);




  return 0;
}
