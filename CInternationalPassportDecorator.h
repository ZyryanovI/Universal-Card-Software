#ifndef UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTDECORATOR_H
#define UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTDECORATOR_H

#include "ICard.h"
#include "CCard.h"
#include <iostream>
#include <bits/shared_ptr.h>
#include <vector>

/**
 * \brief Декорирование загран паспорта
 *
 */

class CInternationalPasportDecorator : public ICard{
public:
    CInternationalPasportDecorator(std::shared_ptr<ICard> new_card)
    {
        card = new_card;
    }

    ~CInternationalPasportDecorator()
    {}

    /**
     * \brief Функция, выводящаяя информацию о загран паспорте
     * \details Выводит имя, страну постоянного места жительства и посещенные страны
     *
     */

    void Get_Info()
    {
        std::cout<<"Full name: "<<card->Get_Name()<<std::endl;
        std::cout<<"Home country: "<<home_country<<std::endl;
        std::cout<<"Visited counties: "<<std::endl;
        for(int i=0; i<visited_countries.size(); ++i)
        {
            std::cout<<visited_countries[i]<<std::endl;
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
     * \brief Установка новой страны постоянного места проживания
     *
     * \param new_home_country
     */

    void Set_Home_Country(std::string &new_home_country)
    {
        home_country = new_home_country;
    }

    /**
     * \brief Добавляет страну в посещенные
     * \param new_country
     */

    void Add_Country(std::string &new_country)
    {
        visited_countries.push_back(new_country);
    }


private:
    std::shared_ptr<ICard> card;
    std::string home_country;
    std::vector<std::string> visited_countries;
};



#endif //UNIVERSAL_CARD_SOFTWARE_CINTERNATIONALPASSPORTDECORATOR_H
