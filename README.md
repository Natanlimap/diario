# Introdução #

Este projeto implementa uma classe de um diario pessoal o qual foi proposto pelo professor da disciplina de Linguagem de Programacao 1, Waldson Patricio da Universidade Federal do Rio Grande Do Norte
O projeto utiliza algumas estrutura de dados comuns em c++, leitura e escrita de arquivos, configuracao do projeto definida pelo cliente e makefile para execucao do projeto.


# Funcoes #

As funcoes principais são: *add*, *list*, *search*.
Alem de funcoes internas como *loadmessages*, *write*, *interactive*, *get_current_data* e *get_current_time* as quais sao necessarias para a execucao do programa.

### ADD
Essa funcao adiciona uma mensagem no vector da classe e e utilizada tanto pelo cliente quanto em funcoes internas.

Para adicionar alguma mensagem basta digitar 
```sh
./diary add
./a.out
```
ou 

```sh
./diary add <mensagem> 
./a.out
```

### LIST
Essa funcao lista todas as mensagens do arquivo predefinido em (diary.config) e mostra no terminal seguindo as configuracoes do projeto.

Para listar as mensagens 
```sh
./diary list
./a.out
```

### SEARCH
Essa funcao retorna um vector com todas as mensagens que possuem a substring que foi digitada pelo cliente.

Para executar, basta 
```sh
./diary search
./a.out
```

## Configurando o projeto
No arquivo diary.config, temos duas configuracoes que podem ser alteradas pelo cliente: path e default_format.

A configuracao path serve para especificar onde o arquivo de mensagens sera lido e ou criado

ja o default_format serve para especificar como as mensagens serao listadas no terminal, seguindo as seguintes regras:
– %d sera substituido pela data da mensagem.
– %t sera substituído pela hora da mensagem.
– %m sera substituído pelo texto da mensagem.
- Todos os outros caracteres serao impressos da forma que foram escritos.

## Executando o programa
```sh
make

./diary

```

## Autor

**Natan Pereira** - (https://github.com/Natanlimap)

## Projeto
https://github.com/Natanlimap/diary

## Agradecimentos
E importante lembrar que partes desse codigo foram inspiradas em implementacoes feitas com a presenca e participacao do professor e dos colegas de turma da disciplina de Linguagem de Programacao 1, 2020.5, lecionada por Wadson Patricio. 

