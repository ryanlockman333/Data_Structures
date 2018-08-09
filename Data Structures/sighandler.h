/* 
 * sighand.h Class Prototypes
 * 
*/

#ifndef SIGHANDLER_H
#define SIGHANDLER_H

// Headers
#include <stdexcept>
#include <string>
using std::runtime_error;

class SigExcp : public runtime_error {
public:
    SigExcp(const std::string &msg) : std::runtime_error(msg) {}
};

class SigHand {
public:
    // Constructors
    SigHand() {}
    ~SigHand() {}

    // Get Members
    static bool getExitSig();

    // Set Members
    static void setExitSig(bool extSig);
    
    // Other Members
    static void exitSigHand(int ignored);
    void setupSigHands();

protected:
    // Data Members
    static bool exitSignal;
};

#endif

