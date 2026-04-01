#include<iostream>
using namespace std;


struct Package{
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package*next;
};
Package* head = NULL;

struct Courier{
    string couriername;
    string vehicletype;
    Courier*front;
    Courier*rear;
    string Array[5];
};
Courier* bas = NULL;

void add ( string a){
  Package* newPackage = new Package();
  newPackage->packageID = a;
  newPackage->next = NULL;}

  void courierregister(string a){
    Courier*newCourier = new Courier();
    newCourier->couriername = a;
    newCourier->rear = NULL;

  }



int main(){
    string a;
    while(a !="exit"){
        cout<<"Enter the operation: (ARRIVAL,REGISTER,DISPATCH,DISPLAY OR EXIT)"<<endl;
        cin >>a;
        if(a=="ARRIVAL"){
            int Length,Width,Height;
            string destination;
            string ID;
            cout<<"Please enter the package's ID,destination,length, width,height : "<<endl;
            cin >>ID>>destination>>Length>>Width>>Height;
            add(ID);
      

        }
        if(a == "REGISTER"){
            string couriername;
            string vehicle;
            cout<<"Please enter courier's name and vehicle type: "<<endl;
            cin >> couriername,vehicle;
            courierregister(couriername);
    
            
        }
        if(a == "DISPATCH"){
            if(bas->front == NULL){
                delete bas;
                bas = NULL;
            
                delete head;
                head = NULL;

            }
        }
        
        if(a=="DISPLAY"){
            while(head != NULL && bas != NULL ){
                cout<<head<<bas<<endl;
                head = head->next;
                bas = bas->front;

            }

        }
        if(a=="EXIT"){
            cout<<"You have succesfully existed the system\n"<<endl;
            return a=="exit";
        }
        
    }
    



    return 0;
}