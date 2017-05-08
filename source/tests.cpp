#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "window.hpp"

TEST_CASE("default konstruktor vector")
{
  Vec2 a{};
  REQUIRE(a.x_ == 0.0f);
  REQUIRE(a.y_ == 0.0f);
}

TEST_CASE("userkonstructor mit koordinaten vector")
{
  Vec2 b{12.0f, 13.0f};
  REQUIRE(b.x_ == 12.0f);
  REQUIRE(b.y_ == 13.0f);
}

TEST_CASE("-= vector")
{
  Vec2 a{4.0f, 3.0f};
  Vec2 b{1.0f, 3.0f};
  a -= b;
  REQUIRE(a.x_==3.0f);
  REQUIRE(a.y_==0.0f);
}
TEST_CASE("+= vector")
{
  Vec2 a{3.0f, 4.0f};
  Vec2 b{5.0f, 6.0f};
  a += b;
  REQUIRE(a.x_==8.0f);
  REQUIRE(a.y_==10.0f);
}
TEST_CASE("*= vector")
{
  Vec2 a{2.0f, 12.0f};
  float b=3.0f;
  a *= b;
  REQUIRE(a.x_==6.0f);
  REQUIRE(a.y_==36.0f);
}
TEST_CASE("/= vector")
{
  Vec2 a{22.0f, 33.0f};
  float b=11.0f;
  a /= b;
  REQUIRE(a.x_==2.0f);
  REQUIRE(a.y_==3.0f);
}




TEST_CASE("* vector")
{
  Vec2 a{2.0f, 12.0f};
  float b=3.0f;
  Vec2 c{};
  c=a*b;
  REQUIRE(c.x_==6.0f);
  REQUIRE(c.y_==36.0f);
}



TEST_CASE("default konstruktor 2x2 matrix")
{
  Mat2 m{};
  REQUIRE(m.a11_==1.0f);
  REQUIRE(m.a12_==0.0f);
  REQUIRE(m.a21_==0.0f);
  REQUIRE(m.a22_==1.0f);
}

TEST_CASE("user konstruktor 2x2 matrix")
{
  Mat2 m{1.0f, 2.0f, 3.0f, 4.0f};
  REQUIRE(m.a11_==1.0f);
  REQUIRE(m.a12_==2.0f);
  REQUIRE(m.a21_==3.0f);
  REQUIRE(m.a22_==4.0f);
}

TEST_CASE("*= 2x2 matrix")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  m1 *= m2;
  REQUIRE(m1.a11_==19.0f);
  REQUIRE(m1.a12_==22.0f);
  REQUIRE(m1.a21_==43.0f);
  REQUIRE(m1.a22_==50.0f);
  Mat2 m3{};
  m1 *= m3;
  REQUIRE(m1.a11_==19.0f);
  REQUIRE(m1.a12_==22.0f);
  REQUIRE(m1.a21_==43.0f);
  REQUIRE(m1.a22_==50.0f);
}

TEST_CASE("m*m 2x2 matrix")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Mat2 m3{};
  m3 = m1 * m2;
  REQUIRE(m3.a11_==19.0f);
  REQUIRE(m3.a12_==22.0f);
  REQUIRE(m3.a21_==43.0f);
  REQUIRE(m3.a22_==50.0f);
}

TEST_CASE("v=m*v 2x2 matrix")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Vec2 v1{3.0f, 5.0f};
  Vec2 v2{7.0f, 9.0f};
  Vec2 v3{};
  v3 = m1 * v1;
  REQUIRE(v3.x_==13.0f);
  REQUIRE(v3.y_==29.0f);
  v3 = m2 * v2;
  REQUIRE(v3.x_==89.0f);
  REQUIRE(v3.y_==121.0f);
}

