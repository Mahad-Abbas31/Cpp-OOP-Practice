#include "Fan.h"
#include <iostream>
#include <fstream>

using namespace std;

void saveToFile(Fan *f,int n);

int main()
{
    int n;
    cout << "Enter number of fans: ";
    cin >> n;

    Fan *f = new Fan[n];


    for(int i=0;i<n;i++)
    {
        string brand, owner;
        int speed, power;
        float price;

        cout << "\nFan " << i+1 << endl;
        cout << "Brand: ";
        cin >> brand;
        cout << "Speed: ";
        cin >> speed;
        cout << "Price: ";
        cin >> price;
        cout << "Power: ";
        cin >> power;
        cout << "Owner: ";
        cin >> owner;

        f[i].setBrand(brand)
            .setSpeed(speed)
            .setPrice(price);

        f[i].setPower(power);
        f[i].setOwner(owner);
    }


    cout << "\n---- All Fans ----\n";

    for(int i=0;i<n;i++)
        f[i].show();


    Fan::showCount();


    cout << "\nAverage Speed = "
         << averageSpeed(f,n) << endl;


    cout << "\nLow Speed Fans\n";
    lowSpeed(f,n);



    // highest speed fan
    int max = f[0].getSpeed();
    int index = 0;

    for(int i=1;i<n;i++)
    {
        if(f[i].getSpeed() > max)
        {
            max = f[i].getSpeed();
            index = i;
        }
    }

    cout << "\nHighest Speed Fan\n";
    f[index].show();


    // operator overloading
    cout << "\nOperator Overloading\n";

    Fan f3 = f[0] + f[1];

    f3.show();


    // another operator use
    Fan f4 = f3 + f[0];

    cout << "\nSecond + Operator\n";
    f4.show();


    saveToFile(f, n);

    delete[] f;

    return 0;
}

// ___ Save to File Function
void saveToFile(Fan *f,int n){
    ofstream fout("fans.txt");

    for(int i=0;i<n;i++)
        fout << f[i].getBrand() << " "
             << f[i].getSpeed() << " "
             << f[i].getPrice() << endl;

    fout.close();
}