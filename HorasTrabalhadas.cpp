//Grupo1: Danilo, Elen, Gabriel Lucas, Gustavo de Oliveira Vital, Jonatas, Leticia, Maria Eduarda, Matheus, Philipp, Sebastião

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Ficha {
    string nome;
    double horasTrabalhadasDia;
    int diasTrabalhados;
    double horasExtrasMes;
};

int main() {
    const int numPessoas = 5; // Variável que define 5 como o limite de fichas
    Ficha fichas[numPessoas];

    int numPessoasAdicionadas = 0; // Número de pessoas adicionadas até agora

    char continuar;
    do {
        if (numPessoasAdicionadas >= numPessoas) { // Condição de bloco que para a execução quando o número de fichas for 5
            cout << "Você atingiu o limite de fichas (" << numPessoas << "). Não é possível adicionar mais pessoas." << endl;
            break;
        }

        cout << "\nFicha da Pessoa " << numPessoasAdicionadas + 1 << endl;
        cout << "-----------------------" << endl;

        cout << "Digite seu primeiro nome: ";
        cin >> fichas[numPessoasAdicionadas].nome;

        cout << "Digite o número de horas trabalhadas em um dia: ";
        cin >> fichas[numPessoasAdicionadas].horasTrabalhadasDia;

        cout << "Digite o número de dias trabalhados no mês: ";
        cin >> fichas[numPessoasAdicionadas].diasTrabalhados;

        cout << "Digite o número de horas extras trabalhadas no mês: ";
        cin >> fichas[numPessoasAdicionadas].horasExtrasMes;

        numPessoasAdicionadas++;

        cout << "\nDeseja adicionar outra pessoa? (S/N): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');

    // Informações padrões que serão utilizadas no gerador de fichas
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
        
        // Relatório da jornada de trabalho e ganhos
        cout << "\nFicha da Pessoa " << i + 1 << endl;
        cout << "-----------------------" << endl;
        cout << "Nome: " << fichas[i].nome << endl;
        cout << "Horas Trabalhadas no Dia: " << fichas[i].horasTrabalhadasDia << " horas" << endl;
        cout << "Horas Trabalhadas no Mês: " << horasTrabalhadasMes << " horas" << endl;
        cout << "Horas Trabalhadas no Ano: " << horasTrabalhadasAno << " horas" << endl;
        cout << "Ganhos Diários: R$" << fixed << setprecision(2) << ganhosTotaisDia << endl;
        cout << "Ganhos Mensais: R$" << fixed << setprecision(2) << ganhosTotaisMes << endl;
        cout << "Ganhos Anuais: R$" << fixed << setprecision(2) << ganhosTotaisAno << endl;
    }

    return 0;
}
