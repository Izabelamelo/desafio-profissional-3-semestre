#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;



// Declara��o da estrutura de dados do usu�rio
struct Usuario {
    int id_usuario;
    string nome;
    string usuario;
    string senha;    
    int nivel_permissao;
    bool motorista;
    // Informa��es de motorista
    int id_motorista;
    string data_nascimento;
    string tipo_sanguineo;
    string num_cnh;
    string telefone;
    string categoria_cnh;
    string sexo;
};

// Declara��o da estrutura de dados de posto
struct Posto {
    int id_posto;
    string nome_posto;
    string endereco_rua;
    string endereco_bairro;
    string endereco_cidade;
    string endereco_estado;
};

// Declara��o da estrutura de dados de ve�culo
struct Veiculo {
    int id_veiculo;
    string tipo_combustivel;
    string chassi;
    string modelo;
    string marca;
    int ano;
    string cor;
    string placa;
    string data_ultima_manutencao;
    string descricao_manutencao;
};

// Declara��o da estrutura de dados de di�rio de bordo
struct DiarioBordo {
    int id_diario;
    int id_veiculo;
    string endereco_viagem;
    string descricao_viagem;
    string data_viagem;
    string horario_inicial;
    string horario_final;
    int km_inicial;
    int km_final;
};

bool fazerLogin(const vector<Usuario>& usuarios, const string& usuario, const string& senha) {
    for (int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].usuario == usuario && usuarios[i].senha == senha) {
            return true;
        }
    }
    return false;
}


// Declara��o da fun��o para adicionar usu�rios ao sistema
void adicionarUsuario(vector<Usuario>& usuarios) {
    static int proximoID = 1; // Vari�vel est�tica para armazenar o pr�ximo ID a ser utilizado

    Usuario novoUsuario;
    novoUsuario.id_usuario = proximoID++; // Define o ID do novo usu�rio como o pr�ximo ID dispon�vel
    cout << "Digite o nome do usu�rio: ";
    cin.ignore();
    getline(cin, novoUsuario.nome);
    cout << "Digite o n�vel de permiss�o do usu�rio: ";
    cin >> novoUsuario.nivel_permissao;
    cout << "O usu�rio � motorista? (1-Sim, 0-N�o): ";
    cin >> novoUsuario.motorista;
    // Informa��es de motorista
    if (novoUsuario.motorista) {
        novoUsuario.id_motorista = novoUsuario.id_usuario; // Define o ID do motorista como o mesmo do usu�rio
        cout << "Digite a data de nascimento do motorista (DD/MM/AAAA): ";
        cin.ignore();
        getline(cin, novoUsuario.data_nascimento);
        cout << "Digite o tipo sangu�neo do motorista: ";
        getline(cin, novoUsuario.tipo_sanguineo);
        cout << "Digite o n�mero da CNH do motorista: ";
        getline(cin, novoUsuario.num_cnh);
        cout << "Digite o telefone do motorista: ";
        getline(cin, novoUsuario.telefone);
        cout << "Digite o nome do motorista: ";
        getline(cin, novoUsuario.nome);
        cout << "Digite a categoria da CNH do motorista: ";
        getline(cin, novoUsuario.categoria_cnh);
        cout << "Digite o sexo do motorista: ";
        getline(cin, novoUsuario.sexo);
    }
    usuarios.push_back(novoUsuario);
    cout << "Usu�rio adicionado com sucesso!\n";
}


