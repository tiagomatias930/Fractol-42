
---

# Fractol

## Descrição

O **Fractol** é um projeto desenvolvido na 42 Luanda que explora o fascinante mundo dos fractais através da programação gráfica. O objetivo principal é renderizar diferentes conjuntos de fractais, como o Mandelbrot e o Julia, utilizando a biblioteca gráfica MiniLibX. Este projeto é uma excelente oportunidade para entender melhor conceitos matemáticos como números complexos e iterações infinitas, além de aprimorar habilidades em programação gráfica e manipulação de eventos.

## Objetivos

- Renderizar e visualizar fractais utilizando a MiniLibX.
- Implementar manipulações como zoom, movimentos e alteração de cores.
- Gerenciar eventos de teclado e mouse para interatividade com os fractais.

## Aprendizado

Ao desenvolver o Fractol, você irá:
- Aprender a trabalhar com números complexos e entender a matemática por trás dos fractais.
- Desenvolver habilidades em programação gráfica, como manipulação de pixels, criação de janelas, e utilização de eventos.
- Aprofundar o conhecimento em gerenciamento de memória e otimização de código.
- Explorar o uso de diferentes bibliotecas, como a MiniLibX, e integrá-las no seu projeto.

## Estrutura do Projeto

- **main.c**: Arquivo principal que inicia o programa e gerencia a escolha do fractal a ser renderizado.
- **mandelbrot.c**: Contém a implementação da geração e renderização do conjunto Mandelbrot.
- **julia.c**: Contém a implementação da geração e renderização do conjunto Julia.
- **eventos.c**: Gerencia os eventos de teclado e mouse para interatividade com os fractais.
- **eventos2.c**: Gerencia eventos específicos para o conjunto Julia.
- **cor_map.c** e **cor_map2.c**: Responsáveis por mapear as iterações em cores para cada fractal.
- **fechar_janela.c**: Contém funções para fechar a janela e liberar recursos.
- **fractol.h**: Header file que define as estruturas e funções utilizadas no projeto.

## Como Usar

### Compilação

Para compilar o projeto, utilize o comando `make` no terminal:

```bash
make
```

### Execução

Para executar o Fractol, utilize o comando abaixo, especificando o fractal que deseja visualizar (mandelbrot ou julia):

```bash
./fractol mandelbrot
```

ou

```bash
./fractol julia
```

### Controles

- **Setas**: Movimentam a visualização do fractal.
- **Teclas '+' e '-'**: Controlam o zoom.
- **Tecla 'C'**: Alterna entre diferentes esquemas de cores.
- **Clique esquerdo/direito do mouse**: Zoom in/out.

## Conclusão

O projeto Fractol não é apenas uma aplicação gráfica, mas também uma experiência educacional que mistura matemática, programação e criatividade. Ao final, você terá uma compreensão mais profunda dos fractais, bem como habilidades práticas em programação gráfica que serão valiosas em projetos futuros.

---
