#ifndef UNIVERSAL_CARD_SOFTWARE_CPOLISREADER_H
#define UNIVERSAL_CARD_SOFTWARE_CPOLISREADER_H

#include "IReader.h"
#include "CInsurancePolicyDecorator.h"

/**
 * \brief Декорирование страхового полиса
 */

class CInsurancePolicyReader : public IReader{
public:
    CInsurancePolicyReader()
    {}

    CInsurancePolicyReader(std::shared_ptr<CInsurancePolicyDecorator> new_card)
    {
        card = new_card;
    }

    ~CInsurancePolicyReader()
    {}

    /**
     * \brief Функция считывания карты
     * \param new_card указатель на карту
     */

    void Read(std::shared_ptr<ICard> new_card)
    {
        CInsurancePolicyDecorator cur_card(new_card);
        std::shared_ptr<CInsurancePolicyDecorator> ptr_cur_card(std::make_shared(&cur_card));
        card = ptr_cur_card;
    }

    /**
     * \brief Функция, выводящая информацию о страховом полисе
     *
     */

    void Show_Info()
    {
        card->Get_Info();
    }

    /**
     * \brief Функция, добавляющая новую страховую ситуцацию
     * \param new_situation_name имя ситуации
     * \param new_payments выплаты в случае ее происшествия
     * \param new_amount_paid сколько заплатил клиент
     */

    void Add_Situation(const std::string &new_situation_name, double new_payments, double new_amount_paid)
    {
        card->Add_Situation(new_situation_name, new_payments, new_amount_paid);
    }

    /**
     * \brief Функция, удаляющая ситуацию
     * \param new_situation_name имя ситуации
     * \param new_payments выплаты в случае ее происшествия
     * \param new_amount_paid сколько заплатил клиент
     */

    void Remove_Situation(const std::string &new_situation_name, double new_payments, double new_amount_paid)
    {
        card->Remove_Situation(new_situation_name, new_payments, new_amount_paid);
    }


private:
    std::shared_ptr<CInsurancePolicyDecorator> card;

};



#endif //UNIVERSAL_CARD_SOFTWARE_CPOLISREADER_H
