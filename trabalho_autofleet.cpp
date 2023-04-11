#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Declaração da estrutura de dados do usuário
struct Usuario {
    int id_usuario;
    string nome;
    int nivel_permissao;
    bool motorista;
    // Informações de motorista
    int id_motorista;
    string data_nascimento;
    string tipo_sanguineo;
    string num_cnh;
    string telefone;
    string categoria_cnh;
    string sexo;
};

// Declaração da estrutura de dados de posto
struct Posto {
    int id_posto;
    string nome_posto;
    string endereco_rua;
    string endereco_bairro;
    string endereco_cidade;
    string endereco_estado;
};

// Declaração da estrutura de dados de veículo
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

// Declaração da estrutura de dados de diário de bordo
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

// Declaração da função para adicionar usuários ao sistema
void adicionarUsuario(vector<Usuario>& usuarios) {
    static int proximoID = 1; // Variável estática para armazenar o próximo ID a ser utilizado

    Usuario novoUsuario;
    novoUsuario.id_usuario = proximoID++; // Define o ID do novo usuário como o próximo ID disponível
    cout << "Digite o nome do usuário: ";
    cin.ignore();
    getline(cin, novoUsuario.nome);
    cout << "Digite o nível de permissão do usuário: ";
    cin >> novoUsuario.nivel_permissao;
    cout << "O usuário é motorista? (1-Sim, 0-Não): ";
    cin >> novoUsuario.motorista;
    // Informações de motorista
    if (novoUsuario.motorista) {
        novoUsuario.id_motorista = novoUsuario.id_usuario; // Define o ID do motorista como o mesmo do usuário
        cout << "Digite a data de nascimento do motorista (DD/MM/AAAA): ";
        cin.ignore();
        getline(cin, novoUsuario.data_nascimento);
        cout << "Digite o tipo sanguíneo do motorista: ";
        getline(cin, novoUsuario.tipo_sanguineo);
        cout << "Digite o número da CNH do motorista: ";
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
    cout << "Usuário adicionado com sucesso!\n";
}


// Declaração da função para exibir informações de um usuário específico
void exibirInformacoesUsuario(const vector<Usuario>& usuarios) {
    int id_usuario;
    cout << "Digite o ID do usuário: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> id_usuario;
    
    for (unsigned int i = 0; i < usuarios.size(); i++) {
        Usuario usuario = usuarios[i];
        if (usuario.id_usuario == id_usuario) {
            cout << "Nome do Usuário: " << usuario.nome << endl;
            cout << "Nível de Permissão: " << usuario.nivel_permissao << endl;
            if (usuario.motorista) {
                cout << "ID do Motorista: " << usuario.id_motorista << endl;
                cout << "Data de Nascimento: " << usuario.data_nascimento << endl;
                cout << "Tipo Sanguíneo: " << usuario.tipo_sanguineo << endl;
                cout << "Número CNH: " << usuario.num_cnh << endl;
                cout << "Telefone: " << usuario.telefone << endl;
                cout << "Categoria CNH: " << usuario.categoria_cnh << endl;
                cout << "Sexo do Motorista: " << usuario.sexo << endl;
            }
            return;
        }
    }
    
    cout << "Usuário não encontrado." << endl;
}
// Declaração da função para atualizar informações do motorista
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
            cout << "Digite o novo tipo sanguíneo do motorista: ";
            getline(cin, usuario.tipo_sanguineo);
            cout << "Digite o novo número da CNH do motorista: ";
            getline(cin, usuario.num_cnh);
            cout << "Digite o novo telefone do motorista: ";
            getline(cin, usuario.telefone);
            cout << "Digite o novo nome do motorista: ";
            getline(cin, usuario.nome);
            cout << "Digite a nova categoria da CNH do motorista: ";
            getline(cin, usuario.categoria_cnh);
            cout << "Digite o novo sexo do motorista: ";
            getline(cin, usuario.sexo);
            cout << "Informações do motorista atualizadas com sucesso!\n";
            return;
        }
    }
    
    cout << "Motorista não encontrado." << endl;
}
// Declaração da função para excluir motoristas do sistema
void excluirMotorista(vector<Usuario>& usuarios) {
    int id_motorista;
    cout << "Digite o ID do motorista a ser excluído: ";
    cin >> id_motorista;
    
    for (vector<Usuario>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        if (it->id_motorista == id_motorista) {
            usuarios.erase(it);
            cout << "Motorista excluído com sucesso!\n";
            return;
        }
    }
    
    cout << "Motorista não encontrado." << endl;
}

