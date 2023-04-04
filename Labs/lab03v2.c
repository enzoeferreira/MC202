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
    int funcionariosLivres, qntFuncionarios, qntClientes, i, t, cont;
    
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
        for(i = 0; i < qntClientes; i++)
        {
            printf("\nAnalisando Cliente %d\n", i);
            imprimirCliente(clientes[i]);
            
            if(!(strcmp(clientes[i].status, "Nao chegou")) && t == clientes[i].chegada)
            {
                // Cliente acabou de chegar
                strcpy(clientes[i].status, "Fila");
                printf("Cliente %d de chegada = %d, ", i, clientes[i].chegada);
                printf("acabou de chegar e esta na fila!\n", i);
            }

            if(!funcionariosLivres)
            {
                // Sem funcionários livres
                if(!strcmp(clientes[i].status, "Fila"))
                {
                    clientes[i].espera++; // Esperou 1 min sem ser atendido
                    printf("Cliente %d esperou +1min na fila\n", i);
                }
                if(!strcmp(clientes[i].status, "Atendimento"))
                {
                    if(clientes[i].atendimentoAtual < clientes[i].atendimentoTotal)
                    {
                        // Ainda precisa ser atendido
                        clientes[i].espera++;
                        clientes[i].atendimentoAtual++; // +1 min de atendimento
                        printf("Cliente %d foi atendido por +1min", i);
                    }
                    else
                    {
                        // Atendimento acabou
                        strcpy(clientes[i].status, "Atendido");
                        funcionariosLivres++;
                        printf("Cliente %d concluiu seu atendimento\n", i);
                    }
                }
            }
            else
            {
                // Funcionários livres
                if(!strcmp(clientes[i].status, "Fila"))
                {
                    if(funcionariosLivres > 0)
                    {
                        // Há funcionários livres, cliente será atendido
                        funcionariosLivres--;
                        strcpy(clientes[i].status, "Atendimento");
                        printf("Cliente %d comecou a ser atendido\n", i);
                    }
                    clientes[i].espera++;
                }
                if(!strcmp(clientes[i].status, "Atendimento"))
                {
                    if(clientes[i].atendimentoAtual < clientes[i].atendimentoTotal)
                    {
                        // Cliente ainda precisa ser atendido
                        clientes[i].atendimentoAtual++;
                        clientes[i].espera++;
                        printf("Cliente %d foi atendido por +1 min (case 2)\n", i);
                    }
                    else
                    {
                        // Cliente não precisa mais ser atendido
                        strcpy(clientes[i].status, "Atendido");
                        printf("Cliente %d concluiu seu atendimento (case 2)\n", i);
                    }
                }
            }
        }
        t++; // Passa o tempo
    }

    /**
     * Contagem de quantos esperaram na fila por mais de 20 min
     */

    printf("\nComecando a contagem\n");
    for(i = 0; i < qntClientes; i++)
    {
        if(clientes[i].espera > 20)
            cont++;
            printf("Cliente %d esperou por mais de 20 min!\n");
    }
    printf("\nContagem: %d", cont);

    // // Impressão de cada cliente
    // for(i = 0; i < qntClientes; i++) // Percorre clientes
    //     imprimirCliente(clientes[i]);

    return 0;
}