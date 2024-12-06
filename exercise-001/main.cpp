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

        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }




    //fmt::println("The sorted vector: [ {} ]", fmt::join(numbers, ", "));
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    fmt::println("The sorting took: {}", elapsed);
    return 0; /* exit gracefully*/
}
