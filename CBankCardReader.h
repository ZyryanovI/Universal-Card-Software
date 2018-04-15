#ifndef UNIVERSAL_CARD_SOFTWARE_CBANKCARDREADER_H
#define UNIVERSAL_CARD_SOFTWARE_CBANKCARDREADER_H

#include "IReader.h"
#include "CBankCardDecorator.h"

/**
 * \brief Считывающее устройство для банкосвкой карты
 */

class CBankReader : public IReader{
public:
    CBankReader()
    {}

    CBankReader(std::shared_ptr<CBankCardDecorator> new_card)
    {
        card = new_card;
    }

    ~CBankReader()
    {}

    /**
     * \brief Считывание карты
     * @param new_card указатель на карту
     */

    void Read(std::shared_ptr<ICard> new_card) {
        CBankCardDecorator cur_card(new_card);
        std::shared_ptr<CBankCardDecorator> ptr_cur_card(std::make_shared(&cur_card));
        card = ptr_cur_card;
    }

    /**
     * \brief Функция снятия денег
     * \details В случае ошибки выводит сообщение об ошибке
     * @param amount денежная сумма
     */

    bool Withdraw_Money(double amount)
    {
        return card->Withdraw_Money(amount);
    }

    /**
     * \brief Функция пополнения счета
     * @param amount
     */

    bool Put_Money(double amount)
    {
        return card->Put_Money(amount);
    }

    /**
     * \brief Функция перевода денег на другую карту
     * \details В случае успешного перевода выводит сообщение об успехе, иначе сообщение об ошибке
     * @param card_id
     * @param amount
     */

    void Transfer_To_Another_Card(unsigned long long int card_id, double amount)
    {
        if(card->Withdraw_Money(amount))
        {
            std::cout<<"Success"<<std::endl;
        }
    }

    /**
     * \brief Пополнение счета на телефоне
     * \details В случае успешного перевода выводит сообщение об успехе, иначе сообщение об ошибке
     * @param number
     * @param amount
     */

    void Put_Money_To_Phone(std::string &number, double amount)
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
