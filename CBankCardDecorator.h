#ifndef UNIVERSAL_CARD_SOFTWARE_CBANKDECORATOR_H
#define UNIVERSAL_CARD_SOFTWARE_CBANKDECORATOR_H

#include <bits/shared_ptr.h>
#include <iostream>
#include "ICard.h"

class CBankCardDecorator : public ICard{

public:
    CBankCardDecorator(std::shared_ptr<ICard> new_card)
    {
        card = new_card;
    }

    ~CBankCardDecorator()
    {}

    void Get_Info()
    {
        std::cout<<"Your balance in "<<balance<<std::endl;
        std::cout<<"Some other information: "<<std::endl;
        card->Get_Info();
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


    bool Is_Valuable()
    {
        //Здесь происходит проверка того, что карта работает(напимер не была ли заблокирована пользователем)
        return true;
    }

    bool Withdraw_Money(double amount)
    {
        if(Is_Valuable())
        {
            if(balance < amount)
            {
                std::cout<<"You don't have enough money"<<std::endl;
                return false;
            }
            balance -= amount;
            return true;
        }
        else
        {
            std::cout<<"Your card isn't valuable"<<std::endl;
            return false;
        }
    }

    bool Put_Money(double amount)
    {
        if(Is_Valuable())
        {
            balance += amount;
            return true;
        }
        else
        {
            std::cout<<"Your card isn't valuable"<<std::endl;
            return false;
        }
    }



private:
    std::shared_ptr<ICard> card;
    double balance;
};



#endif //UNIVERSAL_CARD_SOFTWARE_CBANKDECORATOR_H
