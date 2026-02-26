#include<iostream>
#include<string>
#include"Hero.h"

using namespace std;

int main(){
    Hero ironman("TonyStark", "IronMan", "Brain", "America", 50, 7);
    ironman.display();

    Hero hulk("BruceBanner", "Hulk", "Gamma", "America", 41, 5);
    hulk.display();
    
    Hero antMan("Scott", "AntMan", "PymParticles", "America", 41, 3);
    antMan.display();

    Hero capAmerica("SteveRoggers", "CaptainAmerica", "SuperSerum", "America", 41, 2);
    capAmerica.display();

    Hero hulkBuster = ironman;
    hulkBuster.setName("HulkBuster");
    hulkBuster.setPower("Tech");
    hulkBuster.increaseLevel();
    hulkBuster.display();

    

    return 0;
}