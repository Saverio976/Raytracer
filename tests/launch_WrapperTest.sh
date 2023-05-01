#!/bin/bash

g++ -std=c++20 -lconfig++ -I ../src/Scenes WrapperTest.cpp ../src/Scenes/ConfigWrapper.cpp ../src/Scenes/SettingWrapper.cpp -o WrapperTest
./WrapperTest
