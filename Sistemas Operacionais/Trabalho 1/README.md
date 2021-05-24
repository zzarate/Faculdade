# Interpretador de Comandos
Um interpretador de comandos é um programa que recebe comandos de um usuário e os executa. Além disso, ele pode conter comandos internos para, por exemplo, definir variáveis de ambiente, mostrar o histórico de comandos, etc.

## Funcionalidades

- [ ] 1- Execução de um programa com ou sem argumentos tanto em foreground quanto em background quando terminado pelo caractere &.
- [ ] 2- O mesmo que 1, mas com redirecionamento das saídas padrão (>) ou de erro (2>) para arquivos.
- [ ] 3- O mesmo que 1, mas com redirecionamento da entrada padrão (<) para um arquivo de entrada.
- [ ] 4- O mesmo que 1, mas com redirecionamentos tanto de entrada quanto de saída.
- [ ] 5- Implementação de pipes entre programas. Você deve considerar um número arbitrário de pipes na linha de comando.
- [ ] 6- Os programas a serem executados devem ser pesquisados nos diretórios listados na variável
de ambiente MYPATH. O conteúdo inicial da variável MYPATH deve ser importado da variável
de ambiente PATH.
- [ ] 7- Implementação do comando export para (re)definção de variáveis de ambiente. Por
exemplo, export MYPATH=$MYPATH:/NovoDiretorio
- [ ] 8- Implementação do comando cd para mudança de diretório. Inicialmente, o diretório corrente deve ser definido pela variável de ambiente PWD. Note que após a execução do comando
cd, você deve atualizar o conteúdo da variável PWD.
- [x] 9- Implementação do comando history que mostra os ultimos 50 comandos digitados pelo usuário.
- [x] 10- O seu interpretador de comandos deve mostrar um prompt inicial igual a tecii$, mas deve permitir que o prompt seja redefinido pela variavel de ambiente MYPS1.
- [x] 11- Implementação do comando exit para encerrar o interpretador de comandos. O interpretador tambem deve ser encerrado com a digitação de Ctrl+D.
- [x] 12- Implementação de um tratador de sinais para tratar o sinal SIGINT e evitar que o interpretador de comandos seja terminado quando as teclas Control+C forem pressionadas.
- [ ] 13- Implementação de um tratador de sinais para tratar o sinal SIGTSTP e colocar para
dormir o processo em foreground.
- [ ] 14- Implementação do comando kill para enviar sinais para processos. Note que esse deve
ser um comando do interpretador e não uma invocação ao programa /bin/kill.
- [ ] 15- Implementação do comando jobs para listar os processos em background.
- [ ] 16- Implementação do comando fg para colocar um processo em foreground.
- [ ] 17- Implementação do comando bg para colocar um processo em background.
- [ ] 18- Implementação de um tratador de sinais para tratar o sinal SIGCHLD e evitar a criação
de processos zumbis.
- [ ] 19-Implementação do comando echo para visualizaço do conteudo de variaveis de ambiente
  e impressao de cadeias de caracteres. Por exemplo, echo $MYPATH mostra o conteudo da
  variavel de ambiente MYPATH
- [ ] 20- Implementação do comando set para visualizar todas as variáveis de ambiente.