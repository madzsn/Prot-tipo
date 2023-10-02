//Grupo1: Danilo, Elen, Gabriel Lucas, Gustavo de Oliveira Vital, Jonatas, Leticia, Maria Eduarda, Matheus, Philipp, Sebastião

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double salarioMensal = 1200.0; // Salário mensal fixo em R$ 1200
    double valorHora = salarioMensal / (20 * 8); // Valor da hora considerando um mês com 20 dias úteis e 8 horas por dia
    double valorHoraExtra = valorHora * 1.5; // Valor da hora extra (50% a mais)

    double horasTrabalhadasDia;
    int diasTrabalhados;
    double horasExtrasMes;

    // Solicitar o número de horas trabalhadas em um dia
    cout << "Digite o número de horas trabalhadas em um dia: ";
    cin >> horasTrabalhadasDia;

    // Solicitar o número de dias trabalhados no mês
    cout << "Digite o número de dias trabalhados no mês: ";
    cin >> diasTrabalhados;

    // Solicitar o número de horas extras trabalhadas no mês
    cout << "Digite o número de horas extras trabalhadas no mês: ";
    cin >> horasExtrasMes;

    // Calcular as horas trabalhadas no dia, no mês e no ano
    double horasTrabalhadasMes = horasTrabalhadasDia * diasTrabalhados;
    double horasTrabalhadasAno = horasTrabalhadasMes * 12;

    // Calcular os ganhos diários, mensais e anuais
    double ganhosDia = horasTrabalhadasDia * valorHora;
    double ganhosMes = horasTrabalhadasMes * valorHora;
    double ganhosAno = horasTrabalhadasAno * valorHora;

    // Calcular os ganhos das horas extras
    double ganhosExtrasMes = horasExtrasMes * valorHoraExtra;
    double ganhosExtrasAno = ganhosExtrasMes * 12;

    // Calcular os ganhos totais
    double ganhosTotaisDia = ganhosDia + (horasExtrasMes * valorHoraExtra);
    double ganhosTotaisMes = ganhosMes + ganhosExtrasMes;
    double ganhosTotaisAno = ganhosAno + ganhosExtrasAno;

    // Imprimir o relatório
    cout << "\nRelatório de Horas Trabalhadas e Ganhos" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Horas Trabalhadas no Dia: " << horasTrabalhadasDia << " horas" << endl;
    cout << "Horas Trabalhadas no Mês: " << horasTrabalhadasMes << " horas" << endl;
    cout << "Horas Trabalhadas no Ano: " << horasTrabalhadasAno << " horas" << endl;
    cout << "Ganhos Diários: R$" << fixed << setprecision(2) << ganhosTotaisDia << endl;
    cout << "Ganhos Mensais: R$" << fixed << setprecision(2) << ganhosTotaisMes << endl;
    cout << "Ganhos Anuais: R$" << fixed << setprecision(2) << ganhosTotaisAno << endl;
    
    return 0;
}
