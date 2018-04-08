cmake_minimum_required(VERSION 3.5)
project(Universal_Card_Software)

set(CMAKE_CXX_STANDARD 11)

add_executable(Universal_Card_Software main2.cpp ICard.h IReader.h CBankCardDecorator.h CCard.h CBankCardReader.h CPasportReader.h CPasportDecorator.h CInsurancePolicyDecorator.h CInsurancePolicyReader.h CInternationalPassportDecorator.h CInternationalPassportReader.h)