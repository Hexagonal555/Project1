#include <iostream>
#include <cstring>

using namespace std;
class DisciplinaryAction{
private:
    char *name{},*reason{};
    int id{},kazneti{};

public:
    DisciplinaryAction()= default;
    DisciplinaryAction(char *name,int id,char *reason,int kazneti){
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->reason=new char[strlen(reason)+1];
        strcpy(this->reason,reason);
        this->id=id;
        this->kazneti=kazneti;

    }
    ~DisciplinaryAction(){
        delete[]name;
        delete[]reason;
    }
    DisciplinaryAction(const DisciplinaryAction &d){
        name=new char[strlen(d.name)+1];
        strcpy(name,d.name);
        reason=new char[strlen(d.reason)+1];
        strcpy(reason,d.reason);
        id=d.id;
        kazneti=d.kazneti;
    }
    DisciplinaryAction &operator=(const DisciplinaryAction &d){
        if(this!=&d){
            delete[]name;
            delete[]reason;
            name=new char[strlen(d.name)+1];
            strcpy(name,d.name);
            reason=new char[strlen(d.reason)+1];
            strcpy(reason,d.reason);
            id=d.id;
            kazneti=d.kazneti;

        }
        return *this;
    }
    void setIndex(int idx){
        id=idx;
    }
    friend ostream &operator<<(ostream &out,const DisciplinaryAction &d){
        out<<"Student: "<<d.name<<endl;
        out<<"Student's index: "<<d.id<<endl;
        out<<"Reason: "<<d.reason<<endl;
        out<<"Sessions: "<<d.kazneti<<endl;
        return out;
    }
    DisciplinaryAction &operator++(){
        ++kazneti;
        return *this;
    }
    bool operator>=(DisciplinaryAction &d)const{
        if(kazneti>=d.kazneti)return true;
        return false;
    }
};

int main (){

    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;
        int sessions;

        cin >> name >> index >> reason >> sessions;

        arr[i] = DisciplinaryAction(name, index, reason, sessions);
    }

    cout << "-- Testing operator = & operator <<  --\n";
    cout << arr[0];

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    cout << arr[0];

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    cout << merka;

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for (int i = 0; i < n; i++)
        cout << arr[i];


    cout << "\nTesting operator ++ and <<" << endl;
    for (int i = 0; i < n; i++)
        //       cout << (++arr[i]);


        cout << "\nTesting operator >=" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                //    cout << i << " " << ((arr[i] >= arr[j]) ? ">= " : "< ") << j << endl;
            }
        }
    }



    return 0;
}