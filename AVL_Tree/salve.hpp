// -----------------------------------------------------------------------------
// Universidade Federal do CearÃ¡, Centro de CiÃªncias, Departamento de ComputaÃ§Ã£o
// Disciplina:  LaboratÃ³rio de ProgramaÃ§Ã£o - CK0215 2023.1 T01A
// Professor:   Pablo Mayckon Silva Farias
//
// Trabalho 4 - Interface para ImplementaÃ§Ã£o de DicionÃ¡rio baseado em Ãrvore AVL
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// IDENTIFICAÃ‡ÃƒO DO(A) ESTUDANTE:
//
// NOME:      DANIEL SILVA AGOSTINHO
// MATRÃCULA: 470435
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Tudo o que estÃ¡ presente na interface abaixo deve ser mantido como estÃ¡,
// pois esta interface serÃ¡ utilizada no programa do professor para a realizaÃ§Ã£o
// dos testes.
//
// O trabalho consiste portanto em *completar* a implementaÃ§Ã£o abaixo,
// tornando-a funcional e atendendo aos requisitos deste trabalho.
//
// Os pontos a serem completados estÃ£o marcados com "TODO", isto Ã©, "por fazer".
// -----------------------------------------------------------------------------

#ifndef DICIOAVL_HPP
#define DICIOAVL_HPP

// -----------------------------------------------------------------------------

// A classe DicioAVL deve implementar um dicionÃ¡rio que associe chaves de tipo
// TC a valores de tipo TV.
//
// O dicionÃ¡rio deve organizar esses dados numa Ã¡rvore AVL em que os elementos
// sejam ordenados entre si a partir de suas chaves.
//
// Ã‰ pressuposto da classe que as chaves podem ser normalmente comparadas
// atravÃ©s dos operadores relacionais comuns: <, >=, !=, etc.

