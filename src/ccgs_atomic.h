
#ifndef _CCGS_ATOMIC_H_
#define _CCGS_ATOMIC_H_

#include <pthread.h>
#include <algorithm>
#include "ccgs_thread_mutex.h"

template <typename TYPE>
class CAtomic
{
    public:
        CAtomic()
        {
            value = 0;
        }

        CAtomic(TYPE a)
        {
            value = a;
        }

        ~CAtomic()
        {
        }

        TYPE Value()
        {
            CGuard guard (lock);
            return this->value;
        }

        TYPE operator+= (TYPE a)
        {
            CGuard guard (lock);
            return this->value += a;
        }

        TYPE operator-= (TYPE a)
        {
            CGuard guard (lock);
            return this->value -= a;
        }

        /**
         * @brief pre-increment
         */
        TYPE operator++ (void)
        {
            CGuard guard (lock);
            return ++this->value;
        }

        /**
         * @brief post-increment
         */
        TYPE operator++ (int)   // parameter must is int type
        {
            CGuard guard (lock);
            return this->value++;
        }

        TYPE operator-- (void)
        {
            CGuard guard (lock);
            return --this->value;
        }

        TYPE operator-- (int)  // parameter must is int type
        {
            CGuard guard (lock);
            return this->value--;
        }

        CAtomic<TYPE>& operator= (TYPE a)
        {
            CAtomic<TYPE> tmp (a);
            CGuard guard (lock);
            std::swap (this->value, tmp.value);
            return *this;
        }

        bool operator== (TYPE a)
        {
            CGuard guard (lock);
            return this->value == a;
        }

        bool operator!= (TYPE a) 
        {
            CGuard guard (lock);
            return this->value != a;
        }

        bool operator> (TYPE a)
        {
            CGuard guard (lock);
            return this->value > a;
        }

        bool operator>= (TYPE a)
        {
            CGuard guard (lock);
            return this->value >= a;
        }

        bool operator< (TYPE a)
        {
            CGuard guard (lock);
            return this->value < a;
        }

        bool operator<= (TYPE a)
        {
            CGuard guard (lock);
            return this->value <= a;
        }

    private:
        TYPE    value;
        CMutex  lock;
};

#endif  // _CCGS_ATOMIC_H_
