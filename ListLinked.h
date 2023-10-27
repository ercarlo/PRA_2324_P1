#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

	private:
		Node <T>* first;
		int n;

	public:
		ListLinked(){
			n = 0;
			first = nullptr;

		}


		~ListLinked(){
			while(first != nullptr){
				Node<T>* aux=first->next;
				delete first;
				first=aux;
			}
		}

		T operator[](int pos){
			if(pos > n || pos < 0){
				throw std::out_of_range("la posicion no entra dentro del rango");
			}
			else{
				Node<T>* aux = first;
				for(int i=1; i<pos ; i++){
					aux = aux->next;
				}
				return aux->data;

		}
		}

			
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			out<<"list[";
			Node<T>* aux = list.first;
			
			while(aux){
				out<<aux->data;
					out<<",";
				}
					aux= aux->next;
			
			out << "]";
			return out;

		}
		
		virtual void prepend(T e)override{
			Node<T>* aux= new Node<T>(e,first);
			first=aux;
			n++;
		}

		virtual void append(T e) override{
			if (first==nullptr){
				prepend(e);
			}
			else{
				Node<T>* act=first;
				for(int i=1;i<n;i++){
					act=act->next;
				}
				Node<T>* aux= new Node<T>(e , act->next);
				act->next= aux;
			}
			n++;
		}

		virtual void insert(int pos, T e)override{
			if(pos > n || pos < 0){
				throw std::out_of_range("la posicion no es valida");
			}
			else if (pos == 0){
				prepend(e);
			}
			else if(pos == n){
				append(e);
			}
			else {
				Node<T>* act=first;
				for(int i=1; i<pos;i++){
					act=act->next;
				}
				Node<T>* aux= new Node<T>(e,act->next);
				act->next=aux;
				n++;
			}
		}

		
		virtual   T remove(int pos) override{
			Node<T>* aux = first;
			Node<T>* elim;
			int borr;
			if(pos > size()-1|| pos < 0){
				throw std::out_of_range("Número fuera de rango del array");
			}
					    
			else{
				if(pos == 0){
					first= aux->next;
					elim = aux;	 
					borr = elim->data;
				}
				else{
										
					for(int i = 1; i < pos; i++){
						aux = aux->next;
					}
					elim = aux->next;
					borr = elim->data;
					aux->next = elim->next;
				}
			n--;
			delete elim;
			return borr;
			}
					        
		}

		virtual T get(int pos) override{
			if(pos > size()-1 || pos < 0){
				throw std::out_of_range("Número fuera de rango del array");
			}
			else{
				Node<T>* aux = first;
				for(int i = 0; i < pos; i ++){
					aux = aux ->next;
				}
				return aux->data;
			}				    
		  }

		virtual int search(T e) override{
			Node<T>* aux = first;
			for(int i = 0; i < n ; i++){  
				if ( aux ->data == e){
					return i;
				}
				aux= aux->next;
			}
			return -1;					 
		}


		virtual bool empty() override{
			if(n == 0)
			return true;
			else return false;
		}
		
		virtual int size() override{
			return n;
		}
			  

};
