#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Pila {
    private:
        vector<long double> lista;
    public:

        Pila() {}

        ~Pila() {
            if(!lista.empty())
                lista.clear();
        }

        void add(long double data) {
            lista.push_back(data);
        }

        void limpiar(void) {
            lista.clear();
        }

        bool isEmpty(void) const {
            return lista.empty();
        }

        void mostrar(void) {
            if(lista.empty()) {
                cout << "Empty list." << endl;
                return;
            }
            cout << "{\n";
            for(vector<long double>::iterator it = lista.begin(); it != lista.end(); ++it)
                cout << "\t" << *it << endl;
            cout << "}\n";
        }

        inline long double getLast() {
            return lista[lista.size() - 1];
        }

        inline long double pop() {
            long double val = lista[lista.size() - 1];
            lista.erase(lista.end() - 1);
            return val;
        }

        inline const int size() {
            return lista.size();
        }
};

#endif
