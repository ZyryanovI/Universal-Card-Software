#ifndef UNIVERSAL_CARD_SOFTWARE_IREADER_H
#define UNIVERSAL_CARD_SOFTWARE_IREADER_H

#include <iostream>
#include <bits/shared_ptr.h>
#include "ICard.h"

/**
 * \brief интерфейс считывающего устройства
 *
 * Используется для реализации различных считывающих устройств
 *
 *
 */

class IReader{
public:
    virtual ~IReader() = 0;
    virtual void Read(std::shared_ptr<ICard> new_card) = 0;

};


#endif //UNIVERSAL_CARD_SOFTWARE_IREADER_H
