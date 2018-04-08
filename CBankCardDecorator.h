#ifndef UNIVERSAL_CARD_SOFTWARE_CBANKDECORATOR_H
#define UNIVERSAL_CARD_SOFTWARE_CBANKDECORATOR_H

#include <bits/shared_ptr.h>
#include <iostream>
#include "ICard.h"

/**
 * \brief Декорирование банковской карты
 */

class CBankCardDecorator : public ICard{

public:
    CBankCardDecorator(std::shared_ptr<ICard> new_card)
    {
        card = new_card;
        balance = 0;
    }

    ~CBankCardDecorator()
    {}

    /**
     * \brief Выводит информацию о банковской карте
     * \details выводит информацию о балансе карты и информацию о пользователе
     */

    void Get_Info()
    {
        std::cout<<"Your balance in "<<balance<<std::endl;
        std::cout<<"Some other information: "<<std::endl;
        card->Get_Info();
    }

    /**
     * \brief Реализация функции, возвращающей имя
     * \return Имя пользователя
     */

    std::string Get_Name() const
    {
        return card->Get_Name();
    }

    /**
     * \brief Реализация функции, возвращающей id
     * \return id
     */

    unsigned long long int Get_Id() const
    {
        return card->Get_Id();
    }

    /**
     * \brief Реализация функции, возвращающей дату окончания срок действия карты
     * \return дата окончания срок действия карты
     */

    std::string Get_End() const
    {
        return card->Get_End();
    }

    /**
     * \brief Проверяет, что карта работает
     *
     * Здесь происходит проверка того,
     * что карта работает(напимер не была ли заблокирована пользователем)
     *
     */

    bool Is_Valuable()
    {
        return true;
    }

    /**
     * \brief Функция снятия денег
     *
     * Тип возвращаемого значения - bool,
     * если операция успешна - деньги снимаются, иначе сообщение об ошибке
     *
     */

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

    /**
     * \brief Функция пополнения счета
     *
     * Тип возвращаемого значения - bool,
     * если операция успешна - счет пополнен, иначе сообщение об ошибке
     *
     */

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
