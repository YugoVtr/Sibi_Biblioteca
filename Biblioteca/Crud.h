#ifndef CRUD_H
#define CRUD_H

#include <QList>
#include "Codigo.h"

namespace Vitor
{

template <class Tipo>
class Crud
{
public:
    virtual void incluir(Tipo &objeto) const=0;
    virtual void alterar(Tipo &objeto) const=0;
    virtual QList<Tipo> *listagem() const=0;
    virtual ~Crud() {}
};

}

#endif // CRUD_H
