#include<iostream>
using namespace std;

class Valentine{
    public:
        void showlove(){
            cout<<"Love you,honey!"<<endl;
        }
};

int main(void){
    Valentine darling;
    darling.showlove();
    system("pause"); 
    return 0;
}