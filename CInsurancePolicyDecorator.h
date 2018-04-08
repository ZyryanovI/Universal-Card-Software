#ifndef UNIVERSAL_CARD_SOFTWARE_CPOLISDECORATOR_H
#define UNIVERSAL_CARD_SOFTWARE_CPOLISDECORATOR_H

#include "ICard.h"
#include "CCard.h"
#include <iostream>
#include <bits/shared_ptr.h>
#include <vector>

struct InsuranceSituation{
    InsuranceSituation(std::string new_situation_name, double new_payments, double new_amount_paid)
    {
        situation_name = new_situation_name;
        payments = new_payments;
        amount_paid = new_amount_paid;
    }
    std::string situation_name;
    double payments;
    double amount_paid; //persont pay to have this insurance
};

class CInsurancePolicyDecorator : public ICard{
public:
    CInsurancePolicyDecorator(std::shared_ptr<ICard> new_card)
    {
        card = new_card;
    }

    ~CInsurancePolicyDecorator()
    {}

    void Get_Info()
    {
        std::cout<<"Full name: "<<card->Get_Name()<<std::endl;
        std::cout<<"Your situations: "<<std::endl;
        for(int i=0; i<situantions.size(); ++i)
        {
            std::cout<<situantions[i].situation_name<<" "<<situantions[i].payments<<" "<<situantions[i].amount_paid<<std::endl;
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


    void Add_Situation(std::string new_situation_name, double new_payments, double new_amount_paid)
    {
        situantions.push_back(InsuranceSituation(new_situation_name, new_payments, new_amount_paid));
    }

    int Find_Situation(std::string new_situation_name, double new_payments, double new_amount_paid)
    {
        for(int i = 0; i<situantions.size(); ++i)
        {
            if((situantions[i].situation_name == new_situation_name)&&(situantions[i].payments == new_payments)&&(situantions[i].amount_paid) == new_amount_paid)
            {
                return i;
            }
        }
        return -1;
    }

    void Remove_Situation(std::string new_situation_name, double new_payments, double new_amount_paid)
    {
        int k = Find_Situation(new_situation_name, new_payments, new_amount_paid);
        if(k == -1)
        {
            std::cout<<"There is no such situation"<<std::endl;
            return;
        }
        else
        {
            situantions.erase(situantions.begin()+k);
        }
    }


private:
    std::shared_ptr<ICard> card;
    std::vector<InsuranceSituation> situantions;
};



#endif //UNIVERSAL_CARD_SOFTWARE_CPOLISDECORATOR_H
