#ifndef UNIVERSAL_CARD_SOFTWARE_CPASPORTREADER_H
#define UNIVERSAL_CARD_SOFTWARE_CPASPORTREADER_H

#include "IReader.h"
#include "CPasportDecorator.h"

class CPasportReader : public IReader{
public:
    CPasportReader(std::shared_ptr<CPasportReader> new_card)
    {
        card = new_card;
    }

    ~CPasportReader()
    {}

    void Read(std::shared_ptr<ICard> new_card)
    {
        CPasportDecorator cur_card(new_card);
        std::shared_ptr<CPasportDecorator> ptr_cur_card(std::make_shared(&cur_card));
        card = ptr_cur_card;
    }

    void Show_Info()
    {
        card->Get_Info();
    }


private:
    std::shared_ptr<CPasportDecorator> card;

};



#endif //UNIVERSAL_CARD_SOFTWARE_CPASPORTREADER_H
