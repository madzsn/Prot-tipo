//Grupo1: Danilo, Elen, Gabriel Lucas, Gustavo de Oliveira Vital, Jonatas, Leticia, Maria Eduarda, Matheus, Philipp, Sebastião

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

struct Ficha {
    string nome;
    string cargo;
    double horasTrabalhadasDia;
    int diasTrabalhados;
    double horasExtrasMes;
};

// Função para validar se uma string contém apenas letras
bool contemApenasLetras(const string &str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

// Função para validar a entrada de números inteiros dentro de um intervalo
int obterNumeroInteiro(const string &mensagem, int minValor, int maxValor) {
    int numero;
    bool entradaValida = false;

    do {
        cout << mensagem;
        cin >> numero;

        if (cin.fail() || numero < minValor || numero > maxValor) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Digite um número entre " << minValor << " e " << maxValor << "." << endl;
        } else {
            entradaValida = true;
        }
    } while (!entradaValida);

    return numero;
}

int main() {
    const int numPessoas = 5;
    Ficha fichas[numPessoas];

    int numPessoasAdicionadas = 0;

    char continuar;
    do {
        if (numPessoasAdicionadas >= numPessoas) {
            cout << "Você atingiu o limite de fichas (" << numPessoas << "). Não é possível adicionar mais pessoas." << endl;
            break;
        }

        cout << "\nFicha da Pessoa " << numPessoasAdicionadas + 1 << endl;
        cout << "-----------------------" << endl;

        do {
            cout << "Digite o nome da pessoa (apenas letras): ";
            cin >> fichas[numPessoasAdicionadas].nome;
            
            cout << "Digite seu cargo: ";
            cin >> fichas[numPessoasAdicionadas].cargo;
            if (!contemApenasLetras(fichas[numPessoasAdicionadas].nome)) {
                cout << "Nome inválido. Digite apenas letras." << endl;
            }
        } while (!contemApenasLetras(fichas[numPessoasAdicionadas].nome));

        fichas[numPessoasAdicionadas].horasTrabalhadasDia = obterNumeroInteiro("Digite o número de horas trabalhadas em um dia (limite de 24 horas): ", 0, 24);
        fichas[numPessoasAdicionadas].diasTrabalhados = obterNumeroInteiro("Digite o número de dias trabalhados no mês (limite de 31 dias): ", 0, 31);
        fichas[numPessoasAdicionadas].horasExtrasMes = obterNumeroInteiro("Digite o número de horas extras trabalhadas no mês: ", 0, numeric_limits<int>::max());

        numPessoasAdicionadas++;

        cout << "\nDeseja adicionar outra pessoa? (S/N): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');

    // Agora, você pode gerar uma ficha para cada pessoa
    for (int i = 0; i < numPessoasAdicionadas; i++) {
        double salarioMensal = 1200.0;
        double valorHora = salarioMensal / (20 * 8);
        double valorHoraExtra = valorHora * 1.5;

        double horasTrabalhadasMes = fichas[i].horasTrabalhadasDia * fichas[i].diasTrabalhados;
        double horasTrabalhadasAno = horasTrabalhadasMes * 12;

        double ganhosDia = fichas[i].horasTrabalhadasDia * valorHora;
        double ganhosMes = horasTrabalhadasMes * valorHora;
        double ganhosAno = horasTrabalhadasAno * valorHora;

        double ganhosExtrasMes = fichas[i].horasExtrasMes * valorHoraExtra;
        double ganhosExtrasAno = ganhosExtrasMes * 12;

        double ganhosTotaisDia = ganhosDia + (fichas[i].horasExtrasMes * valorHoraExtra);
        double ganhosTotaisMes = ganhosMes + ganhosExtrasMes;
        double ganhosTotaisAno = ganhosAno + ganhosExtrasAno;

        cout << "\nFicha da Pessoa " << i + 1 << endl;
        cout << "-----------------------" << endl;
        cout << "Nome: " << fichas[i].nome << endl;
        cout << "Cargo: " << fichas[i].cargo << endl;
        cout << "Horas Trabalhadas no Dia: " << fichas[i].horasTrabalhadasDia << " horas" << endl;
        cout << "Horas Trabalhadas no Mês: " << horasTrabalhadasMes << " horas" << endl;
        cout << "Horas Trabalhadas no Ano: " << horasTrabalhadasAno << " horas" << endl;
        cout << "Ganhos Diários: R$" << fixed << setprecision(2) << ganhosTotaisDia << endl;
        cout << "Ganhos Mensais: R$" << fixed << setprecision(2) << ganhosTotaisMes << endl;
        cout << "Ganhos Anuais: R$" << fixed << setprecision(2) << ganhosTotaisAno << endl;
    }

    return 0;
}
