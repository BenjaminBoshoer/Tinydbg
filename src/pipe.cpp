#include <unistd.h>
#include <fcntl.h>
#include <utility>
#include <libtdb/pipe.hpp>
#include <libtdb/error.hpp>

tdb::pipe::pipe(bool close_on_exec) {
    if(pipe2(fds_, close_on_exec ? O_CLOEXEC : 0) < 0) {
        error::send_errno("Pipe creation failed");
    }
}

tdb::pipe::~pipe() {
    close_read();
    close_write();
}

int tdb::pipe::release_read() {
    return std::exchange(fds_[read_fd], -1);
}

int tdb::pipe::release_write() {
    return std::exchange(fds_[write_fd], -1);
}

void tdb::pipe::close_read() {
    if (fds_[read_fd] != -1) {
        close(fds_[read_fd]);
        fds_[read_fd] = -1;
    }   
}

void tdb::pipe::close_write() {
    if(fds_[write_fd] != -1) {
        close(fds_[write_fd]);
        fds_[write_fd] = -1;
    }
}
