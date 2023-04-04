#include <stdio.h>
#include <string.h>

#define FUNCIONARIOSMAX 100
#define CLIENTESMAX 1000

struct clientes
{
    char status[12]; // Nao chegou, Fila, Atendimento, Atendido
    int chegada, atendimentoAtual, atendimentoTotal, espera;
};

void imprimirCliente(struct clientes cliente)
{
    printf("Status: %s, ", cliente.status);
    printf("Chegada: %d, ", cliente.chegada);
    printf("Atendimento: %d de %d, ", cliente.atendimentoAtual, cliente.atendimentoTotal);
    printf("Espera: %d\n", cliente.espera);
}

int main()
{

    struct clientes clientes[CLIENTESMAX];
    int funcionariosLivres, qntFuncionarios, qntClientes, i, t, cont = 0;
    
    scanf("%d %d", &qntFuncionarios, &qntClientes);
    funcionariosLivres = qntFuncionarios;

    for(i = 0; i < qntClientes; i++) // Percorre clientes
    {
        strcpy(clientes[i].status, "Nao chegou"); // Coloca "Não chegou" como status padrão
        scanf("%d %d", &clientes[i].chegada, &clientes[i].atendimentoTotal);
    }
    
    t = 0;
    while(strcmp(clientes[qntClientes - 1].status, "Atendido"))
    {
        printf("\n\nTEMPO = %d\n\n", t);
        for(i = 0; i < qntClientes; i++) // Percorre clientes
        {
            if(t >= clientes[i].chegada)
            {
                // Cliente já chegou
                if(t == clientes[i].chegada)
                {
                    // Cliente acabou de chegar
                    strcpy(clientes[i].status, "Fila");
                    printf("Cliente %d acabou de chegar e esta na fila!\n", i);
                }

                if(!strcmp(clientes[i].status, "Atendimento"))
                {
                    if(clientes[i].atendimentoAtual < clientes[i].atendimentoTotal)
                    {
                        // Cliente está sendo e ainda precisa de atendimento
                        clientes[i].atendimentoAtual++;
                        printf("Cliente %d esta sendo atendido +1 min\n", i);
                    }
                    if(clientes[i].atendimentoAtual == clientes[i].atendimentoTotal)
                    {
                        // Cliente estava sendo atendido mas completou o atendimento
                        funcionariosLivres++;
                        strcpy(clientes[i].status, "Atendido");
                        printf("Cliente %d completou seu atendimento!\n", i);
                    }
                }
                
                if(funcionariosLivres > 0 && !strcmp(clientes[i].status, "Fila"))
                {
                    // Há funcionários livres e cliente está na fila
                    funcionariosLivres--;
                    strcpy(clientes[i].status, "Atendimento");
                    printf("Cliente %d comecou seu atendimento!\n", i);
                }
                if(!funcionariosLivres && !strcmp(clientes[i].status, "Fila"))
                {
                    // Não há funcionários livres e cliente está na fila
                    clientes[i].espera++;
                    printf("Cliente %d esta na fila mas nao ha funcionarios livres\n", i);
                }
                
                printf("Analisando Cliente %d:\n", i);
                imprimirCliente(clientes[i]);
            }
        }
        t++; // Passa o tempo
    }
    for(i = 0; i < qntClientes; i++)
    {
        if(clientes[i].espera > 20)
        {
            cont++;
            printf("Cliente %d esperou mais de 20 min na fila!\n", i);
        }
    }
    printf("%d\n", cont);

    return 0;
}