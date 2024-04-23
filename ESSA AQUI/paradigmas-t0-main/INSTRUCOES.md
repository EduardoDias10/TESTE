Instruções para a realização do trabalho
========================================

Objetivos
---------

Compreender o processo de colaboração no Github e o sistema de testes automatizados.


Tarefas
----------

* Criar um `fork` do projeto [`paradigmas_2024_t0`](https://github.com/exercicios-programacao/paradigmas_2024_t0)
* Implemente, no arquivo `src/genarray.c`, as funções:`
    * `void GenericArray\_set(GenericArray \*array, int index, void\* value);`
    * `void GenericArray\_insert(GenericArray \*array, int index, void\* elem);`
    * `void GenericArray\_remove(GenericArray \*array, int index);`
* Será fornecido um sistema para a compilação e testes automatizados, assim como um _arquivo header_ com as funções que devem ser implementadas.
    * O sistema de compilação utilizará o `make`, o sistema de testes automatizados o `Catch2`, e a ferramenta `valgrind`.
        * Para compilar o programa utilize `make`.
        * Para executar os testes automatizados utilize `make test`.
        * Para executar o teste do `valgrind` utilize `make memtest`.


Sobre a Avaliação
-----------------

Ao requisitar o _pull request_ uma série de testes serão executados e uma
indicação da nota obtida no trabalho será fornecida. Note que esta nota pode
aumentar ou diminuir dependendo de outros fatores, como falhas nos testes de
qualidade de código, que diminuiriam a nota, ou soluções criativas e/ou
elegantes, que aumentariam a nota.

> **IMPORTANTE:** não é permitida a alteração de **nenhum** arquivo fora do
diretório `src`. Caso você queira adicionar mais testes, crie novos
arquivos no diretório `features`, mas não modifique os arquivos existentes.

