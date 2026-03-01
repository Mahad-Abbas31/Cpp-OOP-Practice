#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include"Hero.h"

using namespace std;

int main(){
    srand(time(0));

    Hero ironman("TonyStark", "IronMan", "Brain", "America", 50, 7);
    Hero hulk("BruceBanner", "Hulk", "Gamma", "America", 41, 5);

    
    while(ironman.getHealth()>0  &&  hulk.getHealth()>0 ){

        ironman.takeTurn(hulk);        
        ironman.display();

        if (ironman.getHealth() <= 0) {
            cout << "\n*** " << ironman.getName() << " has been defeated! "
                 << hulk.getName() << " wins! ***\n";
            break;
        }

        hulk.takeTurn(ironman);
        hulk.display();
    }
               
    return 0;
}