#ifndef UNIVERSAL_CARD_SOFTWARE_CPASPORTDECORATOR_H
#define UNIVERSAL_CARD_SOFTWARE_CPASPORTDECORATOR_H

#include "ICard.h"
#include "CCard.h"
#include <iostream>
#include <bits/shared_ptr.h>
#include <vector>

/**
 * \brief Декорирование паспорта
 *
 */

class CPasportDecorator : public ICard{
public:
    CPasportDecorator(std::shared_ptr<ICard> new_card)
    {
        card = new_card;
    }

    ~CPasportDecorator()
    {}

    /**
     * \brief Выводит информацию о паспорте
     * \details Выводит имя пользователя, регистрацию, именя женыи детей, если они есть
     *
     */

    void Get_Info()
    {
        card->Get_Info();
        std::cout<<"Registration place is "<<registration_place<<std::endl;
        std::cout<<"Wife is "<<wife->Get_Name()<<std::endl;
        std::cout<<"Children are: "<<std::endl;
        for(int i =0; i<children.size(); ++i)
        {
            std::cout<<children[i]->Get_Name()<<std::endl;
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
     * \brief Функции добавления детей
     * \param child - указатель на карту ребенка
     */

    void Add_Child(std::shared_ptr<ICard> child)
    {
        children.push_back(child);
    }

    /**
     * \brief функция изменения регистрации
     * \param new_registration_place - новое место прописки
     */

    void Set_Registration_Place(std::string &new_registration_place)
    {
        registration_place = new_registration_place;
    }

    /**
     * \brief Функция изменения жены
     * \param new_wife - указатель на карту жены
     */

    void Set_Spouse(std::shared_ptr<ICard> new_wife)
    {
        spouse = new_wife;
    }



private:
    std::shared_ptr<ICard> card;
    std::string registration_place;
    std::vector<std::shared_ptr<ICard>> children;
    std::shared_ptr<ICard> spouse;
};


#endif //UNIVERSAL_CARD_SOFTWARE_CPASPORTDECORATOR_H
