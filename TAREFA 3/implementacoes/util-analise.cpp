#include "../cabecalhos/util-analise.hpp"

long double calcularErroRelativo(long double valorAtual, long double valorAnterior) {
    return abs((valorAtual-valorAnterior)/valorAtual);
}

tuple<long double, int> testar(func f, long double a, long double b, long double eps, int grau, char filosofia) {
    int n = 1; // Número de repartições do problema
    long double erro = INF;
    long double valorAnterior = INF;
    long double soma; // Somatório dos valores aproximados da integral de cada subintevalo
    long double h;
    long double xi, xf; // Extremos de cada subintervalos que serão calculados para as n partições do problema
    vector<tuple<int, int, long double, long double, long double>>passos;

    PG1 pg1;
    PG2 pg2;
    PG3 pg3;
    PG4 pg4;

    while (erro > eps) {
        n++;
        h = (b-a)/n;
        soma = 0;
        for (int i=0; i<n; i++) {
            xi = a + i*h;
            xf = a + (i+1) * h;

            if (grau == 1) {
                if (filosofia == 'a')
                    soma += pg1.obterAproximacaoAberta(f, xi, xf); // Calculo da aproximacao de grau 1 pela filosofia aberta
                else
                    soma += pg1.obterAproximacaoFechada(f, xi, xf); //Calculo da aproximacao de grau 1 pela filosofia fechada
            }
            else if (grau == 2) {
                if (filosofia == 'a')
                    soma += pg2.obterAproximacaoAberta(f, xi, xf); // Calculo da aproximacao de grau 2 pela filosofia aberta
                else
                    soma += pg2.obterAproximacaoFechada(f, xi, xf); // Calculo da aproximacao de grau 2 pela filosofia fechada
            }
            else if (grau == 3) {
                if (filosofia == 'a')
                    soma += pg3.obterAproximacaoAberta(f, xi, xf); // Obtém aproximação por polinômio de grau 3 usando filosofia aberta
                else
                    soma += pg3.obterAproximacaoFechada(f, xi, xf); // Obtém aproximação por polinômio de grau 3 usando filosofia fechada
            }
            else {
                if (filosofia == 'a')
                    soma += pg4.obterAproximacaoAberta(f, xi, xf); // Obtém aproximação por polinômio de grau 4 usando filosofia aberta
                else
                    soma += pg4.obterAproximacaoFechada(f, xi, xf); // Obtém aproximação por polinômio de grau 4 usando filosofia fechada
            }
            passos.push_back(make_tuple(n, i, xi, xf, soma));
        }
        erro = calcularErroRelativo(soma, valorAnterior);
        valorAnterior = soma;
    }
    return make_tuple(soma, n);
}