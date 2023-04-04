#include <stdio.h>
#include <string.h>

#define FUNCIONARIOSMAX 100
#define CLIENTESMAX 1000

struct clientes
{
    int status, chegada, atendimentoAtual, atendimentoTotal, espera;
};

void imprimirCliente(struct clientes cliente)
{
    printf("\tStatus: %d, ", cliente.status);
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
        clientes[i].status = -1; // Coloca "Não chegou" como status padrão
        clientes[i].atendimentoAtual = 0; // Coloca 0 como atendimento atual por padrão
        clientes[i].espera = 0; // Coloca 0 como espera por padrão
        scanf("%d %d", &clientes[i].chegada, &clientes[i].atendimentoTotal);
    }
    
    t = 0;
    while(clientes[qntClientes - 1].status != 1)
    {
        printf("\n\nTEMPO = %d\n\n", t);
        for(i = 0; i < qntClientes; i++) // Percorre clientes
        {
            if(t >= clientes[i].chegada && clientes[i].status < 1)
            {
                // Cliente já chegou e ainda não saiu
                if(clientes[i].status == 0)
                {
                    // Cliente está sendo atendido
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
                        clientes[i].status = 1;
                        printf("Cliente %d completou seu atendimento!\n", i);
                    }
                }
                else
                {
                    // Cliente ainda não está sendo atendido
                    if(funcionariosLivres > 0 && clientes[i].status == -1)
                    {
                        // Há funcionários livres e cliente está na fila
                        funcionariosLivres--;
                        clientes[i].status = 0;
                        printf("Cliente %d comecou seu atendimento!\n", i);
                        if(t > clientes[i].chegada)
                            clientes[i].espera++;
                    }
                    else if(!funcionariosLivres && clientes[i].status == -1 &&
                            t > clientes[i].chegada)
                    {
                        // Não há funcionários livres e cliente está na fila
                        clientes[i].espera++;
                        printf("Cliente %d esta na fila mas nao ha funcionarios livres\n", i);
                    }
                }
                
                printf("\n\tAnalisando Cliente %d:\n", i);
                imprimirCliente(clientes[i]);
                printf("\n");
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
        else
        {
            printf("\tCliente %d esperou %d min na fila\n", i, clientes[i].espera);
        }
    }
    printf("%d\n", cont);

    return 0;
}