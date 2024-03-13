#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CARROS 100
#define MAX_CLIENTES 100
#define MAX_VENDAS 100
#define MAX_VENDEDORES 10

char senhasClientes[MAX_CLIENTES][50];
char modelos[MAX_CARROS][50];
int anos[MAX_CARROS];
char cores[MAX_CARROS][20];
float precos[MAX_CARROS];
int quantidades[MAX_CARROS];
int totalCarros = 0;
char numTelefone[MAX_CLIENTES][20];

char nomesClientes[MAX_CLIENTES][50];
char cpfsClientes[MAX_CLIENTES][15];
int totalClientes = 0;

char nomesVendas[MAX_VENDAS][50];
int quantidadesVendas[MAX_VENDAS];
int totalVendas = 0;
int totalVendedores = 0;

typedef enum { VENDEDOR, CLIENTE } TipoUsuario;

typedef struct {
    char nome[50];
    char senha[50];
} Vendedor;
Vendedor vendedores[MAX_VENDEDORES];

typedef struct {
    char username[50];
    char password[50];
    TipoUsuario tipo;
} Usuario;

Usuario usuarios[] = {
    {"vendedor", "senha", VENDEDOR},
    {"cliente", "senha", CLIENTE},
};

int totalUsuarios = sizeof(usuarios) / sizeof(Usuario);


void inserirCarro() {
  printf("Modelo do carro: ");
  scanf("%s", modelos[totalCarros]);
  printf("Ano do carro: ");
  scanf("%d", &anos[totalCarros]);
  printf("Cor do carro: ");
  scanf("%s", cores[totalCarros]);
  printf("Preço do carro: ");
  scanf("%f", &precos[totalCarros]);
  printf("Quantidade em estoque: ");
  scanf("%d", &quantidades[totalCarros]);

  totalCarros++;

  printf("Carro inserido com sucesso!\n");
}

void buscarCarro() {
  char modeloBusca[50];
  printf("Digite o modelo do carro: ");
  scanf("%s", modeloBusca);

  for (int i = 0; i < totalCarros; i++) {
    if (strcasecmp(modelos[i], modeloBusca) == 0) {
      printf("Modelo: %s\n", modelos[i]);
      printf("Ano: %d\n", anos[i]);
      printf("Cor: %s\n", cores[i]);
      printf("Preço: %.2f\n", precos[i]);
      printf("Quantidade em estoque: %d\n", quantidades[i]);
      return;
    }
  }
  printf("Carro não encontrado!");
}

void alterarCarro() {
  char modeloAltera[50];
  printf("Digite o modelo do carro a ser alterado: ");
  scanf(" %s", modeloAltera);

  for (int i = 0; i < totalCarros; i++) {
    if (strcasecmp(modelos[i], modeloAltera) == 0) {
      printf("Digite o novo modelo: ");

      scanf(" %s", modelos[i]);
      printf("Digite o novo ano: ");

      scanf(" %d", &anos[i]);
      printf("Digite a nova cor: ");

      scanf(" %s", cores[i]);
      printf("Digite o novo preço: ");

      scanf(" %f", &precos[i]);
      printf("Digite a nova quantidade em estoque: ");

      scanf(" %d", &quantidades[i]);

      printf("Carro alterado com sucesso!\n");

      return;
    }

  }
  printf("Carro não encontrado!\n");
}

  void excluirCarro() {
    char modeloExclui[50];
    printf("Digite o modelo do carro a ser excluído: ");
    scanf("%s", modeloExclui);

    for (int i = 0; i < totalCarros; i++) {
      if (strcasecmp(modelos[i], modeloExclui) == 0) {
        for (int j = i; j < totalCarros - 1; j++) {
          strcpy(modelos[j], modelos[j + 1]);
          anos[j] = anos[j + 1];
          strcpy(cores[j], cores[j + 1]);
          precos[j] = precos[j + 1];
          quantidades[j] = quantidades[j + 1];
        }

        totalCarros--;

        printf("Carro excluído com sucesso!\n");
        return;
      }
    }
  }

  void exibirEstoque() {
    printf("Estoque de carros:\n");
    for (int i = 0; i < totalCarros; i++) {
      printf("Modelo: %s\n", modelos[i]);
      printf("Ano: %d\n", anos[i]);
      printf("Cor: %s\n", cores[i]);
      printf("Preço: %.2f\n", precos[i]);
      printf("Quantidade em estoque: %d\n", quantidades[i]);
      printf("----------------------\n");
    }
  }

  int verificarClienteCadastrado(const char *nome, const char *cpf) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(nomesClientes[i], nome) == 0 && strcmp(cpfsClientes[i], cpf) == 0) {
            return 1;
        }
    }
    return 0; 
}

