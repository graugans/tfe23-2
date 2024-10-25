#include <fmt/chrono.h>
#include <fmt/format.h>

#include <algorithm> /* needed for the std::sort */
#include <random>
#include <vector> /* Does provide std::vector */

#include "CLI/CLI.hpp"
#include "config.h"

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

    
    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 100
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);
    int rand_value = uniform_dist(e1);

    std::vector<unsigned int> numbers;
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < counter; i++)
    {
        numbers.push_back(uniform_dist(e1));
    }
    auto end = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    fmt::println("The inserting took: {}", elapsed);
    //fmt::println("The random vector: [ {} ]", fmt::join(numbers, ", "));


    fmt::println("Let's sort the numbers vector");
    fmt::println("--------------------------------------------------------------------------");

    start = std::chrono::system_clock::now();
    std::sort(numbers.begin(), numbers.end(), std::less<int>());
    end = std::chrono::system_clock::now();

    fmt::println("The sorted numbers vector");
    fmt::println("--------------------------------------------------------------------------");


    //fmt::println("The sorted vector: [ {} ]", fmt::join(numbers, ", "));
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    fmt::println("The sorting took: {}", elapsed);
    return 0; /* exit gracefully*/
}