// Declara��o da fun��o para exibir informa��es de um usu�rio espec�fico
void exibirInformacoesUsuario(const vector<Usuario>& usuarios) {
    int id_usuario;
    cout << "Digite o ID do usu�rio: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> id_usuario;
    
    for (unsigned int i = 0; i < usuarios.size(); i++) {
        Usuario usuario = usuarios[i];
        if (usuario.id_usuario == id_usuario) {
            cout << "Nome do Usu�rio: " << usuario.nome << endl;
            cout << "N�vel de Permiss�o: " << usuario.nivel_permissao << endl;
            if (usuario.motorista) {
                cout << "ID do Motorista: " << usuario.id_motorista << endl;
                cout << "Data de Nascimento: " << usuario.data_nascimento << endl;
                cout << "Tipo Sangu�neo: " << usuario.tipo_sanguineo << endl;
                cout << "N�mero CNH: " << usuario.num_cnh << endl;
                cout << "Telefone: " << usuario.telefone << endl;
                cout << "Categoria CNH: " << usuario.categoria_cnh << endl;
                cout << "Sexo do Motorista: " << usuario.sexo << endl;
            }
            return;
        }
    }
    
    cout << "Usu�rio n�o encontrado." << endl;
}
// Declara��o da fun��o para atualizar informa��es do motorista
void atualizarInformacoesMotorista(vector<Usuario>& usuarios) {
    int id_motorista;
    cout << "Digite o ID do motorista a ser atualizado: ";
    cin >> id_motorista;
    
    for (unsigned int i = 0; i < usuarios.size(); i++) {
        Usuario& usuario = usuarios[i];
        if (usuario.id_motorista == id_motorista) {
            cout << "Digite a nova data de nascimento do motorista (DD/MM/AAAA): ";
            cin.ignore();
            getline(cin, usuario.data_nascimento);
            cout << "Digite o novo tipo sangu�neo do motorista: ";
            getline(cin, usuario.tipo_sanguineo);
            cout << "Digite o novo n�mero da CNH do motorista: ";
            getline(cin, usuario.num_cnh);
            cout << "Digite o novo telefone do motorista: ";
            getline(cin, usuario.telefone);
            cout << "Digite o novo nome do motorista: ";
            getline(cin, usuario.nome);
            cout << "Digite a nova categoria da CNH do motorista: ";
            getline(cin, usuario.categoria_cnh);
            cout << "Digite o novo sexo do motorista: ";
            getline(cin, usuario.sexo);
            cout << "Informa��es do motorista atualizadas com sucesso!\n";
            return;
        }
    }
    
    cout << "Motorista n�o encontrado." << endl;
}
// Declara��o da fun��o para excluir motoristas do sistema
void excluirMotorista(vector<Usuario>& usuarios) {
    int id_motorista;
    cout << "Digite o ID do motorista a ser exclu�do: ";
    cin >> id_motorista;
    
    for (vector<Usuario>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        if (it->id_motorista == id_motorista) {
            usuarios.erase(it);
            cout << "Motorista exclu�do com sucesso!\n";
            return;
        }
    }
    
    cout << "Motorista n�o encontrado." << endl;
}

//Fun��o para adicionar posto
void adicionarPosto(vector<Posto>& postos) {
    static int proximoID = 1; // Vari�vel est�tica para armazenar o pr�ximo ID a ser utilizado

    Posto novoPosto;
    novoPosto.id_posto = proximoID++; // Define o ID do novo posto como o pr�ximo ID dispon�vel
    cout << "Digite o nome do posto: ";
    cin.ignore();
    getline(cin, novoPosto.nome_posto);
    cout << "Digite o endere�o do posto (rua): ";
    getline(cin, novoPosto.endereco_rua);
    cout << "Digite o endere�o do posto (bairro): ";
    getline(cin, novoPosto.endereco_bairro);
    cout << "Digite o endere�o do posto (cidade): ";
    getline(cin, novoPosto.endereco_cidade);
    cout << "Digite o endere�o do posto (estado): ";
    getline(cin, novoPosto.endereco_estado);
    postos.push_back(novoPosto);
    cout << "Posto adicionado com sucesso!\n";
}

//Fun��o para exibir informa��es de um posto
void exibirInformacoesPosto(const vector<Posto>& postos) {
    int id_posto;
    cout << "Digite o ID do posto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> id_posto;
    
    for (unsigned int i = 0; i < postos.size(); i++) {
        Posto posto = postos[i];
        if (posto.id_posto == id_posto) {
            cout << "Nome do posto: " << posto.nome_posto << endl;
            cout << "Endere�o: " << posto.endereco_rua << ", " << posto.endereco_bairro << ", " << posto.endereco_cidade << ", " << posto.endereco_estado << endl;
            return;
        }
    }
    
    cout << "Posto n�o encontrado." << endl;
}

