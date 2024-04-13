#pragma once
#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <iostream>

namespace base {

    class baseObject {
    public:
        virtual ~baseObject();

        virtual bool operator==(const baseObject&) const;
        virtual std::string toString() const;
    };

    std::ostream& operator<<(std::ostream&, const baseObject&);

}

#endif /* BASEOBJECT_H */
