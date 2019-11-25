#include<iostream>
#include<string>
#include<vector>
#include"auto.h"

using namespace std;

ostream& Car::print(ostream& o) {
    o << brand << " " << type << " (" << kW << " kW, " <<
        color_names.at(static_cast<size_t>(color)) << " )\n";
    o << "Extras: ";
    for (CarExtrasList extra : extras)
        o << extras_names.at(static_cast<size_t>(extra)) << ", ";
    o << endl;

    return o;
};

void Car::read(istream& input, ostream& output) {
    int val;

    output << "Band            : "; input >> brand; 
    output << "Type            : "; input >> type;
    output << "kW              : "; input >> kW;
    output << "Color code (0-9): "; input >> val;
    color = static_cast<Color>(val);
    output << " (" << color_names.at(static_cast<size_t>(color)) << ") \n";
    
    output << "Extra names     : \n";
    for (string name : extras_names) output << name << " ";
    output << endl;
    while (input >> val) extras.push_back(static_cast<CarExtrasList>(val));

    output << endl;
};

void histogram(vector<Car> cars, ostream& output) {
    vector<int> allColors;
    output << "----- Color histogram -----\n";
    for (int i = 0; i < int(Color::other); i++)  allColors.push_back(0);
    
    //count the number of unique colors into right position of vector
    for (Car aCar : cars) allColors.at(static_cast<size_t>(aCar.color))++;
    
    // print star as same number as sum of car color in 'cars' vector
    for (int i = 0; i < int(Color::other); i++) {
        output << color_names.at(i) << ": ";
        int color_num = allColors.at(i);
        while (color_num--) output << "*";
        output << endl;
    }
};

bool find(vector<Car> cars, DesiredCar desiredCar) {
    bool foundCar{ false };
    
    for (Car aCar : cars) {
        //check brand 
        if (aCar.brand == desiredCar.brand) {
            foundCar = true;
            cout << "Brand meets expectation: \n";
            aCar.print();
        }
        else if (aCar.type == desiredCar.type) {
            foundCar = true;
            cout << "Type meets expectation: \n";
            aCar.print();
        }
        else if (aCar.kW == desiredCar.kW) {
            foundCar = true;
            cout << "Power meets expectation: \n";
            aCar.print();
        }
        else {
            for (Color desiredColor : desiredCar.colors) {
                if (aCar.color == desiredColor) {
                    foundCar = true;
                    cout << "Color meets expectation: \n";
                    aCar.print();
                    break;
                }
            }
            bool foundExtra{ false };
            for (CarExtrasList desiredExtra : desiredCar.extras) {
                if (foundExtra) break;
                for (CarExtrasList Extra : aCar.extras) {
                    if (desiredExtra == Extra) {
                        foundExtra = true;
                        foundCar = true;
                        break;
                    }
                }
            }
            if (foundExtra) {
                cout << "Extra meets expectation: \n";
                aCar.print();
            }
        }

    }

    return foundCar;
};