#include <stdio.h>
#include <string.h>

// Definição da Estrutura
struct Pokemon {
    char nome[20];
    int vida;
    int ataque;
    int defesa;
};

// Função de Batalha
void batalhar(struct Pokemon *atacante, struct Pokemon *defensor) {
    // Calcula o dano: Ataque - Metade da Defesa
    int dano = atacante->ataque - (defensor->defesa / 2);
    
    // Se a defesa for muito alta, garante pelo menos 1 de dano
    if (dano < 1) dano = 1; 
    
    // Atualiza a vida do defensor
    defensor->vida = defensor->vida - dano;
    
    printf("\n>>> %s atacou %s!\n", atacante->nome, defensor->nome);
    printf(">>> Dano causado: %d\n", dano);
    
    if(defensor->vida < 0) defensor->vida = 0;
    printf(">>> Vida restante de %s: %d\n", defensor->nome, defensor->vida);
}

int menu(){
    int o;
    do {
        printf("\n--- Menu ---\n");
        printf("1 - Batalha pokemon\n");
        printf("2 - Apresentar pokemons\n");
        printf("Escolha: ");
        scanf("%d", &o);
        
        if(o != 1 && o != 2){
            printf("\nOpcao invalida, tente novamente!\n");
        }
    } while(o != 1 && o != 2);
    return o;
}

void ler_pokemon(struct Pokemon *p, int n) {
    printf("\n--- Pokemon %d ---\n", n);
    printf("Insira o nome do Pokemon: ");
    scanf("%19s", p->nome);
    
    do {
        printf("Insira a vida (HP > 0): ");
        scanf("%d", &p->vida);
        if(p->vida <= 0) printf("Erro: Vida deve ser positiva!\n");
    } while(p->vida <= 0);
    
    do {
        printf("Insira o ataque (ATK> 0): ");
        scanf("%d", &p->ataque);
        if(p->ataque <= 0) printf("Erro: Ataque deve ser positivo!\n");
    } while(p->ataque <= 0);
    
    do {
        printf("Insira a defesa (DEF> 0): ");
        scanf("%d", &p->defesa);
        if(p->defesa <= 0) printf("Erro: Defesa deve ser positiva!\n");
    } while(p->defesa <= 0);
}

void apresentar_pokemon(struct Pokemon *p) {
    printf("\n****** DADOS DO POKEMON ******\n");
    printf("Nome:   %s\n", p->nome);
    printf("Vida:   %d\n", p->vida);
    printf("Ataque: %d\n", p->ataque);
    printf("Defesa: %d\n", p->defesa);
    printf("******************************\n");
}

int main() {
    int opc;
    struct Pokemon p1, p2;
    
    // Lê os dados
    ler_pokemon(&p1, 1);
    ler_pokemon(&p2, 2);
    
    // Chama o menu
    opc = menu();
    
    if(opc == 2){
        // Apresenta os pokemons
        apresentar_pokemon(&p1);
        apresentar_pokemon(&p2);
    }
    else {
        // Simula a batalha
        batalhar(&p1, &p2);
    }
    
    return 0;
}