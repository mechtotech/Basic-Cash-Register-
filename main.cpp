#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <iomanip>


using namespace std;

class CashRegister{
  public:
    vector<int> billcoincount;
    vector<tuple<double, int>> result;
    vector<double>denomination;
    double cash;
    double retreiveMoney();
    vector<int> addRemoveCoinBill(int, int,int,int,int,int,int,int,int,int);
    int giveCountBillCoin(double);
    vector<tuple<double, int>> minChange(double,double);
    void printMinChange();
    void updateCashWithPayment(double amountpaid);


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

        this->billcoincount = {
          dollar100,
          dollar50,
          dollar20,
          dollar10,
          dollar5,
          dollar1,
          quarter,
          dime,
          nickel,
          penny
        };
        this->cash = 100 * billcoincount[0] + 50 * billcoincount[1] + 20 * billcoincount[2] + 10 * billcoincount[3] + 5 * billcoincount[4] +billcoincount[5] + 0.25 * billcoincount[6]+ 0.10 * billcoincount[7] + 0.05 * billcoincount[8] + 0.01 * billcoincount[9];
        this->denomination = {100,50,20,10,5, 1,0.25,0.10,0.05,0.01};
    }
};

  double CashRegister::retreiveMoney(){
      cash = 100 * billcoincount[0] + 50 * billcoincount[1] + 20 * billcoincount[2] + 10 * billcoincount[3] + 5 * billcoincount[4] +billcoincount[5] + 0.25 * billcoincount[6]+ 0.10 * billcoincount[7] + 0.05 * billcoincount[8] + 0.01 * billcoincount[9];
      cout <<"Total Cash in Register ="<< cash << endl;
      return cash;
  }

   vector<int> CashRegister::addRemoveCoinBill(int updatedollar100=0, int updatedollar50=0,int updatedollar20=0,int updatedollar10=0, int updatedollar5=0,int updatedollar1=0,int updatequarter=0,int updatedime=0,int updatenickel=0,int updatepenny=0){
    //cout<<"IN addRemoveCoinBill "<<nickel<<"\n";
    //cout<<"nickel + updatenickel "<<nickel + updatenickel<<"\n";

        if (billcoincount[0] + updatedollar100 >=0) {
            billcoincount[0] += updatedollar10;
          }
        if (billcoincount[1] + updatedollar50>=0){
            billcoincount[1] += updatedollar50;
          }
        if (billcoincount[2] + updatedollar20>=0){
            billcoincount[2] += updatedollar20;
          }
        if (billcoincount[3] + updatedollar10>=0){
            billcoincount[3] += updatedollar10;
          }
        if (billcoincount[4] + updatedollar5>=0){
            billcoincount[4] += updatedollar5;
          }
        if (billcoincount[5] + updatedollar1 >=0){
              billcoincount[5] += updatedollar1;
          }
        if (billcoincount[6] + updatequarter>=0){
                billcoincount[6] +=  updatequarter;
          }
        if (billcoincount[7] + updatedime >=0){
                billcoincount[7] += updatedime;
          }
        if ((billcoincount[8] + updatenickel) >= 0){
              //cout<<"nickel original" << nickel<<endl;
              billcoincount[8] += updatenickel;
              //cout<<"nickel updated" << nickel<<endl;
          }
        if (billcoincount[9] + updatepenny >=0){
             billcoincount[9] += updatepenny;
          }
        cash =  100 * billcoincount[0] + 50 * billcoincount[1] + 20 * billcoincount[2] + 10 * billcoincount[3] + 5 * billcoincount[4] +billcoincount[5] + 0.25 * billcoincount[6]+ 0.10 * billcoincount[7] + 0.05 * billcoincount[8] + 0.01 * billcoincount[9];

       return billcoincount;
   }

  int CashRegister::giveCountBillCoin(double denomination){

      //cout<<"denomination ="<<denomination<<endl;
      if (denomination == 100){
          cout << "No. of bills for $100 = " << billcoincount[0] << endl;
          return billcoincount[0];
        }
      if (denomination == 50){
          cout <<"No. of bills for $50 = "<< billcoincount[1]<<endl;
          return billcoincount[1];
        }
      if (denomination == 20){
          cout << "No. of bills for $20 = " << billcoincount[2] << endl;
          return billcoincount[2];
        }
      if (denomination == 10){
          cout << "No. of bills for $10 = " << billcoincount[3] << endl;
          return billcoincount[3];
        }
     if (denomination == 5) {
          cout <<"No. of bills for $5 = "<< billcoincount[4] << endl;
          return billcoincount[4];
        }
      if (denomination == 1) {
          cout << "No. of bills for $1 = "<< billcoincount[5] << endl;
          return billcoincount[5];
        }
      if (denomination == 0.25){
          cout << "No. of coins for ¢25 = " << billcoincount[6] << endl;
          return billcoincount[6];
        }
      if (denomination == 0.10){
          cout << "No. of coins for ¢10 = " << billcoincount[7] << endl;
          return billcoincount[7];
        }
      if (denomination == 0.05){
          cout <<"No. of coins for ¢5 = " << billcoincount[8] << endl;
          return billcoincount[8];
        }
      if  (denomination == 0.01){
          cout <<"No. of coins for ¢1 =" << billcoincount[9] << endl;
          return billcoincount[9];
        }

    }

  vector<tuple<double, int>> CashRegister::minChange(double amountpaid, double total){
      result.clear();
      double changeamount = amountpaid - total;

      if (changeamount < 0){
          cout << "Invalid Entry" <<endl;

      }
      else{
    updateCashWithPayment(amountpaid);

      cout << "Change Amount = $ " << changeamount << endl;
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
              billcoincount[i] = billcoincount[i] - curr_denomination_count;
              //cout<<billcoincount[i]<<endl;
            }
          else{
              changeamount = changeamount - denomination[i]*billcoincount[i];

              result.push_back(make_tuple(denomination[i],billcoincount[i]));
              billcoincount[i] = 0;
              //cout << billcoincount[i]<<endl;

            }
        }

      }


      printMinChange();
      }
      return result;
    }

   //Assume payment done with min number of denominations
  void CashRegister::updateCashWithPayment(double amountpaid){

      cout << "Amount Paid  = $ " << amountpaid << endl;
      //cout << "denomination sizeof" << sizeof(denomination)/sizeof(denomination[0])<< endl;


      for(int i = 0; i < denomination.size(); i++) {


         double double_curr_denomination_count =  amountpaid/denomination[i];

         int curr_denomination_count =  round(double_curr_denomination_count * 1000.0 ) / 1000.0;

             //cout <<"Tuple = "  << denomination[i]<<"="<<curr_denomination_count << endl;
              amountpaid = amountpaid - (denomination[i]*curr_denomination_count);
              //cout <<"Tuple = "  << denomination[i]<<"="<<curr_denomination_count << endl;
              billcoincount[i] = billcoincount[i] + curr_denomination_count;
              cout<<billcoincount[i]<<endl;
      }
    }

  void CashRegister::printMinChange(){

        for(int i = 0; i < result.size(); i++){
            cout <<"Change Amount for bill(s)/coin(s) for $ " << get<0>(result[i]) <<" = "<<get<1>(result[i]) << endl;
    }
  }

