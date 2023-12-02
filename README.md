README - Sistema de Controle de Produtos

Descrição
Este projeto consiste em um sistema de controle de produtos desenvolvido em linguagem C, como parte da Avaliação 1 (AV1) do curso de Indústria e Comércio da UNIJORGE. A solução proposta visa auxiliar processos industriais e comerciais, permitindo a consulta, manipulação e exclusão de dados em uma planilha.

Funcionalidades
Adicionar Produto: Permite a inclusão de novos produtos, fornecendo código, nome, preço e quantidade.

Editar Produto: Possibilita a edição de dados de um produto existente com base no código.

Excluir Produto: Remove um produto da lista, mantendo a integridade dos demais registros.

Listar Produtos: Apresenta a lista de produtos cadastrados, exibindo código, nome, preço e quantidade.

Instruções de Uso

Compilação: Compile o programa utilizando um compilador C, como o GCC. Exemplo de compilação no terminal:

gcc produtos.c

Execução: Execute o programa compilado. Exemplo:

./produtos.exe


Menu de Opções: Escolha as opções no menu para realizar operações como adicionar, editar, excluir ou listar produtos.
Saída: Ao encerrar o programa, os dados são gravados de volta no arquivo CSV automaticamente.

Formato dos Dados no Arquivo CSV
O arquivo "produtos.csv" armazena os dados dos produtos. O formato é o seguinte:

Código, Nome, Preço, Quantidade
1234, Produto Exemplo, 19.99, 10
Lembre-se de que o código é formatado com zeros à esquerda (por exemplo, "0012").

Observações
Este sistema foi desenvolvido como parte de uma avaliação acadêmica da UNIJORGE. Sinta-se à vontade para utilizar, estudar e modificar conforme suas necessidades.

Autor: [Guilherme-Bittencourt]

Data: [27/11/2023]
