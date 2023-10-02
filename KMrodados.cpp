#include <iostream>
#include <iomanip>

// Função para calcular o custo da viagem com base na quilometragem total, consumo e valor do litro de diesel
double calcularCustoDaViagem(double quilometragemTotal, double consumoPorLitro, double valorLitroDiesel) {
    if (quilometragemTotal <= 0 || consumoPorLitro <= 0 || valorLitroDiesel <= 0) {
        std::cerr << "Erro: A quilometragem total, o consumo por litro e o valor do litro de diesel devem ser maiores que zero." << std::endl;
        return -1.0; // Retornar um valor negativo para indicar erro
    }

    double litrosConsumidos = quilometragemTotal / consumoPorLitro;
    return litrosConsumidos * valorLitroDiesel;
}

int main() {
    double quilometragemTotal;

    std::cout << "Informe a quilometragem total da viagem: ";
    std::cin >> quilometragemTotal;

    double consumoPorLitro = 4.04; // Consumo por litro do caminhão
    double valorLitroDiesel = 7.09; // Valor do litro de diesel

    double custoDaViagem = calcularCustoDaViagem(quilometragemTotal, consumoPorLitro, valorLitroDiesel);

    if (custoDaViagem >= 0) {
        std::cout << "A quilometragem total da viagem é: " << std::fixed << std::setprecision(2) << quilometragemTotal << " km" << std::endl;
        std::cout << "O custo da viagem é: R$" << std::fixed << std::setprecision(2) << custoDaViagem << std::endl;
    }

    return 0;
}