///////////////////// Yare /////////////////////////////
// Autor: Leo Gutiérrez Ramírez <leorocko13@hotmail.com>
///////////////////// Yare /////////////////////////////


#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

// Este es el bueno!!!

#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream;

inline bool ordMenor(long double x, long double y) {
    return (x < y);
}

inline bool ordMayor(long double x, long double y) {
    return (x > y);
}

class Array {

    private:
        std::string id;
        std::vector<long double> lista;

    public:
        Array(void) {
        }

        Array(string id) {
            this->id = id;
        }

        Array(string id, double x) {
            this->id = id;
            lista.push_back(x);
        }

        ~Array(void) {
            // limpiar la lista:
            if(!lista.empty())
                lista.clear();
        }

        friend ostream& operator <<(ostream& out, Array &arr) {
            for(vector<long double>::iterator it = arr.lista.begin(); it != arr.lista.end(); ++it)
                cout << "\t" << *it << endl;

            return out;
        }

        inline long double minmax(bool flag) {
            if(lista.size() <= 0)
                return 0.0L;

            long double _max = lista[0];
            for(int i = 0; i < lista.size(); i++)
                if(flag) {
                    if(lista[i] < _max)
                        _max = lista[i];
                } else {
                    if(lista[i] > _max)
                        _max = lista[i];
                }
            return _max;
        }

        vector<long double> &getList() {
            return lista;
        }

        std::string &getId() {
            return id;
        }

        void limpiar(void) {
            lista.clear();
        }

        bool isEmpty(void) const {
            return lista.empty();
        }

        void ordenar(bool order) {
            if(order) {
                std::sort(lista.begin(), lista.end(), ordMayor);
            } else {
                std::sort(lista.begin(), lista.end(), ordMenor);
            }
        }

        long double tail() {
            if(lista.size() > 0) {
                return lista[lista.size() - 1];
            } else {
                return 0.0L;
            }
        }

        long double head() {
            if(lista.size() > 0) {
                return lista[0];
            } else {
                return 0.0L;
            }
        }

        inline void reverse() {
            if(!lista.empty())
                std::reverse(lista.begin(), lista.end());
        }

        void fill(int n) {
            srand((unsigned)time(NULL));

            for(int i = 0; i < n; i++)
                add(((double) rand() / (RAND_MAX)));

        }

        void eliminarN(int &n) {
            if(lista.empty())
                return;
            lista.erase(lista.begin() + n);
        }

        void mostrar(void) {
            if(lista.empty()) {
                std::cout << "Empty list." << std::endl;
                return;
            }
            std::cout << '[' << id << ']' << "{\n";
            for(vector<long double>::iterator it = lista.begin(); it != lista.end(); ++it)
                cout << "\t" << *it << endl;
            cout << "}\n";
        }

        inline long double average(void) {
            if(lista.size() <= 0) {
                return 0.0L;
            }

            long double sum = 0.0L;
            for(vector<long double>::iterator it = lista.begin(); it != lista.end(); ++it)
                sum += *it;

            return (sum / lista.size());

        }

        inline int size(void) {
            return lista.size();
        }

        // Setters:
        void setId(string id) {
            this->id = id;
        }

        void add(long double x) {
            lista.push_back(x);
        }

        void putfront(long double x) {
            lista.insert(lista.begin(), x);
        }

        long double get(int n) {
            if(n < 0 || n > lista.size()) {
                return -1.0f;
            } else {
                return lista.at(n);
            }
        }

};

class Arrays {

    private:
        vector<Array> lista;

    public:
        Arrays(void) {
        }
        ~Arrays(void) {
            if(!lista.empty())
                lista.clear();
        }

        void limpiar(void) {
            lista.clear();
        }

        bool isEmpty(void) const {
            return lista.empty();
        }

        void eliminarN(unsigned int &n) {
            if(lista.empty())
                return;
            lista.erase(lista.begin() + n);
        }

        bool eliminar(string id) {
            if(lista.empty())
                return false;
            for(vector<Array>::iterator it = lista.begin(); it != lista.end(); ++it)
                if((*it).getId().compare(id) == 0) {
                    lista.erase(it);
                    return true;
                }

            return false;
        }

        void add(Array &a) {
            lista.push_back(a);
        }

        size_t getIndex(string id) {
            if(lista.empty())
                return -1;

            unsigned index = 0;
            for(vector<Array>::iterator it = lista.begin(); it != lista.end(); ++it, index++)
                if((*it).getId().compare(id) == 0)
                    return index;

            return -1;
        }

        bool isDefined(string id) {
            if(lista.empty())
                return false;

            for(vector<Array>::iterator it = lista.begin(); it != lista.end(); ++it)
                if((*it).getId().compare(id) == 0)
                    return true;

            return false;
        }

        Array &getListById(string id) {
            for(vector<Array>::iterator it = lista.begin(); it != lista.end(); ++it)
                if((*it).getId().compare(id) == 0)
                    return *it;
            // return NULL;
        }

        Array &getArrByIndex(unsigned int n) {
            return lista[n];
        }

        void mostrar(void) {
            if(lista.empty()) {
                cout << "Empty list." << endl;
                return;
            }
            cout << "{\n";

            for(vector<Array>::iterator it = lista.begin(); it != lista.end(); ++it)
                cout << (*it).getId() << " ...\n" <<  (*it) << "," << endl;
            cout << "}\n";
        }

};

#endif
