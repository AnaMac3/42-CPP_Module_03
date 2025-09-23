# 42-CPP_Module_03
42 Common Core CPP Module 03.  
- Object-Oriented Programming in C++
- Class inheritance

## Table of Contents
- [Orthodox Canonical Form](#orthodox-canonical-form)
- [Class Inheritance](#class-inheritance)

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

### Class Inheritance
Inheritance in C++ allows you to create new classes based on existing ones. These new classes inherit attributes and methods from the base class and can extend or modify its behavior.

- **Inheritance declaration**: To inherit from a class, use the following syntax:

        class BaseClass
        {
          // ...
        };
    
        class DerivedClass : public BaseClass
        {
          //...
        };
  
   - public: means that the public members of the base class remain public in the derived class.
   - Methods and attributes from the base class can be inherited, but constructors are not inherited automatically.
 
- **Inherit attributes and access**: By default, private attributes of the base class are not directly accesible from the derived class. To access them, you can either:
  - Change their visibility to ***protected***:

        class BaseClass
        {
          protected:
            std::string _name;
        };
    
  - Use public getters/setters públicos in the base class.

        class BaseClass
        {
          private:
            std::string _name;
          public:
            const std::string& getName() const;
            void setName(const std::string& name);
        };

- **Constructors in derived classes**: In C++98, you need to explicity define the constructors of the derived class.

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

- **Calling the Base Class Constructor**: When constructing a derived class object, the base class constructor is called first. After calling the parent constructor, inherit attributes (if protected or accessed via setters) can be modified. Initialization syntax:

        DerivedClass::DerivedClass() : BaseClass()
        {
          _name = "new_name"; //modification of inherited attribute
        }

- **Copy Constructor and Assignment Operator**: If the derived class has its own new attributes, you must manually copy them in the copy constructor and assignment operator:

         class DerivedClass : public BaseClass
        {
          private:
            int _level; //own attribute
          public:
            DerivedClass(void);
            DerivedClass(const BaseClass& other):
            DerivedClass& operator=(const BaseClass& other);
            ~DerivedClass(void):
        };

  - Copy constructor:

        DerivedClass::DerivedClass(const DerivedClass &other) : BaseClass(other) //calls base copy constructor
        {
           _level = other._level; //copy own attribute
        } 

  - Assignment operator:
  
        DerivedClass &DerivedClass::operator=(const DerivedClass& other)
        {
          if (this != &other)
          {
            BaseClass::operator=(other); //call base assignment operator
            _level = other._level; //copy own attribute
          }
          return *this;
        }

- **Polymorphism and Virtual Functions**: To allow a function to be overridden and used poymorphically (via pointers or references to the base class) it must be marked as ***virtual*** in the base class:
  
        class BaseClass
        {
          public:
            virtual void  method(); //virtual alows overriding
        };
      
        class DerivedClass : public BaseClass
        {
          public:
            void method(); //overrides BaseClass::method
        }

        int main()
        {
            BaseClass *x = new DerivedClase();
            x->method(); //calls DerivedClass::method
                          // if 'method' in BaseClass were not virtual,
                          // it would call BaseClass::method instead
            delete x;
            return 0;
        }

  ⚠️ In c++98, there is no ***override*** keyword, so the compiler won't warn you if you misspell the method name, change its signature, or use different types. Be carefull!
  
  Overriden method implementation syntax:

    void DerivedClass::method()
    {
      //implementación
    }

  ***virtual*** in base class enables **runtime polymorphism**. Calling method() on a BaseClass* executes the DerivedClass version if the object is actually of the derived type. Without ***virtual***, the compiler performs early binding and calls the base class version.  
    
  ***Early binding vs Late binding***:  
    - Early binding: the function or method to execute is determined at compile time. It is used for non-virtual methods. It is faster, but limits polymorphism because the object cannot dynamically determine which version to execute at runtime.
    - Late binding (or dynamic binding): occurs when the method is ***virtual***. The function call is resolved at runtime based on the actual type of the object, not the type of the pointer or reference.

- **Using inherited methods without overriding**: If the derived class doesn't need to modify an inherited method, there's no need to redeclare it. It can be used directly, as long as it's ***public*** or ***protected***

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

- **Order of calls in Constructon/Destruction**:
    - When creating a derived class object:
        - The base class constructor is called first.
        - Then the derived class constructor is executed.
    - When destroying derived class object:
        - The derived class destructor is called first.
        - Then the base class destructor is called.
    This ensures that the base class resources are available during construction and properly released after the derived class resources during destruction.

---------------------------------