//Função para adicionar posto
void adicionarPosto(vector<Posto>& postos) {
    static int proximoID = 1; // Variável estática para armazenar o próximo ID a ser utilizado

    Posto novoPosto;
    novoPosto.id_posto = proximoID++; // Define o ID do novo posto como o próximo ID disponível
    cout << "Digite o nome do posto: ";
    cin.ignore();
    getline(cin, novoPosto.nome_posto);
    cout << "Digite o endereço do posto (rua): ";
    getline(cin, novoPosto.endereco_rua);
    cout << "Digite o endereço do posto (bairro): ";
    getline(cin, novoPosto.endereco_bairro);
    cout << "Digite o endereço do posto (cidade): ";
    getline(cin, novoPosto.endereco_cidade);
    cout << "Digite o endereço do posto (estado): ";
    getline(cin, novoPosto.endereco_estado);
    postos.push_back(novoPosto);
    cout << "Posto adicionado com sucesso!\n";
}

//Função para exibir informações de um posto
void exibirInformacoesPosto(const vector<Posto>& postos) {
    int id_posto;
    cout << "Digite o ID do posto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> id_posto;
    
    for (unsigned int i = 0; i < postos.size(); i++) {
        Posto posto = postos[i];
        if (posto.id_posto == id_posto) {
            cout << "Nome do posto: " << posto.nome_posto << endl;
            cout << "Endereço: " << posto.endereco_rua << ", " << posto.endereco_bairro << ", " << posto.endereco_cidade << ", " << posto.endereco_estado << endl;
            return;
        }
    }
    
    cout << "Posto não encontrado." << endl;
}

// Declaração da função para adicionar veículos ao sistema
void adicionarVeiculo(vector<Veiculo>& veiculos) {
static int proximoID = 1; // Variável estática para armazenar o próximo ID a ser utilizado
       Veiculo novoVeiculo;
    novoVeiculo.id_veiculo = proximoID++; // Define o ID do novo veículo como o próximo ID disponível
    cout << "Digite o tipo de combustível do veículo: ";
    cin.ignore();
    getline(cin, novoVeiculo.tipo_combustivel);
    cout << "Digite o chassi do veículo: ";
    getline(cin, novoVeiculo.chassi);
    cout << "Digite o modelo do veículo: ";
    getline(cin, novoVeiculo.modelo);
    cout << "Digite a marca do veículo: ";
    getline(cin, novoVeiculo.marca);
    cout << "Digite o ano do veículo: ";
    cin >> novoVeiculo.ano;
    cout << "Digite a cor do veículo: ";
    cin.ignore();
    getline(cin, novoVeiculo.cor);
    cout << "Digite a placa do veículo: ";
    getline(cin, novoVeiculo.placa);
    cout << "Digite a data da última manutenção do veículo (DD/MM/AAAA): ";
    getline(cin, novoVeiculo.data_ultima_manutencao);
    cout << "Digite a descrição da última manutenção do veículo: ";
    getline(cin, novoVeiculo.descricao_manutencao);
    veiculos.push_back(novoVeiculo);
    cout << "Veículo adicionado com sucesso!\n";
}

// Declaração da função para exibir informações de um veículo específico
void exibirInformacoesVeiculo(const vector<Veiculo>& veiculos) {
    string placa_veiculo;
    cout << "Digite a placa do veículo: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, placa_veiculo);
    
    for (unsigned int i = 0; i < veiculos.size(); i++) {
        Veiculo veiculo = veiculos[i];
        if (veiculo.placa == placa_veiculo) {
            cout << "Tipo de Combustível: " << veiculo.tipo_combustivel << endl;
            cout << "Chassi: " << veiculo.chassi << endl;
            cout << "Modelo: " << veiculo.modelo << endl;
            cout << "Marca: " << veiculo.marca << endl;
            cout << "Ano: " << veiculo.ano << endl;
            cout << "Cor: " << veiculo.cor << endl;
            cout << "Placa: " << veiculo.placa << endl;
            cout << "Data da última manutenção: " << veiculo.data_ultima_manutencao << endl;
            cout << "Descrição da última manutenção: " << veiculo.descricao_manutencao << endl;
            return;
        }
    }
    
    cout << "Veículo não encontrado." << endl;
}
// Função para excluir um veículo
void excluirVeiculo(vector<Veiculo>& veiculos) {
    int id_veiculo;
    cout << "Digite o ID do veículo: ";
    cin >> id_veiculo;

    for (unsigned int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].id_veiculo == id_veiculo) {
            veiculos.erase(veiculos.begin() + i);
            cout << "Veículo excluído com sucesso!\n";
            return;
        }
    }

    cout << "Veículo não encontrado.\n";
}