TEST_CASE("*")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Vec2 v1{3.0f, 5.0f};
  Vec2 v2{7.0f, 9.0f};
  Vec2 v3{};
  v3 = v1*m1;
  REQUIRE(v3.x_==12.0f);
  REQUIRE(v3.y_==30.0f);
  v3 = v2*m2;
  REQUIRE(v3.x_==84.0f);
  REQUIRE(v3.y_==126.0f);
}

TEST_CASE("invserse")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Mat2 inv=inverse(m1);
  Mat2 inv2=inverse(m2);
  REQUIRE(inv.a11_==-2.0f);
  REQUIRE(inv.a12_==1.0f);
  REQUIRE(inv.a21_==1.5f);
  REQUIRE(inv.a22_==-0.5f);
  REQUIRE(inv2.a11_==-4.0f);
  REQUIRE(inv2.a12_==3.0f);
  REQUIRE(inv2.a21_==3.5f);
  REQUIRE(inv2.a22_==-2.5f);
}

TEST_CASE("transpose")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Mat2 trn=transpose(m1);
  Mat2 trn2=transpose(m2);
  REQUIRE(trn.a11_==1.0f);
  REQUIRE(trn.a12_==3.0f);
  REQUIRE(trn.a21_==2.0f);
  REQUIRE(trn.a22_==4.0f);
  REQUIRE(trn2.a11_==5.0f);
  REQUIRE(trn2.a12_==7.0f);
  REQUIRE(trn2.a21_==6.0f);
  REQUIRE(trn2.a22_==8.0f);
}

TEST_CASE ("rotation")
{
  Mat2 rot = make_rotation_mat2(30);
  REQUIRE (rot.a11_ == Approx(0.15425f));
  REQUIRE (rot.a12_ == Approx(0.98803f));
  REQUIRE (rot.a21_ == Approx(-0.98803f));
  REQUIRE (rot.a22_ == Approx(0.15425f));
}

TEST_CASE ("circle default konstruktor")
{
  Circle c{};
  REQUIRE (c.getCenter().x_ == 0.0f);
  REQUIRE (c.getCenter().y_ == 0.0f);
  REQUIRE (c.getRadius() == 1.0f);
  REQUIRE (c.getColor().r_ == 0.0f);
  REQUIRE (c.getColor().g_ == 0.0f);
  REQUIRE (c.getColor().b_ == 0.0f);
}

TEST_CASE ("circle user konstruktor")
{
  Circle c{{2.0f, 5.0f}, 10.0f};
  REQUIRE (c.getCenter().x_ == 2.0f);
  REQUIRE (c.getCenter().y_ == 5.0f);
  REQUIRE (c.getRadius() == 10.0f);
  REQUIRE (c.getColor().r_ == 0.0f);
  REQUIRE (c.getColor().g_ == 0.0f);
  REQUIRE (c.getColor().b_ == 0.0f);}

TEST_CASE ("getColor")
{
  Circle c{{2.0f, 5.0f}, 10.0f, 0.7f};
  REQUIRE (c.getCenter().x_ == 2.0f);
  REQUIRE (c.getCenter().y_ == 5.0f);
  REQUIRE (c.getRadius() == 10.0f);
  REQUIRE (c.getColor().r_ == 0.7f);
  REQUIRE (c.getColor().g_ == 0.7f);
  REQUIRE (c.getColor().b_ == 0.7f);}

TEST_CASE ("getCenter")
{
  Circle c{{2.0f, 5.0f}, 10.0f};
  REQUIRE (c.getCenter().x_ == 2.0f);
  REQUIRE (c.getCenter().y_ == 5.0f );
}

TEST_CASE ("getRadius")
{
  Circle c{{2.0f, 5.0f}, 10.0f};
  REQUIRE (c.getRadius() == 10.0f);
}

TEST_CASE ("circumference test")
{
  Circle c{{2.0f, 5.0f}, 10.0f};
  Circle c2{{2.0f, 5.0f}, 0.0f};
  REQUIRE (Approx(c.circumference()) == 62.8318f);
  REQUIRE (c2.circumference() == 0.0f);
}

