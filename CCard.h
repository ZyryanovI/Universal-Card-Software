#ifndef UNIVERSAL_CARD_SOFTWARE_CCARD_H
#define UNIVERSAL_CARD_SOFTWARE_CCARD_H

#include <iostream>
#include <string>
#include "ICard.h"


class CCard : public ICard{
public:
    CCard(unsigned long long int new_id, std::string new_user_full_name, std::string new_ending_day)
    {
        id = new_id;
        user_full_name = new_user_full_name;
        ending_day = new_ending_day;
    }

    void Get_Info()
    {
        std::cout<<"Card's id is "<<id<<std::endl;
        std::cout<<"Card owner is "<<user_full_name<<std::endl;
        std::cout<<"Сard can be used up to "<<ending_day<<std::endl;
    }

    std::string Get_Name() const
    {
        return user_full_name;
    }

    unsigned long long int Get_Id() const
    {
        return id;
    }

    std::string Get_End() const
    {
        return ending_day;
    }


private:

    std::string user_full_name;
    std::string ending_day;
    unsigned long long int id;  //will see if I need it



};


#endif //UNIVERSAL_CARD_SOFTWARE_CCARD_H
