///////////////////// Yare /////////////////////////////
// Autor: Leo Gutiérrez Ramírez <leorocko13@hotmail.com>
///////////////////// Yare /////////////////////////////

#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Var {
    
    private:
        string id;
        long double longValue;

    public:

        Var(void) {}
        friend ostream& operator <<(ostream& out, const Var &var) {
            out << "Id: {" << var.id << "}, value: {" << var.longValue << "}";
            return out;
        }

        Var(string id, long double longValue) {
            this->id = id;
            this->longValue = longValue;
        }

        // Getters:
        string &getId(void) {
            return id;
        }

        long double &getLongDouble(void) {
            return this->longValue;
        }

        // Setters:
        void setId(string id) {
            this->id = id;
        }

        void setLongValue(long double longValue) {
            this->longValue = longValue;
        }

        bool operator()(Var const &v) const {
            return ((id.compare(v.id) == 0) && (longValue == v.longValue));
        }
        bool operator==(const Var &var) const {
            return var.id.compare(id);
        }

};

class Variables {
    private:
        vector<Var> lista;
    public:
        Variables(void) {
        }
        ~Variables() {
            if(!lista.empty())
                lista.clear();
        }
        vector<Var> &getListaVar(void) {
            return lista;
        }

        void mostrar(void) {
            if(lista.empty()) {
                cout << "Empty list." << endl;
                return;
            }
            cout << "{\n";
            for(vector<Var>::iterator it = lista.begin(); it != lista.end(); ++it)
                cout << "\t" << *it << endl;
            cout << "}\n";
        }

        bool isDefined(string id) {
            if(lista.empty())
                return false;

            for(vector<Var>::iterator it = lista.begin(); it != lista.end(); ++it)
                if((*it).getId().compare(id) == 0)
                    return true;

            return false;
        }

        bool eliminar(string id) {
            if(lista.empty())
                return false;
            for(vector<Var>::iterator it = lista.begin(); it != lista.end(); ++it)
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
            for(vector<Var>::iterator it = lista.begin(); it != lista.end(); ++it, index++)
                if((*it).getId().compare(id) == 0)
                    return index;

            return -1;
        }
        
		long double getLongValueById(string id) {
            for(vector<Var>::iterator it = lista.begin(); it != lista.end(); ++it)
                if((*it).getId().compare(id) == 0)
                    return (*it).getLongDouble();
            return 0.0L;
        }
		
		Var &getVarByIndex(unsigned int n) {
            return lista[n];
        }

        void add(Var &variable) {
            lista.push_back(variable);
        }

        void limpiar(void) {
            lista.clear();
        }

        bool isEmpty(void) const {
            return lista.empty();
        }
};

#endif
