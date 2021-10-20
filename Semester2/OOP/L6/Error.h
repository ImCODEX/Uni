#include <exception>
#include <string>

class CustomError: public std::exception {
private:
    std::string msg;
public:
    CustomError(const std::string&);
    const std::string& get_msg() const;
};