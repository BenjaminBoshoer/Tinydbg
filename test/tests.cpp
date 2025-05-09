#include <catch2/catch_test_macros.hpp>
#include <libtdb/process.hpp>
#include <libtdb/error.hpp>
#include <sys/types.h>
#include <signal.h>


using namespace tdb;

namespace {
    bool process_exists(pid_t pid) {
        auto ret = kill(pid, 0);
        return ret != -1 and errno != ESRCH;
    }
}


TEST_CASE("process::launch sucess", "[process]") {
    auto proc = process::launch("yes");
	REQUIRE(process_exists(proc->pid()));
}

TEST_CASE("process::launch no such program", "[process]") {
    REQUIRE_THROWS_AS(process::launch("you_do_not_have_to_be_good"), error);
}
