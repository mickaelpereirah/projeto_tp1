# GUIA DE COMPILAÇÃO - Sistema de Gestão de Hotéis

## ✅ Arquivo projeto_tp1.cbp ATUALIZADO!

### 📁 Novos arquivos adicionados:

**Camada de Apresentação:**
- include/apresentacao/MenuPrincipal.hpp
- include/apresentacao/Utilidades.hpp
- src/apresentacao/MenuPrincipal.cpp
- src/apresentacao/Utilidades.cpp

**Serviço de Autenticação:**
- include/servicos/autenticar/autenticarGerente.hpp
- src/servicos/autenticar/autenticarGerente.cpp

**Diretórios de include adicionados:**
- include/apresentacao
- include/servicos/autenticar

### 🔧 Como compilar no Code::Blocks:

1. **Abra o projeto:**
   - File → Open → Selecione `projeto_tp1.cbp`

2. **Limpe build anterior (recomendado):**
   - Build → Clean

3. **Compile o projeto:**
   - Build → Build (ou pressione Ctrl+F9)

4. **Execute:**
   - Build → Run (ou pressione Ctrl+F10)

### ⚠️ Possíveis problemas:

**Se der erro de "include not found":**
- Verifique se todos os diretórios estão configurados em:
  - Project → Build Options → Search Directories → Compiler

**Se der erro de "undefined reference":**
- Certifique-se que todos os arquivos .cpp estão sendo compilados
- Limpe o projeto (Build → Clean) e compile novamente

### 📝 Estrutura do Menu Principal:

Ao executar, você verá:

```
============================================================
        SISTEMA DE GESTAO DE HOTEIS - 100%
============================================================

1. Criar conta
2. Login
3. Sair

Escolha uma opcao (1-3): _
```

### 🧪 Teste Básico:

1. **Criar uma conta:**
   - Escolha opção 1
   - Preencha: Nome, Ramal, Email, Senha
   - Confirme o sucesso

2. **Fazer Login:**
   - Escolha opção 2
   - Digite o email e senha cadastrados
   - Deve mostrar mensagem de sucesso
   - (Menu do Gerente ainda não implementado - aparecerá mensagem)

3. **Sair:**
   - Escolha opção 3
   - Confirme com 'S'

### 🚀 Próximos passos:

Após confirmar que o MenuPrincipal funciona:
- Implementar MenuGerente
- Implementar MenuConta
- Implementar MenuHoteis
- etc...

---

**IMPORTANTE:** O arquivo main.cpp antigo foi renomeado para main_teste.cpp
