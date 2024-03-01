#include <string>
#include <sstream> 

class AppendBuffer {
    public:
        AppendBuffer();
        void append(const std::string& s);
        std::string getBuffer() const;
        ~AppendBuffer();
    private:
        std::stringstream buffer;
};