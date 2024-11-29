
// For HTML requests
#include <curl/curl.h>
#include <fmt/chrono.h>
#include <fmt/format.h>

#include <nlohmann/json.hpp>

#include "CLI/CLI.hpp"
#include "config.h"

// for convenience
using json = nlohmann::json;

// Callback for CURL
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

auto main(int argc, char **argv) -> int
{
    // CURL stuff
    CURL *curl;
    CURLcode res;

    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    // Perform an HTTP request

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl)
    {
        std::string readBuffer;
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        /* cache the CA cert bundle in memory for a week */
        curl_easy_setopt(curl, CURLOPT_CA_CACHE_TIMEOUT, 604800L);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
        {
            fmt::println("curl_easy_perform() failed: {}", curl_easy_strerror(res));
        }
        else
        {
            fmt::println("{}", readBuffer);
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0; /* exit gracefully*/
}
