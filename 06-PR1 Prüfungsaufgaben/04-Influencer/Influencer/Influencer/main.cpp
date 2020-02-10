#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"video.h"
#include"influencer.h"

using namespace std;

vector <string> platform_names{ "Youtube", "Vimeo", "BitChute", "Flickr", "Facebook" };

int main(){
try {
  cout << "Class Video:\n";
  try {
    Video v{"", 200};
    cout << "test 1 " << v << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 1\n";
  }
  try {
    Video v{"Test", 5};
    cout << "test 2 " << v << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 2\n";
  }
  try {
    Video v{"Test", 0};
    cout << "test 3 " << v << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 3\n";
  }

  const vector<Video> vv{{"Watch Me", 50}, {"View", 271, Platform::BitChute}, {"More", 87, Platform::Facebook},
                         {"My Life", 482}, {"Missing You", 490, Platform::Vimeo},
                         {"I Wonder", 480, Platform::Flickr}, {"Still the Same", 80, Platform::Facebook},
                         {"Sue", 90, Platform::Vimeo}, {"Jim", 87, Platform::BitChute},
                         {"Still here",53}};
  for (auto v : vv) { 
    cerr << v << '\n';
    cout << v << ' ' << v.get_class();
    for (const auto& p : v.upload({Platform::Facebook, Platform::YouTube, Platform::Flickr}))
      cout << '-' << platform_names.at(static_cast<size_t>(p));
    cout << '\n' << v;
    for (const auto& p : v.upload({Platform::Vimeo, Platform::BitChute, Platform::YouTube}))
      cout << '-' << platform_names.at(static_cast<size_t>(p));
    cout << '\n' << v << '\n';
  }
  cout << '\n';

  cout << "\nClass Influencer:\n";
  try {
    Influencer i{"", vv};
    cout << "test 4 " << i << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 4\n";
  }
  const vector<Influencer> vi{{"Eric", vv}, {"Linda", {vv.begin(), vv.begin()+3}},
                              {"Olga", {vv.begin()+3, vv.end()}}, {"Herby"}};
  
  for (auto d : vi) {
    cout << d << '\n';
    d.create_video(*(vv.end()-1));
    cout << d << '\n';
    cout << Influencer("Test", d.videos_in_class(49)) << '\n';
    cout << Influencer("Test", d.videos_in_class(9)) << '\n';
    cerr << d << '\n';
  }
  
// Dekommentieren fuer Zusatz videos_not_on
/*
  cout << "\nAdditional task videos_not_on\n";
  Influencer ti{vi.at(0)};
  cout << Influencer{"Test 1", ti.videos_not_on({Platform::YouTube})} << '\n';
  cout << Influencer{"Test 2", ti.videos_not_on({Platform::Vimeo, Platform::Flickr})} << '\n';
  cout << Influencer{"Test 3", ti.videos_not_on({Platform::BitChute, Platform::Facebook, Platform::YouTube})} << '\n';
  Video v1{vv.at(3)};
  Video v2{vv.at(4)};
  Video v3{vv.at(5)};
  v1.upload({Platform::Vimeo});
  v2.upload({Platform::BitChute, Platform::Flickr}); 
  v3.upload({Platform::Vimeo, Platform::Flickr});
  ti.create_video(v1);
  ti.create_video(v2);
  ti.create_video(v3);
  cout << Influencer{"Test 4", ti.videos_not_on({Platform::YouTube, Platform::Facebook})} << '\n';
  cout << Influencer{"Test 5", ti.videos_not_on({Platform::Vimeo, Platform::Flickr})} << '\n';
  cout << Influencer{"Test 6", ti.videos_not_on({Platform::BitChute, Platform::Facebook, Platform::YouTube})} << '\n';
*/

// Dekommentieren fuer Zusatz share
/*
  cout << "\nAdditional task share\n";
  Influencer i1{vi.at(1)};
  Influencer i2{vi.at(2)};
  cout << i1.share(i2,9) << ' ';
  cout << i2.share(i1,49) << ' ';
  cout << i2.share(i1,24) << '\n';
  cout << i1 << '\n' << i2 << '\n';
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

/* Erwarteter Output
Class Video:
catch 1
catch 2
catch 3
[Watch Me (6): {YouTube}, 50]
[Watch Me (6): {YouTube}, 50] 6-YouTube
[Watch Me (6): {YouTube, Facebook, Flickr}, 50]-YouTube
[Watch Me (6): {YouTube, Facebook, Flickr, Vimeo, BitChute}, 50]
[View (28): {BitChute}, 271]
[View (28): {BitChute}, 271] 28
[View (28): {BitChute, Facebook, YouTube, Flickr}, 271]-BitChute-YouTube
[View (28): {BitChute, Facebook, YouTube, Flickr, Vimeo}, 271]
[More (9): {Facebook}, 87]
[More (9): {Facebook}, 87] 9-Facebook
[More (9): {Facebook, YouTube, Flickr}, 87]-YouTube
[More (9): {Facebook, YouTube, Flickr, Vimeo, BitChute}, 87]
[My Life (49): {YouTube}, 482]
[My Life (49): {YouTube}, 482] 49-YouTube
[My Life (49): {YouTube, Facebook, Flickr}, 482]-YouTube
[My Life (49): {YouTube, Facebook, Flickr, Vimeo, BitChute}, 482]
[Missing You (50): {Vimeo}, 490]
[Missing You (50): {Vimeo}, 490] 50
[Missing You (50): {Vimeo, Facebook, YouTube, Flickr}, 490]-Vimeo-YouTube
[Missing You (50): {Vimeo, Facebook, YouTube, Flickr, BitChute}, 490]
[I Wonder (49): {Flickr}, 480]
[I Wonder (49): {Flickr}, 480] 49-Flickr
[I Wonder (49): {Flickr, Facebook, YouTube}, 480]-YouTube
[I Wonder (49): {Flickr, Facebook, YouTube, Vimeo, BitChute}, 480]
[Still the Same (9): {Facebook}, 80]
[Still the Same (9): {Facebook}, 80] 9-Facebook
[Still the Same (9): {Facebook, YouTube, Flickr}, 80]-YouTube
[Still the Same (9): {Facebook, YouTube, Flickr, Vimeo, BitChute}, 80]
[Sue (10): {Vimeo}, 90]
[Sue (10): {Vimeo}, 90] 10
[Sue (10): {Vimeo, Facebook, YouTube, Flickr}, 90]-Vimeo-YouTube
[Sue (10): {Vimeo, Facebook, YouTube, Flickr, BitChute}, 90]
[Jim (9): {BitChute}, 87]
[Jim (9): {BitChute}, 87] 9
[Jim (9): {BitChute, Facebook, YouTube, Flickr}, 87]-BitChute-YouTube
[Jim (9): {BitChute, Facebook, YouTube, Flickr, Vimeo}, 87]
[Still here (6): {YouTube}, 53]
[Still here (6): {YouTube}, 53] 6-YouTube
[Still here (6): {YouTube, Facebook, Flickr}, 53]-YouTube
[Still here (6): {YouTube, Facebook, Flickr, Vimeo, BitChute}, 53]


Class Influencer:
catch 4
[Eric (10), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [More (9): {Facebook}, 87], [My Life (49): {YouTube}, 482], [Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Still the Same (9): {Facebook}, 80], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53]}]
[Eric (11), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [More (9): {Facebook}, 87], [My Life (49): {YouTube}, 482], [Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Still the Same (9): {Facebook}, 80], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53], [Still here (6): {YouTube}, 53]}]
[Test (2), {[I Wonder (49): {Flickr}, 480], [My Life (49): {YouTube}, 482]}]
[Test (3), {[Jim (9): {BitChute}, 87], [Still the Same (9): {Facebook}, 80], [More (9): {Facebook}, 87]}]
[Eric (11), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [More (9): {Facebook}, 87], [My Life (49): {YouTube}, 482], [Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Still the Same (9): {Facebook}, 80], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53], [Still here (6): {YouTube}, 53]}]
[Linda (3), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [More (9): {Facebook}, 87]}]
[Linda (4), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [More (9): {Facebook}, 87], [Still here (6): {YouTube}, 53]}]
[Test (0), {}]
[Test (1), {[More (9): {Facebook}, 87]}]
[Linda (4), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [More (9): {Facebook}, 87], [Still here (6): {YouTube}, 53]}]
[Olga (7), {[My Life (49): {YouTube}, 482], [Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Still the Same (9): {Facebook}, 80], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53]}]
[Olga (8), {[My Life (49): {YouTube}, 482], [Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Still the Same (9): {Facebook}, 80], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53], [Still here (6): {YouTube}, 53]}]
[Test (2), {[I Wonder (49): {Flickr}, 480], [My Life (49): {YouTube}, 482]}]
[Test (2), {[Jim (9): {BitChute}, 87], [Still the Same (9): {Facebook}, 80]}]
[Olga (8), {[My Life (49): {YouTube}, 482], [Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Still the Same (9): {Facebook}, 80], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53], [Still here (6): {YouTube}, 53]}]
[Herby (0), {}]
[Herby (1), {[Still here (6): {YouTube}, 53]}]
[Test (0), {}]
[Test (0), {}]
[Herby (1), {[Still here (6): {YouTube}, 53]}]

Additional task videos_not_on
[Test 1 (7), {[View (28): {BitChute}, 271], [More (9): {Facebook}, 87], [Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Still the Same (9): {Facebook}, 80], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87]}]
[Test 2 (7), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [More (9): {Facebook}, 87], [My Life (49): {YouTube}, 482], [Still the Same (9): {Facebook}, 80], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53]}]
[Test 3 (3), {[Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Sue (10): {Vimeo}, 90]}]
[Test 4 (7), {[View (28): {BitChute}, 271], [Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87], [Missing You (50): {Vimeo, BitChute, Flickr}, 490], [I Wonder (49): {Flickr, Vimeo}, 480]}]
[Test 5 (7), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [More (9): {Facebook}, 87], [My Life (49): {YouTube}, 482], [Still the Same (9): {Facebook}, 80], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53]}]
[Test 6 (4), {[Missing You (50): {Vimeo}, 490], [I Wonder (49): {Flickr}, 480], [Sue (10): {Vimeo}, 90], [I Wonder (49): {Flickr, Vimeo}, 480]}]

Additional task share
1 2 0
[Linda (4), {[Watch Me (6): {YouTube}, 50], [View (28): {BitChute}, 271], [My Life (49): {YouTube}, 482], [I Wonder (49): {Flickr}, 480]}]
[Olga (6), {[Missing You (50): {Vimeo}, 490], [Still the Same (9): {Facebook}, 80], [Sue (10): {Vimeo}, 90], [Jim (9): {BitChute}, 87], [Still here (6): {YouTube}, 53], [More (9): {Facebook}, 87]}]
*/