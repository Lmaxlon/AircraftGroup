#include <gtest/gtest.h>
#include "../lib/aircraft.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
TEST(constuct, get)
{
    air::Weapon w("No", 4, 5);
    air::Ship ship(w, 200, 15, 500, 1);
    ASSERT_EQ(200, ship.get_health());
    ASSERT_EQ(15, ship.get_speed());
    ASSERT_EQ(500, ship.get_cost());
    ASSERT_EQ(1, ship.get_id());
}
TEST(construct, set)
{
    air::Weapon w("No", 4, 5);
    w.set_damage(10);
    w.set_recharge(4);
    w.set_type(std::string type = "Type");
    air::Ship ship(w, 200, 15, 500, 1)
    ship.set_health(500);
    ship.set_speed(40);
    ship.set_cost(200);
    ship.set_id(3);
    ASSERT_EQ(std::string type = "Type", ship.w.get_type());
    ASSERT_EQ(10, ship.w.get_damage());
    ASSERT_EQ(500, ship.w.get_health());
    ASSERT_EQ(40, ship.get_speed());
    ASSERT_EQ(200, a.get_cost());
    ASSERT_EQ(3, a.get_id());
}
TEST(construct, plane_get){
    //int _health, int _damage, int _cost, int _speed_of_recharge, int _id
    air::Plane p(100, 20, 300, 15, 5);
    ASSERT_EQ(100, ship.get_health());
    ASSERT_EQ(20, ship.get_damage());
    ASSERT_EQ(300, ship.get_cost());
    ASSERT_EQ(15, ship.get_id());
    ASSERT_EQ(5, ship.get_id());
}
TEST(construct, person_get){
    air::Person p("Alex", "Oldest Officer");
    ASSERT_EQ("Alex", ship.get_fio());
    ASSERT_EQ("Oldest Officer", ship.get_level());
}
TEST(construct, person_set){
    air::Person p("Alex", "Oldest Officer");
    p.set_level("Officer");
    p.set_fio("Michael");
    ASSERT_EQ("Officer", p.get_level());
    ASSERT_EQ("Michael", p.get_fio());
}
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}