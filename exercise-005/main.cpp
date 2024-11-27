#include <fmt/chrono.h>
#include <fmt/format.h>

#include <algorithm> /* needed for the std::sort */
#include <random>
#include <vector> /* Does provide std::vector */

#include "CLI/CLI.hpp"
#include "config.h"

class Tier {
    public:
    virtual void iss()  {
        fmt::println("Fresse wie ein Tier!");
    }
};

class Hund : public Tier {
    public:
    void iss() override /*final*/ {
        fmt::println("Wuff! fresse wie ein Hund!");
    }
};

class Pudel : public Hund {
    public:
    void iss() override {
        fmt::println("Wuff! fresse wie ein Pudel!");
    }
};
class Katze: public Tier {
    public:
    void iss() override  {
        fmt::println("Schnurr! fresse wie eine Katze!");
    }
};

class Mensch: public Tier {

};

auto main(int argc, char** argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    auto counter{20};           /* set a default of 20 */
    CLI::App app{PROJECT_NAME}; /* create an instance of an App with the variable name app*/
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        /* Add an command lime option -c or --count and fill the variable counter */
        app.add_option("-c,--count", counter, "How many items to insert");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }

    Tier base;
    Hund elli;
    Katze johnny;
    Mensch sepp;

    base.iss();
    elli.iss();
    johnny.iss();
    sepp.iss();
  

    std::vector<Tier*> rudel{&base,&elli,&johnny,&sepp};
    fmt::println("--------------------------------");
    for(Tier* entity: rudel) {
        entity->iss();
    } 
    return 0; /* exit gracefully*/
}
