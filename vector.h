// vector.h

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

/**
* @class Vector
* @brief template vector, encapsulates the required parts of the STL vector, and is used as a minimal dynamic array
*
* @author Andreas Lau
* @version 01
* @date 22/02/2021 Andreas Lau, started
*
* @bug I may be wrong but there is no bugs at the moment.
*/

template <class T>
class Vector
{
    public:
        /**
         * @brief default constructor
         */
        Vector();

        /**
        * @brief copy constructor
        * @param Vector
        */
        Vector(const Vector& other);

        /**
         * @brief Destructor
         */
        ~Vector();

        /**
        * @brief returns the value stored at the specified index.
        *
        * @return void unsigned int
        */
        int GetCurrentSize() const;

        /**
        *@brief adds data to the end of array
        *@param new data
        */
        void Push(T data);

        /**
        *@brief adds data to specific index
        *@param new data, index for data to be pushed
        */
        void Push(T data, int index);

        /**
        *@brief Empties vector
        */
        void ClearVector();

        /**
        *@brief increases the array size
        */
        void Grow();

        /**
        *@brief prints the contents, current size and capacity of array. Used for testing and debugging
        */
        void Print();

        /**
        *@brief overloaded [] operator
        *@param index
        *@return refence to element at that index
        */
        T& operator[](unsigned int index);

        /**
        * @brief copying between vectors
        *
        * @return Vector<T>
        */
        const Vector& operator=(const Vector& other);


    private:
        std::vector<T> m_vector;
};

//-------------------------------------------------------------------------------------------
// Implementations

template <class T>
Vector<T>::Vector()
    : m_vector() {}


template <class T>
Vector<T>::~Vector() {}

template <class T>
Vector<T>::Vector(const Vector& other)
    : m_vector(other.m_vector) {}

template <class T>
int Vector<T>::GetCurrentSize() const {return(m_vector.size());}

template <class T>
void Vector<T>::Push(T data)
{
    m_vector.push_back(data);
}

template <class T>
void Vector<T>::Push(T data, int index)
{
    m_vector.insert(index, data);
}

template <class T>
void Vector<T>::ClearVector()
{
    m_vector.clear();
}

template <class T>
T& Vector<T>::operator [](unsigned int index)
{
    if(index > m_vector.size())
    {
        exit(-1);
    }
    else if(index == m_vector.size())
    {
        m_vector.resize(m_vector.size()+1);
        return(m_vector[index]);
    }
    else
        return(m_vector[index]);
}

template <class T>
const Vector<T>& Vector<T>::operator =(const Vector &other)
{
    m_vector = other.m_vector;
    return(*this);
}

#endif // VECTOR_H
