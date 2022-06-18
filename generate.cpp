#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<string> split(string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}

string convertString(string line,string ciudad,string cursos,string lista){
    vector<string> results;
    results = split(line,';');
    string nombre = results[0]+" "+results[1];
    string email = results[2];

    char name[nombre.length()+1];
    char mail[email.length()+1];
    char city[ciudad.length()+1];
    char course[cursos.length()+1];
    char list[lista.length()+1];

    strcpy(name,nombre.c_str());
    strcpy(mail,email.c_str());
    strcpy(city,ciudad.c_str());
    strcpy(course,cursos.c_str());
    strcpy(list,lista.c_str());

    char buffer[300];
    
    sprintf(buffer,"%s(new Student('%s',[\"%s\"],'%s','%s'));",list,name,course,mail,city);
    string linea;
    linea += buffer;
    return linea;
}

int main(){

    string ciudades[8] = {"Cordoba","Malaga","Sevilla","Barcelona","Madrid","Valencia","Tarragona","Burgos"};
    string cursos[3] = {"Math,Frances","Math","Frances"};

    int numRan = 0;
    int numRandVector = 0;

    string line, linea;
    ifstream inFile;
    ofstream listA("listA.txt"), listB("listB.txt"), listC("listC.txt");


    inFile.open("texto.txt");
    if(inFile.is_open()){
        while(getline(inFile,line)){
            numRan = rand()%3;
            numRandVector = rand()%8;

            switch(numRan){
                case 0://listC
                    linea = convertString(line,ciudades[numRandVector],cursos[0],"listC.add");
                    listC << linea << endl;
                    linea = convertString(line,ciudades[numRandVector],cursos[1],"listA.add");
                    listA << linea << endl;
                    linea = convertString(line,ciudades[numRandVector],cursos[2],"listB.add");
                    listB << linea << endl;
                break;
                case 1://listA
                    linea = convertString(line,ciudades[numRandVector],cursos[1],"listA.add");
                    listA << linea << endl;
                break;
                case 2://listB
                    linea = convertString(line,ciudades[numRandVector],cursos[2],"listB.add");
                    listB << linea << endl;
                break;
            }

        }
        inFile.close();
        listA.close();
        listB.close();
        listC.close();
    }

}
