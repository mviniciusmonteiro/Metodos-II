#include "../cabecalhos/newton-cotes.hpp"

// NEWTON-COTES
// Função que, dados xi, xf e quantidade de subintervalos entre os pontos, calcula e retorna o tamanho de cada subintervalo
long double NewtonCotes::calcularH(long double xi, long double xf, long double n) {
    return (xf-xi)/n;
}
long double NewtonCotes::obterAproximacaoAberta(func f, long double xi, long double xf) {
    return 0;
    // Função será implementada nas classes filhas (polinômios de grau 1 (PG1), grau 2(PG2), grau 3 (PG3) e de grau 4 (PG4))
}
long double NewtonCotes::obterAproximacaoFechada(func f, long double xi, long double xf) {
   return 0;
    // Função será implementada nas classes filhas (polinômios de grau 1 (PG1), grau 2(PG2), grau 3 (PG3) e de grau 4 (PG4))
}

// Classe que implementa a fórmula de Newton-Cotes para polinômio de interpolaçãõ de grau 1 - Fórmula do Trápezio
//Fórmula Aberta
long double PG1::obterAproximacaoAberta(func f, long double xi, long double xf){
    //Calculando valor de h na filosofia aberta (são usados 2 pontos e 3 subintervalos na regra do Trapezio Aberta)
    long double h = this->calcularH(xi, xf, 3);

    return ((3*h)/2)*(f(xi + h) + f(xi + 2*h));
}
//Fórmula Fechada
long double PG1::obterAproximacaoFechada(func f, long double xi, long double xf){
    //Calculando valor de h na filosofia fechada (são usados 2 pontos na Regra do Trapézio)
    long double h = this->calcularH(xi, xf, 1);

    return (h/2) * (f(xi) + f(xf));
}

//Classe que implementa a fórmula de Newton-Cotes para polinômio de interpolação de grau 2 - Regra de Milne
// Formula Aberta 
long double PG2::obterAproximacaoAberta(func f, long double xi, long double xf){
    //Calculando valor de h na filosofia aberta (são usados 3 pontos e 4 subintervalos na Regra de Milne)
    long double h = this->calcularH(xi, xf, 4);

    return ((4*h)/3) * (2*(f(xi + h)) - f(xi + 2*h) + 2*(f(xi+3*h)));
}
//Formula Fechada
long double PG2::obterAproximacaoFechada(func f, long double xi, long double xf){
    //Calculando valor de h na filosofia fechada (são usados 3 pontos e 2 intervalos na Regra de Simpson)
    long double h = this->calcularH(xi,xf,2);

    return (h/3) * (f(xi) + 4*(f(xi + h)) + f(xf));
}

// Classe que implementa a fórmula de Newton-Cotes para polinômio de interpolação de grau 3 (interpola por 4 pontos) - Simpson 3/8
long double PG3::obterAproximacaoAberta(func f, long double xi, long double xf) {
    // Setando h para ser usado na filosofia aberta (como são necessários 4 pontos, então serão 5 subintervalos)
    long double h = calcularH(xi, xf, 5);

    return ((5*h)/24)*(11*(f(xi + h) + f(xi + 4*h)) + f(xi + 2*h) + f(xi + 3*h));
}
long double PG3::obterAproximacaoFechada(func f, long double xi, long double xf) {
    // Setando h para ser usado na filosofia fechada (como são necessários 4 pontos, então serão 3 subintervalos)
    long double h = calcularH(xi, xf, 3);

    return ((3*h)/8) * (f(xi) + 3*f(xi + h) + 3*f(xi +2*h) + f(xf));
}

// Classe que implementa a fórmula de Newton-Cotes para polinômio de interpolaçao de grau 4 (interpola por 5 pontos)
long double PG4::obterAproximacaoAberta(func f, long double xi, long double xf) {
    /* Setando o h para ser usado na fisosia aberta (como são 5 pontos, desconsiderando as extremidades, então serão 6 subintervalos)
    */
    long double h = this->calcularH(xi, xf, 6);

    return ((xf-xi)/20)*(11*(f(xi+h) + f(xi+5*h)) - 14*(f(xi+2*h) + f(xi+4*h)) + 26*f(xi+3*h));
}
long double PG4::obterAproximacaoFechada(func f, long double xi, long double xf) {
    /* Setando o h para ser usado na fisosia aberta (como são 5 pontos, considerando as extremidades, então serão 4 subintervalos)
    */
    long double h = this->calcularH(xi, xf, 4);

    return ((xf-xi)/90)*(7*(f(xi) + f(xf)) + 32*(f(xi+h) + f(xi+3*h)) + 12*f(xi+2*h));
}