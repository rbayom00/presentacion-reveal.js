#include "discoveryScanner.h"

using namespace nmap_wrapper;
using namespace scanner;

discoveryScanner::discoveryScanner(std::string ip, bool runOnLinux){
    if (runOnLinux)
    {
        this->m_nmapCommand = "nmap -T5 -Pn -sS -O " + ip + " -oX output.xml >> /dev/null"; //Version Unix
    }
    else
    {
        this->m_nmapCommand = "nmap -T5 -Pn -sS -O " + ip + " -oX output.xml > NUL"; // Version Windows
    }
}