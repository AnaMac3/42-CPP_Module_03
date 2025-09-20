# 42-CPP_Module_03
42 Common Core CPP Module 03

## Table of Contents
- [Orthodox Canonical Form](#orthodox-canonical-form)
- [Herencia de clases](#herencia-de-clases)
- [](#)
- [](#)

----------------------------------------

### Orthodox Canonical Form
The Orthodox Canonical Form requires four member functions: Default constructor, Copy constructor, Copy assignment operator, and Destructor.
- **Default constructor**: a special method automatically invoked when creating an object (an instance of a class).
  - Signature: BaseClass().
  - It can include initialization list, which initializes attributes before the body of the constructor.
    
        BaseClass() : x(value)
    
- **Copy constructor**: it is called when initializing a new object as a copy of an existing one.
    - Signature: BaseClass(const BaseClass& other)
      - const: because the object that is received as an argument won't be modified
      - BaseClass&: the object is received as reference, because if it were passed value, it would recursively call the copy constructor, leading to infinite recursion.
      - other: existent object we want to copy
  - Usage: two ways
    
        BaseClass obj1;
        BaseClass obj2 = obj1
        BaseClass obj3(obj1);

- **Copy assignment operator**: used when an already existing object is assigned the value of another one.
    - Signature: BaseClass& operator=(const BaseClass& other);
    - This operator must check the self-assignment before copying (if (this != &other))
    - Usage:
      
          BaseClass obj1;
          BaseClass obj2;
          obj2 = obj1;
    
- **Destructor**: a special method automatically called when an objectis destroyed. It is used to free resources, close files, free dynamic memory, etc.

Simple class example in Orthodox Canonical Form:

    class   Fixed
    {
    	private:
    		int _value;
    		
    	public:
    		Fixed(void) : _value(0) {} //default constructor
    		Fixed(const Fixed& other) //Copy constructor
            {
                *this = other;
                //this->_value = other._value;
            }
    		Fixed& operator=(const Fixed& other) //Asignment operator
            {
                if (this != &other)
                    this->_value = other._value;
                return (*this);
            }
            ~Fixed(void) {} //destructor
      };

### Herencia de clases
La herencia en C++ permite crear nuevas clases a partir de clases existentes. Estas nuevas clases heredan atributos y métodos de la clase base y pueden extender o modificar su comportamiento.  

- **Declaración de herencia**: para heredar de una clase, se utiliza esta sintaxis:

        class BaseClass
        {
          // ...
        };
    
        class DerivedClass : public BaseClass
        {
          //...
        };
  
   - public: significa que los miembros públicos de la clase base siguen siendo públicos en la clase derivada.
   - Se pueden heredar métodos y atributos de la clase base, pero no se heredan los constructores automáticamente.
 
- **Atributos heredados y acceso**: por defecto, los atributos privados de la clase base no son accesibles directamente desde la clase derivada. Para acceder a ellos, se puede:
  - Cambiar su visibilidad a ***protected***:

        class BaseClass
        {
          protected:
            std::string _name;
        };
    
  - Usar getters/setters públicos en la clase base.

        class BaseClass
        {
          private:
            std::string _name;
          public:
            const std::string& getName() const;
            void setName(const std::string& name);
        };

- **Constructores en clases derivadas**: en C++98 hay que definir explícitamente los constructores de la clase hija.

        class BaseClass
        {
          protected:
            std::string _name;
          public:
            BaseClass(void);
            BaseClass(const BaseClass& other):
            BaseClass& operator=(const BaseClass& other);
            ~BaseClass(void):
        };
      
        class DerivedClass : public BaseClass
        {
          public:
            DerivedClass(void);
            DerivedClass(const BaseClass& other):
            DerivedClass& operator=(const BaseClass& other);
            ~DerivedClass(void):
        };

- **Llamada al constructor de la clase base**: Al construir un objeto de la clase hiha, el constructor de la clase base se llama primero. Sintaxis de inicialización:

        DerivedClass::DerivedClass() : BaseClass()
        {
          _name = "new_name"; //atributo heredado
        }

Después de llamar al constructor del padre, se pueden modificar atributos heredados (si están accesibles con protected o mediante setters).

- **Copy constructor y Assignment operator**: si la clase hija tiene nueos atrivutos propios, se deben copiar manualmente en el copy constructor y en el assignment operator:

         class DerivedClass : public BaseClass
        {
          private:
            int _level;
          public:
            DerivedClass(void);
            DerivedClass(const BaseClass& other):
            DerivedClass& operator=(const BaseClass& other);
            ~DerivedClass(void):
        };

  - Copy constructor:

        DerivedClass::DerivedClass(const DerivedClass &other) : BaseClass(other) //lama al constructor del padre y copia sus atributos
        {
           _level = other._level; //copia atributo propio
        } 

  - Assignment operator:
  
        DerivedClass &DerivedClass::operator=(const DerivedClass& other)
        {
          if (this != &other)
          {
            BaseClass::operator=(other); //llama al operador del padre
            _level = other._level;
          }
          return *this;
        }

- **Polimorfismo y funciones virtuales**: Para que una función pueda ser sobreescrita y usada de forma polimórfica (con punteros o referencias a la clase base), debe estar marcada como ***virtual*** en la clase base:
  
        class BaseClass
        {
          public:
            virtual void  method();
        };
      
        class DerivedClass : public BaseClass
        {
          public:
            void method(); //sobreescribe method
        }

⚠️ En c++98 no existe la palabra clave ***override***, por lo que el compilador no te avisa si te equivocas en el nombre de la función, cambias la firma o usas tipos distintos, así que, Atención!

En la implementación del método sobreescrito en la clase hija, la sintaxis es así:

    void DerivedClass::method()
    {
      //implementación
    }

- **Uso de métodos heredados sin sobreescribir**: Si la clase hija no necesita modificar un método heredado, no es necesario volver a declararlo. Se puede usar directamente, siempre que sea public o protected:

    class BaseClass
    {
      protected:
        std::string _name;
      public:
        BaseClass(void);
        BaseClass(const BaseClass& other):
        BaseClass& operator=(const BaseClass& other);
        ~BaseClass(void):

        virtual void  method();
        void  otherMethod();
    };
  
    class DerivedClass : public BaseClass
    {
      public:
        DerivedClass(void);
        DerivedClass(const BaseClass& other):
        DerivedClass& operator=(const BaseClass& other);
        ~DerivedClass(void);

        void method();
    }

    int main()
    {
      DerivedClass object1;

      object1.otherMethod() //llamado sin redeclaración

      return 1;
    }

  - **Orden de llamadas en construcción/destrucción**:
    - Al crear un objeto de clase derivada:
        - Se llama primero al constructor de la clase base
        - Luego se ejecuta el constructor de la clase hija
    - Al destruir un objeto:
        - Se llama primero al destructor de la clase hija
        - Luego al destructor de la clase base.
    Esto garantiza que los recursos del padre estén disponibes durante la consturcción y se liberen después de los del hijo en al destrucción. 
