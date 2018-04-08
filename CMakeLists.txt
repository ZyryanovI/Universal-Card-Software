cmake_minimum_required(VERSION 3.9)
project(Universal_Card_Software)

set(CMAKE_CXX_STANDARD 11)

add_executable(Universal_Card_Software main.cpp ICard.h IReader.h CBankCardDecorator.h CCard.h CBankCardReader.h CPasportReader.h CPasportDecorator.h)