#include <iostream>
#include <iomanip>
#include <cmath>
#include "./cabecalhos/newton-cotes.hpp"
#include "./cabecalhos/util-analise.hpp"

using namespace std;

// Funções disponíveis para integração
long double f(long double x) {
    return pow(sin(2*x) + 4*x*x + 3*x, 2);
}

long double g(long double x) {
    return (x*sqrt(x) + sqrt(x))/(1+pow(x, 2));
}

int main() {
    long double a, b;
    long double eps;
    int resp = 0;

    tuple<long double, int> pg1A;
    tuple<long double, int> pg1F;
    tuple<long double, int> pg2A;
    tuple<long double, int> pg2F;
    tuple<long double, int> pg3A;
    tuple<long double, int> pg3F;
    tuple<long double, int> pg4A;
    tuple<long double, int> pg4F;

    cout << "Programa para calculo numerico de integral usando as Formulas de Newton-Cotes\n";
    while (resp == 0) {
        cout << "Selecione a funcao que deseja integrar: " << endl <<
                "  1. (sin(2x) + 4x^2 + 3x)^2" << endl <<
                "  2. (x*sqrt(x) + sqrt(x))/(1+x^2)" << endl <<
                "Sua resposta: ";
        cin >> resp;
        if (resp < 1 || resp > 2)
            resp = 0;
    }
    cout << "Informe o intervalo de integracao ([a, b] separados por espaco): ";
    cin >> a >> b;
    cout << "Informe o erro maximo tolerado: ";
    cin >> eps;

    switch (resp) {
        case 1:
            pg1A = testar(f, a, b, eps, 1, 'a');
            pg1F = testar(f, a, b, eps, 1, 'f');
            pg2A = testar(f, a, b, eps, 2, 'a');
            pg2F = testar(f, a, b, eps, 2, 'f');
            pg3A = testar(f, a, b, eps, 3, 'a');
            pg3F = testar(f, a, b, eps, 3, 'f');
            pg4A = testar(f, a, b, eps, 4, 'a');
            pg4F = testar(f, a, b, eps, 4, 'f');
            break;
        case 2:
            pg1A = testar(g, a, b, eps, 1, 'a');
            pg1F = testar(g, a, b, eps, 1, 'f');
            pg2A = testar(g, a, b, eps, 2, 'a');
            pg2F = testar(g, a, b, eps, 2, 'f');
            pg3A = testar(g, a, b, eps, 3, 'a');
            pg3F = testar(g, a, b, eps, 3, 'f');
            pg4A = testar(g, a, b, eps, 4, 'a');
            pg4F = testar(g, a, b, eps, 4, 'f');
            break;
    }

    cout << "\nRESULTADOS OBTIDOS COM AS FORMULAS DE NEWTON-COTES:" << endl
         << "1. Polinomio Interpolador de grau 1:" << endl
         << "  1.1 Usando filosofia aberta: " << setiosflags (ios::fixed) << setprecision(10) <<std::get<0>(pg1A) << ", com " << std::get<1>(pg1A) << " particoes;" << endl
         << "  1.2 Usando filosofia fechada: " << setiosflags (ios::fixed) << setprecision(10) <<std::get<0>(pg1F) << ", com " << std::get<1>(pg1F) << " particoes;" << endl
         << "2. Polinomio Interpolador de grau 2:" << endl
         << "  2.1 Usando filosofia aberta: " << setiosflags (ios::fixed) << setprecision(10) <<std::get<0>(pg2A) << ", com " << std::get<1>(pg2A) << " particoes;" << endl
         << "  2.1 Usando filosofia fechada: " << setiosflags (ios::fixed) << setprecision(10) <<std::get<0>(pg2F) << ", com " << std::get<1>(pg2F) << " particoes;" << endl
         << "3. Polinomio Interpolador de grau 3:" << endl
         << "  3.1 Usando filosofia aberta:  " << setiosflags (ios::fixed) << setprecision(10) << std::get<0>(pg3A) << ", com " << std::get<1>(pg3A) << " particoes;" << endl
         << "  3.2 Usando filosofia fechada: " << setiosflags (ios::fixed) << setprecision(10) << std::get<0>(pg3F) << ", com " << std::get<1>(pg3F) << " particoes." << endl
         << "4. Polinomio Interpolador de grau 4:" << endl
         << "  4.1 Usando filosofia aberta:  " << setiosflags (ios::fixed) << setprecision(10) << std::get<0>(pg4A) << ", com " << std::get<1>(pg4A) << " particoes;" << endl
         << "  4.2 Usando filosofia fechada: " << setiosflags (ios::fixed) << setprecision(10) << std::get<0>(pg4F) << ", com " << std::get<1>(pg4F) << " particoes." << endl;

    return 0;
}
