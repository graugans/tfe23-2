#include <fmt/chrono.h>
#include <fmt/format.h>

#include <algorithm> /* needed for the std::sort */
#include <random>
#include <vector> /* Does provide std::vector */

#include "CLI/CLI.hpp"
#include "config.h"
#include "myvector.hpp"

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

    fmt::println("Hello exercise number 3");
    {
        MyVector vec;
    }

    MyVector vec2(27);
    fmt::println("Hello exercise number 3 after Vector");

    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 100
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);
    for (int i = 0; i < counter; i++)
    {
        int rand = uniform_dist(e1);
        fmt::println("The value of the random: {}", rand);
        vec2.push_back(rand);
    }

    for (int i = 0; i < vec2.size(); i++)
    {
        fmt::println("The element number {} contains: {}", i, vec2.at(i));
    }

    return 0; /* exit gracefully*/
}