// Função para consultar todos os veículos
void consultarVeiculos(const vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veículo cadastrado.\n";
        return;
    }

    cout << "Veículos cadastrados:\n";
    for (int i = 0; i < veiculos.size(); i++) {
        const Veiculo& veiculo = veiculos[i];
        cout << "ID do veículo: " << veiculo.id_veiculo << endl;
        cout << "Tipo de combustível: " << veiculo.tipo_combustivel << endl;
        cout << "Chassi: " << veiculo.chassi << endl;
        cout << "Modelo: " << veiculo.modelo << endl;
        cout << "Marca: " << veiculo.marca << endl;
        cout << "Ano: " << veiculo.ano << endl;
        cout << "Cor: " << veiculo.cor << endl;
        cout << "Placa: " << veiculo.placa << endl;
        cout << "Data da última manutenção: " << veiculo.data_ultima_manutencao << endl;
        cout << "Descrição da última manutenção: " << veiculo.descricao_manutencao << endl;
        cout << endl;
    }
}


// Função para adicionar diário de bordo
void adicionarDiarioBordo(vector<DiarioBordo>& diariosBordo, const vector<Veiculo>& veiculos) {
    static int proximoID = 1;
    DiarioBordo novoDiarioBordo;
    novoDiarioBordo.id_diario = proximoID++;
    
    // Pede o ID do veículo
    cout << "Digite o ID do veículo: ";
    int id_veiculo;
    cin >> id_veiculo;
    // Procura o veículo com o ID informado
    bool veiculoEncontrado = false;
    for (unsigned int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].id_veiculo == id_veiculo) {
            veiculoEncontrado = true;
            break;
        }
    }
    if (!veiculoEncontrado) {
        cout << "Veículo não encontrado." << endl;
        return;
    }
    novoDiarioBordo.id_veiculo = id_veiculo;
    
    cout << "Digite o endereço da viagem: ";
    cin.ignore();
    getline(cin, novoDiarioBordo.endereco_viagem);
    cout << "Digite a descrição da viagem: ";
    getline(cin, novoDiarioBordo.descricao_viagem);
    cout << "Digite a data da viagem (DD/MM/AAAA): ";
    getline(cin, novoDiarioBordo.data_viagem);
    cout << "Digite o horário inicial (HH:MM): ";
    getline(cin, novoDiarioBordo.horario_inicial);
    cout << "Digite o horário final (HH:MM): ";
    getline(cin, novoDiarioBordo.horario_final);
    cout << "Digite o km inicial: ";
    cin >> novoDiarioBordo.km_inicial;
    cout << "Digiteo km final: ";
    cin >> novoDiarioBordo.km_final;
    // Adiciona o novo diário de bordo ao vetor
    diariosBordo.push_back(novoDiarioBordo);
    cout << "Diário de bordo adicionado com sucesso!" << endl;
}

// Função para alterar um diário de bordo
void alterarDiarioBordo(vector<DiarioBordo>& diariosBordo) {
    int id_diario;
    cout << "Digite o ID do diário de bordo que deseja alterar: ";
    cin >> id_diario;

    for (unsigned int i = 0; i < diariosBordo.size(); i++) {
        if (diariosBordo[i].id_diario == id_diario) {
            DiarioBordo& diario = diariosBordo[i];
            cout << "Digite o endereço da viagem: ";
            cin.ignore();
            getline(cin, diario.endereco_viagem);
            cout << "Digite a descrição da viagem: ";
            getline(cin, diario.descricao_viagem);
            cout << "Digite a data da viagem (DD/MM/AAAA): ";
            getline(cin, diario.data_viagem);
            cout << "Digite o horário inicial da viagem (HH:MM): ";
            getline(cin, diario.horario_inicial);
            cout << "Digite o horário final da viagem (HH:MM): ";
            getline(cin, diario.horario_final);
            cout << "Digite o km inicial: ";
            cin >> diario.km_inicial;
            cout << "Digite o km final: ";
            cin >> diario.km_final;
            cout << "Diário de bordo alterado com sucesso!\n";
            return;
        }
    }

    cout << "Diário de bordo não encontrado.\n";
}


