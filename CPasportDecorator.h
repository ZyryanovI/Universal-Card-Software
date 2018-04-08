#ifndef UNIVERSAL_CARD_SOFTWARE_CPASPORTDECORATOR_H
#define UNIVERSAL_CARD_SOFTWARE_CPASPORTDECORATOR_H

#include "ICard.h"
#include "CCard.h"
#include <iostream>
#include <bits/shared_ptr.h>
#include <vector>


class CPasportDecorator : public ICard{
public:
    CPasportDecorator(std::shared_ptr<ICard> new_card)
    {
        card = new_card;
    }

    ~CPasportDecorator()
    {}

    void Get_Info()
    {
        card->Get_Info();
        std::cout<<"Registration place is "<<registration_place<<std::endl;
        std::cout<<"Wife is "<<wife->Get_Name()<<std::endl;
        std::cout<<"Children are: "<<std::endl;
        for(int i =0; i<children.size(); ++i)
        {
            children[i]->Get_Name();
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


private:
    std::shared_ptr<ICard> card;
    std::string registration_place;
    std::vector<std::shared_ptr<ICard>> children;
    std::shared_ptr<ICard> wife;
};


#endif //UNIVERSAL_CARD_SOFTWARE_CPASPORTDECORATOR_H
