#include <iostream>
using namespace std;

struct treeNode {
    int dato;
    struct treeNode *rightPtr;
    struct treeNode *leftPtr;       
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

void insertar(TREENODEPTR *, int );
void preOrden(TREENODEPTR);
int contarNodos(TREENODEPTR);

int main()
{
    int item;
    TREENODEPTR rootPtr = NULL;
  
    cout<<"Ingresar un numero. -99 para salir"<<endl;
    cin>>item;
  
    while(item != -99)
    {
        insertar(&rootPtr,item);
        cout<<"Ingresar un numero. -99 para salir"<<endl;
        cin>>item;           
    }
  
    cout << "\nRecorrido preOrden: ";
    preOrden(rootPtr);
    cout << endl;

    if(rootPtr != NULL && rootPtr->rightPtr != NULL){
        int cant = contarNodos(rootPtr->rightPtr);
        cout << "Cantidad de nodos en el subarbol derecho: " << cant << endl;
    } else {
        cout << "El arbol no tiene subarbol derecho." << endl;
    }
  
    system("pause");
    return 1;
}

void insertar(TREENODEPTR *treePtr, int valor)
{
    if (*treePtr == NULL)
    {
        *treePtr = new(TREENODE);
        if (*treePtr != NULL)
        {
            (*treePtr)->dato = valor;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;                 
        }
        else
            cout<<"No hay memoria"<<endl;           
    }
    else if (valor < (*treePtr)->dato)
        insertar(&((*treePtr)->leftPtr),valor);
    else if (valor > (*treePtr)->dato)
        insertar(&((*treePtr)->rightPtr),valor);
    else
        cout<<"DUPLICADO"<<endl;
}

void preOrden(TREENODEPTR treePtr)
{
    if (treePtr != NULL)
    {
        cout<<treePtr->dato<<"->";
        preOrden(treePtr->leftPtr); 
        preOrden(treePtr->rightPtr);          
    }     
}

int contarNodos(TREENODEPTR treePtr)
{
    if(treePtr == NULL)
        return 0;
    else
        return 1 + contarNodos(treePtr->leftPtr) + contarNodos(treePtr->rightPtr);
}