void cadastrarCliente() {
    char novoNome[50];
    char novoCPF[15];
    char novaSenha[50]; 

    printf("Nome do cliente: ");
    scanf("%s", novoNome);

    printf("CPF do cliente: ");
    scanf("%s", novoCPF);

    printf("Senha: ");
    scanf("%s", novaSenha);

    strcpy(nomesClientes[totalClientes], novoNome);
    strcpy(cpfsClientes[totalClientes], novoCPF);
    strcpy(senhasClientes[totalClientes], novaSenha);

    printf("Numero de telefone do cliente: ");
    scanf("%s", numTelefone[totalClientes]);

    totalClientes++;

    printf("Cliente cadastrado com sucesso!\n");
}

  void alterarCliente() {
    char cpfAltera[15];
    printf("Digite o CPF do cliente a ser alterado: ");
    scanf("%s", cpfAltera);

    for (int i = 0; i < totalClientes; i++) {
      if (strcmp(cpfsClientes[i], cpfAltera) == 0) {

        printf("Digite o novo telefone: ");
        scanf(" %s", numTelefone[i]);

        printf("Cliente alterado com sucesso!\n");

        return;
      }
    }

    printf("Cliente não encontrado.\n");
  }

  void excluirCliente() {
    char cpfExclui[15];
    printf("Digite o CPF do cliente a ser excluído: ");
    scanf("%s", cpfExclui);

    for (int i = 0; i < totalClientes; i++) {
      if (strcmp(cpfsClientes[i], cpfExclui) == 0) {
        for (int j = i; j < totalClientes - 1; j++) {
          strcpy(nomesClientes[j], nomesClientes[j + 1]);
          strcpy(cpfsClientes[j], cpfsClientes[j + 1]);
          strcpy(numTelefone[j], numTelefone[j + 1]);
        }

        totalClientes--;

        printf("Cliente excluído com sucesso!\n");
        return;
      }
    }

    printf("Cliente não encontrado.\n");
  }

  void exibirClientes() {

    if (totalClientes <= 0)
      printf("Não há clientes cadastrados.\n");
    else {
      printf("Lista de clientes:\n");
      for (int i = 0; i < totalClientes; i++) {
        printf("Nome: %s\n", nomesClientes[i]);
        printf("CPF: %s\n", cpfsClientes[i]);
        printf("Telefone: %s\n", numTelefone[i]);
        printf("----------------------\n");
      }
    }
  }
void cadastrarVendedor() {
    if (totalVendedores < MAX_VENDEDORES) {
        printf("Nome do vendedor: ");
        scanf("%s", vendedores[totalVendedores].nome);

        printf("Senha: ");
        scanf("%s", vendedores[totalVendedores].senha);

        totalVendedores++;

        printf("Vendedor cadastrado com sucesso!\n");
    } else {
        printf("Limite máximo de vendedores atingido!\n");
    }
}

void realizarVendas() {
    char modeloVenda[50];
    printf("Digite o modelo do carro a ser vendido: ");
    scanf("%s", modeloVenda);

    int carroEncontrado = 0;

    for (int i = 0; i < totalCarros; i++) {
        if (strcmp(modelos[i], modeloVenda) == 0) {
            carroEncontrado = 1;

            int quantidadeVenda;
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &quantidadeVenda);
            if (quantidadeVenda > 0 && quantidadeVenda <= quantidades[i]) {
                quantidades[i] -= quantidadeVenda;
                strcpy(nomesVendas[totalVendas], modelos[i]);
                quantidadesVendas[totalVendas] = quantidadeVenda;
                totalVendas++;
                printf("Venda realizada com sucesso!\n");
                return;
            } else if (quantidadeVenda > 0 && quantidades[i] == 0) {
                printf("Carro não disponível em estoque.\n");
                printf("Deseja deixar a venda pendente? (s/n): ");
                char opcao;
                scanf(" %c", &opcao);
                if (opcao == 's' || opcao == 'S') {
                    printf("Venda pendente registrada com sucesso!\n");
                    strcpy(nomesVendas[totalVendas], modelos[i]);
                    quantidadesVendas[totalVendas] = quantidadeVenda;
                    totalVendas++;
                } else {
                    printf("Venda cancelada.\n");
                }
                return;
            } else {
                printf("Quantidade inválida ou insuficiente em estoque.\n");
                return;
            }
        }
    }

    if (!carroEncontrado) {
        printf("Carro não encontrado.\n");
        printf("Deseja deixar a venda pendente? (s/n): ");
        char opcao;
        scanf(" %c", &opcao);
        if (opcao == 's' || opcao == 'S') {
            printf("Venda pendente registrada com sucesso!\n");
            strcpy(nomesVendas[totalVendas], modeloVenda);
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &quantidadesVendas[totalVendas]);
            totalVendas++;
        } else {
            printf("Venda cancelada.\n");
        }
    }
}

  void consultarVendas() {
    if (totalVendas <= 0)
      printf("Não há vendas realizadas.\n");
    else
      printf("Lista de vendas:\n");
    for (int i = 0; i < totalVendas; i++) {
      printf("Carro: %s\n", nomesVendas[i]);
      printf("Quantidade vendida: %d\n", quantidadesVendas[i]);
      printf("----------------------\n");
    }
  }