TEST_CASE ("rectangle default konstruktor")
{
  Rectangle r{};
  REQUIRE (r.getMin_().x_ ==0.0f);
  REQUIRE (r.getMin_().y_ ==0.0f);
  REQUIRE (r.getMax_().x_ ==0.0f);
  REQUIRE (r.getMax_().y_ ==0.0f);
  REQUIRE (r.getColor_().r_ ==0.0f);
  REQUIRE (r.getColor_().g_ ==0.0f);
  REQUIRE (r.getColor_().b_ ==0.0f);
}

TEST_CASE ("Rectangle user input konstruktor")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 6.0f}};
  REQUIRE (r.getMin_().x_ ==2.0f);
  REQUIRE (r.getMin_().y_ ==5.0f);
  REQUIRE (r.getMax_().x_ ==3.0f);
  REQUIRE (r.getMax_().y_ ==6.0f);
  REQUIRE (r.getColor_().r_ ==0.0f);
  REQUIRE (r.getColor_().g_ ==0.0f);
  REQUIRE (r.getColor_().b_ ==0.0f);
}

TEST_CASE ("rectangle define konstruktor")
{
  Rectangle r{{2.0f, 5.0f},{3.0f, 6.0f},{0.5f, 0.7f, 0.9f}};
  REQUIRE (r.getMin_().x_ ==2.0f);
  REQUIRE (r.getMin_().y_ ==5.0f);
  REQUIRE (r.getMax_().x_ ==3.0f);
  REQUIRE (r.getMax_().y_ ==6.0f);
  REQUIRE (r.getColor_().r_ ==0.5f);
  REQUIRE (r.getColor_().g_ ==0.7f);
  REQUIRE (r.getColor_().b_ ==0.9f);
}

TEST_CASE ("getmin")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 7.0f}};
  REQUIRE (r.getMin_().x_ == 2.0f);
  REQUIRE (r.getMin_().y_ == 5.0f );
}

TEST_CASE ("getmax")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 7.0f}};
  REQUIRE (r.getMax_().x_ == 3.0f);
  REQUIRE (r.getMax_().y_ == 7.0f);
}

TEST_CASE ("getcolor")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 7.0f}};
  Rectangle r2{{2.0f, 5.0f},{3.0f, 6.0f},{0.5f, 0.7f, 0.9f}};
  REQUIRE (r.getColor_().r_== 0.0f);
  REQUIRE (r.getColor_().g_== 0.0f);
  REQUIRE (r.getColor_().b_== 0.0f);
  REQUIRE (r2.getColor_().r_== 0.5f);
  REQUIRE (r2.getColor_().g_== 0.7f);
  REQUIRE (r2.getColor_().b_== 0.9f);
}


TEST_CASE ("circumference rectangle")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 7.0f}};
  REQUIRE (r.circumference()== 6.0f);
  Rectangle r2{{0.0f, 0.0f}, {0.0f, 0.0f}};
  REQUIRE (r2.circumference()==0.0f);
}

TEST_CASE ("isinside rectangle")
{
  Rectangle r{{5.0f, 5.0f}, {10.0f, 10.0f}};
  Vec2 p{7.0f, 7.0f};
  Rectangle r2{{5.0f, 5.0f}, {10.0f, 10.0f}};
  Vec2 p2{-5.0f, -5.0f};
  REQUIRE (r.isInsideRect(p) == true);
  REQUIRE (r2.isInsideRect(p2) == false);
}

TEST_CASE ("isinside circle")
{
  Circle c{{5.0f, 5.0f}, 10.0f};
  Vec2 p{7.0f, 7.0f};
  Circle c2{{5.0f, 5.0f}, 10.0f};
  Vec2 p2{-5.0f, -5.0f};
  REQUIRE (c.isInsideCirc(p) == true);
  REQUIRE (c2.isInsideCirc(p2) == false);
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
