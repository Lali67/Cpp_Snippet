#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector.h"

TEST_CASE("VectorTest, CopyConstructor") {
  const Vector v({0,1,2,3,4,5,6,7,8,9});
  Vector other{v};

  CHECK( other.size() == 10 );
  CHECK( other.empty() == false );

  for (size_t i=0;i<other.size();i++) {
    CHECK(v[i] == other[i]);
  }

  other.pop_back();

  CHECK( v.size() == other.size() + 1 );
}

TEST_CASE("VectorTest, Assignment") {
  const Vector a({0,1,2,3,4,5,6,7,8,9});
  Vector b;
  b = a;

  for(size_t i=0; i < a.size(); ++i)
    CHECK(a[i] == b[i]);

  CHECK(a.empty() == false);
  CHECK(a.size() == 10);
  CHECK(b.size() == 10);

  b.pop_back();

  CHECK(a.size() == 10);
  CHECK(b.size() == 9);
}

TEST_CASE("IteratorTest, DefaultConstructible") {
  Vector::iterator a;
  Vector::const_iterator b;
}

TEST_CASE("IteratorTest, CopyConstructible") {
  Vector v({1,2});
  Vector::iterator a{v.begin()};
  Vector::iterator b{a};
  CHECK_EQ(a, b);
}

TEST_CASE("IteratorTest, CopyAssignable") {
  Vector v({1,2});
  Vector::iterator a{v.begin()};
  Vector::iterator b{v.end()};
  CHECK_NE(a, b);
  a = b;
  CHECK_EQ(a, b);
}

TEST_CASE("IteratorTest, PreIncrement") {
  Vector v({1});
  Vector::iterator a{v.begin()};
  Vector::iterator b{v.end()};
  CHECK_NE(a, b);
  CHECK_EQ(++a, b);
}

TEST_CASE("IteratorTest, PostIncrement") {
  Vector v({1});
  Vector::iterator a{v.begin()};
  Vector::iterator b{v.end()};
  CHECK_NE(a, b);
  CHECK_NE(a++, b);
  CHECK_EQ(a, b);
}

TEST_CASE("IteratorTest, Dereference") {
  Vector v({0,1,2,3,4});
  {
    size_t cnt = 0;
    for(auto it = v.begin(); it != v.end(); ++it) {
      CHECK_EQ(*it, cnt++);
    }
    CHECK_EQ(cnt, 5);
  }
  auto it = v.begin();
  CHECK_EQ(*it, 0);
  *it = 999;
  CHECK_EQ(*it, 999);
}

TEST_CASE("IteratorTest, ArrowOperator") {
  Vector v({0,1,2,3,4});
  Vector::iterator a{v.begin()};
  Vector::iterator b{v.end()};
  {
    size_t cnt = 0;
    for(auto it = v.begin(); it != v.end(); ++it) {
      CHECK_EQ(*(it.operator->()), cnt++);
    }
    CHECK_EQ(cnt, 5);
  }
}

/**
 * ConstIterator
 */
TEST_CASE("ConstIteratorTest, CopyConstructible") {
  Vector v({1,2});
  Vector::const_iterator a{v.begin()};
  Vector::const_iterator b{a};
  CHECK_EQ(a, b);
}

TEST_CASE("ConstIteratorTest, CopyAssignable") {
  Vector v({1,2});
  Vector::const_iterator a{v.begin()};
  Vector::const_iterator b{v.end()};
  CHECK_NE(a, b);
  a = b;
  CHECK_EQ(a, b);
}

TEST_CASE("ConstIteratorTest, PreIncrement") {
  Vector v({1});
  Vector::const_iterator a{v.begin()};
  Vector::const_iterator b{v.end()};
  CHECK_NE(a, b);
  CHECK_EQ(++a, b);
}

TEST_CASE("ConstIteratorTest, PostIncrement") {
  Vector v({1});
  Vector::const_iterator a{v.begin()};
  Vector::const_iterator b{v.end()};
  CHECK_NE(a, b);
  CHECK_NE(a++, b);
  CHECK_EQ(a, b);
}

TEST_CASE("ConstIteratorTest, Dereference") {
  Vector v({0,1,2,3,4});
  Vector::const_iterator beg{v.begin()};
  Vector::const_iterator end{v.end()};
  {
    size_t cnt = 0;
    for(; beg != end; ++beg) {
      CHECK_EQ(*beg, cnt++);
    }
    CHECK_EQ(cnt, 5);
  }
}

TEST_CASE("ConstIteratorTest, ArrowOperator") {
  Vector v({0,1,2,3,4});
  Vector::const_iterator beg{v.begin()};
  Vector::const_iterator end{v.end()};
  {
    size_t cnt = 0;
    for(; beg != end; ++beg) {
      CHECK_EQ(*(beg.operator->()), cnt++);
    }
    CHECK_EQ(cnt, 5);
  }
}

TEST_CASE("IteratorTest, TypeConversion") {
  Vector v({1});
  Vector::iterator it{v.begin()};
  Vector::const_iterator cit{it};

  //call Vector::const_iterator's operators
  CHECK(!(cit != it));
  CHECK(  cit == it);

  //call Vector::iterator's operators
  CHECK(!(it != cit));
  CHECK(  it == cit);
}

TEST_CASE("IteratorTest, Insert/Erase") {
  Vector v{1,2,3};
  auto x = v.insert(++v.begin(),4);
  CHECK_EQ(v[1],4);
  CHECK_EQ(*x,4);
  auto it =v.begin();
  ++it;
  ++it;
  auto y = v.erase(it);
  CHECK_EQ(*y,3);
  CHECK_EQ(v[2],3);
}