int fazerLogin(char *username, char *password, TipoUsuario *tipoUsuario) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(username, nomesClientes[i]) == 0 && strcmp(password, senhasClientes[i]) == 0) {
            *tipoUsuario = CLIENTE;
            return 1;
        }
    }
  for (int i = 0; i < totalVendedores; i++) {
          if (strcmp(username, vendedores[i].nome) == 0 && strcmp(password, vendedores[i].senha) == 0) {
              *tipoUsuario = VENDEDOR;
              return 1;
          }
      }

      return 0;
  }

int main() {
    char escolha;
    char username[50];
    char password[50];
    TipoUsuario tipoUsuario;

    printf("Bem-vindo\n");

    while (1) {
        printf("Você deseja se cadastrar? (S/N): ");
        scanf(" %c", &escolha);

        if (escolha == 'S' || escolha == 's') {
           
            printf("Você deseja se cadastrar como vendedor ou cliente? (V/C): ");
            scanf(" %c", &escolha);

            if (escolha == 'V' || escolha == 'v') {
                 
                cadastrarVendedor();
            } else if (escolha == 'C' || escolha == 'c') {
               
                cadastrarCliente();
            } else {
                printf("Opção inválida. Por favor, escolha V ou C.\n");
            }
        } else if
          (escolha == 'N' || escolha == 'n') {
           
            printf("Nome de usuário: ");
            scanf("%s", username);

            printf("Senha: ");
            scanf("%s", password);

            if (fazerLogin(username, password, &tipoUsuario)) {
                printf("Login bem-sucedido!\n");
                break; 
            } else {
                printf("Usuário ou senha incorretos. Por favor, tente novamente.\n");
            }
        } else {
            printf("Opção inválida. Por favor, escolha S ou N.\n");
        }
    }
    if (tipoUsuario == VENDEDOR) {
        int opcao;
        while (1) {
            printf("\n-------Menu do Vendedor-------\n");
            printf("(1) Inserir carro\n");
            printf("(2) Buscar carro\n");
            printf("(3) Alterar carro\n");
            printf("(4) Excluir carro\n");
            printf("(5) Exibir estoque\n");
            printf("(6) Cadastrar Cliente\n");
            printf("(7) Alterar Cliente\n");
            printf("(8) Excluir Cliente\n");
            printf("(9) Exibir Clientes\n");
            printf("(10) Realizar vendas\n");
            printf("(11) Consultar vendas\n");
            printf("(12) Sair\n");

            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    inserirCarro();
                    break;
                case 2:
                    buscarCarro();
                    break;
              case 3:
                alterarCarro();
                break;
              case 4:
                excluirCarro();
                break;
              case 5:
                exibirEstoque();
                break;
              case 6:
                cadastrarCliente();
                break;
              case 7:
                alterarCliente();
                break;
              case 8:
                excluirCliente();
                break;
              case 9:
                exibirClientes();
                break;
              case 10:
                realizarVendas();
                break;
              case 11:
                consultarVendas();
                break;
              case 12:
                    printf("Saindo do programa. Até logo!\n");
                    exit(0);
                default:
                    printf("Opção inválida. Por favor, escolha novamente.\n");
            }
        }
    } else if (tipoUsuario == CLIENTE) {
        int opcao;
        while (1) {
            printf("\n-------Menu do Cliente-------\n");
            printf("(1) Buscar carro\n");
            printf("(2) Realizar compras\n");
            printf("(3) Consultar vendas\n");
            printf("(4) Sair\n");

            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    buscarCarro();
                    break;
               
               case 2:
                    printf("Saindo do programa. Até logo!\n");
                    exit(0);
                default:
                    printf("Opção inválida. Por favor, escolha novamente.\n");
            }
        }
    }

    return 0;
}

