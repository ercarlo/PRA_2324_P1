#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;
		void resize(int new_size){
			
			T aux[new_size];  //se crea un nuevo array del tamaño requerido
			for(int i; i<new_size; i++){
				aux[i] = arr[i];
			}
			delete arr;

			T arr[new_size];
			for(int i; i<new_size; i++){
				arr[i] = aux[i];
			}
			delete aux;
			max = new_size;

		}
	public:
		ListArray(){
			arr = new int [MINSIZE];
			max=2;
			n=0;
		}
		

		~ListArray(){
		delete[] arr;
		}


		T operator[](int pos){
			if(pos > n || pos < 0){
				throw std::out_of_range("Numero fuera del rango");
			}
			else{
				return arr[pos];
			}
		}


		friend std::ostream& operator<<(std::ostream &out,const ListArray<T> &list){
			out<< "List=[ ";
			for(int i=0;i<list.n;i++){
				out<<list.arr[i]<<" ";
			}
			out<<"]";
			return out;
		}
		

		virtual void insert(int pos, T e){
			if(pos > n-1 || pos < 0){
				throw std::out_of_range("numero fuera del intervalo");
			}
			else{
				if(n=max){
					resize(n*2);
				}
				if(pos==0){
					prepend(e);
				}
				else if(pos==n){
					append(e);
				}
				else {
					for(int i=pos; i<n; i++){
						arr[i+1]=arr[i];
					}
					arr[pos]=e;
					n++;
				}
				
		}
			if (n == max){
				resize(n*2);
			}
			arr[n]=e;
			n++;
		}

		virtual void prepend(T e) override{
			if (n==max){
				resize(n*2);
			}

			for(int i=0; i<n;i++){
				arr[i+1]= arr[i];
			}

			arr[0]=e;
			n++;
		}

		virtual T remove(int pos) override{
			if(pos > n-1 || pos < 0){
				throw std::out_of_range("numero fuera del intervalo");
			}
			else{
				return arr[pos];
				
				for(int i=pos; i<n; i++){
					arr[i]=arr[i+1];
				}
				n--;
			}
		}

		virtual T get(int pos) override{
			if(pos > n-1 || pos < 0){
				throw std::out_of_range("numero fuera del intervalo")
			}
			else{
				return arr[pos];
			}
		}
		
		virtual int search( T e) override{
			for(int i=0; i<n ; i++){
				if(arr[i]== e){
					return i;
				}
			}
			return -1;
		}

		virtual bool empty() override{
			if(n=0){return true;}
			else{return false;}
		}

		virtual int size() override{
			return n;
		}

			


};
