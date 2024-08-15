#include <stdio.h>
#include <string.h>
#include <locale.h>
#include<time.h>
#include <stdlib.h>
char palavrasecreta[20];
char chutes[30];
int chutesdados = 0;
void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
}


int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}


void desenhaforca() {

    printf("Vocé já deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}


void escolhepalavra() {
   FILE*f;
char *tema []= {"personagemAnime.txt", "palavras.txt", "filmes.txt","paises.txt","jogos.txt","animes.txt"}; 
char seleciona [100];
int temaAchado =0;
while(!temaAchado){
  printf("Temas disponíveis:\n personagemAnime.txt, palavras.txt, filmes.txt, paises.txt, jogos.txt, animes.txt \n ");
printf("Digite o tema: ");
scanf("%s", seleciona);
printf(" O tema selecionado foi: %s\n", seleciona);
for (int i = 0; i < 6; i++)
{
   if(strcmp(seleciona, tema[i]) == 0){
        temaAchado = 1;
        break;
   }
}
 if(!temaAchado){
    printf("Tema '%s' não encontrado. Por favor, introduza novamente um tema válido.\n", seleciona);
 }
}


for (int i = 0; i < 6; i++)
{
if(strcmp(seleciona, tema[i]) == 0){
f = fopen(tema[i], "r");
if(f == 0){
    printf("Banco de dados de palavras não disponível\n\n");
 fclose(f);
}
int qtddepalavras;
   fscanf(f, "%d", &qtddepalavras);
srand(time(0));
int randomico = rand()%qtddepalavras;
for (int i = 0; i < randomico; i++)
{
fscanf(f,"%s", &palavrasecreta);
}
fclose(f);
}

}  
}

int  enforcou(){
    int erros = 0;
    for (int i = 0; i < chutesdados; i++)
    {
        int existe = 0;
        for (int j = 0; j < strlen(palavrasecreta); j++)
        { 
        if(chutes[i] == palavrasecreta[j]){
            existe = 1;
            break;
        }
        }
    if(!existe)erros++;
    
    }
    printf("  _______\n");
    printf(" |/      |\n");
    printf(" |      %c%c%c\n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c\n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c\n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c\n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |\n");
    printf("_|___\n");
    printf("\n\n");
    return erros >= 5; 
}

int acertou(){
    
    for (int i=0; i<strlen(palavrasecreta); i++){
    if(!jachutou(palavrasecreta[i])){
        return 0;
    }

    }
 return  1; 
}
void desenharvitoria() {
    printf("\n");
    printf("       \\O/    \n");
    printf("        |     \n");
    printf("       / \\    \n");
    printf("    Parabéns! Você ganhou!\n");
    printf("\n");
}

int main(){
setlocale(LC_ALL, "");

    
    

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

        chutesdados++;

    } while (!acertou() && !enforcou());
printf("\n");
if(acertou()){
    desenharvitoria();
}
else{
    printf("enforcou. A palavra secreta era \n%s " ,palavrasecreta); 
}
}
