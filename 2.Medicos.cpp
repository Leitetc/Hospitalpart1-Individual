#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Medico
{
private:
    string CRM;
    string Nome;
    string Especialidade;

public:
    Medico(string CRM, string Nome, string Especialidade);
    string getCRM() const;
    string getNome()const;
    string getEspecialidade()const;
    void setCRM(string CRM);
    void setNome(string Nome);
    void setEspecialidade(string Especialidade);
};

Medico::Medico(string CRM, string Nome, string Especialidade)
{
    this->CRM = CRM;
    this->Nome = Nome;
    this->Especialidade = Especialidade;
}

string Medico::getCRM() const
{
    return CRM;
}

string Medico::getNome() const
{
    return Nome;
}

string Medico::getEspecialidade() const
{
    return Especialidade;
}

void Medico::setCRM(string CRM)
{
    this->CRM = CRM;
}

void Medico::setNome(string Nome)
{
    this->Nome = Nome;
}

void Medico::setEspecialidade(string Especialidade)
{
    this->Especialidade = Especialidade;
}

// Função para incluir um novo medico
void IncluirMedico(vector<Medico> &medicos)
{
    string CRM, Nome, Especialidade;
    cout << "CRM: ";
    cin >> CRM;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, Nome);
    cout << "Especialidade: ";
    cin >> Especialidade;

    Medico novoMedico(CRM, Nome, Especialidade);
    medicos.push_back(novoMedico);
    cout << "Medico incluido com sucesso!" << endl;
}

// Função para excluir um medico por CRM
void ExcluirMedico(vector<Medico>& medicos) {
    string Excluircrm;
    cout << "Digite o CRM do Medico que deseja excluir: ";
    cin >> Excluircrm;

    for (auto it = medicos.begin(); it != medicos.end(); ++it) {
        if (it->getCRM() == Excluircrm) {
            medicos.erase(it);
            cout << "Medico excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "CRM nao encontrado. Nenhum medico excluido." << endl;
}

// Função para alterar dados do medico por CRM
void AlterarMedico(vector<Medico>& medicos) {
    string Alterarcrm;
    cout << "Digite o CRM do medico que deseja alterar: ";
    cin >> Alterarcrm;

    for (auto& medico : medicos) {
        if (medico.getCRM() == Alterarcrm) {
            cout << "Dados atuais do medico:" << endl;
            cout << "CRM: " << medico.getCRM() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade : " << medico.getEspecialidade() << endl;

            char opcao;
            cout << "Deseja alterar o nome do medico? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe o novo nome: ";
                cin.ignore();
                string Nome; 
                getline(cin, Nome);
                medico.setNome(Nome);
            }

            cout << "Deseja alterar a especialidade do paciente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe a nova Especialidade: ";
                string Especialidade; 
                cin >> Especialidade;
                medico.setEspecialidade(Especialidade);
            }

            cout << "MEdico alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "CRM nao encontrado." << endl;
}

// Função para listar todos os medicos
void ListarMedico(vector<Medico>& medicos) {
    if (medicos.empty()) {
        cout << "Nenhum medico cadastrado." << endl;
        return;
    }

    cout << "Lista de medicos:" << endl;
    for (const Medico& medico : medicos) {
        cout << "CRM: " << medico.getCRM() << endl;
        cout << "Nome: " << medico.getNome() << endl;
        cout << "Especialidade: " << medico.getEspecialidade() << endl;
        cout << "---------------------------" << endl;
    }
}

// Função para localizar um medico por CRM
void LocalizarMedico(vector<Medico>& medicos) {
    string Localizarcrm;
    cout << "Digite o CRM do medico que deseja localizar: ";
    cin >> Localizarcrm;

    for (const Medico& medico : medicos) {
        if (medico.getCRM() == Localizarcrm) {
            cout << "CRM: " << medico.getCRM() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            return;
        }
    }

    cout << "CRM nao encontrado." << endl;
}

int main()
{
    vector<Medico> medicos;
    int escolha;
    do {
        cout << endl<< "Menu de Opcoes:" << endl;
        cout << "1. Incluir Medico" << endl;
        cout << "2. Excluir Medico" << endl;
        cout << "3. Alterar Medico (Apenas por CRM)" << endl;
        cout << "4. Listar Medicoss" << endl;
        cout << "5. Localizar Medico (Apenas por CRM)" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                IncluirMedico(medicos);
                break;
            case 2:
                ExcluirMedico(medicos);
                break;
            case 3:
                AlterarMedico(medicos);
                break;
            case 4:
                ListarMedico(medicos);
                break;
            case 5:
                LocalizarMedico(medicos);
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