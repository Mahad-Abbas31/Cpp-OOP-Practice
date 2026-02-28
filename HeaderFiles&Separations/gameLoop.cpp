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
        int op1;
        
        cout << "-------------------------------\n";
        cout << "      " << hulk.getName() << endl;
        cout << "  Select the Option to Attack:\n";
        cout << "-------------------------------\n";
        cout << "1) Light Attack 1\n";
        cout << "2) Light Attack 2\n";
        cout << "3) Heavy Attack 1\n";
        cout << "4) Heavy Attack 2\n";
        cout << "5) Special Attack 1\n";
        cout << "6) Special Attack 2\n";
        cin >> op1;
        
        switch (op1)
        {
            case 1:    hulk.lightAttack1(ironman);    break;
            case 2:    hulk.lightAttack2(ironman);    break;
            case 3:    hulk.highAttack1(ironman);    break;
            case 4:    hulk.highAttack2(ironman);    break;
            case 5:    hulk.special1(ironman);    break;
            case 6:    hulk.special2(ironman);    break;
            default:    break;
        }
        
        ironman.display();
        
        int op2;
        
        cout << "-------------------------------\n";
        cout << "      " << ironman.getName() << endl;
        cout << "  Select the Option to Attack:\n";
        cout << "-------------------------------\n";
        cout << "1) Light Attack 1\n";
        cout << "2) Light Attack 2\n";
        cout << "3) Heavy Attack 1\n";
        cout << "4) Heavy Attack 2\n";
        cout << "5) Special Attack 1\n";
        cout << "6) Special Attack 2\n";
        cin >> op2;
        
        switch (op2)
        {
            case 1:    ironman.lightAttack1(hulk);    break;
            case 2:    ironman.lightAttack2(hulk);    break;
            case 3:    ironman.highAttack1(hulk);    break;
            case 4:    ironman.highAttack2(hulk);    break;
            case 5:    ironman.special1(hulk);    break;
            case 6:    ironman.special2(hulk);    break;
            default:   break;
        }
        
        hulk.display();
    }
        
        
        
        // ironman.display();
        
        // hulk.display();
        
        // Hero antMan("Scott", "AntMan", "PymParticles", "America", 41, 3);
        // antMan.display();
        
        // Hero capAmerica("SteveRoggers", "CaptainAmerica", "SuperSerum", "America", 41, 2);
        // capAmerica.display();
        
        // Hero hulkBuster = ironman;
        // hulkBuster.setName("HulkBuster");
        // hulkBuster.setPower("Tech");
        // hulkBuster.increaseLevel();
        // hulkBuster.display();
        
        return 0;
    }