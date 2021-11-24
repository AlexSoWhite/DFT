cmake_minimum_required(VERSION 3.20)
project(dft)

set(CMAKE_CXX_STANDARD 14)

add_executable(dft main.cpp include/Methods.h include/Generator.h include/Presenter.h src/Presenter.cpp src/Resolver.cpp include/Resolver.h)
