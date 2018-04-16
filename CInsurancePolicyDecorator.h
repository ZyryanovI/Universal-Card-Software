#ifndef UNIVERSAL_CARD_SOFTWARE_CPOLISDECORATOR_H
#define UNIVERSAL_CARD_SOFTWARE_CPOLISDECORATOR_H

#include "ICard.h"
#include "CCard.h"
#include <iostream>
#include <bits/shared_ptr.h>
#include <vector>

/**
 * \brief Структура для страховой ситуации
 *
 * Под страховой ситуацией понимается возможное событие,
 * на случай которого хочет застрахаваться клиент.
 * В нем указаны название ситуации,
 * сколько выплат получит клиент в случае осуществления этой ситуации
 * и сколько заплатил клиент для заключения договора на эту ситуацию
 *
 */

struct InsuranceSituation{
    InsuranceSituation(const std::string new_situation_name, double new_payments, double new_amount_paid)
    {
        situation_name = new_situation_name;
        payments = new_payments;
        amount_paid = new_amount_paid;
    }
    std::string situation_name;
    double payments;
    double amount_paid;
};

class CInsurancePolicyDecorator : public ICard{
public:
    CInsurancePolicyDecorator(std::shared_ptr<ICard> new_card)
    {
        card = new_card;
    }

    ~CInsurancePolicyDecorator()
    {}

    /**
     * \brief Функция, выводящая информацию
     * \details Выводит имя клиента и перечень страховых ситуаций
     */

    void Get_Info()
    {
        std::cout<<"Full name: "<<card->Get_Name()<<std::endl;
        std::cout<<"Your situations: "<<std::endl;
        for(int i=0; i<situantions.size(); ++i)
        {
            std::cout<<situantions[i].situation_name<<" "<<situantions[i].payments<<" "<<situantions[i].amount_paid<<std::endl;
        }
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
     * \brief Добавление новой страховой ситуации
     * @param new_situation_name
     * @param new_payments
     * @param new_amount_paid
     */

    void Add_Situation(const std::string &new_situation_name, double new_payments, double new_amount_paid)
    {
        situantions.push_back(InsuranceSituation(new_situation_name, new_payments, new_amount_paid));
    }

    /**
     * \brief Поиск страховой ситуации
     * \details Поиск производится по трем параметра ситуации
     * @param new_situation_name
     * @param new_payments
     * @param new_amount_paid
     * @return Индекс вхождения ситуации, если не найден -1
     */

    int Find_Situation(const std::string &new_situation_name, double new_payments, double new_amount_paid)
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

    /**
     * \brief Удаление ситации
     * \details Производится поиск ситуации, если не найдена - сообщение об ошибке, инча удаляется
     * @param new_situation_name
     * @param new_payments
     * @param new_amount_paid
     */

    void Remove_Situation(const std::string &new_situation_name, double new_payments, double new_amount_paid)
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
