typedef struct Model
{
    int dato;
    Nodo* next;

public:
    T getDato(){
        return this->dato;
    }
    void setDato(T dato){
    this->dato = dato;
    }
    Nodo* getNext(){
        return this->next;
    }
    void setNext(Nodo* next){
        this->next = next;
    }
    Nodo(T dato, Nodo* next){
        this->dato = dato;
        this->next = next;
    }
} Nodo;
template  typename T
class LinkedList{
    |                    ^
    int size;
    Nodo<T>* head;

public:
    int getSize(){
        return this->size;
    }
    void setSize(int size){
        this->size = size;
    }
    Nodo<T>* getHead(){
        return this->head;
    }
    void setHead(Nodo<T>* head){
        this->head = head;
    }
    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }
    void agregarInicio(T valor){
        Nodo<T>* nuevo = new Nodo<T>(valor,this->head);
        this->head = nuevo;
        this->size++;
    }
    void agregarFinal(T valor){
        Nodo<T>* nuevo = new Nodo<T>(valor,nullptr);
       
