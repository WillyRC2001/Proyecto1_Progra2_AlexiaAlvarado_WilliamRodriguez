
#include <iomanip>
#include <sstream>
#include <typeinfo>
#include "baseObject.h"
using namespace std;

namespace base {

    baseObject::~baseObject() {
    }

    bool baseObject::operator==(const baseObject& obj) const {
        return this == &obj;
    }

    string baseObject::toString() const {
        stringstream r;
        r << typeid (*this).name();
        r << "@" << hex << this;
        return r.str();
    }

    ostream& operator<<(ostream& out, const baseObject& obj) {
        out << obj.toString();
        return out;
    }

}
