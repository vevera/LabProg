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


#include <iostream>

template <typename TC, typename TV>
class DicioAVL
  {
   public:

   struct Noh
     {
      TC chave;  TV valor;

      Noh* filho_esq_;
      Noh* filho_dir_;
      Noh* pai_;
      int altura_;

      Noh() {};

      Noh(Noh* default_, TC chave, TV valor): filho_dir_{default_}, filho_esq_{default_}, pai_{default_}, chave{chave}, valor{valor} {}

      Noh* obter_dir (){
       return filho_dir_;
      }

      Noh* obter_esq (){
        return filho_esq_;
      }

      Noh* obter_pai () {
        return pai_;
      }

     }; // struct Noh

   Noh  sent;  // NÃ³ sentinela.
   Noh *raiz;  // "raiz" deve apontar para "sent" quando a Ã¡rvore estiver vazia.

   // ==========================================================================
   template <typename FuncDef>
   void ApplyFunctionToElements(Noh* root, FuncDef &function){
      if (root == &sent){
        return;
      }
      std::cout << "about to call ApplyFunctionToElements to left son" << std::endl;
      ApplyFunctionToElements(root->filho_esq_, function);
      std::cout << "about to call ApplyFunctionToElements to right son" << std::endl;
      ApplyFunctionToElements(root->filho_dir_, function);
      std::cout << "Actually applying func to element > " << root->chave << std::endl;
      function(root);
    }
   private:

    Noh* RotacaoEsquerda(Noh* x){

      Noh* y = x->filho_dir_;
      x->filho_dir_ = y->filho_esq_;
      x->filho_dir_->pai_ = x;

      y->pai_ = x->pai_;
      if (x->pai_ == &sent) {
          raiz = y;
      }
      else if (x->pai_->filho_esq_ == x){
          x->pai_->filho_esq_ = y;
      }
      else if (x->pai_->filho_dir_ == x){ 
          x->pai_->filho_dir_ = y;
      }
      x->pai_ = y;
      y->filho_esq_ = x;

      y->altura_ = std::max(y->filho_dir_->altura_, y->filho_esq_->altura_) + 1;
      x->altura_ = std::max(x->filho_dir_->altura_, x->filho_esq_->altura_) + 1;

      return y;
    }

    Noh* RotacaoDireita(Noh* y){

      Noh* x = y->filho_esq_;
      y->filho_esq_ = x->filho_dir_;
      y->filho_esq_->pai_ = y;

      x->pai_ = y->pai_;
      if (y->pai_ == &sent) {
          raiz = x;
      }
      else if (y->pai_->filho_dir_ == y){
          y->pai_->filho_dir_ = x;
      }
      else if (y->pai_->filho_esq_ == y){
          y->pai_->filho_esq_ = x;
      }

      y->pai_ = x;
      x->filho_dir_ = y;

      y->altura_ = std::max(y->filho_dir_->altura_, y->filho_esq_->altura_) + 1;
      x->altura_ = std::max(x->filho_dir_->altura_, x->filho_esq_->altura_) + 1;

      return x;
    }

    Noh* interno_inserir(Noh* noh_atual, Noh* novo_noh){
      std::cout << "case insert > " << novo_noh->chave << " \n";
      std::cout << "curr noh > " << noh_atual->chave << " \n";

      if (noh_atual == &sent){
        return novo_noh;
      }
      if (novo_noh->chave < noh_atual->chave) {
        noh_atual->filho_esq_ = interno_inserir(noh_atual->filho_esq_, novo_noh);
        noh_atual->filho_esq_->pai_ = noh_atual;
      }
      else if(novo_noh->chave >= noh_atual->chave){
          noh_atual->filho_dir_ = interno_inserir(noh_atual->filho_dir_, novo_noh);
          noh_atual->filho_dir_->pai_ = noh_atual;
      }

      noh_atual->altura_ = 1 + std::max(noh_atual->filho_esq_->altura_, noh_atual->filho_dir_->altura_);
      int balance_factor = noh_atual->filho_esq_->altura_ - noh_atual->filho_dir_->altura_;

      if (balance_factor > 1) {
        std::cout << "if balance_factor > 1\n";
        if (novo_noh->chave < noh_atual->filho_esq_->chave) {
            std::cout << "if novo_noh->chave < noh_atual->filho_esq_->chave\n";
            return RotacaoDireita(noh_atual);
        }
        else if (novo_noh->chave > noh_atual->filho_esq_->chave){
            std::cout << "if novo_noh->chave > noh_atual->filho_esq_->chave\n";
            noh_atual->filho_esq_ = RotacaoEsquerda(noh_atual->filho_esq_);
            return RotacaoDireita(noh_atual);
        }
      }

      if (balance_factor < -1) {
        std::cout << "if balance_factor < -1\n";
        if (novo_noh->chave > noh_atual->filho_dir_->chave) {
            std::cout << "novo_noh->chave > noh_atual->filho_dir_->chave\n";
            return RotacaoEsquerda(noh_atual);
        }
        else if (novo_noh->chave < noh_atual->filho_dir_->chave) {
            std::cout << "novo_noh->chave > noh_atual->filho_dir_->chave\n";
            noh_atual->filho_dir_ = RotacaoDireita(noh_atual->filho_dir_);
            return RotacaoEsquerda(noh_atual);

        }
      }

      return noh_atual;
    }

    Noh* interno_busca(Noh* noh_atual, TC chave) {
      if (noh_atual == &sent){
        return noh_atual;
      }

      Noh* prox_raiz_busca = nullptr;
      if (noh_atual->chave > chave) {
        prox_raiz_busca = noh_atual->filho_esq_;
      }
      else if (noh_atual->chave < chave) {
        prox_raiz_busca = noh_atual->filho_dir_;
      }

      if (prox_raiz_busca == nullptr){
        return noh_atual;
      }

      return interno_busca(prox_raiz_busca, chave);
    }
    
    Noh*  interno_remover(Noh* noh_atual, Noh* noh_a_ser_removido, bool& deleted){
      if (noh_atual == &sent){
          return noh_atual;
      }

      if (noh_a_ser_removido->chave < noh_atual->chave) {
          noh_atual->filho_esq_ = interno_remover(noh_atual->filho_esq_, noh_a_ser_removido, deleted);
          noh_atual->filho_esq_->pai_ =  noh_atual;
      }
      else if(noh_a_ser_removido->chave > noh_atual->chave){
          noh_atual->filho_dir_ = interno_remover(noh_atual->filho_dir_, noh_a_ser_removido, deleted);
          noh_atual->filho_dir_->pai_ = noh_atual;
      }
      else if(noh_a_ser_removido->chave == noh_atual->chave){
          auto left_child = noh_atual->filho_esq_;
          auto right_child = noh_atual->filho_dir_;

          Noh * next_value = nullptr;
          Noh * temp = noh_atual;
          if (left_child != &sent && right_child != &sent) {
              next_value = *(++Iterador(noh_atual, this));
              auto f_esq = noh_atual->filho_esq_;
              noh_atual = next_value;
              if (!deleted) {
                deleted = true;
                delete temp;
              }  
              noh_atual->filho_dir_ = interno_remover(temp->filho_dir_, next_value, deleted);
              noh_atual->filho_esq_ = f_esq;
              noh_atual->filho_esq_->pai_ = f_esq;
              noh_atual->filho_dir_->pai_ = noh_atual;
          }
          else {
              next_value = left_child != &sent? left_child: right_child;
              noh_atual = next_value;
              if (!deleted) {
                deleted = true;
                delete temp;
              } 
          } 
      }

      if (noh_atual == &sent){
          return noh_atual;
      }

      noh_atual->altura_ = 1 + std::max(noh_atual->filho_esq_->altura_, noh_atual->filho_dir_->altura_);
      int balance_factor = noh_atual->filho_esq_->altura_ - noh_atual->filho_dir_->altura_;

      Noh* noh_retorno = noh_atual;

      if (balance_factor > 1) {
          int left_balance_factor = noh_atual->filho_esq_->filho_esq_->altura_ - noh_atual->filho_esq_->filho_dir_->altura_;
          if (left_balance_factor >= 0) {
              return RotacaoDireita(noh_atual);
          }
          else if (left_balance_factor < 0){
              noh_atual->filho_esq_ = RotacaoEsquerda(noh_atual->filho_esq_);
              return RotacaoDireita(noh_atual);
          }
      }

      if (balance_factor < -1) {
          int right_balance_factor = noh_atual->filho_dir_->filho_esq_->altura_ - noh_atual->filho_dir_->filho_dir_->altura_;
          if (right_balance_factor <= 0) {
              return RotacaoEsquerda(noh_atual);
          }
          else if (right_balance_factor > 0) {
              noh_atual->filho_dir_ = RotacaoDireita(noh_atual->filho_dir_);
              return RotacaoEsquerda(noh_atual);
          }
      }

      return noh_retorno;
    }

   public:

   class Iterador
     {
      private:

        Noh* data_;
        DicioAVL* dicio_;

      friend DicioAVL;

      public:

      Iterador (){
       data_ = &sent;
      }

      Iterador (Noh * data, DicioAVL * dicio){
       data_ = data;
       dicio_ = dicio;
      }

      bool operator != (Iterador j) {
        return data_ != j.data_;
      }

      bool operator == (Iterador j) {
        return data_ == j.data_;
      }

      TC chave () {
        return data_->chave;
      }

      TV valor () {
        return data_->valor;
      }

      Noh* operator*(){
        return data_;
      }
      Noh* operator->(){
        return data_;
      }

      Iterador& operator ++ () {
          if (data_->filho_dir_ != &dicio_->sent) {
            data_ = data_->filho_dir_;
            while (data_->filho_esq_ != &dicio_->sent) {
              data_ = data_->filho_esq_;
            }
          }

          else if (data_->filho_dir_ == &dicio_->sent) {
            Noh* previous = data_;
            data_ = data_->pai_;
            while (previous != data_->filho_esq_ && data_ != &dicio_->sent) {
              previous = data_;
              data_ = data_->pai_;
            }  
          }
          return *this; 
      }


     }; // class Iterador

   DicioAVL () {
     sent.altura_ = 0;
     sent.pai_ = &sent;
     sent.filho_dir_ = &sent;
     sent.filho_esq_ = &sent;

     raiz = &sent;
    }

   ~DicioAVL () {
      auto delete_node = [](Noh* node_to_delete) -> void {
        if (node_to_delete != nullptr) {
          delete node_to_delete;
          node_to_delete->filho_dir_ = nullptr;
        }
          
      };
      //ApplyFunctionToElements(raiz, delete_node);
   }

   Iterador begin () {
      Noh * menor = raiz;
      while (menor->filho_esq_ != &sent)
      {
        menor = menor->filho_esq_;
      }
      return Iterador(menor, this);
   }

   Iterador end (){
    return Iterador(&sent, this);
   }

   Iterador inserir (TC c, TV v) {
      Noh * novo_noh = new Noh();
      novo_noh->chave = c;
      novo_noh->valor = v;
      novo_noh->filho_dir_ = &sent;
      novo_noh->filho_esq_ = &sent;
      novo_noh->pai_ = &sent;
      novo_noh->altura_ = 0;

      raiz = interno_inserir(raiz, novo_noh);

      return Iterador(novo_noh, this);
   }

   Iterador buscar (TC c) {
      Noh* noh_buscado = interno_busca(raiz, c);
      return Iterador(noh_buscado, this);
   }

   void remover (Iterador i){
    Noh* noh_deletado = *i;
    if (noh_deletado != &sent){
      bool deleted = false;
      raiz = interno_remover(raiz, noh_deletado, deleted);
    }
   }

  }; // class DicioAVL

// -----------------------------------------------------------------------------

#endif