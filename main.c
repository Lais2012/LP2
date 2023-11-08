/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct livro
{   int codigo,ano,isbn;
    char subtitulo[50],autor[50],conhecimento[50],titulo[50],editora[50];
};


int main(void)
{
    struct livro L;
    char isbn[13],info[100];
    int opcao;
    
    FILE *fp;
    
    printf("ACERVO\n\n");
    
    printf("Insira o isbn do livro: ");
    scanf("%s", &isbn);
    printf("Escolha uma opcao para prosseguir: \n\n1-Cadastrar livro\n2-Consultar Livro\n3-Acrescentar informações\n4-Sair\n");
    scanf("%d",&opcao);
    
    while(opcao!=4)
    {    switch(opcao)
        {   case 1:
            {
        
                fp= fopen(isbn,"r");
                
                if (fp != (FILE *)(NULL))
                {
                    printf("Livro já cadastrado\n\n");
                }
                else
                {   
                    fp= fopen(isbn,"w");
                    L.isbn= atoi(isbn);
                    printf("Título: ");
                    scanf("%s",&L.titulo);
                    printf("Subtítulo: ");
                    scanf("%s",&L.subtitulo);
                    printf("Autor: ");
                    scanf("%s",&L.autor);
                    printf("Editora: ");
                    scanf("%s",&L.editora);
                    printf("Area de conhecimento: ");
                    scanf("%s",&L.conhecimento);
                    fwrite(&L,sizeof(struct livro),1,fp);
                    fclose(fp);
                }
                break;
            }
            case 2:
            {
                fp=fopen(isbn,"r");
                
                if (fp != (FILE *)(NULL))
                {    fread(&L,sizeof(struct livro),1,fp);
                    
                    printf("Titulo: %s\n",&L.titulo);
                    printf("Subtitulo: %s\n",&L.subtitulo);
                    printf("Autor: %s\n",&L.autor);
                    printf("Editora: %s\n",&L.editora);
                    printf("Area de conhecimento: %s\n",&L.conhecimento);
                    printf("%s\n\n",&info);
                    fclose(fp);
                }
                else 
                    printf("Livro nao cadastrado\n\n");
                break;
            }
            case 3:
            {
                fp=fopen(isbn,"a");
                
                if (fp != (FILE *)(NULL))
                {    printf("Digite a informação desejada:");
                     scanf("%s",&info);
                     fprintf("%s",&info);
                }
                else
                    printf("Livro nao cadastrado\n\n");
            }
        }
        printf("Escolha uma opcao para prosseguir: \n1-Cadastrar livro\n2-Consultar Livro\n3-Acrescentar informações\n4-Sair\n\n");
        scanf("%d",&opcao);
    }
    return 0;
}




