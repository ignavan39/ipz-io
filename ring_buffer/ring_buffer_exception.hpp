#ifndef RINGBUFFEREXCEPTION_H
#define RINGBUFFEREXCEPTION_H

#include <exception>
#include <iostream>
#include <utility>

class RingBufferException: public std::exception{
private:
    std::string error_message;
public:
    explicit RingBufferException(std::string errorMessage) : error_message(std::move(errorMessage)) {}
    [[nodiscard]] const char *what() const noexcept override {
        return error_message.c_str();
    }
    ~RingBufferException() override = default;

};

#endif //RINGBUFFEREXCEPTION_H