template <typename TC, typename TV>
class DicioAVL
  {
   public:

   // Numa implementaÃ§Ã£o tÃ­pica de dicionÃ¡rio,
   // a representaÃ§Ã£o interna normalmente fica inacessÃ­vel ao usuÃ¡rio;
   // neste trabalho, porÃ©m,
   // o professor precisa avaliar se a Ã¡rvore estÃ¡ correta,
   // e por isso a estrutura do nÃ³ Ã© exposta ao usuÃ¡rio (daÃ­ o "public" acima),
   // assim como o ponteiro raiz e a sentinela:

   struct Noh
     {
      TC chave;  TV valor;

      // VocÃª deve completar a estrutura do nÃ³ com:
      //
      // 1. Ponteiros para filho esquerdo, filho direito e pai.
      //
      // 2. Se necessÃ¡rio, algum campo adicional que viabilize a implementaÃ§Ã£o
      //    da Ã¡rvore AVL, como a altura do nÃ³, a informaÃ§Ã£o do balanceamento
      //    (-1, 0, +1), etc.
      //
      // VocÃª Ã© livre para escolher como vai representar esses elementos,
      // mas deve implementar as funÃ§Ãµes a seguir,
      // que permitirÃ£o que a estrutura da Ã¡rvore seja percorrida.
      // (quando o filho direito / filho esquerdo / pai nÃ£o existir,
      //  a respectiva funÃ§Ã£o deve retornar um ponteiro para "sent",
      //  declarada mais abaixo):

      // TODO: defina os campos restantes do nÃ³ da Ã¡rvore AVL.

      Noh * filho_esq_;
      Noh * filho_dir_;
      Noh * pai_;
      int altura_;

      // -----------------------------------------------------------------------

      // Esta funÃ§Ã£o deve retornar um ponteiro para o filho direito,
      // se o nÃ³ possuir filho direito;
      // em caso contrÃ¡rio, deve ser retornado um ponteiro para o nÃ³ sentinela,
      // definido mais abaixo.

      Noh* obter_dir (){
       return filho_dir_;
      }

      // -----------------------------------------------------------------------

      // Esta funÃ§Ã£o deve retornar um ponteiro para o filho esquerdo,
      // se o nÃ³ possuir filho esquerdo;
      // em caso contrÃ¡rio, deve ser retornado um ponteiro para o nÃ³ sentinela,
      // definido mais abaixo.

      Noh* obter_esq (){
        return filho_esq_;l
      }

      // -----------------------------------------------------------------------

      // Esta funÃ§Ã£o deve retornar um ponteiro para o nÃ³ pai,
      // se o nÃ³ possuir nÃ³ pai;
      // em caso contrÃ¡rio, deve ser retornado um ponteiro para o nÃ³ sentinela,
      // definido mais abaixo.

      Noh* obter_pai () {
        return pai_;
      }

     }; // struct Noh

   // --------------------------------------------------------------------------

   // Campos pÃºblicos de DicioAVL: raiz e sentinela.
   // Lembrete: nÃ£o altere-os, pois serÃ£o usados nos testes automÃ¡ticos.

   Noh  sent;  // NÃ³ sentinela.
   Noh *raiz;  // "raiz" deve apontar para "sent" quando a Ã¡rvore estiver vazia.

   // ==========================================================================

   private:

   // VocÃª pode incluir campos e mÃ©todos que sejam relevantes para a
   // implementaÃ§Ã£o mas que fiquem inacessÃ­veis ao usuÃ¡rio da classe DicioAVL.

   // ==========================================================================

   public:

   // Lembrete: tudo o que estÃ¡ abaixo em DicioAVL deve ser mantido pÃºblico e
   // inalterado, pois serÃ¡ utilizado nos testes do professor.
   //
   // Observe que isso nÃ£o impede que vocÃª inclua mÃ©todos que nÃ£o estejam
   // presentes abaixo; porÃ©m, analise se eles devem mesmo ser pÃºblicos.

   // --------------------------------------------------------------------------

   class Iterador
     {
      private:

      // VocÃª pode incluir campos e mÃ©todos que sejam relevantes para a
      // implementaÃ§Ã£o mas que fiquem inacessÃ­veis ao usuÃ¡rio de "Iterador".

      // TODO: Defina os campos da classe Iterador.

      // -----------------------------------------------------------------------

      // O comando abaixo permite que a classe DicioAVL enxergue os membros
      // privados desta classe Iterador.
      // Isso serÃ¡ particularmente Ãºtil no mÃ©todo "remover" de DicioAVL,
      // que recebe um iterador e precisa, a partir dele, acessar o nÃ³ a ser
      // removido.

      friend DicioAVL;

      // -----------------------------------------------------------------------

      public:

      // Lembrete: tudo o que estÃ¡ abaixo deve ser mantido pÃºblico em Iterador,
      // pois serÃ¡ utilizado nos testes do professor.
      //
      // Observe que isso nÃ£o impede que vocÃª inclua mÃ©todos que nÃ£o estejam
      // presentes abaixo.

      // -----------------------------------------------------------------------

      // Lembrete: Ã© possÃ­vel implementar diferentes construtores para uma mesma
      // classe.

      // Construtor padrÃ£o (sem argumentos): deve ser possÃ­vel inicializar um
      // iterador sem que ele aponte para algum elemento especÃ­fico de um
      // DicioAVL. Isso Ã© Ãºtil para declarar uma variÃ¡vel de tipo Iterador sem
      // ter a obrigaÃ§Ã£o de jÃ¡ apontÃ¡-la para um elemento de um dicionÃ¡rio.
      //
      // A Ãºnica operaÃ§Ã£o esperada sobre um iterador assim inicializado Ã©
      // receber uma cÃ³pia de outro iterador.
      // Portanto, nÃ£o se deve chamar mÃ©todos como "chave" nem operadores como
      // "==" e "++" sobre um iterador que nÃ£o esteja apontando para um elemento
      // de um dicionÃ¡rio.
      //
      // ObservaÃ§Ã£o: caso deseje, vocÃª pode implementar o construtor padrÃ£o de
      // forma que seja vÃ¡lido chamar os operadores "==" e "!=" sobre um
      // iterador assim inicializado. PorÃ©m, isso nÃ£o Ã© exigido neste trabalho.

      Iterador ();
      //  {
      //  // TODO
      //  }

      // -----------------------------------------------------------------------

      // Os operadores "!=" e "==" abaixo podem ser chamados mesmo caso
      // o iterador esteja no "fim" do dicionÃ¡rio ("posiÃ§Ã£o" em que o iterador
      // nÃ£o se refere a nenhum elemento propriamente dito).

      // -----------------------------------------------------------------------

      // Este mÃ©todo deve retornar "true" se e somente se
      // o iterador atual e "j" NÃƒO SE REFEREM ao mesmo elemento ou posiÃ§Ã£o do
      // dicionÃ¡rio.

      bool operator != (Iterador j);
      //  {
      //  // TODO
      //  }

      // -----------------------------------------------------------------------

      // Este mÃ©todo deve retornar "true" se e somente se
      // o iterador atual e "j" SE REFEREM ao mesmo elemento ou posiÃ§Ã£o do
      // dicionÃ¡rio.

      bool operator == (Iterador j);
      //  {
      //  // TODO
      //  }

      // -----------------------------------------------------------------------

      // Os mÃ©todos abaixo possuem como PRÃ‰-CONDIÃ‡ÃƒO o fato de que o iterador
      // aponta para um elemento propriamente dito do dicionÃ¡rio, ou seja,
      // que o iterador nÃ£o aponta para o "fim" do dicionÃ¡rio.
      //
      // Como para toda prÃ©-condiÃ§Ã£o, Ã© responsabilidade do usuÃ¡rio de Iterador
      // garantir que ela serÃ¡ satisfeita sempre que o mÃ©todo for chamado.
      //
      // Portanto, esses mÃ©todos NÃƒO PRECISAM TESTAR se o iterador aponta para o
      // "fim" do dicionÃ¡rio.

      // -----------------------------------------------------------------------

      // Este mÃ©todo deve retornar a "chave" do elemento apontado pelo iterador.

      TC chave ();
      //  {
      //  // TODO
      //  }

      // -----------------------------------------------------------------------

      // Este mÃ©todo deve retornar o "valor" do elemento apontado pelo iterador.

      TV valor ();
      //  {
      //  // TODO
      //  }

      // -----------------------------------------------------------------------

      // Este mÃ©todo deve fazer o iterador passar ao prÃ³ximo elemento do
      // dicionÃ¡rio, isto Ã©, ao elemento da CHAVE SUCESSORA, na ordem crescente
      // das chaves, se houver uma chave sucessora.
      //
      // Caso nÃ£o haja chave sucessora (ou seja, caso o iterador aponte para a
      // maior chave), o iterador deve passar a apontar para o "fim" do
      // dicionÃ¡rio.

      Iterador& operator ++ ();
      //  {
      //  // TODO
      //  }

     }; // class Iterador

   // --------------------------------------------------------------------------

   // MÃ©todos pÃºblicos de DicioAVL:

   // --------------------------------------------------------------------------

   // Construtor: deve inicializar o dicionÃ¡rio como vazio.

   DicioAVL ();
   //  {
   //  // TODO
   //  }

   // --------------------------------------------------------------------------

   // Destrutor: deve desalocar toda a memÃ³ria dinamicamente alocada pelo
   // dicionÃ¡rio (no caso, basicamente a Ã¡rvore AVL).

   ~DicioAVL ();
   //  {
   //  // TODO
   //  }

   // --------------------------------------------------------------------------

   // Este mÃ©todo deve retornar um iterador apontando para o elemento de menor
   // chave, caso exista um.
   // Se o dicionÃ¡rio estiver vazio, deve retornar um iterador para o "fim".

   Iterador begin ();
   //  {
   //  // TODO
   //  }

   // --------------------------------------------------------------------------

   // Deve retornar um iterador num estado especial, que seja diferente do
   // estado de um iterador que aponte para um elemento propriamente dito,
   // e que dessa forma sirva para caracterizar a situaÃ§Ã£o em que o iterador
   // tenha atingido o "fim" do dicionÃ¡rio.

   Iterador end ();
   //  {
   //  // TODO
   //  }

   // --------------------------------------------------------------------------

   // Este mÃ©todo deve inserir a chave "c" e o valor "v" no dicionÃ¡rio, partindo
   // da PRÃ‰-CONDIÃ‡ÃƒO de que a chave "c" nÃ£o estÃ¡ presente no dicionÃ¡rio,
   // ou seja, a funÃ§Ã£o nÃ£o precisa nem deve fazer esse teste.
   //
   // Em caso de falha de alocaÃ§Ã£o de memÃ³ria,
   // o mÃ©todo deve jogar uma exceÃ§Ã£o do tipo std::bad_alloc
   // (que jÃ¡ Ã© aquele jogada pelo operador "new" em caso de falha de alocaÃ§Ã£o).
   //
   // A funÃ§Ã£o deve retornar um iterador apontando para o elemento inserido.
   //
   // ATENÃ‡ÃƒO: o iterador retornado deve continuar vÃ¡lido e relativo ao par
   // -------  (c,v) enquanto esse par nÃ£o for removido do dicionÃ¡rio.
   //
   // A observaÃ§Ã£o acima Ã© particularmente importante para o caso da REMOÃ‡ÃƒO
   // em que o nÃ³ do par a ser removido possui dois filhos. Nesse caso, nÃ£o
   // basta apenas copiar os campos do nÃ³ sucessor para o nÃ³ em questÃ£o, pois
   // isso faria com que o par sucessor mudasse de nÃ³, invalidando algum
   // iterador relativo a esse par; portanto, nesse caso da remoÃ§Ã£o, Ã©
   // necessÃ¡rio que o nÃ³ do sucessor realmente ocupe o lugar da Ã¡rvore que
   // estava sendo ocupado pelo nÃ³ a ser removido.

   Iterador inserir (TC c, TV v);
   //  {
   //  // TODO
   //  }

   // --------------------------------------------------------------------------

   // Deve retornar um iterador apontando para o elemento de chave "c",
   // caso essa chave esteja presente no dicionÃ¡rio.
   // Se a chave nÃ£o estiver presente, deve retornar um iterador para o "fim".

   Iterador buscar (TC c);
   //  {
   //  // TODO
   //  }

   // --------------------------------------------------------------------------

   // Este mÃ©todo deve remover do dicionÃ¡rio o elemento apontado pelo iterador
   // recebido, caso o iterador aponte para um elemento do dicionÃ¡rio.
   //
   // Ã‰ PRÃ‰-CONDIÃ‡ÃƒO da funÃ§Ã£o que o iterador recebido estarÃ¡ apontando
   // para algum elemento ou para o "fim" do dicionÃ¡rio.
   //
   // Se o iterador apontar para o "fim" do dicionÃ¡rio,
   // a funÃ§Ã£o deve simplesmente deixar o dicionÃ¡rio inalterado.

   void remover (Iterador i);
   //  {
   //  // TODO
   //  }

  }; // class DicioAVL

// -----------------------------------------------------------------------------

#endif