#ifndef UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTREADER_H
#define UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTREADER_H


#include "IReader.h"
#include "CInternationalPassportDecorator.h"

class CInternationalPasportReader : public IReader{
public:
    CInternationalPasportReader(std::shared_ptr<CInternationalPasportDecorator> new_card)
    {
        card = new_card;
    }

    ~CPasportReader()
    {}

    void Read(std::shared_ptr<ICard> new_card)
    {
        CInternationalPasportDecorator cur_card(new_card);
        std::shared_ptr<CInternationalPasportDecorator> ptr_cur_card(std::make_shared(&cur_card));
        card = ptr_cur_card;
    }

    void Show_Info()
    {
        card->Get_Info();
    }


private:
    std::shared_ptr<CInternationalPasportDecorator> card;

};



#endif //UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTREADER_H
