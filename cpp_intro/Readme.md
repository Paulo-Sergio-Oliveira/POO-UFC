# Pesquisa sobre C++

- Quais as vantagens de uma linguagem compilada em relação a uma interpretada?
- Quais os tipos de comentários em C++?
- O include é um comando para o compilador ou para o pré-processador?
- O que é o pre-processador? Todos os comandos iniciados por # são para o pré-processador?
- O que é um namespace? Cite outras linguagens que possuem algo similar.
- Qual o conceito de escopo em uma linguagem de programação?
- Qual a diferença entre uma variável local e uma global?
- Quando uma variável é alocada na Stack e quando é alocada na Heap?
- Quais as formas de se inicializar uma variável em C++? Qual a mais recomendada?
- O que é o buffer de entrada e saída padrão? Como manipular esses buffers?
- O buffer de entrada sempre são sempre teclado e tela ou podem ser redirecionados?
- Quais os tipos primivos de dados em C++?
- Quais os principais modificadores de tipo em C++?
- Como funciona a palavra reservada auto?
- Como fazer a conversão entre tipos primivos em C e com é a sintaxe do static_cast? Qual a diferença entre static_cast e reinterpret_cast?
- Qual a diferença entre o ++ antes e depois de uma variável?
- Reescreva o seguinte código sem sem usar os operadores unários ++ e -- [LINK](#corrija)
- Na sintaxe de if, else, existe algum padrão que defina quando usar chaves ou não? Não apenas sobre a sintaxe, mas sobre a legibilidade e boas práticas de programação?
- C++ aceita inicialização de variáveis dentro de um if? No modelo `if (int x = 5; x < value) { ... }`?
- Como funciona um operador ternário? Quando vale a pena substituir um if else por um operador ternário?
- Em c++ função são elementos de primeira classe? O que isso significa?
- Qual seria a sintaxe para uma função lambda que recebe dois inteiros e retorna a soma deles?
- Para que serve um return em função função que não retorna nada?
- Em uma função, melhor criar vários ifs, elses ou múltiplos pontos de return?
- A passagem de parâmetros em C++ pode ser cópia, ponteiro ou referência. Qual a diferença entre cada uma delas?
- O que é um parâmetro default em uma função?
- O que é uma função inline? Quando vale a pena usar uma função inline?
- O que seria uma sobrecarga de função? Como o compilador diferencia duas funções com o mesmo nome?
- Qual a diferença entre passar um parâmetro por cópia ou por referência constante? Quando usar cada um?
- Qual a diferença entre declaração e definição de uma função?
- O que é a tabela de símbolos de um programa? Como ela é usada pelo compilador?
- Qual o tipo padrão de um texto "Hello World" em C++?
- Quais as formas de se criar um laço de repetição em C++?
- O que faz o continue e o break em um laço de repetição?
- Pesquise onde o C++ é mais utilizado e quais as vantagens de se usar essa linguagem em relação a outras.
- Quais são as principais linguagens com concorrem com C++ e quais as vantagens de cada uma delas?

## Corrija

```cpp
int a = 5;
int b = a++;
int c = ++a + --b;
std::cout << a << " " << b << " " << c << '\n';
```

# Resolução

1. **Vantagens de uma linguagem compilada em relação a uma interpretada**:
   - **Desempenho**: Linguagens compiladas tendem a ser mais rápidas, pois o código é convertido diretamente para código de máquina, o que elimina a necessidade de interpretação em tempo de execução.
   - **Verificação antecipada de erros**: Durante a compilação, erros são detectados antes da execução, o que permite maior segurança e menos problemas em tempo de execução.
   - **Distribuição**: O programa compilado pode ser distribuído como executável, sem necessidade do código-fonte.

2. **Tipos de comentários em C++**:
   - **Comentário de linha única**: `// comentário aqui`
   - **Comentário de múltiplas linhas**: `/* comentário aqui */`

3. **O `#include` é um comando para o compilador ou para o pré-processador?**
   - O `#include` é um comando para o **pré-processador**, que insere o conteúdo do arquivo especificado antes da etapa de compilação.

4. **O que é o pré-processador? Todos os comandos iniciados por `#` são para o pré-processador?**
   - O pré-processador é uma etapa do compilador que processa diretivas iniciadas pelo símbolo `#`, como `#include` e `#define`, realizando tarefas de inclusão de arquivos, substituições de macros e outras preparações antes da compilação.
   - Sim, todos os comandos iniciados por `#` são destinados ao pré-processador.

5. **O que é um namespace? Cite outras linguagens que possuem algo similar**:
   - Um **namespace** é uma forma de agrupar identificadores, como funções e variáveis, para evitar conflitos de nomes. Em C++, `namespace std` é amplamente utilizado para incluir elementos padrão.
   - Linguagens como **Java** (pacotes), **Python** (módulos) e **C#** (namespaces) têm conceitos semelhantes para organizar o código.

6. **Conceito de escopo em uma linguagem de programação**:
   - **Escopo** define a área dentro de um código onde uma variável ou função é reconhecida e pode ser acessada. Em C++, os escopos incluem escopo de função, escopo de bloco e escopo global.

7. **Diferença entre uma variável local e uma global**:
   - **Variável local**: Declarada dentro de uma função ou bloco e acessível apenas nesse contexto.
   - **Variável global**: Declarada fora de funções, acessível em qualquer parte do código após sua declaração.

8. **Quando uma variável é alocada na Stack e quando é alocada na Heap?**
   - **Stack**: Variáveis locais e alocações automáticas são geralmente alocadas na stack. A memória é gerenciada automaticamente, e o espaço é liberado ao sair do escopo.
   - **Heap**: Variáveis alocadas dinamicamente, como com `new`, são armazenadas na heap. O desenvolvedor deve liberar a memória (por exemplo, com `delete`).

9. **Formas de inicializar uma variável em C++ e a mais recomendada**:
   - **Inicialização direta**: `int x = 5;`
   - **Inicialização uniforme (C++11)**: `int x{5};`
   - **Inicialização por cópia**: `int x(5);`
   - A **inicialização uniforme** com `{ }` é a mais recomendada, pois evita conversões implícitas indesejadas e é mais segura.

10. **O que é o buffer de entrada e saída padrão? Como manipular esses buffers?**
   - O **buffer de entrada e saída padrão** é uma área de memória temporária onde os dados são armazenados antes de serem lidos ou escritos. Em C++, `cin` usa o buffer de entrada, enquanto `cout` usa o buffer de saída.
   - Para manipular buffers, você pode usar métodos como `cin.ignore()` para descartar entradas indesejadas ou `cout.flush()` para forçar a saída imediata dos dados em `cout`.

11. **O buffer de entrada sempre são teclado e tela ou podem ser redirecionados?**
   - O buffer de entrada padrão normalmente é o teclado, e o buffer de saída padrão é a tela. No entanto, eles podem ser redirecionados para arquivos ou outros dispositivos usando `freopen` ou manipuladores de fluxos em C++, como `ifstream` e `ofstream`.

12. **Quais os tipos primitivos de dados em C++?**
   - Os tipos primitivos em C++ incluem: `int`, `char`, `float`, `double`, `bool`, além de variações como `short`, `long`, `unsigned` e `wchar_t`.

13. **Quais os principais modificadores de tipo em C++?**
   - Os principais modificadores de tipo em C++ são `signed`, `unsigned`, `short`, e `long`, que permitem alterar o tamanho e o sinal de tipos primitivos como `int` e `char`.

14. **Como funciona a palavra reservada `auto`?**
   - A palavra-chave `auto` permite ao compilador deduzir o tipo da variável com base no valor de inicialização. Por exemplo, `auto x = 5;` faz com que `x` seja do tipo `int` automaticamente.

15. **Como fazer a conversão entre tipos primitivos em C e qual é a sintaxe do `static_cast`? Qual a diferença entre `static_cast` e `reinterpret_cast`?**
   - Em C++, o `static_cast` é uma maneira segura de conversão entre tipos compatíveis e tem a sintaxe `static_cast<tipo>(variável)`, por exemplo, `static_cast<int>(x)`.
   - `reinterpret_cast`, por outro lado, realiza conversões de ponteiros e tipos de maneira menos segura, interpretando os dados diretamente sem alterar a representação subjacente, o que pode ser arriscado e é mais usado em contextos específicos de baixo nível.

16. **Qual a diferença entre o `++` antes e depois de uma variável?**
   - `++variável` é o **pré-incremento**, que incrementa o valor antes de usá-lo na expressão.
   - `variável++` é o **pós-incremento**, que usa o valor atual da variável na expressão e, em seguida, incrementa o valor.

17. **Reescreva o código sem usar os operadores unários `++` e `--`:**
   ```cpp
    int a = 5;
    int b = a;
    a += 1;
    int c = (a +=1) + (b -= 1);
    std::cout << a << " " << b << " " << c << '\n';
   ```

18. **Na sintaxe de `if`, `else`, existe algum padrão que defina quando usar chaves ou não?**
   - Embora C++ permita omitir as chaves `{ }` em blocos de uma linha, é uma **boa prática** usá-las sempre, mesmo em blocos de uma linha, para evitar erros acidentais e aumentar a legibilidade. Isso melhora a manutenção do código, especialmente em trechos onde uma simples linha pode crescer para um bloco maior no futuro.

19. **C++ aceita inicialização de variáveis dentro de um `if`?**
   - Sim, C++ permite inicializar variáveis dentro de um `if` usando a sintaxe `if (int x = 5; x < value) { ... }`. Este formato inicializa `x` apenas para o escopo do `if`, o que limita seu alcance e evita conflitos de nomes.

20. **Como funciona um operador ternário? Quando vale a pena substituir um `if else` por um operador ternário?**
   - O operador ternário é uma expressão condicional simplificada com a sintaxe `condição ? valor_se_verdadeiro : valor_se_falso`. Ele é útil para atribuir valores ou realizar operações simples em uma única linha, onde o uso de `if-else` seria mais verboso. Vale a pena usá-lo quando a expressão for curta e fácil de ler, como em `int result = (x > 5) ? 10 : 20;`.

21. **Em C++, funções são elementos de primeira classe? O que isso significa?**
   - Em C++, funções **não são elementos de primeira classe**. Isso significa que, diferentemente de linguagens funcionais, elas não podem ser tratadas diretamente como variáveis (por exemplo, armazenadas em variáveis ou passadas como argumentos sem adaptadores como ponteiros de função ou lambdas). Em C++, lambdas e ponteiros para funções podem aproximar o comportamento de elementos de primeira classe.

22. **Qual seria a sintaxe para uma função lambda que recebe dois inteiros e retorna a soma deles?**
   - A sintaxe de uma função lambda para somar dois inteiros é:
     ```cpp
     auto soma = [](int a, int b) { return a + b; };
     ```

23. **Para que serve um `return` em uma função que não retorna nada?**
   - Um `return` em uma função `void` (sem retorno) serve para **encerrar a execução** da função antes de chegar ao final. Isso pode ser útil para sair de uma função quando uma condição é atendida, sem executar as instruções subsequentes.

24. **Em uma função, é melhor criar vários `if`s, `else`s ou múltiplos pontos de `return`?**
   - A escolha depende da situação e da legibilidade. Em geral, **múltiplos pontos de `return`** são aceitáveis se deixarem a lógica mais clara, especialmente para verificar condições de saída logo no início. Vários `if-else` são apropriados quando há múltiplas condições mutuamente exclusivas, mas devem ser evitados se dificultarem a leitura.

25. **A passagem de parâmetros em C++ pode ser por cópia, ponteiro ou referência. Qual a diferença entre cada uma delas?**
   - **Por cópia**: cria uma cópia do valor original, isolando a variável original de alterações.
   - **Por ponteiro**: passa o endereço da variável, permitindo a modificação direta da variável original e um melhor controle sobre a alocação de memória.
   - **Por referência**: passa a variável diretamente (não cria uma cópia), mas sem a sintaxe de ponteiros. É mais eficiente que a cópia e permite modificar o valor original.

26. **O que é um parâmetro default em uma função?**
   - Um **parâmetro default** é um valor padrão que uma função usará caso um argumento não seja fornecido para aquele parâmetro na chamada. Por exemplo, `void exemplo(int x = 10);` permite chamar `exemplo()` sem argumentos e atribui `10` a `x`.

27. **O que é uma função `inline`? Quando vale a pena usar uma função `inline`?**
   - Uma **função `inline`** é uma sugestão ao compilador para expandir o código da função no local onde ela é chamada, em vez de fazer uma chamada de função convencional. Isso pode melhorar o desempenho em funções curtas e frequentemente chamadas, evitando a sobrecarga da chamada de função. Vale a pena usar `inline` em funções pequenas e chamadas frequentemente, mas não em funções grandes, onde o aumento de código pode piorar o desempenho.

28. **O que seria uma sobrecarga de função? Como o compilador diferencia duas funções com o mesmo nome?**
   - A **sobrecarga de função** é o recurso que permite a criação de várias funções com o mesmo nome, mas com diferentes parâmetros (tipo, quantidade ou ordem). O compilador diferencia as funções pelo número e tipos dos parâmetros (assinatura da função), permitindo que ele escolha a versão correta com base nos argumentos passados.

29. **Qual a diferença entre passar um parâmetro por cópia ou por referência constante? Quando usar cada um?**
   - **Por cópia**: o valor do parâmetro é copiado para a função, então qualquer modificação na função não afeta o original. É ideal para tipos simples e pequenos, como `int`.
   - **Por referência constante**: permite que a função acesse o valor original sem copiá-lo, mas impede a modificação do valor original. É eficiente para tipos maiores ou complexos, como objetos, pois evita a cópia desnecessária.
   - Use **cópia** para dados pequenos e **referência constante** para dados maiores ou objetos, onde você quer garantir a integridade do valor.

30. **Qual a diferença entre declaração e definição de uma função?**
   - **Declaração**: informa ao compilador sobre a função (seu nome, tipo de retorno e parâmetros), mas sem implementá-la. Exemplo: `void minhaFuncao(int);`.
   - **Definição**: inclui a implementação completa da função, ou seja, o código que a função executa. Exemplo:
     ```cpp
     void minhaFuncao(int x) {
         // corpo da função
     }
     ```
   - A declaração é normalmente usada em cabeçalhos (`.h`), enquanto a definição é implementada nos arquivos de origem (`.cpp`).

31. **O que é a tabela de símbolos de um programa? Como ela é usada pelo compilador?**
   - A **tabela de símbolos** é uma estrutura de dados que o compilador usa para armazenar informações sobre variáveis, funções e objetos (como nomes, tipos e endereços). Ela permite ao compilador identificar e localizar os símbolos durante a compilação e vinculação, e ajuda a verificar a consistência do código.

32. **Qual o tipo padrão de um texto `"Hello World"` em C++?**
   - O tipo padrão de um texto como `"Hello World"` em C++ é `const char[]`, um array de caracteres constante. Esse tipo pode ser convertido em `const char*` ou usado com `std::string`.

33. **Quais as formas de se criar um laço de repetição em C++?**
   - C++ oferece várias estruturas para laços de repetição:
     - `for`: usado para iteração controlada, como `for (int i = 0; i < n; i++)`.
     - `while`: executa o laço enquanto a condição é verdadeira, como `while (condição)`.
     - `do-while`: executa o bloco pelo menos uma vez antes de verificar a condição, como `do { ... } while (condição);`.

34. **O que fazem `continue` e `break` em um laço de repetição?**
   - `continue`: interrompe a iteração atual e avança para a próxima, ignorando o código subsequente no laço.
   - `break`: encerra completamente o laço de repetição, saindo da estrutura antes de completar todas as iterações.

35. **Onde o C++ é mais utilizado e quais as vantagens de se usar essa linguagem em relação a outras?**
   - C++ é amplamente usado em **desenvolvimento de jogos**, **aplicações de alto desempenho** (como simulações e renderizações), **sistemas operacionais**, e **dispositivos embarcados**. Suas vantagens incluem controle de memória, alta eficiência e o suporte a paradigmas de programação tanto orientada a objetos quanto procedural e genérica, o que facilita o desenvolvimento de software robusto e de alto desempenho.

36. **Quais são as principais linguagens que concorrem com C++ e quais as vantagens de cada uma?**
   - **Java**: facilita o desenvolvimento multiplataforma e oferece um gerenciamento automático de memória, o que pode simplificar o desenvolvimento para aplicações empresariais.
   - **Python**: é altamente legível e oferece uma rica coleção de bibliotecas, facilitando o desenvolvimento rápido de protótipos e aplicativos de ciência de dados, embora seja menos eficiente em termos de desempenho.
   - **Rust**: fornece segurança de memória sem coletor de lixo e é cada vez mais popular em sistemas e desenvolvimento de software de baixo nível, com foco em segurança e desempenho.
   - **C#**: usado amplamente no desenvolvimento de jogos com Unity, além de ser popular em ambientes de desenvolvimento de software para Windows, com integração forte ao ecossistema da Microsoft.