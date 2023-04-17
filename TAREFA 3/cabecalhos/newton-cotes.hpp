#ifndef NEWTONCOTES_HPP
#define NEWTONCOTES_HPP

typedef long double (*func)(long double); // func é um ponteiro para uma função que recebe long double e retorna long double

class NewtonCotes {
    public:
        // Função que, dados xi, xf e quantidade de subintervalos entre os pontos, calcula o tamanho de cada subintervalo
        virtual long double calcularH(long double xi, long double xf, long double n);
        virtual long double obterAproximacaoAberta(func f, long double xi, long double xf);
        virtual long double obterAproximacaoFechada(func f, long double xi, long double xf);
};

// Classe que implementa a fórmula de Newton-Cotes para polinômio de interpolaçãõ de grau 1 - Fórmula do Trápezio
class PG1 : public NewtonCotes {
    public:
       long double obterAproximacaoAberta(func f, long double xi, long double xf);
       long double obterAproximacaoFechada(func f, long double xi , long double xf);
};

//Classe que implementa a fórmula de Newton-Cotes para polinômio de interpolação de grau 2 - Regra de Milne e Simpson 1/3
class PG2 : public NewtonCotes {
    public:
       long double obterAproximacaoAberta(func f, long double xi, long double xf);
       long double obterAproximacaoFechada(func f, long double xi , long double xf);
};
// Classe que implementa a fórmula de Newton-Cotes para polinômio de interpolação de grau 3 (interpola por 4 pontos) - Simpson 3/8
class PG3 : public NewtonCotes {
    public:
        long double obterAproximacaoAberta(func f, long double xi, long double xf);
        long double obterAproximacaoFechada(func f, long double xi, long double xf);
};

// Classe que implementa a fórmula de Newton-Cotes para polinômio de interpolação de grau 4 (interpola por 5 pontos)
class PG4 : public NewtonCotes {
    public:
        long double obterAproximacaoAberta(func f, long double xi, long double xf);
        long double obterAproximacaoFechada(func f, long double xi, long double xf);
};

#endif