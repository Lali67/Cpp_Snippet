/*2019 - W07 - Exercise_7_01.cpp :

Exercise 7.1
    Lösen Sie das Beispiel "Adressverwaltung" aus der Übung mit allen Erweiterungen.

    Erstellen Sie ein struct City bestehend aus zwei Strings für zip_code und city_name
    Definieren Sie im vorgegebenen struct ZIP (/home/Xchange/PR1/ue7/zip.h) die Methoden check und print. 
    check soll true retournieren, wenn der zip_code des this-Objekts in der Liste ZIP.cities gefunden werden
    kann, false sonst. 
    print soll den Code und die zugehörige Bezeichnung der Stadt am Bildschirm ausgeben, 
    wie in der letzten Zeile im Beispiel oben. Kann für eine Postleitzahl kein passender Ort gefunden werden,
    so ist eine Exception vom Typ runtime_error zu werfen.

    Erstellen Sie ein struct Address bestehend aus first_name, surname, road, street_number und zip_code. 
    Die ersten vier Felder sind Strings zip_code hat den Datentyp ZIP.

    Erstellen Sie eine Funktion group, die eine Liste von Adressen (Vektor) als Parameter erhält und 
    einen vector<vector<Address>> als Ergebnis liefert, in dem die Adressen nach Postleitzahl gruppiert sind
    (Der erste Eintrag im Ergebnisvektor beinhaltet eine Liste der Adressen mit der ersten Postleitzahl etc.;
    die Reihenfolge ist unerheblich).

*/

#include <iostream>
#include "address.h"  //address.cpp

int main()
{
    vector<Address> addresses;

    try {
        read_data(addresses);

        cout << "\nAddresses\n\n";
        for (auto& address : addresses) { //const intentionally not used
            address.print();
            cout << "\n\n";
        }

        cout << "\nGrouped Addresses\n\n";
        vector<vector<Address>> grouped_addresses{ group(addresses) };
        for (auto& addresses : grouped_addresses) { //const intentionally not used
            for (auto& address : addresses) { //const intentionally not used
                address.print();
                cout << "\n\n";
            }
            cout << '\n';
        }
    }
    catch (runtime_error & e) {
        cerr << "Error: " << e.what() << '\n';
        cerr << "Program terminated!\n";
    }
    
    return 0;
}