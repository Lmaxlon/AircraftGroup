#include <gtest/gtest.h>
#include "../lib/aircraft.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
TEST(constuct, get)
{
    air::Ship a(1, 2, 3);
    ASSERT_EQ("NO", a.get_type());
}

TEST(construct, get)
{
    air::Weapon a("NO", 1, 2);
    ASSERT_EQ("No", a.get_type());
    ASSERT_EQ(1, a.get_damage());
    ASSERT_EQ(2, a.get_recharge());;
}
TEST(construct, set)
{
    air::Weapon p("No", 1, 2);
    hypocyc::hypocycloid a;
    a.set_type("No");
    a.set_damage(1);
    a.set_recharge(2);
    ASSERT_EQ("No", a.set_type());
    ASSERT_EQ(1, a.set_damage());
    ASSERT_EQ(2, a.set_recharge());
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
