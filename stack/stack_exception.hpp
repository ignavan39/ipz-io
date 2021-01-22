#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H

#include <exception>
#include <iostream>
#include <utility>

class StackException: public std::exception{
private:
    std::string error_message;
public:
    explicit StackException(std::string errorMessage) : error_message(std::move(errorMessage)) {}
    [[nodiscard]] const char *what() const noexcept override {
        return error_message.c_str();
    }
    ~StackException() override = default;

};

#endif //STACKEXCEPTION_H