#ifndef QUEUEEXCEPTION_H
#define QUEUEEXCEPTION_H

#include <exception>
#include <iostream>
#include <utility>

class QueueException: public std::exception{
private:
    std::string error_message;
public:
    explicit QueueException(std::string errorMessage) : error_message(std::move(errorMessage)) {}
    [[nodiscard]] const char *what() const noexcept override {
        return error_message.c_str();
    }
    ~QueueException() override = default;

};

#endif //QUEUEEXCEPTION_H