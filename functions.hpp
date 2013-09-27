///////////////////// Yare /////////////////////////////
// Autor: Leo Gutiérrez Ramírez <leorocko13@hotmail.com>
///////////////////// Yare /////////////////////////////


#ifndef _PROCS_H
#define _PROCS_H

#include <string>
#include <vector>
#include <algorithm>
#include "astnode.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Function {
    private:
        string id;
        union nodeTypeTag *pNodos;

    public:
        Function(void) {
        }

        friend ostream& operator <<(ostream& out, const Function func) {
            out << "Function Id: {" << func.id << "}";
            return out;
        }

        Function(string id, union nodeTypeTag *pNodos) {
            this->id = id;
            this->pNodos = pNodos;
        }

        // Getters:
        string &getId(void) {
            return id;
        }

        union nodeTypeTag &getFuncNodes(void) {
            return *pNodos;
        }

        // Setters:
        void setId(string id) {
            this->id = id;
        }

        void setNodes(union nodeTypeTag *nodo) {
            this->pNodos = nodo;
        }

        bool operator()(Function const &func) const {
            return (id.compare(func.id) == 0);
        }
        bool operator==(const Function &func) const {
            return func.id.compare(id);
        }
};

class Funciones {
    private:
        vector<Function> lista;
    public:
        Funciones(void) {
        }
        ~Funciones() {
            if(!lista.empty())
                lista.clear();
        }
        vector<Function> &getListaFunctions(void) {
            return lista;
        }
        void mostrar(void) {
            if(lista.empty()) {
                cout << "Empty list." << endl;
                return;
            }
            cout << "{\n";
            for(vector<Function>::iterator it = lista.begin(); it != lista.end(); ++it)
                cout << "\t" << *it << endl;
            cout << "}\n";
        }

        bool isDefined(string id) {
            if(lista.empty())
                return false;

            for(vector<Function>::iterator it = lista.begin(); it != lista.end(); ++it)
                if((*it).getId().compare(id) == 0)
                    return true;

            return false;
        }

        bool eliminar(string id) {
            if(lista.empty())
                return false;
            for(vector<Function>::iterator it = lista.begin(); it != lista.end(); ++it)
                if((*it).getId().compare(id) == 0) {
                    lista.erase(it);
                    return true;
                }

            return false;
        }

        void eliminarN(unsigned int &n) {
            if(lista.empty())
                return;

            lista.erase(lista.begin() + n);
        }

        size_t getIndex(string id) {
            if(lista.empty())
                return -1;

            unsigned index = 0;
            for(vector<Function>::iterator it = lista.begin(); it != lista.end(); ++it, index++)
                if((*it).getId().compare(id) == 0)
                    return index;

            return -1;
        }

        union nodeTypeTag getNodesById(string id) {
            for(vector<Function>::iterator it = lista.begin(); it != lista.end(); ++it)
                if((*it).getId().compare(id) == 0)
                    return (*it).getFuncNodes();
            //return NULL
        }

        Function &getFuncIndex(unsigned int n) {
            return lista[n];
        }

        void add(Function &func) {
            lista.push_back(func);
        }

        void limpiar(void) {
            lista.clear();
        }

        bool isEmpty(void) const {
            return lista.empty();
        }

        bool isDefined(Function &func) const {
            return find_if(lista.begin(), lista.end(), func) != lista.end();
        }

};

#endif
