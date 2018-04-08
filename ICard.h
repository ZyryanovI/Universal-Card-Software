#ifndef UNIVERSAL_CARD_SOFTWARE_ICARD_H
#define UNIVERSAL_CARD_SOFTWARE_ICARD_H

#include <string>

/**
 * \brief Интерфейс карты
 *
 * \details Используется для реализации карты и декорирования
 *
 *
 */

class ICard{

public:
    virtual ~ICard() = 0;
    virtual void Get_Info() = 0;
    virtual std::string Get_Name() const = 0;
    virtual unsigned long long int Get_Id() const = 0;
    virtual std::string Get_End() const = 0;
};




#endif //UNIVERSAL_CARD_SOFTWARE_ICARD_H