// Função para consultar um diário de bordo por veículo e data
void consultarDiarioBordo(const vector<DiarioBordo>& diariosBordo) {
	string id_veiculo, data;
	bool encontrado = false;
	cout << "Digite o código do veículo: ";
	cin.ignore();
	getline(cin, id_veiculo);
	cout << "Digite a data da viagem (DD/MM/AAAA): ";
	getline(cin, data);
	for (int i = 0; i < diariosBordo.size(); i++) {
  	  if (diariosBordo[i].id_veiculo != -1 && diariosBordo[i].data_viagem == data) {
	        cout << "ID do diário: " << diariosBordo[i].id_diario << endl;
	        cout << "Endereço da viagem: " << diariosBordo[i].endereco_viagem << endl;
	        cout << "Descrição da viagem: " << diariosBordo[i].descricao_viagem << endl;
	        cout << "Data da viagem: " << diariosBordo[i].data_viagem << endl;
	        cout << "Horário inicial: " << diariosBordo[i].horario_inicial << endl;
	        cout << "Horário final: " << diariosBordo[i].horario_final << endl;
	        cout << "KM inicial: " << diariosBordo[i].km_inicial << endl;
	        cout << "KM final: " << diariosBordo[i].km_final << endl;
	        encontrado = true;
	        break;
	    }
	}	

	if (!encontrado) {
	    cout << "Diário de bordo não encontrado.\n";
	}
}


// Função principal para executar o programa
int main() {
    vector<Usuario> usuarios;
    vector<Posto> postos;
    vector<Veiculo> veiculos;
    vector<DiarioBordo> diariosBordo;

    int opcao;
    while (true) {
        cout << "\n--- Autofleet - Controle de Frota de veículos da prefeitura ---\n"
             << "Escolha uma opção:\n"
             << "1. Usuário\n"
             << "2. Posto\n"
             << "3. Veiculo\n"
             << "4. Diario de bordo\n"
             << "0. Sair\n";
        cin >> opcao;
    
        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            // Menu de opções do usuário/motorista
            while (true) {
                cout << "\n--- Menu de Usuário/Motorista ---\n"
                     << "Escolha uma opção:\n"
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
                    cout << "Opção inválida." << endl;
                }
            }
        }
        else if (opcao == 2) {
            // Menu de opções do posto
            while (true) {
                cout << "\n--- Menu de Posto ---\n"
                     << "Escolha uma opção:\n"
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
                    cout << "Opção inválida." << endl;
                }
            }
        }
        else if (opcao==3) {
            // Menu de opções veiculos
            while (true) {
                cout << "\n--- Menu de Veiculos ---\n"
                     << "Escolha uma opção:\n"
                     << "1. Cadastrar veiculo\n"
                     << "2. Consulta - todos veiculos\n"
                     << "3. Consultar veiculo\n"
                     << "4. Excluir veiculo\n"
                     << "0. Voltar\n";
                cin >> opcao;
    
                if (opcao == 0) {
                    break;
                }
                else if (opcao == 1) {
                    adicionarVeiculo(veiculos);
                }
                else if (opcao == 2) {
                    consultarVeiculos(veiculos);
                }
                else if (opcao == 3) {
                    exibirInformacoesVeiculo(veiculos);
                } 
                else if (opcao == 4) {
                    excluirVeiculo(veiculos);
                } 				               
                else {
                    cout << "Opção inválida." << endl;
                }
		   }
    	}
		else if (opcao==4){
			//menu de opcoes diario de bordo
            while (true) {
                cout << "\n--- Diario de bordo dos veiculos ---\n"
                     << "Escolha uma opção:\n"
                     << "1. Cadastrar novo diario de bordo\n"
                     << "2. Alterar diario de bordo\n"
                     << "3. Consultar diario de bordo\n"
                     << "0. Voltar\n";
                cin >> opcao;
    
                if (opcao == 0) {
                    break;
                }
                else if (opcao == 1) {
                    adicionarDiarioBordo(diariosBordo,veiculos);
                }
                else if (opcao == 2) {
                    alterarDiarioBordo(diariosBordo);
                }
                else if (opcao == 3) {
                    consultarDiarioBordo(diariosBordo);
                }				               
                else {
                    cout << "Opção inválida." << endl;
                }			
	    	}
		}
		
		
        else {
            cout << "Opção inválida." << endl;
        }
    }
}


