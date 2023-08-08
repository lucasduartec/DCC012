#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

#include <cmath>

#define A 0.85

/* Função de hash que retorna o resto da divisão */
int hash_divide(int key, int table_size)
{
    return key % table_size;
}

/* Função hash multiplicacao */
int hash_multiply(int key, int table_size)
{
    return floor(table_size*((key * A) - floor(key * A)));
}

/* Funçao minha hash */
int hash_my_func(int key, int table_size)
{
    //TODO: Implementar sua função de hash
    return 0; // altere essa linha
}



#endif /* HASH_FUNCTION_H */