// Declara��o da fun��o para adicionar ve�culos ao sistema
void adicionarVeiculo(vector<Veiculo>& veiculos) {
static int proximoID = 1; // Vari�vel est�tica para armazenar o pr�ximo ID a ser utilizado
       Veiculo novoVeiculo;
    novoVeiculo.id_veiculo = proximoID++; // Define o ID do novo ve�culo como o pr�ximo ID dispon�vel
    cout << "Digite o tipo de combust�vel do ve�culo: ";
    cin.ignore();
    getline(cin, novoVeiculo.tipo_combustivel);
    cout << "Digite o chassi do ve�culo: ";
    getline(cin, novoVeiculo.chassi);
    cout << "Digite o modelo do ve�culo: ";
    getline(cin, novoVeiculo.modelo);
    cout << "Digite a marca do ve�culo: ";
    getline(cin, novoVeiculo.marca);
    cout << "Digite o ano do ve�culo: ";
    cin >> novoVeiculo.ano;
    cout << "Digite a cor do ve�culo: ";
    cin.ignore();
    getline(cin, novoVeiculo.cor);
    cout << "Digite a placa do ve�culo: ";
    getline(cin, novoVeiculo.placa);
    cout << "Digite a data da �ltima manuten��o do ve�culo (DD/MM/AAAA): ";
    getline(cin, novoVeiculo.data_ultima_manutencao);
    cout << "Digite a descri��o da �ltima manuten��o do ve�culo: ";
    getline(cin, novoVeiculo.descricao_manutencao);
    veiculos.push_back(novoVeiculo);
    cout << "Ve�culo adicionado com sucesso!\n";
}

// Declara��o da fun��o para exibir informa��es de um ve�culo espec�fico
void exibirInformacoesVeiculo(const vector<Veiculo>& veiculos) {
    string placa_veiculo;
    cout << "Digite a placa do ve�culo: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, placa_veiculo);
    
    for (unsigned int i = 0; i < veiculos.size(); i++) {
        Veiculo veiculo = veiculos[i];
        if (veiculo.placa == placa_veiculo) {
            cout << "Tipo de Combust�vel: " << veiculo.tipo_combustivel << endl;
            cout << "Chassi: " << veiculo.chassi << endl;
            cout << "Modelo: " << veiculo.modelo << endl;
            cout << "Marca: " << veiculo.marca << endl;
            cout << "Ano: " << veiculo.ano << endl;
            cout << "Cor: " << veiculo.cor << endl;
            cout << "Placa: " << veiculo.placa << endl;
            cout << "Data da �ltima manuten��o: " << veiculo.data_ultima_manutencao << endl;
            cout << "Descri��o da �ltima manuten��o: " << veiculo.descricao_manutencao << endl;
            return;
        }
    }
    
    cout << "Ve�culo n�o encontrado." << endl;
}
// Fun��o para excluir um ve�culo
void excluirVeiculo(vector<Veiculo>& veiculos) {
    int id_veiculo;
    cout << "Digite o ID do ve�culo: ";
    cin >> id_veiculo;

    for (unsigned int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].id_veiculo == id_veiculo) {
            veiculos.erase(veiculos.begin() + i);
            cout << "Ve�culo exclu�do com sucesso!\n";
            return;
        }
    }

    cout << "Ve�culo n�o encontrado.\n";
}

// Fun��o para consultar todos os ve�culos
void consultarVeiculos(const vector<Veiculo>& veiculos) {
   
    if (veiculos.empty()) {
        cout << "Nenhum ve�culo cadastrado.\n";
        return;
    }

    cout << "Ve�culos cadastrados:\n";
    Veiculo veiculo : veiculos
    for (const Veiculo& veiculo : veiculos) {
        cout << "ID do ve�culo: " << veiculo.id_veiculo << endl;
        cout << "Tipo de combust�vel: " << veiculo.tipo_combustivel << endl;
        cout << "Chassi: " << veiculo.chassi << endl;
        cout << "Modelo: " << veiculo.modelo << endl;
        cout << "Marca: " << veiculo.marca << endl;
        cout << "Ano: " << veiculo.ano << endl;
        cout << "Cor: " << veiculo.cor << endl;
        cout << "Placa: " << veiculo.placa << endl;
        cout << "Data da �ltima manuten��o: " << veiculo.data_ultima_manutencao << endl;
        cout << "Descri��o da �ltima manuten��o: " << veiculo.descricao_manutencao << endl;
        cout << endl;
    }
}

