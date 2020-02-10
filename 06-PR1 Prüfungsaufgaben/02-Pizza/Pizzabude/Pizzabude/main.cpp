#include <iostream>
#include <string>
#include <vector>
#include "topping.h"
#include "pizza.h"

using namespace std;

int main() {
	try {
		cout << "Class Topping:\n";
		try {
			Topping t{ "" };
			cout << "test 1 " << t << '\n';
		}
		catch (runtime_error& e) {
			cout << "catch 1\n";
		}
		try {
			Topping t{ "","AE",true };
			cout << "test 2 " << t << '\n';
		}
		catch (runtime_error& e) {
			cout << "catch 2\n";
		}
		const vector<Topping> vt{ {"Prosciutto","",true},{"Ham"},{"Frutti di mare","ABDR",true},{"Mozzarella","G"},
								{"Olives"},{"Mushrooms"},{"Garlic","GM"},{"Salami","M"},{"Bacon"},{"Peppers","FM"},
								{"Thuna","DF"}, {"Cheese","G"}, {"Tomato sauce"}, {"Sunflower seed","AEFGHMN"},
								{"Onions"},{"Escargots","R",true} };
		for (const auto& t : vt)
			cout << t << (t.is_specialty() ? "! " : " ");
		cout << '\n';
		for (size_t i{ 1 }; i < vt.size(); i += 7) {
			for (const auto& t : vt)
				cout << (t == vt.at(i));
			cout << '\n';
		}
		cout << (vt.at(13) == Topping{ "Sunflower seed","",true }) << '\n';

		cout << "\nClass Pizza:\n";
		try {
			Pizza p{ {vt.at(5),vt.at(2)}, {vt.at(11),vt.at(2),vt.at(5),vt.at(12)} };
			cout << "test 3 " << p << '\n';
		}
		catch (runtime_error& e) {
			cout << "catch 3\n";
		}
		try {
			Pizza p{ {}, {vt.at(12),vt.at(2),vt.at(5),vt.at(11)} };
			cout << "test 4 " << p << '\n';
		}
		catch (runtime_error& e) {
			cout << "catch 4\n";
		}
		try {
			Pizza p{ {vt.at(12)}, {vt.at(11),vt.at(2),vt.at(5),vt.at(12)} };
			cout << "test 5 " << p << '\n';
		}
		catch (runtime_error& e) {
			cout << "catch 5\n";
		}
		const vector<Pizza> vp{ {{vt.at(0),vt.at(2),vt.at(15)}},{},{{},{vt.at(11)}},{{},{vt.at(12)}},
							   {{vt.at(2),vt.at(3),vt.at(6),vt.at(7),vt.at(9),vt.at(10),vt.at(11),vt.at(13),vt.at(15)}},
							   {{vt.at(1),vt.at(4),vt.at(5),vt.at(8)},{vt.at(11),vt.at(12),vt.at(3)}} };
		for (const auto& p : vp)
			cout << p << '\n';
		for (const auto& p : vp)
			cerr << p << '\n';

		// Dekommentieren fuer Zusatz allergenes
		/*
		  cout << "\nAdditional task allergenes\n";
		  for (const auto& p : vp)
			cout << p.allergenes() << '\n';
		*/

		// Dekommentieren fuer Zusatz accommodate
		/*
		  cout << "\nAdditional task accomodate\n";
		  Pizza test{vp.at(0)};
		  test.accommodate("ABDGR");
		  cout << test << '\n';
		  test = vp.at(4);
		  test.accommodate("DGR");
		  cout << test << '\n';
		  test.accommodate("");
		  cout << test << '\n';
		  test.accommodate("FH");
		  cout << test << '\n';
		  test = Pizza{{vt.at(6),vt.at(3)},{vt.at(12)}};
		  try {
			test.accommodate("G");
			cout << "test 6" << test << '\n';
		  }
		  catch (runtime_error& e) {
			cout << "catch 6\n";
		  }
		  cout << test << '\n';
		*/
	}
	catch (exception& e) {
		cout << "Unexpected exception: " << e.what() << '\n';
	}
	catch (...) {
		cout << "Non standard exception thrown!";
	}
	return 0;
}

/* Erwartete Ausgabe:
Class Topping:
catch 1
catch 2
Prosciutto! Ham Frutti di mare (A, B, D, R)! Mozzarella (G) Olives Mushrooms Garlic (G, M) Salami (M) Bacon Peppers (F, M) Thuna (D, F) Cheese (G) Tomato sauce Sunflower seed (A, E, F, G, H, M, N) Onions Escargots (R)!
0100000000000000
0000000010000000
0000000000000001
1

Class Pizza:
test 3 [{Mushrooms, Frutti di mare (A, B, D, R)}, 7.5 Euro]
catch 4
test 5 [{Tomato sauce}, 7 Euro]
[{Tomato sauce, Cheese (G), Prosciutto, Frutti di mare (A, B, D, R), Escargots (R)}, 9.5 Euro]
[{Tomato sauce, Cheese (G)}, 7 Euro]
[{Tomato sauce}, 7 Euro]
[{Cheese (G)}, 7 Euro]
[{Tomato sauce, Cheese (G), Frutti di mare (A, B, D, R), Mozzarella (G), Garlic (G, M), Salami (M), Peppers (F, M), Thuna (D, F), Sunflower seed (A, E, F, G, H, M, N), Escargots (R)}, 14 Euro]
[{Ham, Olives, Mushrooms, Bacon}, 7 Euro]
[{Tomato sauce, Cheese (G), Prosciutto, Frutti di mare (A, B, D, R), Escargots (R)}, 9.5 Euro]
[{Tomato sauce, Cheese (G)}, 7 Euro]
[{Tomato sauce}, 7 Euro]
[{Cheese (G)}, 7 Euro]
[{Tomato sauce, Cheese (G), Frutti di mare (A, B, D, R), Mozzarella (G), Garlic (G, M), Salami (M), Peppers (F, M), Thuna (D, F), Sunflower seed (A, E, F, G, H, M, N), Escargots (R)}, 14 Euro]
[{Ham, Olives, Mushrooms, Bacon}, 7 Euro]

Additional task allergenes
ABDGR
AG
A
AG
ABDEFGHMNR
A

Additional task accomodate
[{Tomato sauce, Prosciutto}, 7.5 Euro]
[{Tomato sauce, Salami (M), Peppers (F, M)}, 7 Euro]
[{Tomato sauce, Salami (M), Peppers (F, M)}, 7 Euro]
[{Tomato sauce, Salami (M)}, 7 Euro]
catch 6
[{Cheese (G), Garlic (G, M), Mozzarella (G)}, 7 Euro]
*/