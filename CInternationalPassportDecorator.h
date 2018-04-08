#ifndef UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTDECORATOR_H
#define UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTDECORATOR_H

#include "ICard.h"
#include "CCard.h"
#include <iostream>
#include <bits/shared_ptr.h>
#include <vector>


class CInternationalPasportDecorator : public ICard{
public:
    CInternationalPasportDecorator(std::shared_ptr<ICard> new_card)
    {
        card = new_card;
    }

    ~CInternationalPasportDecorator()
    {}

    void Get_Info()
    {
        std::cout<<"Full name: "<<card->Get_Name()<<std::endl;
        std::cout<<"Home country: "<<home_country<<std::endl;
        std::cout<<"Visited counties: "<<std::endl;
        for(int i=0; i<visited_countries.size(); ++i)
        {
            std::cout<<visited_countries[i]<<std::endl;
        }
    }

    std::string Get_Name() const
    {
        return card->Get_Name();
    }

    unsigned long long int Get_Id() const
    {
        return card->Get_Id();
    }

    std::string Get_End() const
    {
        return card->Get_End();
    }

    void Set_Home_Country(std::string new_home_country)
    {
        home_country = new_home_country;
    }

    void Add_Country(std::string new_country)
    {
        visited_countries.push_back(new_country);
    }


private:
    std::shared_ptr<ICard> card;
    std::string home_country;
    std::vector<std::string> visited_countries;
};



#endif //UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTDECORATOR_H
