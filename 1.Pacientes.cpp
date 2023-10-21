#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente
{
private:
    string CPF;
    string Nome;
    string Nascimento;

public:
    Paciente(string CPF, string Nome, string Nascimento);
    string getCPF() const;
    string getNome()const;
    string getNascimento()const;
    void setCPF(string CPF);
    void setNome(string Nome);
    void setNascimento(string Nascimento);
};

Paciente::Paciente(string CPF, string Nome, string Nascimento)
{
    this->CPF = CPF;
    this->Nome = Nome;
    this->Nascimento = Nascimento;
}

string Paciente::getCPF() const
{
    return CPF;
}

string Paciente::getNome() const
{
    return Nome;
}

string Paciente::getNascimento() const
{
    return Nascimento;
}

void Paciente::setCPF(string CPF)
{
    this->CPF = CPF;
}

void Paciente::setNome(string Nome)
{
    this->Nome = Nome;
}

void Paciente::setNascimento(string Nascimento)
{
    this->Nascimento = Nascimento;
}

// Função para incluir um novo paciente
void IncluirPaciente(vector<Paciente> &pacientes)
{
    string CPF, Nome, Nascimento;
    cout << "CPF: ";
    cin >> CPF;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, Nome);
    cout << "Data de Nascimento: ";
    cin >> Nascimento;

    Paciente novoPaciente(CPF, Nome, Nascimento);
    pacientes.push_back(novoPaciente);
    cout << "Paciente incluido com sucesso!" << endl;
}

// Função para excluir um paciente por CPF
void ExcluirPaciente(vector<Paciente>& pacientes) {
    string Excluircpf;
    cout << "Digite o CPF do Paciente que deseja excluir: ";
    cin >> Excluircpf;

    for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
        if (it->getCPF() == Excluircpf) {
            pacientes.erase(it);
            cout << "Paciente excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF nao encontrado. Nenhum paciente excluido." << endl;
}

// Função para alterar dados do paciente por CPF
void AlterarPaciente(vector<Paciente>& pacientes) {
    string Alterarcpf;
    cout << "Digite o CPF do paciente que deseja alterar: ";
    cin >> Alterarcpf;

    for (auto& paciente : pacientes) {
        if (paciente.getCPF() == Alterarcpf) {
            cout << "Dados atuais do paciente:" << endl;
            cout << "CPF: " << paciente.getCPF() << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Data de Nascimento: " << paciente.getNascimento() << endl;

            char opcao;
            cout << "Deseja alterar o nome do paciente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe o novo nome: ";
                cin.ignore();
                string Nome; 
                getline(cin, Nome);
                paciente.setNome(Nome);
            }

            cout << "Deseja alterar a data de nascimento do paciente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe a nova data de nascimento: ";
                string Nascimento; 
                cin >> Nascimento;
                paciente.setNascimento(Nascimento);
            }

            cout << "Paciente alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF nao encontrado." << endl;
}

// Função para listar todos os pacientes
void ListarPaciente(vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "Nenhum paciente cadastrado." << endl;
        return;
    }

    cout << "Lista de pacientes:" << endl;
    for (const Paciente& paciente : pacientes) {
        cout << "CPF: " << paciente.getCPF() << endl;
        cout << "Nome: " << paciente.getNome() << endl;
        cout << "Data de Nascimento: " << paciente.getNascimento() << endl;
        cout << "---------------------------" << endl;
    }
}

// Função para localizar um paciente por CPF
void LocalizarPaciente(vector<Paciente>& pacientes) {
    string Localizarcpf;
    cout << "Digite o CPF do paciente que deseja localizar: ";
    cin >> Localizarcpf;

    for (const Paciente& paciente : pacientes) {
        if (paciente.getCPF() == Localizarcpf) {
            cout << "CPF: " << paciente.getCPF() << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Data de Nascimento: " << paciente.getNascimento() << endl;
            return;
        }
    }

    cout << "CPF nao encontrado." << endl;
}

int main()
{
    vector<Paciente> pacientes;
    int escolha;
    do {
        cout << endl<< "Menu de Opcoes:" << endl;
        cout << "1. Incluir Paciente" << endl;
        cout << "2. Excluir Paciente" << endl;
        cout << "3. Alterar Paciente (Apenas por CPF)" << endl;
        cout << "4. Listar Pacientes" << endl;
        cout << "5. Localizar Paciente (Apenas por CPF)" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                IncluirPaciente(pacientes);
                break;
            case 2:
                ExcluirPaciente(pacientes);
                break;
            case 3:
                AlterarPaciente(pacientes);
                break;
            case 4:
                ListarPaciente(pacientes);
                break;
            case 5:
                LocalizarPaciente(pacientes);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    } while (escolha != 0);

    return 0;
}