#!/bin/bash

set -e
set -x

cd lib
g++ -c --std=c++11 aircraft.cpp -o aircraft.o 
ar rc libaircraft.a aircraft.o 
ranlib libaircraft.a 
cd ..


cd run
g++ --std=c++11 main.cpp func.cpp -laircraft -L ../lib -I ../lib -o run.out
mv run.out ../
cd ..


cd tst
g++ --std=c++11 test.cpp -laircraft -L ../lib -I ../lib -o tst.out -lpthread -lgtest
mv tst.out ../
cd ..


exit 0
