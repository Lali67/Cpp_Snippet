#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"show.h"
#include"tvstation.h"

using namespace std;

int main(){

  // Show Konstruktor

  try{
    Show s{"", Genre::Sitcom};
    cout << s << '\n';
  }
  catch(runtime_error& e){
    cout << "Error1" << "\n";
  }
  try{
    Show s{"Scrubs", Genre::Sitcom,0};
    cout << s << '\n';
  }
  catch(runtime_error& e){
    cout << "Error2" << "\n";
  }
  try{
    Show s{"Scrubs", Genre::Sitcom,11};
    cout << s << '\n';
  }
  catch(runtime_error& e){
    cout << "Error3" << "\n";
  }
  const Show cs1{"How I Met your Mother", Genre::Sitcom,10};
  const Show cs2{"Star Trek", Genre::SciFi,9};

  cout << cs1 << '\n';
  cerr << cs1 << '\n';


  Show gg{"Gossip Girl",Genre::Drama,4};
  Show got{"Game of Thrones",Genre::Fantasy,10};
  Show pic{"Picard",Genre::SciFi};
  Show rr{"Rick & Morty",Genre::Cartoon};
  Show bm{"Big Mouth",Genre::Cartoon,3};
  Show bbt{"Big Bang Theory",Genre::Sitcom,10};

  cout << gg << '\n';
  cerr << gg << '\n';


  // cancel
  
  rr.cancel();
  got.cancel();
  try{
    got.cancel();
    cout << "canceled" << '\n';
  }catch(runtime_error &e){
    cout << "Error4" << '\n';
  }

  // produce season
  
  cout << gg.produce_season() << '\n';
  cout << bbt.produce_season() << '\n';
  cout << rr.produce_season() << '\n';

  // reboot
  
  cout << rr.reboot("") << '\n';
  cout << rr.reboot("Reboot rr") << '\n';
  cout << gg.reboot("Reboot gg") << '\n';
  cout << got.reboot("Reboot got") << '\n';

  // has_genre

  cout << gg.has_genre(Genre::Sitcom) << '\n';
  cout << gg.has_genre(Genre::Drama) << '\n';
  cout << got.has_genre(Genre::Drama) << '\n';
  cout << got.has_genre(Genre::Fantasy) << '\n';
  cout << cs1.has_genre(Genre::Sitcom) << '\n';
  cout << cs2.has_genre(Genre::Fantasy) << '\n';


  // output
  
  rr.cancel();
  pic.cancel();
  bm.cancel();
  cout << cs1 << '\n';
  cout << gg << '\n';
  cout << rr << '\n';
  cout << bbt << '\n';
  cerr << bbt << '\n';
  bbt.cancel();
  cout << bbt << '\n';
  cerr << bbt << '\n';

  
  // TV_Station
  
  // Konstruktor
  
  try{
    TV_Station t{"ABC",{}};
    cout << t << '\n';
  }catch(runtime_error& e){
    cout << "Error5" << '\n';
  }
  try{
    TV_Station t{"",{Genre::Sitcom}};
    cout << t << '\n';
  }catch(runtime_error& e){
    cout << "Error6" << '\n';
  }
  try{
    TV_Station t{"ABC",{Genre::Sitcom},{bbt,gg}};
    cout << t << '\n';
  }catch(runtime_error& e){
    cout << "Error7" << '\n';
  }

  TV_Station abc{"ABC",{Genre::Sitcom,Genre::Cartoon,Genre::SciFi},{pic,rr,bbt,Show{"Friends",Genre::Sitcom,10}}};
  TV_Station bbc{"BBC",{Genre::Fantasy},{got,Show{"The Witchers",Genre::Fantasy}}};
  TV_Station cad{"CAD",{Genre::Fantasy,Genre::Cartoon,Genre::Drama},{got,gg,bm,Show{"Inuyasha",Genre::Fantasy,5},Show{"Tom & jerry", Genre::Cartoon,9}}};

  // add_shows
  for(const auto& s : abc.add_shows({pic,rr,Show{"The Witcher",Genre::Fantasy},got,bm,Show{"Inuyasha",Genre::Cartoon,5}}))
    cout << s << '\n';
  for(const auto& s : bbc.add_shows({}))
    cout << s << '\n';
  for(const auto& s : cad.add_shows({pic,rr,Show{"The Witcher",Genre::Fantasy},got,bm,Show{"Inuyasha",Genre::Cartoon,4},gg}))
    cout << s << '\n';

  // produce
  
  cout << abc << '\n';
  cout << abc.produce() << '\n';
  cout << abc << '\n';
  cout << bbc << '\n';
  cout << bbc.produce() << '\n';
  cout << bbc << '\n';
  
  //output

  cout << cad << '\n';
  cerr << cad << '\n';
  
  //Basisfunktionalitaet Ende
  //Zusatz 1 
  /*
    cout << abc.mass_reboot() << '\n';
    cout << abc << '\n';
    cout << bbc.mass_reboot() << '\n';
    cout << bbc << '\n';
    cout << cad.mass_reboot() << '\n';
    cout << cad << '\n';
    cout << cad.mass_reboot() << '\n';
    cout << cad << '\n';
  */

  // Zusatz 2
  /*
  vector<TV_Station> tvs{abc,bbc,cad};
  for(const auto& s : TV_Station::blacklist({Genre::Fantasy,Genre::Cartoon,Genre::Sitcom},tvs))
    cout << s << '\n';
  */


  return 0;
}

