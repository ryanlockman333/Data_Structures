/* 
 * sighand.cpp Class Implementations
 *
*/

// Headers
#include <signal.h>
#include <errno.h>
#include "sighandler.h"

// Get Members
bool SigHand::getExitSig() { return exitSignal; }

// Set Members
void SigHand::setExitSig(bool extSig) { exitSignal = extSig; }
   
// Other Members
void SigHand::exitSigHand(int ignored) { exitSignal = true; } 

void SigHand::setupSigHands() {
    if(signal((int)SIGINT, SigHand::exitSigHand) == SIG_ERR)
        throw SigExcp("Error setupSigHands\n");
}

// Data Members
bool SigHand::exitSignal;

