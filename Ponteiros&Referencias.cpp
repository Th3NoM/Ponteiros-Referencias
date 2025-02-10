#include <iostream>

/**
*   Classe de funcionalidades
*/
class Funcoes
{
public:

    // Imprimindo valores referenciados
    void imprimirReferencia(int& valor);

    // Imprimindo o endereço de memória
    void imprimirEndereco(int* valor);

    // Pegando o valor de uma variavel com ponteiro, e não o endereço dela
    void imprimirValor(int* valor);

};

void Funcoes::imprimirReferencia(int& valor)
{
    // Imprime o valor referenciado
    std::cout << valor << std::endl;
}

void Funcoes::imprimirEndereco(int* valor)
{
    // Como pode observar, estou utilizando o indicador de referência aqui
    // mas aqui como o valor de parâmetro precisamos de outro valor já alocado, porém passando o endereço
    // de memória, na impressão, pegamos apenas a referência dele para imprimirmos a referencia do
    // endereço de memória do valor passado no parâmetro
    std::cout << &valor << std::endl;
}

void Funcoes::imprimirValor(int* valor)
{
    // Aqui o processo é um pouco diferente, mas nem tanto!
    // precisamos aqui o que chamamos de desreferencição! Sim!
    // Iremos desreferenciar o valor do parâmetro.
    // Sempre que de algum modo precisarmos manipular o valor após 
    // resgatarmos esse valor utilizando uma referencia de memória, que inclusive assim 
    // o precesso é mais rápido, precisamos depois desreferenciar esse valor

    // Aqui eu crio uma nova variavel que será apenas para demonstrar melhor
    // Para esse processo, precisamos apontar o ponteiro antes da variavel, isso
    // indica que essa variavel está desreferenciada do seu endereço de memória,
    // então podemos acessar o seu valor
    int valorDesreferenciado = *valor;

    std::cout << "Valor de endereco de memoria: " << &valor << std::endl;
    std::cout << "Valor desreferenciado (valor da variavel): " << valorDesreferenciado << std::endl;

}

int main()
{
    // Criando um objeto com ponteiro
    Funcoes* funcao = new Funcoes();

    // Obs: Como esta função está pedindo uma referência,
    // um lvalue, precisamos de valores que já estão alocados na memória.
    // Ou seja, valores por referência como o "&", eles buscam pela referência de memória da
    // variavel alocada. Então se colocarmos um valor diretamente assim como no exemplo abaixo, que se diz
    // um valor rvalue (um valor temporário), o compilador ja nos indicará um erro.
    // --- Desmarque a função abaixo para analisar o erro ---
    //funcao->imprimirReferencia(10);

    // Então precisamos criar uma variavel de valor inteiro
    // e assim passar como argunto no parâmetro
    int valorRef = 10;

    funcao->imprimirReferencia(valorRef);

    // criando um ponteiro, precisamos iniciarlizar ele,
    // então podemos criar um inteiro lvalue padrão, e no ponteiro passar uma referência desse novo 
    // valor
    int valor = 10;
    int* valorPtr = &valor;

    // Quando compilarmos o código, veremos um resultado um tanto estranho,
    // mas na verdade, é o valor de endereço de memória onde a variavel "valor" está alocada
    funcao->imprimirEndereco(valorPtr);

    // O valor desreferenciado também precisamos realizar o mesmo processo anterior;
    // irei utilizar as mesmas variaves para comparação
    funcao->imprimirValor(valorPtr);

    // Não esqueça de liberar memória após o uso da funcao
    delete funcao;

    return 0;

}
