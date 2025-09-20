# 42-CPP_Module_03
42 Common Core CPP Module 03

## Table of Contents
- [Orthodox Canonical Form](#orthodox-canonical-form)
- [](#)
- [](#)
- [](#)

----------------------------------------

### Orthodox Canonical Form
The Orthodox Canonical Form requires four member functions: Default constructor, Copy constructor, Copy assignment operator, and Destructor.
- **Default constructor**: a special method automatically invoked when creating an object (an instance of a class).
  - Signature: MyClass().
  - It can include initialization list, which initializes attributes before the body of the constructor.
    
        MyClass() : x(value)
    
- **Copy constructor**: it is called when initializing a new object as a copy of an existing one.
    - Signature: MyClass(const MyClass& other)
      - const: because the object that is received as an argument won't be modified
      - MyClass&: the object is received as reference, because if it were passed value, it would recursively call the copy constructor, leading to infinite recursion.
      - other: existent object we want to copy
  - Usage: two ways
    
        MyClass obj1;
        MyClass obj2 = obj1
        MyClass obj3(obj1);

- **Copy assignment operator**: used when an already existing object is assigned the value of another one.
    - Signature: MyClass& operator=(const MyClass& other);
    - This operator must check the self-assignment before copying (if (this != &other))
    - Usage:
      
          MyClass obj1;
          MyClass obj2;
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

### Heredar clases
Sin using, cada constructor debe definirse explícitamente en la clase derivada.
Se puede llamar al constructor de la clase base usando la sintaxis :ClapTrap() para inicializar name o cualquier otra cosa que queramos heredar.
Después de llamar al constructor de base, podemos modificar cualquier atributo heredado para darle valores distintos.
Para poder acceder a atributos privados de la clase base desde la clase que hereda, tengo que cambiar el estatus de esos atributos de private a protected; de esta manera, podría acceder a ellos desde la clase hija. o con getters/setters.
Sobreescritura de métodos: simplemente volver a escribirlos, no hace falt aponer override
Nuevos métodos....



