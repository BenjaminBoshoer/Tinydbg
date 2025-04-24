#ifndef TDB_PROCESS_HPP
#define TDB_PROCESS_HPP

#include <filesystem>
#include <memory>
#include <sys/types.h>
#include <cstdint>

namespace tdb {
    enum class process_state {
        stopped,
        running,
        exited,
        terminated
    };

    struct stop_reason {
        stop_reason(int wait_status);
        process_state reason;
        std::uint8_t info;
    };

    class process {
        public:
            static std::unique_ptr<process> launch(std::filesystem::path path);
            static std::unique_ptr<process> attach(pid_t pid);
            
            // make sure that the user cant consruct the process in any other way
            process() = delete;
            process(const process&) = delete;
            process& operator=(const process&) = delete;
            ~process();

            void resume();
            stop_reason wait_on_signal();

            pid_t pid() const { return pid_; }
            process_state state() const { return state_;}

        private:
            // definig a private constructor so the static members can construct a process object.
            process(pid_t pid, bool terminate_on_end) 
                : pid_(pid), terminate_on_end_(terminate_on_end) {}
            pid_t pid_ = 0;
            bool terminate_on_end_;
            process_state state_ = process_state::stopped;
    };

}

#endif
