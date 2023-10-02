#include <iostream>
#include <iomanip>
#include <vector> // Para armazenar resumos de viagem

struct Viagem {
    std::string nomeMotorista;
    double quilometragemTotal;
    double custoDaViagem;
    double litrosConsumidos;
};

// Função para calcular os litros de diesel consumidos com base na quilometragem total e no consumo por litro
double calcularLitrosConsumidos(double quilometragemTotal, double consumoPorLitro) {
    if (quilometragemTotal <= 0 || consumoPorLitro <= 0) {
        std::cerr << "Erro: A quilometragem total e o consumo por litro devem ser maiores que zero." << std::endl;
        return -1.0; // Retornar um valor negativo para indicar erro
    }

    return quilometragemTotal / consumoPorLitro;
}

// Função para calcular o custo da viagem com base na quilometragem total, consumo e valor do litro de diesel
double calcularCustoDaViagem(double quilometragemTotal, double consumoPorLitro, double valorLitroDiesel) {
    if (quilometragemTotal <= 0 || consumoPorLitro <= 0 || valorLitroDiesel <= 0) {
        std::cerr << "Erro: A quilometragem total, o consumo por litro e o valor do litro de diesel devem ser maiores que zero." << std::endl;
        return -1.0; // Retornar um valor negativo para indicar erro
    }

    double litrosConsumidos = calcularLitrosConsumidos(quilometragemTotal, consumoPorLitro);
    return litrosConsumidos * valorLitroDiesel;
}

int main() {
    double consumoPorLitro = 4.04; // Consumo por litro do caminhão
    double valorLitroDiesel = 7.09; // Valor do litro de diesel
    std::vector<Viagem> resumos; // Vetor para armazenar resumos de viagem
    const int limiteResumos = 10; // Limite de 10 resumos

    int opcao;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Registrar Resumo de Viagem" << std::endl;
        std::cout << "2. Ver Resumos de Viagem" << std::endl;
        std::cout << "3. Encerrar" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                if (resumos.size() >= limiteResumos) {
                    std::cout << "Limite de resumos atingido. Não é possível registrar mais resumos." << std::endl;
                } else {
                    Viagem viagem;

                    std::cout << "Informe o nome do motorista: ";
                    std::cin.ignore(); // Limpa o buffer do teclado
                    std::getline(std::cin, viagem.nomeMotorista);

                    std::cout << "Informe a quilometragem total da viagem: ";
                    std::cin >> viagem.quilometragemTotal;

                    viagem.custoDaViagem = calcularCustoDaViagem(viagem.quilometragemTotal, consumoPorLitro, valorLitroDiesel);

                    if (viagem.custoDaViagem >= 0) {
                        viagem.litrosConsumidos = calcularLitrosConsumidos(viagem.quilometragemTotal, consumoPorLitro);
                        resumos.push_back(viagem);
                        std::cout << "Resumo de viagem registrado com sucesso!" << std::endl;
                    }
                }
                break;
            }
            case 2: {
                if (resumos.empty()) {
                    std::cout << "Não há resumos de viagem registrados." << std::endl;
                } else {
                    std::cout << "Resumos de Viagem:" << std::endl;
                    int contador = 1;
                    for (const auto& viagem : resumos) {
                        std::cout << "Resumo " << contador << ":" << std::endl;
                        std::cout << "Nome do Motorista: " << viagem.nomeMotorista << std::endl;
                        std::cout << "Quilometragem Total da Viagem: " << std::fixed << std::setprecision(4) << viagem.quilometragemTotal << " km" << std::endl;
                        std::cout << "O custo da viagem é: R$" << std::fixed << std::setprecision(4) << viagem.custoDaViagem << std::endl;
                        std::cout << "Foram consumidos " << std::fixed << std::setprecision(4) << viagem.litrosConsumidos << " litros de diesel." << std::endl;
                        contador++;
                    }
                }
                break;
            }
            case 3:
                std::cout << "Encerrando o programa." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Por favor, escolha uma opção válida." << std::endl;
                break;
        }
    } while (opcao != 3);

    return 0;
}
