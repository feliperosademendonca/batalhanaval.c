# Desafio - Jogo de Batalha Naval em C

Este projeto foi desenvolvido como parte dos desafios propostos nos módulos de programação em C da disciplina de Análise e Desenvolvimento de Sistemas (ADS) da Estácio de Sá. O objetivo é aplicar os conceitos de vetores, matrizes, loops e condicionais para construir um jogo simplificado de Batalha Naval.

## 🧠 Objetivo

- Representar um tabuleiro 10x10 usando matriz bidimensional.
- Posicionar dois navios de tamanho 3:
  - Um na horizontal.
  - Um na vertical.
- Garantir que os navios não ultrapassem os limites do tabuleiro e não se sobreponham.
- Exibir o tabuleiro no console com os navios posicionados.
- Adicionar habilidades especiais com áreas de efeito visuais.

## 🧨 Habilidades Especiais

No nível mestre do desafio, foram adicionadas três habilidades especiais ao tabuleiro, cada uma com uma área de efeito distinta. Essas habilidades são representadas por matrizes separadas e sobrepostas ao tabuleiro principal, marcando as posições afetadas com o valor `5`.

### Tipos de Habilidades

- **Cone**: Área em forma de triângulo invertido, com origem no topo e expansão para baixo.
- **Cruz**: Área em forma de cruz, com origem no centro.
- **Octaedro (Losango)**: Área em forma de losango, simulando a vista frontal de um octaedro.

### Representação no Tabuleiro

- `0` → Água  
- `3` → Navio  
- `5` → Área afetada pela habilidade

### Exemplo de Saída
