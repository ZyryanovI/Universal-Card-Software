#ifndef UNIVERSAL_CARD_SOFTWARE_CBANKCARDREADER_H
#define UNIVERSAL_CARD_SOFTWARE_CBANKCARDREADER_H

#include "IReader.h"
#include "CBankCardDecorator.h"

class CBankReader : public IReader{
public:
    CBankReader(std::shared_ptr<CBankCardDecorator> new_card)
    {
        card = new_card;
    }

    ~CBankReader()
    {}

    void Read(std::shared_ptr<ICard> new_card)
    {
        CBankCardDecorator cur_card(new_card);
        std::shared_ptr<CBankCardDecorator> ptr_cur_card(std::make_shared(&cur_card));
        card = ptr_cur_card;
    }

    void Withdraw_Money(double amount)
    {
        card->Withdraw_Money(amount);
    }

    void Put_Money(double amount)
    {
        card->Put_Money(amount);
    }

    void Transfer_To_Another_Card(unsigned long long int card_id, double amount)
    {
        if(card->Withdraw_Money(amount))
        {
            std::cout<<"Success"<<std::endl;
        }
    }

    void Put_Money_To_Phone(std::string number, double amount)
    {
        if(card->Withdraw_Money(amount))
        {
            std::cout<<"Success"<<std::endl;
        }
    }

private:
    std::shared_ptr<CBankCardDecorator> card;

};


#endif //UNIVERSAL_CARD_SOFTWARE_CBANKCARDREADER_H
