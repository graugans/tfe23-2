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
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }

    fmt::println("Hello exercise number two");
    return 0; /* exit gracefully*/
}