/* Erwarteter Output
Error1
Error2
Error3
[*How I Met your Mother*, 10 Staffel(n), Sitcom]
[*How I Met your Mother*, 10 Staffel(n), Sitcom]
[*Gossip Girl*, 4 Staffel(n), Drama]
[*Gossip Girl*, 4 Staffel(n), Drama]
Error4
1
0
0
0
1
0
0
0
1
0
1
1
0
[*How I Met your Mother*, 10 Staffel(n), Sitcom]
[*Gossip Girl*, 5 Staffel(n), Drama]
[Reboot rr, 2 Staffel(n), Cartoon]
[*Big Bang Theory*, 10 Staffel(n), Sitcom]
[*Big Bang Theory*, 10 Staffel(n), Sitcom]
[Big Bang Theory, 10 Staffel(n), Sitcom]
[Big Bang Theory, 10 Staffel(n), Sitcom]
Error5
Error6
Error7
[*The Witcher*, 1 Staffel(n), Fantasy]
[Game of Thrones, 10 Staffel(n), Fantasy]
[Picard, 1 Staffel(n), Sci-Fi]
[ABC, [Sitcom, Cartoon, Sci-Fi], {[Picard, 1 Staffel(n), Sci-Fi], [Reboot rr, 2 Staffel(n), Cartoon], [Big Bang Theory, 10 Staffel(n), Sitcom], [*Friends*, 10 Staffel(n), Sitcom], [Picard, 1 Staffel(n), Sci-Fi], [Reboot rr, 2 Staffel(n), Cartoon], [Big Mouth, 3 Staffel(n), Cartoon], [*Inuyasha*, 5 Staffel(n), Cartoon]}]
1
[ABC, [Sitcom, Cartoon, Sci-Fi], {[Picard, 1 Staffel(n), Sci-Fi], [Reboot rr, 2 Staffel(n), Cartoon], [Big Bang Theory, 10 Staffel(n), Sitcom], [*Friends*, 10 Staffel(n), Sitcom], [Picard, 1 Staffel(n), Sci-Fi], [Reboot rr, 2 Staffel(n), Cartoon], [Big Mouth, 3 Staffel(n), Cartoon], [*Inuyasha*, 6 Staffel(n), Cartoon]}]
[BBC, [Fantasy], {[Game of Thrones, 10 Staffel(n), Fantasy], [*The Witchers*, 1 Staffel(n), Fantasy]}]
1
[BBC, [Fantasy], {[Game of Thrones, 10 Staffel(n), Fantasy], [*The Witchers*, 2 Staffel(n), Fantasy]}]
[CAD, [Fantasy, Cartoon, Drama], {[Game of Thrones, 10 Staffel(n), Fantasy], [*Gossip Girl*, 5 Staffel(n), Drama], [Big Mouth, 3 Staffel(n), Cartoon], [*Inuyasha*, 5 Staffel(n), Fantasy], [*Tom & jerry*, 9 Staffel(n), Cartoon], [Reboot rr, 2 Staffel(n), Cartoon], [*The Witcher*, 1 Staffel(n), Fantasy], [Game of Thrones, 10 Staffel(n), Fantasy], [Big Mouth, 3 Staffel(n), Cartoon], [*Inuyasha*, 4 Staffel(n), Cartoon], [*Gossip Girl*, 5 Staffel(n), Drama]}]
[CAD, [Fantasy, Cartoon, Drama], {[Game of Thrones, 10 Staffel(n), Fantasy], [*Gossip Girl*, 5 Staffel(n), Drama], [Big Mouth, 3 Staffel(n), Cartoon], [*Inuyasha*, 5 Staffel(n), Fantasy], [*Tom & jerry*, 9 Staffel(n), Cartoon], [Reboot rr, 2 Staffel(n), Cartoon], [*The Witcher*, 1 Staffel(n), Fantasy], [Game of Thrones, 10 Staffel(n), Fantasy], [Big Mouth, 3 Staffel(n), Cartoon], [*Inuyasha*, 4 Staffel(n), Cartoon], [*Gossip Girl*, 5 Staffel(n), Drama]}]
5
[ABC, [Sitcom, Cartoon, Sci-Fi], {[*Picard Reboot*, 2 Staffel(n), Sci-Fi], [*Reboot rr Reboot*, 3 Staffel(n), Cartoon], [Big Bang Theory, 10 Staffel(n), Sitcom], [*Friends*, 10 Staffel(n), Sitcom], [*Picard Reboot*, 2 Staffel(n), Sci-Fi], [*Reboot rr Reboot*, 3 Staffel(n), Cartoon], [*Big Mouth Reboot*, 4 Staffel(n), Cartoon], [*Inuyasha*, 6 Staffel(n), Cartoon]}]
0
[BBC, [Fantasy], {[Game of Thrones, 10 Staffel(n), Fantasy], [*The Witchers*, 2 Staffel(n), Fantasy]}]
3
[CAD, [Fantasy, Cartoon, Drama], {[Game of Thrones, 10 Staffel(n), Fantasy], [*Gossip Girl*, 5 Staffel(n), Drama], [*Big Mouth Reboot*, 4 Staffel(n), Cartoon], [*Inuyasha*, 5 Staffel(n), Fantasy], [*Tom & jerry*, 9 Staffel(n), Cartoon], [*Reboot rr Reboot*, 3 Staffel(n), Cartoon], [*The Witcher*, 1 Staffel(n), Fantasy], [Game of Thrones, 10 Staffel(n), Fantasy], [*Big Mouth Reboot*, 4 Staffel(n), Cartoon], [*Inuyasha*, 4 Staffel(n), Cartoon], [*Gossip Girl*, 5 Staffel(n), Drama]}]
0
[CAD, [Fantasy, Cartoon, Drama], {[Game of Thrones, 10 Staffel(n), Fantasy], [*Gossip Girl*, 5 Staffel(n), Drama], [*Big Mouth Reboot*, 4 Staffel(n), Cartoon], [*Inuyasha*, 5 Staffel(n), Fantasy], [*Tom & jerry*, 9 Staffel(n), Cartoon], [*Reboot rr Reboot*, 3 Staffel(n), Cartoon], [*The Witcher*, 1 Staffel(n), Fantasy], [Game of Thrones, 10 Staffel(n), Fantasy], [*Big Mouth Reboot*, 4 Staffel(n), Cartoon], [*Inuyasha*, 4 Staffel(n), Cartoon], [*Gossip Girl*, 5 Staffel(n), Drama]}]
[Game of Thrones, 10 Staffel(n), Fantasy]
[*The Witchers*, 2 Staffel(n), Fantasy]
[Game of Thrones, 10 Staffel(n), Fantasy]
[*Inuyasha*, 5 Staffel(n), Fantasy]
[*The Witcher*, 1 Staffel(n), Fantasy]
[Game of Thrones, 10 Staffel(n), Fantasy]
[*Reboot rr Reboot*, 3 Staffel(n), Cartoon]
[*Reboot rr Reboot*, 3 Staffel(n), Cartoon]
[*Big Mouth Reboot*, 4 Staffel(n), Cartoon]
[*Inuyasha*, 6 Staffel(n), Cartoon]
[*Big Mouth Reboot*, 4 Staffel(n), Cartoon]
[*Tom & jerry*, 9 Staffel(n), Cartoon]
[*Reboot rr Reboot*, 3 Staffel(n), Cartoon]
[*Big Mouth Reboot*, 4 Staffel(n), Cartoon]
[*Inuyasha*, 4 Staffel(n), Cartoon]
[Big Bang Theory, 10 Staffel(n), Sitcom]
[*Friends*, 10 Staffel(n), Sitcom]
*/