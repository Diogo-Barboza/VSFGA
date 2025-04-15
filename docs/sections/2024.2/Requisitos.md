# Requisitos

## Sumário

1. [Unidade 1]()
    1. [Fundamentos de Eng. Software (Overview: Abordagens, Ciclos de Vida, Processos.)](#Fundamentos.Eng)
    2. [Introdução a Engenharia de Requisitos (ER)](#Intro-ESW)
    3. [Processo de ER](#ProcessoER)
    4. [Valores e Princípios da ER]()
    5. [Tipos de Requisitos e Regras de Negócio]()
    6. [Entendendo Problema e Necessidades]()
2. [Unidade 2]()
    7. [Atividades e Técnicas de ER]()
    8. [Definição do Backlog do Produto]()
    9. [Definição de MVP]() 
    10. [DoR e DoD]()
3. [Unidade 3]()
    11. [Fundamentos, conceitos e exercícios: PBB e BDD]()
    12. [User Story Mapping]()
    13. [Aspectos humanos e sociais da Engenharia de Requisitos]()
4. [Unidade 4]()
    14. [Modelos de casos de uso]()
    15. [Especificação de casos de uso]()
<br><br><br><br><br>

<a id="Fundamentos.Eng"></a>

## Fundamentos de Eng. Software
## Abordagem de desenvolvimento de Software

### Abordagem dirigida por Plano
- Maior esforço no *planejamento inicial*.
- *Requisitos são bem definidos antes da implementação*
- Processos sequencial: análise -> projeto -> implementação -> testes.
- *Vantagens:* Ideal para projetos *grandes e críticos* (exemplos: sistemas aeroespaciais, UTIs).
- *Desvantagens:* Se os requisitos mudam,há necessidades de *retrabalho,* tornando-o *pouco flexível*.

### Abordagem Ágil
- Melhor para *ambientes dinâmicos* e projetos que exigem rapidez.
- Desenvolvimento em *incrementos* permitindo *feedback contínuo* dos usúarios.
- Redução da documentação formal -> foco na *comunicação e colaboração*.
- Ideal para *Software de negócio e startups*, onde os requisitos mudam frequentemente.

## Ciclos de vida do Software
O *ciclo de vida* representa as *fases que um software passa*, desde sua *definição* até sua *descontinuação*.

### Ciclo de vida preditivo (Modelo Cascata)
- Modelo *sequencial* (cada fase termina antes da próxima começar).
- *Melhor para projetos com requisitos bem definidos*.
- Problema: *qualquer mudança exige recomeçar o projeto*.

### Ciclo de Vida Iterativo
- Permite obter o *feedback antes da finalização* do software.
- Mais flexível que o modelo cascata.

### Ciclo de Vida Incremental
- Cada entrega fornece uma *versão utilizável* do produto.
- Cliente pode começar a suar partes do software antes da finalização completa.

### Ciclo de Vida Ágil
- Combina características dos modelos *iterativos e incremental*.
- Prioriza entregas contínuas e feedback constante.
- *Exemplos:* Scrum, XP, Kanban.

### Ciclo de Vida Híbrido
- *Mistura abordagens preditivas e ágeis* para entender necessidades específicas do projeto.
- *Exemplo:* Um software pode ter um *núcleo desenvolvido com abordagem preditiva,* enquanto *novas funcionalidade seguem um modelo ágil*.

## Processos de Desenvolvimento de Software
Os processos organizam *como um software e contruído*.

### Modelo Cascata
- *Processo Linear* -> Cada etapa deve ser finalizada antes da próxima começar.
- *Pouca Flexibilidade*, pois mudanças exigem refazer fases anteriores.

### Modelo Espiral
- *Baseado na análise de riscos*.
- *Cada ciclo* gera uma versão refinada do software.
- Mais indicado para projetos de *grande porte e com altos riscos*.

### Modelo RAD (Rapid Application Developmnet)
- *Foco na prootipação rápida*, com feedback constante do usuário.
- Bom para sistemas que precisam ser entregas rapidamente.

### Unified Processo (Processo Unificado)
- *Iterativo e incremental*. 
- Identificação de *requisitos* ocorre no início, mas com possibilidade de adaptações ao longo do tempo.

### Scrum
- *Framework Ágil* -> organiza o projeto em *sprints (iteração de 2 a 4 semanas)*.
- *Equipe auto-organizada* prorizam tarefas.

### Extreme Programming (XP)
- *Método ágil* voltado para a qualidade e desenvolvimento rápido.
- Uso de *teste automatizados e refatoração constante*.

### SAFe (Scaled Agile Framework)
- *Escala métodos ágeis para grndes organizações*.
- Usa concietos do Lean, Agile e DevOps.

---

<a id="Intro-ESW"></a>

## Introdução a Engrenharia de Requisitos
## Como Escolher o processo de desenvolvimento?
A escolha do processo de desenvolvimento não é uma "*receita de bolo*. O engenheiro de software deve analisaro contexto do projeto e responder a perguntas sobre:
- O sistema que está sendo desenvolviedo (*aspectos humanos*).
- O time de desenvolvimento (*aspectos humanos*).
- A organização que está desenvolvendo e adquirindo o sistema (*aspectos organizacionais*).

## Critérios Propostos por Sommerville para Escolher uma Abordagem
### Perguntas Técnicas
1. *Qual é o tamanho do Sistema?*Pequenos sistemas podem usar abordagens ágeis, enquanto sistemas grandes exigem maior planejamento.
2. *Qual é o tipo de sistema?* Sistemas críticos precisam de planejamento rigoroso.
3. *Qual é a vida útil prevista para o sistema?* Se for de longa duração, pode precisar de planejamento mais detalhado.
4. *O sistema está sujeito a controle externo?* Normas regulatórias podem exigir processos mais estruturados.

### Perguntas Humanas
1. *Qual é o nível de competência da equipe?* Equipes experientes lidam melhor com abordagens ágeis.
2. *Como está organizada a equipe?* Times distribuídos podem precisar de mais documentação e processos definidos.
3. *Quais tecnologias estão disponíveis?* Algumas abordagens exigem ferramentas específicas.

### Perguntas Organizacionais
1. *É necessário um projeto detalhado antes da implementação?* Algumas empresas exigem especificações rigorosas por contrato.
2. *A entrega incremental é viável?* Se o cliente puder dar feedback contínuo, abordagens ágeis são melhores.
3. *Os clientes participarão ativamente?* Se sim, o uso de Scrum ou XP pode ser vantajoso.
4. Q*uestões culturais influenciam o projeto?* Algumas organizações têm resistência a mudanças ágeis.

## Modelos de Ciclo de vida do Software
### Modelo Cascata
- Processo *linear e seuqencial* -> Cada fase precisa ser finalizada antes da próxima começar.
- Melhor para projetos *previsiveis e estáveis*.
- *Desvantagem:* Difícil adaptação a mudanças.

### Modelo Incremental
- Similar ao cascata, mas permite *entregas praciais ao cliente*.
- Melhor para projetos onde os requisitos podem mudar.

### Modelo Evolutivo
- Requisitos são revisados em *cada ciclo de desenvolvimento*.
- Ideal para Projetos com *requisitos incertos ou em evolução*.

### Modelo Espiral
- *Foco na análise de risco*.
- Permite refinamento contínuo do projeto.
- Exige *bom gerenciamento de riscos* e equipe experiente.

## Como selecionar o modelo Ideal?
A escolha do modelo depende de *quatro fatores principais:* <br>
- *Requisitos do sistema* -> Estáveis ou variáveis? <br>
- *Equipe de desenvolvimento* -> Experiência, tamanho e organização. <br>
- *Envolvimento do usuário* -> Ele participa ativamente ou não? <br>
- *Tipo de projetos e riscos* -> Projeto crítico ou flexível. <br>

---

<a id="ProcessoER"></a>

## Processos de ER