// Fun��o para adicionar di�rio de bordo
void adicionarDiarioBordo(vector<DiarioBordo>& diariosBordo, const vector<Veiculo>& veiculos) {
    static int proximoID = 1;
    DiarioBordo novoDiarioBordo;
    novoDiarioBordo.id_diario = proximoID++;
    
    // Pede o ID do ve�culo
    cout << "Digite o ID do ve�culo: ";
    int id_veiculo;
    cin >> id_veiculo;
    // Procura o ve�culo com o ID informado
    bool veiculoEncontrado = false;
    for (unsigned int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].id_veiculo == id_veiculo) {
            veiculoEncontrado = true;
            break;
        }
    }
    if (!veiculoEncontrado) {
        cout << "Ve�culo n�o encontrado." << endl;
        return;
    }
    novoDiarioBordo.id_veiculo = id_veiculo;
    
    cout << "Digite o endere�o da viagem: ";
    cin.ignore();
    getline(cin, novoDiarioBordo.endereco_viagem);
    cout << "Digite a descri��o da viagem: ";
    getline(cin, novoDiarioBordo.descricao_viagem);
    cout << "Digite a data da viagem (DD/MM/AAAA): ";
    getline(cin, novoDiarioBordo.data_viagem);
    cout << "Digite o hor�rio inicial (HH:MM): ";
    getline(cin, novoDiarioBordo.horario_inicial);
    cout << "Digite o hor�rio final (HH:MM): ";
    getline(cin, novoDiarioBordo.horario_final);
    cout << "Digite o km inicial: ";
    cin >> novoDiarioBordo.km_inicial;
    cout << "Digiteo km final: ";
    cin >> novoDiarioBordo.km_final;
    // Adiciona o novo di�rio de bordo ao vetor
    diariosBordo.push_back(novoDiarioBordo);
    cout << "Di�rio de bordo adicionado com sucesso!" << endl;
}

// Fun��o para alterar um di�rio de bordo
void alterarDiarioBordo(vector<DiarioBordo>& diariosBordo) {
    int id_diario;
    cout << "Digite o ID do di�rio de bordo que deseja alterar: ";
    cin >> id_diario;

    for (unsigned int i = 0; i < diariosBordo.size(); i++) {
        if (diariosBordo[i].id_diario == id_diario) {
            DiarioBordo& diario = diariosBordo[i];
            cout << "Digite o endere�o da viagem: ";
            cin.ignore();
            getline(cin, diario.endereco_viagem);
            cout << "Digite a descri��o da viagem: ";
            getline(cin, diario.descricao_viagem);
            cout << "Digite a data da viagem (DD/MM/AAAA): ";
            getline(cin, diario.data_viagem);
            cout << "Digite o hor�rio inicial da viagem (HH:MM): ";
            getline(cin, diario.horario_inicial);
            cout << "Digite o hor�rio final da viagem (HH:MM): ";
            getline(cin, diario.horario_final);
            cout << "Digite o km inicial: ";
            cin >> diario.km_inicial;
            cout << "Digite o km final: ";
            cin >> diario.km_final;
            cout << "Di�rio de bordo alterado com sucesso!\n";
            return;
        }
    }

    cout << "Di�rio de bordo n�o encontrado.\n";
}

