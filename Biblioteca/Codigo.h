#ifndef CODIGO_H
#define CODIGO_H
#include "fstream"
#include "QString"
#include "QFile"
#include "QTextStream"
namespace Vitor
{
    class Codigo
    {
    private:
        int value;
    public:
        Codigo();
        int gerarCodigo();
    };
}

#endif // CODIGO_H
