/*2019 - W09 - Exercise_9_03.cpp :

Exercise 9.3
 Implementieren Sie eine Klasse Kurs zur Verwaltung der Teilnehmerinnen einer Lehrveranstaltung. 
 Realisieren Sie einen Konstruktor, mit dem der Titel der Lehrveranstaltung festgelegt werden kann und 
 weiters Methoden zur Eingabe von Namen und Matrikelnummern für die einzelnen Studentinnen, 
 die über eine Ihnen zugewiesene Nummer (d.h. einen Index) identifiziert werden. 

 Es muss (über geeignete Methoden) möglich sein, für jede einzelne Studentin die Ergebnisse von Beurteilungen
 (i.e. erreichte Punkte bei Tests) zu speichern und den Durchschnitt der erreichten Punkte pro Studentin und
 pro Kurs zu errechnen. Beachten Sie, dass nicht alle Studierenden an jedem Test teilnehmen. 

 Definieren Sie den Ausgabeoperator <<, um eine Ergebnisliste für den gesamten Kurs auszugeben.
 Zum Testen der Klasse muss ein geeignetes Testprogramm erstellt werden.


*/

#include <iostream>
#include "Course.h"

using namespace std;

int main() {
    Course courseCpp{ 1, "Programmierung 1 (PR1) WS2019",
        string("Die VU Programmierung 1 ist eine Pflichtlehrveranstaltung im Modul PR1") +
        string("der Studieneingangs- und Orientierungsphase (StEOP) des Bachelorstudiums Informatik ") +
        string("(A 033 521 Version 2016) und des Bachelorstudiums Wirtschaftsinformatik") +
        string("(A 033 526 Version 2016) ") };
    //Print simple description of course
    courseCpp.printGeneralInfo();
    
    // fill list of Course
    vector<Student> st_list{
        {7, "James Bond"}, {666, "Devil"}, {77, "Christiano Ronaldo"}
    };
    courseCpp.fillStudentList(st_list);
    cout << "----- Students in " << courseCpp.getName() <<endl;
    courseCpp.printSortedStudentByID();
    cout << endl;

    vector<Assessment> ass_list{
        {1, "C++ Test1"}, {3, "C++ Test3"}, {2, "C++ Test2"}
    };
    courseCpp.fillAssessmentList(ass_list);
    cout << "----- Assessment in " << courseCpp.getName() << endl;
    courseCpp.printSortedAssessmentByID();
    cout << endl;

    vector<Score> sc_list{
        {7,1, 15}, {77, 2, 30}, {666, 3, 49},
        {77,1, 65}, {7, 2, 99}, {666, 2, 55},
        {7,3, 69}, {666, 1, 66}, {77, 3, 77}
    };
    courseCpp.fillScoreList(sc_list);
    cout << "----- Scores in " << courseCpp.getName() << endl;
    courseCpp.printSortedScoresByID();
    cout << endl;

    //calculate average assessment value of a student
    Student ast{77,""};
    cout << "----- Calculate average value of Assessments by Student " << endl;
    double figure = courseCpp.getAvgAssessmentScoreByID(ast);
    cout << "Average value of Assessments: "<< figure << "% \n";

	return 0;
}