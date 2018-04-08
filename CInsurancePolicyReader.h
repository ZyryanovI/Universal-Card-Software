#ifndef UNIVERSAL_CARD_SOFTWARE_CPOLISREADER_H
#define UNIVERSAL_CARD_SOFTWARE_CPOLISREADER_H

#include "IReader.h"
#include "CInsurancePolicyDecorator.h"

class CInsurancePolicyReader : public IReader{
public:
    CInsurancePolicyReader(std::shared_ptr<CInsurancePolicyDecorator> new_card)
    {
        card = new_card;
    }

    ~CInsurancePolicyReader()
    {}

    void Read(std::shared_ptr<ICard> new_card)
    {
        CInsurancePolicyDecorator cur_card(new_card);
        std::shared_ptr<CInsurancePolicyDecorator> ptr_cur_card(std::make_shared(&cur_card));
        card = ptr_cur_card;
    }

    void Show_Info()
    {
        card->Get_Info();
    }

    void Add_Situation(std::string new_situation_name, double new_payments, double new_amount_paid)
    {
        card->Add_Situation(new_situation_name, new_payments, new_amount_paid);
    }

    void Remove_Situation(std::string new_situation_name, double new_payments, double new_amount_paid)
    {
        card->Remove_Situation(new_situation_name, new_payments, new_amount_paid);
    }


private:
    std::shared_ptr<CInsurancePolicyDecorator> card;

};



#endif //UNIVERSAL_CARD_SOFTWARE_CPOLISREADER_H
