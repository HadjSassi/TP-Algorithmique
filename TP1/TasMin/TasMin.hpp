#include <vector>

#include "../TasMax/TasMax.hpp"
using namespace std;

class TasMin : public TasMax {
public:
    void fixUnverifiedNodes();

    int extractMin();
};