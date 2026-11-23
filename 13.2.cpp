<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

class Logger {
    Logger() {}                      // private constructor

public:
    Logger(const Logger&) = delete;  // no copies
    void operator=(const Logger&) = delete;

    static Logger& get() {           // thread-safe since C++11
        static Logger instance;      // created once, on first call
        return instance;
    }

    void log(const string &m) {
        cout << "[LOG] " << m << endl;
    }
};

int main() {
    Logger::get().log("system up");
    Logger::get().log("same single instance");

    return 0;
=======
#include <iostream>
#include <string>
using namespace std;

class Logger {
    Logger() {}                      // private constructor

public:
    Logger(const Logger&) = delete;  // no copies
    void operator=(const Logger&) = delete;

    static Logger& get() {           // thread-safe since C++11
        static Logger instance;      // created once, on first call
        return instance;
    }

    void log(const string &m) {
        cout << "[LOG] " << m << endl;
    }
};

int main() {
    Logger::get().log("system up");
    Logger::get().log("same single instance");

    return 0;
>>>>>>> bb7a10374dc0e5456bf47fc1efad8b0641cac135
}