int main() {
    int dollar100=1;
    int dollar50=1;
    int dollar20=1;
    int dollar10=1;
    int dollar5=1;
    int dollar1=1;
    int quarter=1;
    int dime=1;
    int nickel=1;
    int penny=1;
  //  keysightRegister is the object of CashRegister class

  CashRegister keysightRegister(dollar100, dollar50, dollar20, dollar10, dollar5, dollar1, quarter, dime, nickel, penny);
  keysightRegister.retreiveMoney();
  keysightRegister.giveCountBillCoin(100);
  keysightRegister.giveCountBillCoin(50);
  keysightRegister.giveCountBillCoin(20);
  keysightRegister.giveCountBillCoin(10);
  keysightRegister.giveCountBillCoin(5);
  keysightRegister.giveCountBillCoin(1);
  keysightRegister.giveCountBillCoin(0.25);
  keysightRegister.giveCountBillCoin(0.10);
  keysightRegister.giveCountBillCoin(0.05);
  keysightRegister.giveCountBillCoin(0.01);


  int updatedollar100=1;
  int updatedollar50=1;
  int updatedollar20=1;
  int updatedollar10=1;
  int updatedollar5=1;
  int updatedollar1=1;
  int updatequarter=1;
  int updatedime=1;
  int updatenickel=2;
  int updatepenny=4;

  keysightRegister.addRemoveCoinBill(updatedollar100, updatedollar50, updatedollar20, updatedollar10, updatedollar5,updatedollar1, updatequarter, updatedime, updatenickel,updatepenny);
  keysightRegister.giveCountBillCoin(100);
  keysightRegister.giveCountBillCoin(50);
  keysightRegister.giveCountBillCoin(20);
  keysightRegister.giveCountBillCoin(10);
  keysightRegister.giveCountBillCoin(5);
  keysightRegister.giveCountBillCoin(1);
  keysightRegister.giveCountBillCoin(0.25);
  keysightRegister.giveCountBillCoin(0.10);
  keysightRegister.giveCountBillCoin(0.05);
  keysightRegister.giveCountBillCoin(0.01);

  keysightRegister.retreiveMoney();


  keysightRegister.minChange(4.00,3.22);

  keysightRegister.retreiveMoney();
  keysightRegister.giveCountBillCoin(100);
  keysightRegister.giveCountBillCoin(50);
  keysightRegister.giveCountBillCoin(20);
  keysightRegister.giveCountBillCoin(10);
  keysightRegister.giveCountBillCoin(5);
  keysightRegister.giveCountBillCoin(1);
  keysightRegister.giveCountBillCoin(0.25);
  keysightRegister.giveCountBillCoin(0.10);
  keysightRegister.giveCountBillCoin(0.05);
  keysightRegister.giveCountBillCoin(0.01);




  return 0;
}
