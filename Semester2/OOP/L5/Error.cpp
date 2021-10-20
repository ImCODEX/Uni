#include "Error.h"

CustomError::CustomError(const std::string &msg): msg{msg}, std::exception(){

}

const std::string &CustomError::get_msg() const {
    return this->msg;
}