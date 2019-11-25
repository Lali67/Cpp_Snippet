/*2019 - W07 - Exercise_7_02.cpp :

Exercise 7.2
    Lösen Sie das Beispiel "Auto" aus der Übung mit allen Erweiterungen.

    Erstellen Sie ein struct Car aus den Feldern brand (String), type (String), kW (int), color (enum) und 
    extras (enum Liste).
    Ein Auto kann nur eine Farbe haben, aber beliebig viele Extras.
    Schreiben Sie die Methoden print und read, um den Zustand eines Autos auf dem Bildschirm auszugeben, 
    oder von der Tastatur einzulesen.
    Beachten Sie beim Einlesen, dass jedes Extra nur einmal in der Liste der Extras auftreten darf.
    Für die Ein-/Ausgabe ist es vorteilhaft, für die enums globale Konstanten mit den passenden 
    Bezeichnungen zu definieren, z.B.:
    const vector<string> color_names{"red","green","blue"};
    enum class Color {red, green, blue} color{Color::blue};
    cout<< color_names.at(static_cast<size_t>(Color::green));
    cout<< color_names.at(static_cast<size_t>(color));

    Schreiben Sie eine Funktion histogram, die einen Vektor von Autos als Parameter bekommt und
    einen Vektor liefert, der die Anzahlen der Autos in einer bestimmten Farbe enthält. 
    Die Anzahl für eine Farbe soll dabei im Vektor an der, dem enum-Wert entsprechenden Indexposition 
    gespeichert werden
    Geben Sie das Ergebnis "grafisch" aus, z.B.: 
    red:******* 
    green:**

*/

#include <iostream>
#include "auto.h"  //auto.cpp

int main()
{
    Car aCar;
    vector<Car> cars{ 
        {"Skoda", "Octavia 2.0 TDI", 110, Color::white,
        {CarExtrasList::four_wheel_drive, CarExtrasList::adaptive_LED_headlights} } };

    cars.at(0).print();
    //read a Car
    aCar.read();
    cars.push_back(aCar);

    //histogram
    histogram(cars);

    return 0;
}