// Fun��o para consultar um di�rio de bordo por ve�culo e data
void consultarDiarioBordo(const vector<DiarioBordo>& diariosBordo) {
    string placa_veiculo, data;
    cout << "Digite a placa do ve�culo: ";
    cin.ignore();
    getline(cin, placa_veiculo);
    cout << "Digite a data da viagem (DD/MM/AAAA): ";
    getline(cin, data);

    for (const DiarioBordo& diario : diariosBordo) {
        if (diario.id_veiculo != -1 && diario.placa == placa_veiculo && diario.data_viagem == data) {
            cout << "ID do di�rio: " << diario.id_diario << endl;
            cout << "Endere�o da viagem: " << diario.endereco_viagem << endl;
            cout << "Descri��o da viagem: " << diario.descricao_viagem << endl;
            cout << "Data da viagem: " << diario.data_viagem << endl;
            cout << "Hor�rio inicial: " << diario.horario_inicial << endl;
            cout << "Hor�rio final: " << diario.horario_final << endl;
            cout << "KM inicial: " << diario.km_inicial << endl;
            cout << "KM final: " << diario.km_final << endl;
            return;
        }
    }

    cout << "Di�rio de bordo n�o encontrado.\n";
}

// Fun��o principal para executar o programa
int main() {
    vector<Usuario> usuarios = {
        {1, "Jo�o", "joaob", "senha123", 1, true, 123, "01/01/1990", "A+", "1234567890", "123456789", "B", "Masculino"},
        {2, "Maria", "mariab", "abc123", 2, false, 0, "", "", "", "", "", ""},
        {3, "Jos�", "jose", "1234", 1, true, 123, "01/01/1984", "A-", "1234786780", "453256789", "D", "Masculino"},
    };

    vector<Posto> postos;
    int opcao;
        int tentativas = 0;
    
    while (tentativas < 3) {
        string usuario, senha;
        cout << "Digite o nome de usu�rio: ";
        cin >> usuario;
        cout << "Digite a senha: ";
        cin >> senha;
    
        if (fazerLogin(usuarios, usuario, senha)) {
            cout << "Login realizado com sucesso!" << endl;
            break;
        } else {
            cout << "Login falhou. Usu�rio ou senha incorretos." << endl;
            tentativas++;
        }
    }
    
    if (tentativas >= 3) {
        cout << "N�mero m�ximo de tentativas excedido. Encerrando o programa." << endl;
        return 0;
    }
    
    while (true) {

        cout << "\n--- Sistema de Controle de Transporte ---\n"
             << "Escolha uma op��o:\n"
             << "1. Usu�rio\n"
             << "2. Posto\n"
             << "3. Veiculo\n"
             << "0. Sair\n";
        cin >> opcao;
    
        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            // Menu de op��es do usu�rio/motorista
            while (true) {
                cout << "\n--- Menu de Usu�rio/Motorista ---\n"
                     << "Escolha uma op��o:\n"
                     << "1. Adicionar Motorista\n"
                     << "2. Atualizar Cadastro do Motorista\n"
                     << "3. Excluir Motorista\n"
                     << "4. Consultar Motorista\n"
                     << "0. Voltar\n";
                cin >> opcao;
    
                if (opcao == 0) {
                    break;
                }
                else if (opcao == 1) {
                    adicionarUsuario(usuarios);
                }
                else if (opcao == 2) {
                    atualizarInformacoesMotorista(usuarios);
                }
                else if (opcao == 3) {
                    excluirMotorista(usuarios);
                }
                else if (opcao == 4) {
                    exibirInformacoesUsuario(usuarios);
                }
                else {
                    cout << "Op��o inv�lida." << endl;
                }
            }
        }
        else if (opcao == 2) {
            // Menu de op��es do posto
            while (true) {
                cout << "\n--- Menu de Posto ---\n"
                     << "Escolha uma op��o:\n"
                     << "1. Adicionar Posto\n"
                     << "2. Atualizar Cadastro do Posto\n"
                     << "3. Excluir Posto\n"
                     << "4. Consultar Posto\n"
                     << "0. Voltar\n";
                cin >> opcao;
    
                if (opcao == 0) {
                    break;
                }
                else if (opcao == 1) {
                    adicionarPosto(postos);
                }
                else if (opcao == 2) {
                    exibirInformacoesPosto(postos);
                }
                /*
                else if (opcao == 3) {
                    excluirPosto(postos);
                }
                else if (opcao == 4) {
                    exibirInformacoesPosto(postos);
                }
                */
                else {
                    cout << "Op��o inv�lida." << endl;
                }
            }
        }
        else {
            cout << "Op��o inv�lida." << endl;
        }
        }

    }   
    return 0;
}


