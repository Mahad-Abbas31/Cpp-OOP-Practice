#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include"Hero.h"

using namespace std;

// __ Have to make it universal for all heroes, so that we can use it in the future for any hero
int main(){
    srand(time(0));

    Hero player;
    Hero enemy;

    // ___ Heroes
    Hero ironman("TonyStark", "IronMan", "Brain", "America", 50, 7);
    Hero hulk("BruceBanner", "Hulk", "Gamma", "America", 41, 5);
    Hero captainAmerica("SteveRogers", "CaptainAmerica", "Shield", "America", 45, 6);
    Hero thor("ThorOdinson", "Thor", "Thunder", "Asgard", 60, 8);
    Hero antMan("ScottLang", "AntMan", "pymParticles", "America", 38, 4);
    Hero blackPanther("TChalla", "BlackPanther", "Vibranium", "Wakanda", 42, 6);
    Hero Loki("Loki", "Loki", "Illusion", "Asgard", 55, 7);
    Hero hulkBuster("BruceBanner", "HulkBuster", "Technology", "America", 45, 6);
    Hero captainMarvel("CarolDanvers", "CaptainMarvel", "Energy", "America", 48, 7);
    Hero shangChi("ShangChi", "ShangChi", "MartialArts", "Japan", 40, 5);


            
    int op;
        
    cout << "------------------------------------\n";
    cout << "            PLAYER SELECT           \n";
    cout << "------------------------------------\n";
    cout << "1. IronMan" << endl << "2. Hulk" << endl 
         << "3. CaptainAmerica" << endl << "4. Thor" << endl 
         << "5. AntMan" << endl << "6. BlackPanther" << endl 
         << "7. Loki" << endl << "8. HulkBuster" << endl 
         << "9. CaptainMarvel" << endl << "10. ShangChi" << endl;
        
    cin >> op;

    switch (rand()%10 + 1){
        case 1:    enemy = hulk;               break;
        case 2:    enemy = captainAmerica;     break;
        case 3:    enemy = thor;               break;
        case 4:    enemy = antMan;             break;
        case 5:    enemy = blackPanther;       break;
        case 6:    enemy = Loki;               break;
        case 7:    enemy = hulkBuster;         break;
        case 8:    enemy = captainMarvel;      break;
        case 9:    enemy = shangChi;           break;
       case 10:    enemy = ironman;            break;
    };
        
    switch(op){
        case 1:    player = ironman;           break;
        case 2:    player = hulk;              break;
        case 3:    player = captainAmerica;    break;
        case 4:    player = thor;              break;
        case 5:    player = antMan;            break;
        case 6:    player = blackPanther;      break;
        case 7:    player = Loki;              break;
        case 8:    player = hulkBuster;        break;
        case 9:    player = captainMarvel;     break;
       case 10:    player = shangChi;          break;
                    
    };

    player.gameLoop(player, enemy);
              
    return 0;
}

