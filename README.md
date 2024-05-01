Instruções para configurar o projeto no seu Visual Studio

- Descopacte o arquivo SFM-2.5.1.zip.
- Primeiro execute o arquivo .sln para abrir o projeto no Visual Studio.
- Certifique-se que a plataforma de solução ativa do seu Visual Studio seja x86.
- Vá em propriedades do projeto ou pressione alt + enter, em Propriedades de Configuração, C/C++, Geral, Diretório de Inclusão Adicionais, 
insira o diretório do projeto + "/SFML-2.5.1/include".
- Agora também em Propriedades de Configuração, vá na aba Vinculador, Geral, Diretório de Biblioteca Adicionais, 
insira o diretório do projeto + "/SFML-2.5.1/lib", e aplique as alterações.
- Depois abra o arquivo "Definitions.h", e mude a variável PATH de acordo com o diretório do projeto em sua 
máquina, + "/SFMLGame/"
