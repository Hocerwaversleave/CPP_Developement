//Copy and Move
#include <iostream>

using namespace std;

class Vector {
private:
    double* elements;
    int size;
public:
    Vector(int s); // constructor: establish invariant, acquire resources
    ~Vector() { delete[] elements; } // destructor: release resources
    
    Vector(const Vector& a); // copy constructor
    Vector& operator=(const Vector& a); // copy assignment
    
    Vector(Vector&& a); // move constr uctor
    Vector& operator=(Vector&& a); // move assignment
    
    double& operator[](int i);
    const double& operator[](int i) const;
    
    int size() const;
};

Vector::Vector(const Vector& a) // copy constructor
    :elements{new double[size]}, // allocate space for elements
    size{a.size} {
    for (int i = 0; i != size; ++i) // copy elements
        elements[i] = a.elements[i];
}
Vector& Vector::operator=(const Vector& a) { // copy assignment
    double* ptr = new double[a.size];
    
    for (int i = 0; i != a.size; ++i)
        ptr[i] = a.elements[i];
    delete[] elements; // delete old elements
    elements = ptr;
    size = a.size;
    return *this;
}

Vector::Vector(Vector&& a)
    :elem{a.elem}, // "grab the elements" from a
    sz{a.sz} {
    a.elem = nullptr; // now a has no elements
    a.sz = 0;
}
Vector f() {
    Vector x(1000);
    Vector y(1000);
    Vector z(1000);
    // ...
    z = x; // we get a copy
    y = std::move(x); // we get a move
    // ...
    return z; // we get a move
};
int 
main() {
    
    return 0;
}
//3.3.3 Resource Management
std::vector<thread> my_threads;

Vector init(int n)
{
thread t {heartbeat}; // run hear tbeat concurrently (on its own thread)
my_threads.push_back(move(t)); // move t into my_threads
// ... more initialization ...
Vector vec(n);
for (int i=0; i<vec.size(); ++i) vec[i] = 777;
return vec; // move res out of init()
}

auto v = init(); // star t hear tbeat and initialize v

3.3.4 Suppressing Operations
        
    class Shape {
public:
Shape(const Shape&) =delete; // no copy operations
Shape& operator=(const Shape&) =delete;
Shape(Shape&&) =delete; // no move operations
Shape& operator=(Shape&&) =delete;
˜Shape();
// ...
};

3.4 Templates
        
template<typename T>
class Vector
private:
T∗ elem; // elem points to an array of sz elements of type T
int sz;
public:
}
template<typename T>
Vector<T>::Vector(int s)
{
if (s<0) throw Negative_siz e{};
elem = new T[s];
sz = s;
}
3.4.3 Function Objects
      