#include <fmt/chrono.h>
#include <fmt/format.h>

#include <algorithm> /* needed for the std::sort */
#include <random>
#include <vector> /* Does provide std::vector */

#include "CLI/CLI.hpp"
#include "config.h"

// Global variable
// .bss Segment
// Nicht initialisierte globale Variablen
uint8_t foo = 0;
int foo2;

// .data Segment
// Initialisierte globale Variablen
uint8_t bar = 100;
int bar2 = 42;

// .rodata Segment
// Read-only globale Variablen
const int rodata = 4711;
const int rodata2 = 4712;

void myFunction()
{
    static int value = 100;
    fmt::println("[myFunction] the value of variable value: {} the address of value {}", value, fmt::ptr(&value));
    value = value + 1;
}

void myFunctionBSS()
{
    static int bss;
    fmt::println("[myFunctionBSS] the value of variable value: {} the address of value {}", bss, fmt::ptr(&bss));
    bss = bss + 1;
}

void myFunctionStack(uint8_t a, uint8_t b)
{
    uint8_t d = 65;
    fmt::println("[myFunctionStack] the value of variable a: {}, b: {} the address of value a: {}, b: {}", a, b,
                 fmt::ptr(&a), fmt::ptr(&b));

    fmt::println("[myFunctionStack] the value of variable d: {} the address of value d: {}", d, fmt::ptr(&d));
}

void indirecktCall()
{
    uint8_t value = 34;
    fmt::println("[indirecktCall] the value of {} address of value: {}", value, fmt::ptr(&value));
    myFunctionStack(22, 23);
}

// Rekursion
void callMySelf()
{
    uint8_t data = 78;
    fmt::print("{}, ", fmt::ptr(&data));
    callMySelf();
}

int* returnAPtr() {
    int* foo = new int(100);
    fmt::println("Address of foo: {}",fmt::ptr(foo));
    return foo;
}

auto main(int argc, char** argv) -> int
{
    int local_variable;
    int local_variable2;

    int local_variable3 = 100;
    static int local_variable4 = 101;

    const int local_variable5 = 200;
    const int local_variable6 = 201;

    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    auto counter{20};           /* set a default of 20 */
    CLI::App app{PROJECT_NAME}; /* create an instance of an App with the variable name app*/
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }

    fmt::println("Hello exercise number two");
    fmt::println("The value of variable foo: {} and the address {}", foo, fmt::ptr(&foo));
    fmt::println("The value of variable foo2: {} and the address {}", foo2, fmt::ptr(&foo2));
    fmt::println("The value of variable bar: {} and the address {}", bar, fmt::ptr(&bar));
    fmt::println("The value of variable bar2: {} and the address {}", bar2, fmt::ptr(&bar2));

    fmt::println("The value of variable rodata: {} and the address {}", rodata, fmt::ptr(&rodata));
    fmt::println("The value of variable rodata2: {} and the address {}", rodata2, fmt::ptr(&rodata2));

    fmt::println("The value of local variable local_variable: {} and the address {}", local_variable,
                 fmt::ptr(&local_variable));
    fmt::println("The value of local variable local_variable2: {} and the address {}", local_variable2,
                 fmt::ptr(&local_variable2));

    fmt::println("The value of local variable local_variable3: {} and the address {}", local_variable3,
                 fmt::ptr(&local_variable3));
    fmt::println("The value of local variable local_variable4: {} and the address {}", local_variable4,
                 fmt::ptr(&local_variable4));

    fmt::println("The value of local variable local_variable5: {} and the address {}", local_variable5,
                 fmt::ptr(&local_variable5));
    fmt::println("The value of local variable local_variable6: {} and the address {}", local_variable6,
                 fmt::ptr(&local_variable6));

    myFunction();
    myFunction();

    myFunctionBSS();
    myFunctionBSS();

    myFunctionStack(45, 56);

    myFunctionStack(foo /*bss segment */, bar /* data segment */);

    indirecktCall();

    //callMySelf();

    int* ptr = new int(67);
    int* ptr2 = new int(69);
    
    fmt::println("The value of the variable ptr points to: {} the address of ptr: {}",
        *ptr, 
        fmt::ptr(ptr)
    );

    fmt::println("The value of the variable ptr2 points to: {} the address of ptr2: {}",
        *ptr2, 
        fmt::ptr(ptr2)
    );

    ptr = returnAPtr();
    delete ptr;
    ptr = returnAPtr();

    return 0; /* exit gracefully*/
}
